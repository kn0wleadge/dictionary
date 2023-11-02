#include "wordlist.h"
#include "ui_wordlist.h"

WordList::WordList(QWidget *parent, QSqlTableModel* tableModel) :
    QWidget(parent),
    ui(new Ui::WordList)
{
    ui->setupUi(this);
    ui->tableView->setModel(tableModel);





}

WordList::~WordList()
{
    delete ui;
}
