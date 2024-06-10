#ifndef ANOTHERWINDOW_H
#define ANOTHERWINDOW_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>

namespace Ui {
class AnotherWindow;
}

class AnotherWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit AnotherWindow(QWidget *parent = nullptr);
    ~AnotherWindow();


    QString NameBuilds;
    QString idBuilds;
    QModelIndexList selectedRowsParts;
    int GlobalRoll = 0;
    QString trueName;
    int GOST = 0;

private slots:
    void ConnectDataBase();

    void on_addBuilds_clicked();

    void on_fullExit_2_clicked();

    void on_pushButton_clicked();

    void on_upBuilds_clicked();

    void on_upPart_clicked();

    void on_upParts_clicked();

    void on_upAudit_clicked();

    void on_delBuilds_clicked();

    void on_redBuilds_clicked();

    void on_AdminButton_clicked();

    void on_fullGuild_2_clicked();

    void on_fullInfo_2_clicked();

    void on_delAudit_clicked();

    void on_tableViewAudit_clicked(const QModelIndex &index);

    void on_tableViewGOST_clicked(const QModelIndex &index);

    void on_addPart_clicked();

    void on_delPart_clicked();

    void on_redPArt_clicked();

    void on_tableViewBuilds_clicked(const QModelIndex &index);

    void on_addPartLocal_clicked();

    void on_tableViewBuilds_doubleClicked(const QModelIndex &index);

    void on_delParts_clicked();

    void on_addPartGOST_clicked();

    void on_redParts_clicked();

    void countParts();//считате число деталей в сборке

    void RollButton();

    void on_tableViewParts_clicked(const QModelIndex &index);

    void on_tableViewParts_activated(const QModelIndex &index);

private:
    Ui::AnotherWindow *ui;
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

#endif // ANOTHERWINDOW_H
