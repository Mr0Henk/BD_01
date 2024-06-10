#include "anotherwindow.h"
#include "ui_anotherwindow.h"

#include "adminroom.h"

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
#include <QDialogButtonBox>
#include <QDateEdit>
#include <QFormLayout>
#include <QSpinBox>

#include "addbuilds.h"


AnotherWindow::AnotherWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::AnotherWindow)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../../bd/MUCY.db");
    if (db.open())
    {
        ui->S->setText("Вы успешно подключились к базе данных: "+db.databaseName());
        ui->S->setAlignment(Qt::AlignCenter); // Выравнивание по центру
        ui->S->setFont(QFont("Arial", 9)); // Установка шрифта размером 9
        ui->S->setStyleSheet("color: green;");


        // Настройка модели и отображения для таблицы GOST
        modelGOST = new QSqlRelationalTableModel(this, db);
        modelGOST->setTable("GOST");
        modelGOST->select();
        ui->tableViewGOST->setModel(modelGOST);
        ui->tableViewGOST->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewGOST));
        ui->tableViewGOST->setSortingEnabled(true);
        ui->tableViewGOST->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewGOST->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewGOST->setSelectionBehavior(QAbstractItemView::SelectRows);


        // Настройка модели и отображения для таблицы GOST
        modelBuilds = new QSqlRelationalTableModel(this, db);
        modelBuilds->setTable("builds");
        modelBuilds->select();
        ui->tableViewBuilds->setModel(modelBuilds);
        ui->tableViewBuilds->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewBuilds));
        ui->tableViewBuilds->setSortingEnabled(true);
        ui->tableViewBuilds->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewBuilds->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewBuilds->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableViewBuilds->hideColumn(6);

        // Настройка модели и отображения для таблицы audit
        modelAudit = new QSqlRelationalTableModel(this, db);
        modelAudit->setTable("audit");
        modelAudit->select();
        ui->tableViewAudit->setModel(modelAudit);
        ui->tableViewAudit->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewAudit));
        ui->tableViewAudit->setSortingEnabled(true);
        ui->tableViewAudit->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewAudit->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewAudit->setSelectionBehavior(QAbstractItemView::SelectRows);

        // Настройка модели и отображения для таблицы parts
        modelParts = new QSqlRelationalTableModel(this, db);
        modelParts->setTable(NameBuilds);
        modelParts->select();
        ui->tableViewParts->setModel(modelParts);
        ui->tableViewParts->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewParts));
        ui->tableViewParts->setSortingEnabled(true);
        ui->tableViewParts->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewParts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewParts->setSelectionBehavior(QAbstractItemView::SelectRows);

        QSqlQuery helloUser;
        helloUser.exec("SELECT Фамилия, Имя, Роль FROM users where Состояние = 'в сети'");
        while (helloUser.next()) {
            QString userName = helloUser.value(1).toString()+" " +helloUser.value(0).toString();
            QString roll = helloUser.value(2).toString();
            if (roll == "admin"){GlobalRoll = 2;};
            if (roll == "user"){GlobalRoll = 0;};
            if (roll == "ingeneer"){GlobalRoll = 1;};
            ui->labelName->setText(userName);
            ui->labelName->setAlignment(Qt::AlignCenter); // Выравнивание по центру
            ui->labelName->setFont(QFont("Arial", 14)); // Установка шрифта размером 9
            ui->labelName->setStyleSheet("color: green;");

            ui->labelRoll->setText(roll);
            ui->labelRoll->setAlignment(Qt::AlignCenter); // Выравнивание по центру
            ui->labelRoll->setFont(QFont("Arial", 14)); // Установка шрифта размером 9
            ui->labelRoll->setStyleSheet("color: green;");
        }
        RollButton();


    }
    else
    {
        ui->S->setText("Ошибка подключения к базе данных: "+db.lastError().databaseText());
        ui->S->setAlignment(Qt::AlignCenter); // Выравнивание по центру
        ui->S->setFont(QFont("Arial", 9)); // Установка шрифта размером 9
        ui->S->setStyleSheet("color: red;");
    }
}

AnotherWindow::~AnotherWindow()
{
    db.close();
    delete ui;
}



void AnotherWindow::RollButton(){
    switch(GlobalRoll){
        case 2://админу доступно всё
        break;

        case 1: //инжинеру - редактирование деталей и сборок
        ui->addPart->hide(); //окно деталей ГОСТ
        ui->redPArt->hide();
        ui->delPart->hide();


        ui->delAudit->hide(); //окно аудита

        ui->AdminButton->hide();//окно админа
        break;

        case 0: //пользователю - только смотреть
        ui->addBuilds->hide(); //окно сборок
        ui->redBuilds->hide();
        ui->delBuilds->hide();


        ui->addPart->hide(); //окно деталей ГОСТ
        ui->redPArt->hide();
        ui->delPart->hide();


        ui->delAudit->hide(); //окно аудита

        ui->AdminButton->hide();//окно админа

        ui->delParts->hide();
        ui->addPartLocal->hide();
        ui->redParts->hide();
        ui->addPartGOST->hide();
        ui->label_5->hide();
        ui->label_6->hide();
        ui->lineEditGOST->hide();
        break;
    }
}



