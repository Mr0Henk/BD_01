#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMainWindow>
#include <AnotherWindow.h>
#include <QtSql>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    MainWindow(const QString &title);
    ~MainWindow();

private slots:
    void on_buttonExit_clicked();

    void on_buttonEnter_clicked();

    void on_buttonRegist_clicked();

    void on_MainWindow_iconSizeChanged(const QSize &iconSize);

private:
    Ui::MainWindow *ui;
    AnotherWindow *MUSYWindow;
    QSqlDatabase db;
    QSqlRelationalTableModel *model;
};
#endif // MAINWINDOW_H
