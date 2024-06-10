#include "addbuilds.h"
#include "ui_addbuilds.h"

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


AddBuilds::AddBuilds(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddBuilds)
{
    ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("./../../bd/MUCY.db");
    if (db.open())
    {
        model = new QSqlRelationalTableModel(this, db);
        modelBuilds = new QSqlRelationalTableModel(this, db);
    }
}

AddBuilds::~AddBuilds()
{
    delete ui;
    db.close();
}

void AddBuilds::on_okButton_clicked()
{
    QString name = ui->lineName->text();
    QString author;
    QSqlQuery Query;
    if (name.isEmpty() or !Query.prepare("select count(*) from builds where Название = :name")) {
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


    QSqlQuery helloUser;
    helloUser.exec("SELECT Фамилия, Имя FROM users where Состояние = 'в сети'");
    while (helloUser.next()) {
        author = helloUser.value(0).toString()+" " +helloUser.value(1).toString();
        modelBuilds->select();
    }

    QSqlQuery insertQuery;
    insertQuery.prepare("INSERT INTO builds('Название','Автор сборки') VALUES (:name, :author)");
    insertQuery.bindValue(":name", name);
    insertQuery.bindValue(":author", author);


    if (insertQuery.exec()) {
        QMessageBox::information(this, "Успех", "Сборка добавлена в базу данных");
        QSqlQuery newDataBase;
        name = ui->lineName->text();
        newDataBase.exec("CREATE TABLE IF NOT EXISTS '"+name+"' ('Деталь'	TEXT  NOT NULL, 'Вес'	INTEGER  DEFAULT 0, 'Материал'	TEXT NOT NULL, 'изСборки' TEXT NOT NULL, 'key' INTEGER, "
                         +" FOREIGN KEY('изСборки') REFERENCES 'builds'('IDbuild') PRIMARY KEY('key' AUTOINCREMENT))");
        modelBuilds->select(); // Обновляем модель данных
        this->close();
    } else {
        QMessageBox::critical(this, "Ошибка", "Не удалось добавить сборку:\n" + insertQuery.lastError().text());
    }
    modelBuilds->select();
    db.close();
    QDialog::exec();
}


void AddBuilds::on_canButton_clicked()
{
    modelBuilds->select();
    this->close();
}