void AnotherWindow::countParts() {
    // Получение модели таблицы
    QAbstractItemModel *model = ui->tableViewParts->model();

    // Получение значения второго столбца из данной строки
    int rowModelCount = ui->tableViewParts->model()->rowCount();
    int sum=0;
    int soloSum;
    QString gost;
    for (int i = 0; i<rowModelCount; i++){
        soloSum = model->data(model->index(i, 1)).toInt();
        sum += soloSum;
        gost = model->data(model->index(i, 4)).toString();
        if (gost !="0"){
        QSqlQuery query;
        query.prepare("SELECT * FROM GOST WHERE ГОСТ = :gost");
        query.bindValue(":gost", gost);
        query.exec();
        query.next();

        QString part = query.value(1).toString();
        QString material = query.value(3).toString();
        int weight = query.value(4).toInt();
        QSqlQuery query2;
        query2.prepare("UPDATE '" + trueName + "' SET Деталь = :part, Вес = :weight, Материал = :material  WHERE ГОСТ = :gost");
        query2.bindValue(":part", part);
        query2.bindValue(":weight", weight);
        query2.bindValue(":material", material);
        query2.bindValue(":gost", gost);
        query2.exec();
        qDebug() << "Номер строки: "<<i<<" Гост: " << gost<<"Название: "<<part<<" Материал: "<<material<<"Вес: "<<weight;
        }
    }


    int rowCount = ui->tableViewParts->model()->rowCount();
    QSqlQuery query;
    query.prepare("SELECT * FROM builds WHERE Название = :name");
    query.bindValue(":name",NameBuilds);

    query.prepare("UPDATE builds SET числоДеталей = :count, Вес = :weight WHERE Название = :name");
    query.bindValue(":count",rowCount);
    query.bindValue(":weight",sum);
    query.bindValue(":name",NameBuilds);

    if (!query.exec()) {
        QMessageBox::critical(this, "Ошибка", "Не удалось получить данные о сборке:\n" + query.lastError().text());
        return;
    }

    // Подготавливаем запрос
    query.prepare("UPDATE '"+trueName+"' SET 'изСборки' = :trueName");

    // Привязываем значение переменной к параметру запроса
    query.bindValue(":trueName", NameBuilds);

    // Выполняем запрос
    if (!query.exec()) {
        //QMessageBox::critical(this, "Ошибка", "не удалось заполнить таблицу именем:\n" + query.lastError().text());
        return;
    }

    if (!query.exec()) {
    QMessageBox::critical(this, "Ошибка", "Не удалось получить данные о сборке:\n" + query.lastError().text());
    return;
    }

    //QMessageBox::warning(this, "правдивое имя", trueName);


}

void AnotherWindow::ConnectDataBase(){
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../../bd/MUCY.db");
    QString editBuildName = "buildtest";
    if (db.open())
    {
        ui->S->setText("Вы успешно подключились к базе данных: "+db.databaseName());
        ui->S->setAlignment(Qt::AlignCenter); // Выравнивание по центру
        ui->S->setFont(QFont("Arial", 9)); // Установка шрифта размером 9
        ui->S->setStyleSheet("color: green;");


        // Настройка модели и отображения для таблицы GOST
        modelGOST = new QSqlRelationalTableModel(this, db);
        modelGOST->setTable("GOST");
        modelGOST->select();
        ui->tableViewGOST->setModel(modelGOST);
        ui->tableViewGOST->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewGOST));
        ui->tableViewGOST->setSortingEnabled(true);
        ui->tableViewGOST->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewGOST->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewGOST->setSelectionBehavior(QAbstractItemView::SelectRows);


        // Настройка модели и отображения для таблицы GOST
        modelBuilds = new QSqlRelationalTableModel(this, db);
        modelBuilds->setTable("builds");
        modelBuilds->select();
        ui->tableViewBuilds->setModel(modelBuilds);
        ui->tableViewBuilds->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewBuilds));
        ui->tableViewBuilds->setSortingEnabled(true);
        ui->tableViewBuilds->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewBuilds->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewBuilds->setSelectionBehavior(QAbstractItemView::SelectRows);
        ui->tableViewBuilds->hideColumn(6);

        // Настройка модели и отображения для таблицы audit
        modelAudit = new QSqlRelationalTableModel(this, db);
        modelAudit->setTable("audit");
        modelAudit->select();
        ui->tableViewAudit->setModel(modelAudit);
        ui->tableViewAudit->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewAudit));
        ui->tableViewAudit->setSortingEnabled(true);
        ui->tableViewAudit->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewAudit->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewAudit->setSelectionBehavior(QAbstractItemView::SelectRows);

        // Настройка модели и отображения для таблицы parts
        modelParts = new QSqlRelationalTableModel(this, db);
        modelParts->setTable(editBuildName);
        modelParts->select();
        ui->tableViewParts->setModel(modelParts);
        ui->tableViewParts->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewParts));
        ui->tableViewParts->setSortingEnabled(true);
        ui->tableViewParts->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
        ui->tableViewParts->setEditTriggers(QAbstractItemView::NoEditTriggers);
        ui->tableViewParts->setSelectionBehavior(QAbstractItemView::SelectRows);
    }
    else
    {
        ui->S->setText("Ошибка подключения к базе данных: "+db.lastError().databaseText());
        ui->S->setAlignment(Qt::AlignCenter); // Выравнивание по центру
        ui->S->setFont(QFont("Arial", 9)); // Установка шрифта размером 9
        ui->S->setStyleSheet("color: red;");
    }
}

