#include "adminroom.h"
#include "ui_adminroom.h"

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
#include <QLineEdit>
#include <QFormLayout>
#include <QDialogButtonBox>

AdminRoom::AdminRoom(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AdminRoom)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../../bd/MUCY.db");
    if (db.open())
    {
        model = new QSqlRelationalTableModel(this, db);
        model->setTable("users");
        model->select();
        ui->tableView->setModel(model);
        ui->tableView->setItemDelegate(new QSqlRelationalDelegate(ui->tableView));
        ui->tableView->setSortingEnabled(true);
        ui->tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableView->setSelectionBehavior(QAbstractItemView::SelectRows);
    }
}

AdminRoom::~AdminRoom()
{
    delete ui;
    db.close();
}

void AdminRoom::on_pushButton_5_clicked()
{
    this->close();
}


void AdminRoom::on_pushButton_4_clicked()
{
    model->select();
}


void AdminRoom::on_addAdmin_clicked()
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
            QMessageBox::information(this, "Успех", "Пользователь добавлен");
            model->select(); // Обновляем модель данных
            dialog.close();
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось добавить пользователя:\n" + insertQuery.lastError().text());
        }
    });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::close);

    // Отображаем диалоговое окно
    dialog.exec();
}


void AdminRoom::on_dellAdmin_clicked()
{

    QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите пользователя для удаления");
        return;
    }
    QModelIndex selectedIndex = selectedRows.at(0).siblingAtColumn(1);
    int currentRowBuilds = selectedRows.at(0).row();
    QString Dell = model->data(selectedIndex, Qt::DisplayRole).toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Удаление", "Вы уверены, что хотите удалить данные об этом сотруднике?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        model->removeRow(currentRowBuilds);
        model->select();
    }
}


void AdminRoom::on_redAdmin_clicked()
{QModelIndexList selectedRows = ui->tableView->selectionModel()->selectedRows();
if (selectedRows.isEmpty()) {
    QMessageBox::warning(this, "Ошибка", "Выберите пользователя для редактирования");
    return;
}
QModelIndex selectedIndex = selectedRows.at(0).siblingAtColumn(0);
int currentRowAdmin = selectedRows.at(0).row();
QString id = model->data(selectedIndex, Qt::DisplayRole).toString();
QSqlQuery query;
query.prepare("SELECT * FROM users WHERE ID = :id");
query.bindValue(":id", id);
if (!query.exec()) {
    QMessageBox::critical(this, "Ошибка", "Не удалось получить данные о сотруднике:\n" + query.lastError().text());
    return;
}
if (query.next()) {
    // Создаем новое диалоговое окно для редактирования данных о пользователе
    QDialog *editUserDialog = new QDialog(this);
    editUserDialog->setWindowTitle("Редактирование пользователя");

    // Создаем элементы управления для диалогового окна
    QFormLayout *formLayout = new QFormLayout;
    QLineEdit *nameLineEdit = new QLineEdit(query.value("Имя").toString());
    QLineEdit *surnameLineEdit = new QLineEdit(query.value("Фамилия").toString());
    QComboBox *roleComboBox = new QComboBox;
    roleComboBox->addItems({"user", "ingeneer", "admin"});
    roleComboBox->setCurrentText(query.value("Роль").toString());
    QLineEdit *loginLineEdit = new QLineEdit(query.value("Логин").toString());
    QLineEdit *passwordLineEdit = new QLineEdit(query.value("Пароль").toString());
    QLineEdit *stateLineEdit = new QLineEdit(query.value("Состояние").toString());
    stateLineEdit->setReadOnly(true); // Поле "Состояние" нельзя редактировать

    // Добавляем элементы управления в диалоговое окно
    formLayout->addRow("Имя:", nameLineEdit);
    formLayout->addRow("Фамилия:", surnameLineEdit);
    formLayout->addRow("Роль:", roleComboBox);
    formLayout->addRow("Логин:", loginLineEdit);
    formLayout->addRow("Пароль:", passwordLineEdit);

    // Создаем кнопки для диалогового окна
    QDialogButtonBox *buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);

    // Подключаем обработчики событий к кнопкам
    connect(buttonBox, &QDialogButtonBox::accepted, [=](){
        // Если нажата кнопка "Подтвердить"
        QSqlQuery updateQuery;
        updateQuery.prepare("UPDATE users SET Имя = :name, Фамилия = :surname, Роль = :role, Логин = :login, Пароль = :password WHERE ID = :id");
        updateQuery.bindValue(":id", id);
        updateQuery.bindValue(":name", nameLineEdit->text());
        updateQuery.bindValue(":surname", surnameLineEdit->text());
        updateQuery.bindValue(":role", roleComboBox->currentText());
        updateQuery.bindValue(":login", loginLineEdit->text());
        updateQuery.bindValue(":password", passwordLineEdit->text());
        if (updateQuery.exec()) {
            // Обновляем данные в таблице
            model->select();
            QMessageBox::information(this, "Успех", "Данные о пользователе успешно обновлены");
        } else {
            QMessageBox::critical(this, "Ошибка", "Не удалось обновить данные о пользователе:\n" + updateQuery.lastError().text());
        }
        editUserDialog->close();
    });
    connect(buttonBox, &QDialogButtonBox::rejected, editUserDialog, &QDialog::close);

    // Добавляем кнопки в диалоговое окно
    QVBoxLayout *mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);
    editUserDialog->setLayout(mainLayout);

    // Отображаем диалоговое окно
    editUserDialog->exec();
}

}

