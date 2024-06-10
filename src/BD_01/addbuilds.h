#ifndef ADDBUILDS_H
#define ADDBUILDS_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>

namespace Ui {
class AddBuilds;
}

class AddBuilds : public QDialog
{
    Q_OBJECT

public:
    explicit AddBuilds(QWidget *parent = nullptr);
    ~AddBuilds();

private slots:
    void on_okButton_clicked();

    void on_canButton_clicked();

private:
    Ui::AddBuilds *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

    // НОВОЕ: Переменные для работы с таблицей всех Сборок
    QSqlRelationalTableModel *modelBuilds;
    int currentRowBuilds;

    // НОВОЕ4: Переменные для работы с таблицей Аудита
    QSqlTableModel *modelAudit;
    int currentRowAudit;
};

#endif // ADDBUILDS_H