void AnotherWindow::on_addBuilds_clicked() {
    // Создаем диалоговое окно с одним полем ввода текста
    QDialog dialog;
    QLineEdit *lineEdit = new QLineEdit(&dialog);
    QPushButton *addButton = new QPushButton("Добавить");
    QPushButton *cancelButton = new QPushButton("Отмена");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lineEdit);
    layout->addWidget(addButton);
    layout->addWidget(cancelButton);
    dialog.setLayout(layout);

    QString author;

    QSqlQuery helloUser;
    helloUser.exec("SELECT Фамилия, Имя FROM users where Состояние = 'в сети'");
    while (helloUser.next()) {
        author = helloUser.value(0).toString()+" " +helloUser.value(1).toString();
        modelBuilds->select();
    }

    // Подключаем обработчик нажатия кнопки "Добавить"
    QObject::connect(addButton, &QPushButton::clicked, [&]() {
        QString name = lineEdit->text();
        QSqlQuery Query;
        // Проверка на пустое поле и выполнение запроса к базе данных
        if (name.isEmpty() || !Query.prepare("select count(*) from builds where Название = :name")) {
            QMessageBox::critical(this, "Ошибка", "изСборки обязательно!");
            return;
        }

        Query.bindValue(":name", name);
        if (Query.exec() && Query.next()) {
            int count = Query.value(0).toInt(); // Получаем количество повторяющихся названий
            if (count >= 1) { // Проверяем, что логин повторяется больше одного раза
                QMessageBox::critical(this, "Ошибка", "Сборка с таким названием уже есть!");
                return;
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Ошибка при выполнении запроса!");
            return;
        }
        int count=-1;
        QString locTrueName = name;
        while(count != 0){
            QSqlQuery query("SELECT COUNT(*) FROM builds WHERE trueName = '"+locTrueName+"'");
            if (query.exec() && query.next()) {
                count = query.value(0).toInt(); // Получаем количество повторяющихся названий
                if (count >= 1) { // Проверяем, что логин повторяется больше одного раза
                    locTrueName = locTrueName+"kek";
                }
            }
        }
        // Вставка сборки в базу данных
        QSqlQuery insertQuery;
        insertQuery.prepare("INSERT INTO builds('Название', 'Автор сборки','trueName') VALUES (:name, :author,:truename)");
        insertQuery.bindValue(":name", name);
        insertQuery.bindValue(":author", author);
        insertQuery.bindValue(":truename", locTrueName);
    if (insertQuery.exec()) {
        QMessageBox::information(this, "Успех", "Сборка добавлена в базу данных");
        QSqlQuery newDataBase;
        newDataBase.exec("CREATE TABLE IF NOT EXISTS '"+locTrueName+"' ('Деталь'	TEXT  NOT NULL, 'Вес'	INTEGER  DEFAULT 0, 'Материал'	TEXT NOT NULL, 'изСборки' TEXT NOT NULL,'ГОСТ'	INTEGER  DEFAULT 0, 'key' INTEGER, "
                         +"PRIMARY KEY('key' AUTOINCREMENT))");
        modelBuilds->select(); // Обновляем модель данных
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить сборку:\n" + insertQuery.lastError().text());
    }
    modelBuilds->select();

        // Закрываем диалоговое окно
        dialog.close();
    });

    // Подключаем обработчик нажатия кнопки "Отмена"
    QObject::connect(cancelButton, &QPushButton::clicked, [&]() {
        dialog.close();
    });

    // Отображаем диалоговое окно
    dialog.exec();
}


void AnotherWindow::on_fullExit_2_clicked()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Выход", "Действительно выйти?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
    QApplication::quit(); // Закрытие приложения
    }
    // Если ответ "Нет", ничего не делаем, просто закрываем окно сообщения
}


void AnotherWindow::on_pushButton_clicked()
{
    ConnectDataBase();
}


void AnotherWindow::on_upBuilds_clicked()
{
    ConnectDataBase();
}


void AnotherWindow::on_upPart_clicked()
{
    ConnectDataBase();
}


void AnotherWindow::on_upParts_clicked()
{
    countParts();
    modelParts->select();
    modelBuilds->select();
    modelAudit->select();
}


void AnotherWindow::on_upAudit_clicked()
{
    ConnectDataBase();
}


void AnotherWindow::on_delBuilds_clicked()
{
    QModelIndexList selectedRows = ui->tableViewBuilds->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Выберите сборку для удаления");
            return;
    }
    QModelIndex selectedIndex = selectedRows.at(0).siblingAtColumn(1);
    int currentRowBuilds = selectedRows.at(0).row();
    QString Dell = modelBuilds->data(selectedIndex, Qt::DisplayRole).toString();

    //QMessageBox::warning(this,"запрос","DROP TABLE '"+Dell+"'");
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Удаление", "Вы уверены, что хотите удалить эту сборку?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
            QSqlQuery dellDate;
            dellDate.prepare("DROP TABLE '"+Dell+"'");
            dellDate.exec();
            dellDate.next();
            modelBuilds->removeRow(currentRowBuilds);
            modelBuilds->select();
            modelAudit->select();
    }
    countParts();
    modelParts->select();
    modelBuilds->select();
    modelAudit->select();
}


