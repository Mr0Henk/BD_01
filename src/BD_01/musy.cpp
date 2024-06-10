#include "musy.h"
#include "ui_musy.h"

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

MUSY::MUSY(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MUSY)
{}
MUSY::~MUSY()
{
    delete ui;
}

void MUSY::on_addBuilds_clicked()
{

}

