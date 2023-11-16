#include "nosic.h"
#include "ui_nosic.h"
#include<QFile>
nosic::nosic(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::nosic)
{
    ui->setupUi(this);
    this->setWindowFlag(Qt::FramelessWindowHint);


}

nosic::~nosic()
{
    delete ui;
}

void nosic::setjpg(int row){
    switch(row){
    case 0:{ ui->jpg_label->setPixmap(QPixmap(":/new/prefix2/music/Jpg/00.png"));break;}
    case 1:{ ui->jpg_label->setPixmap(QPixmap(":/new/prefix2/music/Jpg/10.png"));process(":/new/prefix2/music/lrcs/Call of Silence.lrc");break;}
    case 2:{ ui->jpg_label->setPixmap(QPixmap(":/new/prefix2/music/Jpg/20.png"));process(":/new/prefix2/music/lrcs/Operation Ashring.lrc");break;}
    case 3:{ ui->jpg_label->setPixmap(QPixmap(":/new/prefix2/music/Jpg/30.png"));process(":/new/prefix2/music/lrcs/Operation Deepness.lrc");break;}
    case 4:{ ui->jpg_label->setPixmap(QPixmap(":/new/prefix2/music/Jpg/40.png"));process(":/new/prefix2/music/lrcs/Renegade.lrc");break;}
    case 5:{ ui->jpg_label->setPixmap(QPixmap(":/new/prefix2/music/Jpg/50.png"));process(":/new/prefix2/music/lrcs/Running In The Dark.lrc");break;}
    default:{ui->jpg_label->setPixmap(QPixmap(":/new/prefix2/music/Jpg/00.png"));break;}
    }

}
bool operator <(const LyricLine& A, const LyricLine& B)
{
    return A.time<B.time;
}

void nosic::clear()
{
    ui->label_1->setText("");
    ui->label_2->setText("");
    ui->label_3->setText("");
    ui->label_4->setText("");
    ui->label_5->setText("");
    ui->label_6->setText("");
}
QString nosic::getLyricText(int index)//根据下标获得歌词内容
{
    if(index<0 || index>=lines.size()){
        return "";
    }else{
        //qDebug()<<"输出歌词："<<lines[index].text;
        return lines[index].text;
    }
}
void nosic::showcontent(qint64 position)//显示当前播放进度的歌词
{
    int index=getIndex(position);
    if(index==-1){
        ui->label_1->setText("");
        ui->label_2->setText("");
        ui->label_3->setText(u8"当前歌曲无歌词");
        ui->label_4->setText("");
        ui->label_5->setText("");
        ui->label_6->setText("");
    }else{
        ui->label_1->setText(getLyricText(index-2));
        ui->label_2->setText(getLyricText(index-1));
        ui->label_3->setText(getLyricText(index));
        ui->label_4->setText(getLyricText(index+1));
        ui->label_5->setText(getLyricText(index+2));
        ui->label_6->setText(getLyricText(index+3));
    }
}
int nosic::getIndex(qint64 position)//获取歌词位置
{
    if(!lines.size()){
        return -1;//如果没歌词
    }
    else{
        if(lines[0].time>=position){
            return 0;
        }
    }
    int i=1;
    for(i=1;i<lines.size();i++){
        if(lines[i-1].time<position && lines[i].time>=position){
            return i-1;
        }
    }
    return lines.size()-1;
}
bool nosic::process(QString filePath)
{
    QFile lyricFile(filePath);
    lyricFile.open(QFile::ReadOnly);
    //QString content(QString::fromLocal8Bit(lyricFile.readAll()));
    QString content(lyricFile.readAll());
    lyricFile.close();

    //先清空歌词
    lines.clear();

    const QRegExp rx("\\[(\\d+):(\\d+(\\.\\d+)?)\\]"); //用来查找时间标签的正则表达式

    // 步骤1
    int pos = rx.indexIn(content);//返回第一个匹配项的位置，如果没有匹配项则返回-1。
    if (pos == -1) {
        return false;
    }
    else {
        int lastPos;//
        QList<int> timeLabels;//时间标签
        do {
            // 步骤2
            timeLabels << (rx.cap(1).toInt() * 60 + rx.cap(2).toDouble()) * 1000;
            lastPos = pos + rx.matchedLength();//返回最后一个匹配字符串的长度，如果没有匹配则返回-1
            pos = rx.indexIn(content, lastPos);
            if (pos == -1) {
                QString text = content.mid(lastPos).trimmed();
                foreach (const int& time, timeLabels)
                    lines.push_back(LyricLine(time, text));
                break;
            }
            // 步骤3
            QString text = content.mid(lastPos, pos - lastPos);
            if (!text.isEmpty()) {
                foreach (const int& time, timeLabels)
                    lines.push_back(LyricLine(time, text.trimmed()));
                timeLabels.clear();
            }
        }
        while (true);
        // 步骤4
        //stable_sort(lines.begin(), lines.end());//排序
    }
    if (lines.size()) {
        return true;
    }
    return false;
}