void AnotherWindow::on_redBuilds_clicked()
{
    QModelIndexList selectedRows = ui->tableViewBuilds->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
    QMessageBox::warning(this, "Ошибка", "Выберите сборку для редактирования");
    return;
    }
    QModelIndex selectedIndex = selectedRows.at(0).siblingAtColumn(1);
    QString Red = modelBuilds->data(selectedIndex, Qt::DisplayRole).toString();

    QSqlQuery query;
    query.prepare("SELECT * FROM builds WHERE Название = :id");
    query.bindValue(":id", Red);
    if (!query.exec()) {
    QMessageBox::critical(this, "Ошибка", "Не удалось получить данные о сотруднике:\n" + query.lastError().text());
    return;
    }

    // Если данные найдены, открываем диалоговое окно для редактирования
    if (query.next()) {
    // Создаем диалоговое окно
    QDialog dialog;
    dialog.setWindowTitle("Редактирование сборки");

    // Создаем строку ввода
    QLineEdit lineEdit;
    lineEdit.setText(Red);

    // Создаем кнопки
    QPushButton buttonConfirm("Подтвердить");
    QPushButton buttonCancel("Выйти");

    // Размещаем виджеты на диалоговом окне
    QVBoxLayout layout;
    layout.addWidget(&lineEdit);
    layout.addWidget(&buttonConfirm);
    layout.addWidget(&buttonCancel);
    dialog.setLayout(&layout);

    // Подключаем обработчики событий к кнопкам
    connect(&buttonConfirm, &QPushButton::clicked, &dialog, &QDialog::accept);
    connect(&buttonCancel, &QPushButton::clicked, &dialog, &QDialog::reject);

    // Отображаем диалоговое окно
    if (dialog.exec() == QDialog::Accepted) {
            // Получаем введенное значение
            QString newRed = lineEdit.text();

            QSqlQuery nameQuery;
            if (newRed.isEmpty()){
                QMessageBox::critical(this, "Ошибка", "Нужно ввести новое НЕ пустое значение!");
                return;
            }

        if (nameQuery.exec("select count(*) from builds where Название = '"+newRed+"'") && nameQuery.next()) {
            int count = nameQuery.value(0).toInt(); // Получаем количество повторяющихся логинов
            if (count >= 1) { // Проверяем, что логин повторяется больше одного раза
                QMessageBox::critical(this, "Ошибка", "Такая сборка уже есть");
                return;
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Ошибка при выполнении запроса!");
            return;
        }


            // Обновляем данные в базе данных
            query.prepare("UPDATE builds SET Название = :newRed WHERE Название = :oldRed");
            query.bindValue(":newRed", newRed);
            query.bindValue(":oldRed", Red);

            if (!query.exec()) {
            QMessageBox::critical(this, "Ошибка", "Не удалось обновить данные о сборке1:\n" + query.lastError().text());
            return;
            }
            // Обновляем данные в модели
            modelBuilds->setData(selectedIndex, newRed, Qt::DisplayRole);
    }
    }

    ConnectDataBase();
    modelBuilds->select();
    modelAudit->select();

}


void AnotherWindow::on_AdminButton_clicked()
{
    AdminRoom AdminWindow;
    AdminWindow.setModal(true);
    AdminWindow.exec();
    QSqlQuery helloUser;
    helloUser.exec("SELECT Фамилия, Имя, Роль FROM users where Состояние = 'в сети'");
    while (helloUser.next()) {
    QString userName = helloUser.value(1).toString()+" " +helloUser.value(0).toString();
    QString roll = helloUser.value(2).toString();
    if (roll == "admin"){GlobalRoll = 2;};
    if (roll == "user"){GlobalRoll = 0;};
    if (roll == "ingeneer"){GlobalRoll = 1;};
    ui->labelName->setText(userName);
    ui->labelName->setAlignment(Qt::AlignCenter); // Выравнивание по центру
    ui->labelName->setFont(QFont("Arial", 14)); // Установка шрифта размером 9
    ui->labelName->setStyleSheet("color: green;");

    ui->labelRoll->setText(roll);
    ui->labelRoll->setAlignment(Qt::AlignCenter); // Выравнивание по центру
    ui->labelRoll->setFont(QFont("Arial", 14)); // Установка шрифта размером 9
    ui->labelRoll->setStyleSheet("color: green;");
    };
    RollButton();
}


void AnotherWindow::on_fullGuild_2_clicked()
{
    QString filePath = "./../rykovod.txt"; // Путь к файлу руководства (главное, чтобы в ресурсах был)
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл руководства.");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();

    QMessageBox::information(this, "Руководство", content);

    file.close();
}


void AnotherWindow::on_fullInfo_2_clicked()
{

    QString filePath = "./../oprog.txt"; // Путь к файлу информации о программе (главное, чтобы в ресурсах был)
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Ошибка", "Не удалось открыть файл с информацией о программе.");
        return;
    }

    QTextStream in(&file);
    QString content = in.readAll();

    QMessageBox::information(this, "О программе", content);

    file.close();
}


void AnotherWindow::on_delAudit_clicked()
{
    modelAudit->removeRow(currentRowAudit);
    modelAudit->select();
}


void AnotherWindow::on_tableViewAudit_clicked(const QModelIndex &index)
{
    currentRowAudit = index.row();
}


void AnotherWindow::on_tableViewGOST_clicked(const QModelIndex &index)
{
    currentRowGOST = index.row();
}


