#ifndef ADDWORD_H
#define ADDWORD_H

#include <QWidget>
#include<vector>
namespace Ui {
class addWord;
}

class addWord : public QWidget
{
    Q_OBJECT

public:
    explicit addWord(QWidget *parent = nullptr);
    ~addWord();

private:
    Ui::addWord *ui;
//    QString rus;
//    QString eng;
//    QString trc;
public slots:
    void addWordButtonClicked();
signals:
    void SignalAddNewWordToDb(std::vector<QString> vec);
};

#endif // ADDWORD_H
