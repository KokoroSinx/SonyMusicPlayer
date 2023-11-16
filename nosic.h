#ifndef NOSIC_H
#define NOSIC_H

#include <QWidget>
#include<QMap>
#include<QVector>
#include <algorithm>
#include <QTextCodec>
class LyricLine
{
public:
    qint64 time;
    QString text;
    LyricLine(qint64 time, QString text):time(time), text(text){}
};

bool operator <(const LyricLine& A, const LyricLine& B);

namespace Ui {
class nosic;
}

class nosic : public QWidget
{
    Q_OBJECT

public:
    explicit nosic(QWidget *parent = nullptr);
    ~nosic();
    int flag;
    int getflag(){
        return flag;
    }

    QVector<LyricLine> lines;
    void setjpg(int row);

    //将歌词文件的内容处理为歌词结构的QList
    bool process(QString filePath);
    //根据时间找到对应位置的歌词
    int getIndex(qint64 position);
    //显示当前播放进度的歌词
    void showcontent(qint64 position);
    //根据下标获得歌词内容
    QString getLyricText(int index);
    //清空歌词Label
    void clear();

private slots:
    void on_toolButton_clicked();

    void on_pushButton_clicked();

    void on_radioButton_clicked(bool checked);

    void on_radioButton_2_clicked(bool checked);

private:
    Ui::nosic *ui;
};

#endif // NOSIC_H