void AnotherWindow::on_addPart_clicked()
{
    // Создаем диалоговое окно
    QDialog dialog;
    dialog.setWindowTitle("Добавление детали");

    // Создаем элементы формы
    QFormLayout *formLayout = new QFormLayout;

    QLabel *labelName = new QLabel("Название детали");
    QLineEdit *lineEditName = new QLineEdit;

    QLabel *labelGOST = new QLabel("Номер ГОСТ");
    QLineEdit *lineEditGOST = new QLineEdit;
    lineEditGOST->setValidator(new QIntValidator(0, 99999, this));
    lineEditGOST->setMaxLength(5);

    connect(lineEditGOST, &QLineEdit::textEdited, [this, lineEditGOST](const QString &text) {
        if (text.length() < 5) {
            lineEditGOST->setStyleSheet("background-color: red;");
        } else {
            lineEditGOST->setStyleSheet("");
        }
    });


    QLabel *labelMaterial = new QLabel("Материал");
    QComboBox *comboBoxMaterial = new QComboBox;
    comboBoxMaterial->addItems({"Алюминий", "Бронза", "Никель", "Свинец", "Титан", "Кобальт", "Сталь", "Железо"});

    QLabel *labelWeight = new QLabel("Вес");
    QLineEdit *lineEditWeight = new QLineEdit;
    lineEditWeight->setValidator(new QIntValidator(0, 9999, this));

    QLabel *labelDate = new QLabel("Дата введения");
    QDateEdit *dateEditDate = new QDateEdit;
    dateEditDate->setDisplayFormat("dd.MM.yyyy");

    QLabel *labelStatus = new QLabel("Статус");
    QComboBox *comboBoxStatus = new QComboBox;
    comboBoxStatus->addItems({"Действующий", "Недействующий"});

    // Добавляем элементы в форму
    formLayout->addRow(labelName, lineEditName);
    formLayout->addRow(labelGOST, lineEditGOST);
    formLayout->addRow(labelMaterial, comboBoxMaterial);
    formLayout->addRow(labelWeight, lineEditWeight);
    formLayout->addRow(labelDate, dateEditDate);
    formLayout->addRow(labelStatus, comboBoxStatus);

    // Создаем кнопки
    QPushButton *addButton = new QPushButton("Добавить", &dialog);
    QPushButton *cancelButton = new QPushButton("Отмена", &dialog);

    dialog.setLayout(formLayout);
    formLayout->addRow(addButton);
    formLayout->addRow(cancelButton);

    connect(addButton, &QPushButton::clicked, [&]() {
        // Получаем данные из формы
        QString name = lineEditName->text();
        QString gost = lineEditGOST->text();
        QString material = comboBoxMaterial->currentText();
        int weight = lineEditWeight->text().toInt();
        QDate date = dateEditDate->date();
        QString status = comboBoxStatus->currentText();
        // Проверяем данные
        if (lineEditName->text().isEmpty() || lineEditGOST->text().isEmpty() || comboBoxMaterial->currentText().isEmpty() || lineEditWeight->text().toInt() == 0 || dateEditDate->date().isNull() || comboBoxStatus->currentText().isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Заполните все поля");
            return;
        }

        QSqlQuery GOSTQuery;
        if (GOSTQuery.exec("select count(*) from 'GOST' where ГОСТ = '"+gost+"'") && GOSTQuery.next()) {
            int count = GOSTQuery.value(0).toInt(); // Получаем количество повторяющихся логинов
            if (count >= 1) { // Проверяем, что гост повторяется больше одного раза
                QMessageBox::critical(this, "Ошибка", "номер ГОСТ повторяется больше одного раза!");
                return;
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Ошибка при выполнении запроса!");
            return;
        }

        // Добавляем деталь в базу данных
        QSqlQuery query;
        query.prepare("INSERT INTO GOST ('Название детали', 'ГОСТ', 'Материал', 'Вес', 'Дата введения', 'Статус') VALUES (?, ?, ?, ?, ?, ?)");
        query.addBindValue(name);
        query.addBindValue(gost);
        query.addBindValue(material);
        query.addBindValue(weight);
        query.addBindValue(date.toString("dd.MM.yyyy"));
        query.addBindValue(status);
        if (!query.exec())
        {
            QMessageBox::critical(this, "Ошибка", query.lastError().text());
            return;
        }

        // Обновляем модель
        modelGOST->select();
        modelAudit->select();
        dialog.close();
    });

    connect(cancelButton, &QPushButton::clicked, &dialog, &QDialog::close);

    // Отображаем диалоговое окно
    dialog.exec();
}

void AnotherWindow::on_delPart_clicked()
{
    QModelIndexList selectedRows = ui->tableViewGOST->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
        QMessageBox::warning(this, "Ошибка", "Выберите пользователя для удаления");
        return;
    }
    QModelIndex selectedIndex = selectedRows.at(0).siblingAtColumn(1);
    int currentRowGOST = selectedRows.at(0).row();
    QString Dell = modelGOST->data(selectedIndex, Qt::DisplayRole).toString();

    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, "Удаление", "Вы уверены, что хотите удалить данные об этом сотруднике?",
                                  QMessageBox::Yes | QMessageBox::No);
    if (reply == QMessageBox::Yes) {
        modelGOST->removeRow(currentRowGOST);
        modelGOST->select();
        modelAudit->select();
    }

}


