#ifndef ADMINROOM_H
#define ADMINROOM_H

#include <QDialog>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>

namespace Ui {
class AdminRoom;
}

class AdminRoom : public QDialog
{
    Q_OBJECT

public:
    explicit AdminRoom(QWidget *parent = nullptr);
    ~AdminRoom();

private slots:
    void on_pushButton_5_clicked();

    void on_pushButton_4_clicked();

    void on_addAdmin_clicked();

    void on_dellAdmin_clicked();

    void on_redAdmin_clicked();

private:
    Ui::AdminRoom *ui;
    QSqlDatabase db;
    QSqlTableModel *model;

    int currentRowAdmin;
};

#endif // ADMINROOM_H
