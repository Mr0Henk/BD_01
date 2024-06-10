#ifndef MUSY_H
#define MUSY_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>

namespace Ui {
class MUSY;
}

class MUSY : public QMainWindow
{
    Q_OBJECT

public:
    MUSY(QWidget *parent = nullptr);
    ~MUSY();

private slots:
    void on_addBuilds_clicked();

private:
    Ui::MUSY *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

    // НОВОЕ: Переменные для работы с таблицей всех Сборок
    QSqlRelationalTableModel *modelBuilds;
    int currentRowBuilds;

    // НОВОЕ2: Переменные для работы с таблицей деталей
    QSqlRelationalTableModel *modelGOST;
    int currentRowGOST;

    // НОВОЕ3: Переменные для работы с таблицей Редактирования сборки
    QSqlRelationalTableModel *modelParts;
    int currentRowParts;

    // НОВОЕ4: Переменные для работы с таблицей Аудита
    QSqlTableModel *modelAudit;
    int currentRowAudit;
};

#endif // MUSY_H