void AnotherWindow::on_redPArt_clicked()
{
    QModelIndexList selectedRows = ui->tableViewGOST->selectionModel()->selectedRows();
        if (selectedRows.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Выберите деталь для редактирования");
            return;
        }
        QModelIndex selectedIndex = selectedRows.at(0).siblingAtColumn(0);
        int currentRowGOST = selectedRows.at(0).row();
        QString id = modelGOST->data(selectedIndex, Qt::DisplayRole).toString();
        QSqlQuery query;
        query.prepare("SELECT * FROM 'GOST' WHERE IDGOST = :id");
        query.bindValue(":id", id);
        if (!query.exec()) {
            QMessageBox::critical(this, "Ошибка", "Не удалось получить данные о детали:\n" + query.lastError().text());
            return;
        }

if (query.next()) {
        // Создаем диалоговое окно
        QDialog dialog;
        dialog.setWindowTitle("Редактирование детали");

        // Создаем элементы формы
        QFormLayout *formLayout = new QFormLayout;
        QLabel *labelName = new QLabel("Название детали");
        QLineEdit *lineEditName = new QLineEdit(query.value("Название детали").toString());
        QLabel *labelGOST = new QLabel("Номер ГОСТ");
        QLineEdit *lineEditGOST = new QLineEdit(query.value("ГОСТ").toString());
        lineEditGOST->setValidator(new QIntValidator(0, 99999, this));
        lineEditGOST->setMaxLength(5);

        QLabel *labelMaterial = new QLabel("Материал");
        QComboBox *comboBoxMaterial = new QComboBox;
        comboBoxMaterial->addItems({"Алюминий", "Бронза", "Никель", "Свинец", "Титан", "Кобальт", "Сталь", "Железо"});
        comboBoxMaterial->setCurrentText(query.value("Материал").toString());

        QLabel *labelWeight = new QLabel("Вес");
        QLineEdit *lineEditWeight = new QLineEdit(query.value("Вес").toString());
        lineEditWeight->setValidator(new QIntValidator(0, 9999, this));
        QLabel *labelDate = new QLabel("Дата введения");
        QDateEdit *dateEditDate = new QDateEdit;
        dateEditDate->setDisplayFormat("dd.MM.yyyy");
        QLabel *labelStatus = new QLabel("Статус");
        QComboBox *comboBoxStatus = new QComboBox;
        comboBoxStatus->addItems({"Действующий", "Недействующий"});
        comboBoxStatus->setCurrentText(query.value("Статус").toString());

        // Добавляем элементы в форму
        formLayout->addRow(labelName, lineEditName);
        formLayout->addRow(labelGOST, lineEditGOST);
        formLayout->addRow(labelMaterial, comboBoxMaterial);
        formLayout->addRow(labelWeight, lineEditWeight);
        formLayout->addRow(labelDate, dateEditDate);
        formLayout->addRow(labelStatus, comboBoxStatus);

        // Создаем кнопки
        QPushButton *saveButton = new QPushButton("Сохранить", &dialog);
        QPushButton *cancelButton = new QPushButton("Отмена", &dialog);
        dialog.setLayout(formLayout);
        formLayout->addRow(saveButton);
        formLayout->addRow(cancelButton);

        connect(saveButton, &QPushButton::clicked, [&]() {
        // Получаем данные из формы
        QString name = lineEditName->text();
        QString gost = lineEditGOST->text();
        QString material = comboBoxMaterial->currentText();
        int weight = lineEditWeight->text().toInt();
        QDate date = dateEditDate->date();
        QString status = comboBoxStatus->currentText();
        // Проверяем данные
        if (lineEditName->text().isEmpty() || lineEditGOST->text().isEmpty() || comboBoxMaterial->currentText().isEmpty() || lineEditWeight->text().toInt() == 0 || dateEditDate->date().isNull() || comboBoxStatus->currentText().isEmpty())
        {
            QMessageBox::warning(this, "Ошибка", "Заполните все поля");
            return;
        }

        QSqlQuery GOSTQuery;
        if (GOSTQuery.exec("select count(*) from 'GOST' where ГОСТ = '"+gost+"'") && GOSTQuery.next()) {
            int count = GOSTQuery.value(0).toInt(); // Получаем количество повторяющихся логинов
            count -=1;
            if (count >= 1) { // Проверяем, что гост повторяется больше одного раза
                QMessageBox::critical(this, "Ошибка", "номер ГОСТ повторяется больше одного раза!");
                return;
            }
        } else {
            QMessageBox::critical(this, "Ошибка", "Ошибка при выполнении запроса!");
            return;
        }

        // Добавляем деталь в базу данных
        QSqlQuery query;
        query.prepare("UPDATE  GOST SET 'Название детали' = :name, 'ГОСТ' = :gost, 'Материал' = :material, 'Вес' = :weight, 'Дата введения' = :date, 'Статус' = :status WHERE IDGOST = :id");
        query.bindValue(":id", id);
        query.bindValue(":name",name);
        query.bindValue(":gost",gost);
        query.bindValue(":material",material);
        query.bindValue(":weight",weight);
        query.bindValue(":date",date.toString("dd.MM.yyyy"));
        query.bindValue(":status",status);
        if (!query.exec())
        {
            QMessageBox::critical(this, "Ошибка", query.lastError().text());
            return;
        }

        // Обновляем модель
        modelGOST->select();
        modelAudit->select();
        dialog.close();
        });

        connect(cancelButton, &QPushButton::clicked, [&]() {
            // Закрыть диалоговое окно
            dialog.close();
        });

// Отобразить диалоговое окно
dialog.exec();
}
}


