#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "AnotherWindow.h"
#include "MUSY.h"
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>
#include <QDebug>
#include <QMessageBox>


#include <QFile>
#include <QTextStream>
#include <QSqlRelationalDelegate>
#include <QSqlRecord>
#include <QSqlQuery>
#include <QBoxLayout>

#include <QPixmap>

bool logining = false;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
   // QPixmap pix(":/img/img/regist.png");
    //int w = ui->imgRegist->width();
    //int h = ui->imgRegist->height();
    //ui->imgRegist->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../../bd/MUCY.db");
    if (db.open())
    {
        model = new QSqlRelationalTableModel(this, db);
        ui->statusbar->showMessage("Вы успешно подключились к базе данных: "+db.databaseName());

        QSqlQuery updateQuery;
        if (updateQuery.prepare("UPDATE users SET Состояние = 'не в сети'")) {
            updateQuery.exec();
        }
    }
    else
    {
        ui->statusbar->showMessage("Ошибка подключения к базе данных: "+db.lastError().databaseText());
    }

}
MainWindow::~MainWindow()
{
    db.close();
    delete ui;
}


void MainWindow::on_buttonExit_clicked() // выход из программы
{
    close();
}


void MainWindow::on_buttonEnter_clicked()
{
    QString login,password;
    login = ui->lineLogin->text();
    password=ui->linePassword->text();

    if (!db.isOpen()){
        qDebug()<<"Ошибка открытия базы данных";
    }

    QSqlQuery qry;
    //QMessageBox::information(this, "проверка", "логин: "+ login + " пароль: " + password);

    if(qry.prepare("select * from users where Логин = :login AND Пароль = :password")){
        qry.bindValue(":login", login);
        qry.bindValue(":password", password);
        if (qry.exec() && qry.next()) {
            ui->labelStatus->setText("Добро пожаловать!");
            ui->labelStatus->setStyleSheet("color: green;");
            logining = true;


            QSqlQuery updateQuery;
            if (updateQuery.prepare("UPDATE users SET Состояние = 'в сети' WHERE Логин = :login")) {
                updateQuery.bindValue(":login", login);
                if (updateQuery.exec()) {
                    // Статус пользователя успешно обновлен
                } else {
                    // Ошибка при обновлении статуса пользователя
                    qDebug() << "Ошибка при обновлении статуса пользователя:" << updateQuery.lastError().text();
                }

        } else {
            ui->labelStatus->setText("В логине или пароле допущена ошибка или такого пользователя нет!");
            ui->labelStatus->setStyleSheet("color: red;");
        }
    }

    if (logining == true){
        MUSYWindow = new AnotherWindow();
        MUSYWindow->show();
        this->close();
    }
    else{ui->labelStatus->setText("Ошибка логина или пороля!");
    ui->labelStatus->setAlignment(Qt::AlignCenter); // Выравнивание по центру
    ui->labelStatus->setFont(QFont("Arial", 11)); // Установка шрифта размером 11
    ui->labelStatus->setStyleSheet("color: red;");
    }
}
}

void MainWindow::on_buttonRegist_clicked()
{
    // Создаем диалоговое окно для добавления сотрудника
    QDialog dialog(this);
    QVBoxLayout layout(&dialog);

    // Добавляем поля для ввода данных о сотруднике
    QLineEdit *surnameLineEdit = new QLineEdit(&dialog);
    QLineEdit *nameLineEdit = new QLineEdit(&dialog);
    QLineEdit *loginLineEdit = new QLineEdit(&dialog);
    QLineEdit *passwordLineEdit = new QLineEdit(&dialog);

    // Добавляем выпадающий список для роли
    QComboBox *storageComboBox = new QComboBox(&dialog);
    QStringList lst;
    lst <<"user"<<"ingeneer"<<"admin";
    storageComboBox->addItems(lst);

    // Создаем кнопки "Добавить" и "Отмена"
    QPushButton *addButton = new QPushButton("Добавить", &dialog);
    QPushButton *cancelButton = new QPushButton("Отмена", &dialog);

    // Размещаем элементы на диалоговом окне
    layout.addWidget(new QLabel("Фамилия:", &dialog));
    layout.addWidget(surnameLineEdit);
    layout.addWidget(new QLabel("Имя:", &dialog));
    layout.addWidget(nameLineEdit);
    layout.addWidget(new QLabel("Логин:", &dialog));
    layout.addWidget(loginLineEdit);
    layout.addWidget(new QLabel("Пароль:", &dialog));
    layout.addWidget(passwordLineEdit);

    layout.addWidget(new QLabel("Роль:", &dialog));
    layout.addWidget(storageComboBox);
    layout.addWidget(addButton);
    layout.addWidget(cancelButton);

    // Подключаем сигналы и слоты для кнопок
    connect(addButton, &QPushButton::clicked, [&]() {
        // Проверяем, что фамилия и имя не пустые
        if (surnameLineEdit->text().isEmpty() || nameLineEdit->text().isEmpty()) {
            QMessageBox::critical(this, "Ошибка", "Фамилия и имя сотрудника не должны быть пустыми!");
            return;
        }

        // Проверяем, что логин ввели
        QString logine = loginLineEdit->text();
        QSqlQuery loginQuery;

        if (logine.isEmpty()){
            QMessageBox::critical(this, "Ошибка", "Логин обязателен!");
            return;
        }

        //if (!loginQuery.prepare("select count(*) from users where Логин = :login"))
        //loginQuery.bindValue(":login", logine);
        if (loginQuery.exec("select count(*) from users where Логин = '"+logine+"'") && loginQuery.next()) {
            int count = loginQuery.value(0).toInt(); // Получаем количество повторяющихся логинов
            if (count >= 1) { // Проверяем, что логин повторяется больше одного раза
                QMessageBox::critical(this, "Ошибка", "Логин повторяется больше одного раза!");
                return;
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Ошибка при выполнении запроса!");
            return;
        }

        // Проверяем, что пароль ввели
        QString passworde = passwordLineEdit->text();
        if (passworde.isEmpty()) {
            QMessageBox::critical(this, "Ошибка", "Безопасность это не шутка - Пароль обязателен!");
            return;
        }

        // Добавляем нового сотрудника в базу данных
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO users('Имя', 'Фамилия', 'Роль', 'Логин', 'Пароль') VALUES (:name, :surname, :roll, :login, :password)");
        insertQuery.bindValue(":name", nameLineEdit->text());
        insertQuery.bindValue(":surname", surnameLineEdit->text());
        insertQuery.bindValue(":roll", storageComboBox->currentText());
        insertQuery.bindValue(":login", loginLineEdit->text());
        insertQuery.bindValue(":password", passwordLineEdit->text());
        //QMessageBox::information(this, "вот что мы запомним"," имя: "+ nameLineEdit->text() + "Фамилия: " + surnameLineEdit->text()+ "Роль: " + storageComboBox->currentText()+ "Логин: " + loginLineEdit->text()+ "Пароль: " + passwordLineEdit->text());
        if (insertQuery.exec()) {
            QMessageBox::information(this, "Успех", "Вы успешно зарегестрировались!");
            model->select(); // Обновляем модель данных
            dialog.close();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось зарегестрироваться:\n" + insertQuery.lastError().text());
        }
    });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::close);

    // Отображаем диалоговое окно
    dialog.exec();
}


void MainWindow::on_MainWindow_iconSizeChanged(const QSize &iconSize)
{

}