void AnotherWindow::on_tableViewBuilds_clicked(const QModelIndex &index) {


}


void AnotherWindow::on_addPartLocal_clicked() {
    if (selectedRowsParts.isEmpty()) {
                QMessageBox::warning(this, "Ошибка", "Выберите сборку для добавления в неё деталей");
                return;
    }
    else {
    QDialog* dialog = new QDialog(this);
    dialog->setWindowTitle("Добавление детали");
    dialog->setModal(true);

    QFormLayout* formLayout = new QFormLayout;
    QLineEdit* partLineEdit = new QLineEdit;
    QSpinBox* weightSpinBox = new QSpinBox;
    weightSpinBox->setMinimum(0);
    QStringList materials = {"Алюминий", "Бронза", "Никель", "Свинец", "Титан", "Кобальт", "Сталь", "Железо"};
    QComboBox* materialComboBox = new QComboBox;
    materialComboBox->addItems(materials);

    QLineEdit *lineEditWeight = new QLineEdit;
    lineEditWeight->setValidator(new QIntValidator(0, 9999, this));


    formLayout->addRow("Деталь:", partLineEdit);
    formLayout->addRow("Вес:", lineEditWeight);
    formLayout->addRow("Материал:", materialComboBox);

    QDialogButtonBox* buttonBox = new QDialogButtonBox(QDialogButtonBox::Ok | QDialogButtonBox::Cancel);
    connect(buttonBox, &QDialogButtonBox::accepted, dialog, &QDialog::accept);
    connect(buttonBox, &QDialogButtonBox::rejected, dialog, &QDialog::reject);

    QVBoxLayout* mainLayout = new QVBoxLayout;
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(buttonBox);

    dialog->setLayout(mainLayout);

    if (dialog->exec() == QDialog::Accepted) {
        QString part = partLineEdit->text();
        int weight = lineEditWeight->text().toInt();
        QString material = materialComboBox->currentText();

        if (part.isEmpty() || weight == 0 || material.isEmpty()) {
            QMessageBox::warning(this, "Ошибка", "Все поля должны быть заполнены!");
            return;
        }

        QSqlQuery query;
        query.prepare("INSERT INTO '" + trueName + "' ('Деталь', 'Вес', 'Материал', 'изСборки') VALUES (:part, :weight, :material, :name)");
        query.bindValue(":part", part);
        query.bindValue(":weight", weight);
        query.bindValue(":material", material);
        query.bindValue(":name", NameBuilds);
        query.exec();
        countParts();
        modelParts->select();
        modelBuilds->select();
        modelAudit->select();
    }
    countParts();
    modelParts->select();
    modelBuilds->select();
    modelAudit->select();
    dialog->deleteLater();}
}


void AnotherWindow::on_tableViewBuilds_doubleClicked(const QModelIndex &index)
{
selectedRowsParts = ui->tableViewBuilds->selectionModel()->selectedRows();
if (selectedRowsParts.isEmpty()) {
return;
}
QModelIndex selectedIndex1 = selectedRowsParts.at(0).siblingAtColumn(1);
NameBuilds = modelBuilds->data(selectedIndex1, Qt::DisplayRole).toString();
QModelIndex selectedIndex = selectedRowsParts.at(0).siblingAtColumn(6);
trueName = modelBuilds->data(selectedIndex, Qt::DisplayRole).toString();
idBuilds = modelBuilds->data(selectedRowsParts.at(0).siblingAtColumn(0), Qt::DisplayRole).toString();

modelParts->setTable(trueName);
modelParts->select();
ui->tableViewParts->setModel(modelParts);
ui->tableViewParts->setItemDelegate(new QSqlRelationalDelegate(ui->tableViewParts));
ui->tableViewParts->setSortingEnabled(true);
ui->tableViewParts->horizontalHeader()->setSectionResizeMode(QHeaderView::ResizeToContents);
ui->tableViewParts->setEditTriggers(QAbstractItemView::NoEditTriggers);
countParts();
}


void AnotherWindow::on_delParts_clicked()
{
if (selectedRowsParts.isEmpty()) {
QMessageBox::warning(this, "Ошибка", "Выберите деталь для удаления");
return;
}
QModelIndex selectedIndex = ui->tableViewParts->selectionModel()->currentIndex();
QString Dell = modelParts->data(selectedIndex, Qt::DisplayRole).toString();

QMessageBox::StandardButton reply;
reply = QMessageBox::question(this, "Удаление", "Вы уверены, что хотите удалить эту деталь?",
                              QMessageBox::Yes | QMessageBox::No);
if (reply == QMessageBox::Yes) {
modelParts->removeRow(selectedIndex.row());
modelParts->select();
modelBuilds->select();
modelAudit->select();
}
countParts();
modelParts->select();
modelBuilds->select();
modelAudit->select();
}


void AnotherWindow::on_addPartGOST_clicked()
{

    countParts();
    modelParts->select();
    modelBuilds->select();
    modelAudit->select();
    QString gost = ui->lineEditGOST->text();

    if (gost.isEmpty() || gost.size() != 5 || !gost.toInt()) {
    QMessageBox::warning(this, "Ошибка", "Введите корректный ГОСТ (5 цифр)");
    return;
    }

    QSqlQuery query;
    query.prepare("SELECT * FROM GOST WHERE ГОСТ = :gost AND Статус = 'Действующий'");
    query.bindValue(":gost", gost);
    if (!query.exec())
    {
    QMessageBox::warning(this, "Ой-ой", "такого номера ГОСТ нет или он недейсвителен!");
    return;
    }
    query.exec();
    query.next();

    QString part = query.value(1).toString();
    QString material = query.value(3).toString();
    int weight = query.value(4).toInt();

    QSqlQuery query2;
    query2.prepare("INSERT INTO '" + trueName + "' ('Деталь', 'Вес', 'Материал','изСборки','ГОСТ') VALUES (:part, :weight, :material, :name, :gost)");
    query2.bindValue(":part", part);
    query2.bindValue(":weight", weight);
    query2.bindValue(":material", material);
    query2.bindValue(":name", NameBuilds);
    query2.bindValue(":gost", gost);
    query2.exec();
    countParts();
    modelParts->select();
    modelBuilds->select();
    modelAudit->select();
}


void AnotherWindow::on_redParts_clicked(){
    QModelIndexList selectedRows = ui->tableViewParts->selectionModel()->selectedRows();
    if (selectedRows.isEmpty()) {
    QMessageBox::warning(this, "Ошибка", "Выберите сборку для редактирования");
    return;
    }
    QModelIndex selectedIndex = selectedRows.at(0).siblingAtColumn(5);
    QString id = modelParts->data(selectedIndex, Qt::DisplayRole).toString();


    QModelIndex selectedIndex2 = selectedRows.at(0).siblingAtColumn(4);
    QString gost = modelParts->data(selectedIndex2, Qt::DisplayRole).toString();
    //QMessageBox::critical(this, "Ошибка", id+gost);

    if (gost != "0") {
    QMessageBox::warning(this, "Ошибка", "Нельзя редактировать ГОСТ!");
    return;
    }


    QSqlQuery query;
    query.prepare("SELECT * FROM '"+trueName+"' WHERE key = :id");
    query.bindValue(":id", id);
    if (!query.exec()) {
    QMessageBox::critical(this, "Ошибка", "Не удалось получить данные о детали:\n" + query.lastError().text());
    return;
    }

if (query.next()) {
        // Создаем диалоговое окно
        QDialog dialog;
        dialog.setWindowTitle("Редактирование детали");

        // Создаем элементы формы
        QFormLayout *formLayout = new QFormLayout;
        QLabel *labelName = new QLabel("Название детали");
        QLineEdit *lineEditName = new QLineEdit(query.value("Деталь").toString());

        QLabel *labelMaterial = new QLabel("Материал");
        QComboBox *comboBoxMaterial = new QComboBox;
        comboBoxMaterial->addItems({"Алюминий", "Бронза", "Никель", "Свинец", "Титан", "Кобальт", "Сталь", "Железо"});
        comboBoxMaterial->setCurrentText(query.value("Материал").toString());

        QLabel *labelWeight = new QLabel("Вес");
        QLineEdit *lineEditWeight = new QLineEdit(query.value("Вес").toString());
        lineEditWeight->setValidator(new QIntValidator(0, 9999, this));

        // Добавляем элементы в форму
        formLayout->addRow(labelName, lineEditName);
        formLayout->addRow(labelMaterial, comboBoxMaterial);
        formLayout->addRow(labelWeight, lineEditWeight);

        // Создаем кнопки
        QPushButton *saveButton = new QPushButton("Сохранить", &dialog);
        QPushButton *cancelButton = new QPushButton("Отмена", &dialog);
        dialog.setLayout(formLayout);
        formLayout->addRow(saveButton);
        formLayout->addRow(cancelButton);

        connect(saveButton, &QPushButton::clicked, [&]() {
        // Получаем данные из формы
        QString name = lineEditName->text();
        QString material = comboBoxMaterial->currentText();
        int weight = lineEditWeight->text().toInt();
        // Проверяем данные
        if (lineEditName->text().isEmpty() || comboBoxMaterial->currentText().isEmpty() || lineEditWeight->text().toInt() == 0)
        {
            QMessageBox::warning(this, "Ошибка", "Заполните все поля");
            return;
        }
        // Добавляем деталь в базу данных
        QSqlQuery query;
        query.prepare("UPDATE '" + trueName + "' SET 'Деталь' = :part, 'Вес' = :weight, 'Материал' = :material WHERE key = :key");
        query.bindValue(":part",name);
        query.bindValue(":weight",weight);
        query.bindValue(":material",material);
        query.bindValue(":key",id);

        if (!query.exec())
        {
            QMessageBox::critical(this, "Ошибка", query.lastError().text());
            return;
        }
        // Обновляем модель
        countParts();
        modelParts->select();
        modelBuilds->select();
        modelAudit->select();
        dialog.close();
        });

        connect(cancelButton, &QPushButton::clicked, [&]() {
            // Закрыть диалоговое окно
            dialog.close();
        });

// Отобразить диалоговое окно
dialog.exec();
}
}

void AnotherWindow::on_tableViewParts_clicked(const QModelIndex &index)
{
}


void AnotherWindow::on_tableViewParts_activated(const QModelIndex &index)
{

}

