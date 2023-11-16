#include "sparkdemo.h"

SparkDemo::SparkDemo()
{

}


QString SparkDemo::call(QString value)
{
    QString pythonFilePath = "C:/Qt/SparkApi.py";

    QProcess pythonProcess;
    QStringList arguments;
    QStringList functionArguments;

    functionArguments << "22afa830"
                      << "1d24e137c4ac052f210b6de045202e3c"
                      << "MzE5MWYxNDQ2NTY1MDY3NTZkZTA3NThk"
                      << "wss://spark-api.xf-yun.com/v1.1/chat"
                      << value;

    arguments << pythonFilePath << "main" << functionArguments;

    pythonProcess.start("C:/Qt/python.exe", arguments);
    // 根据您的实际Python可执行文件路径进行修改

    if (pythonProcess.waitForFinished(-1))
    {
        QByteArray output = pythonProcess.readAllStandardOutput();
        QString pythonOutput = QString::fromUtf8(output);

        QByteArray error = pythonProcess.readAllStandardError();

        if (!pythonOutput.isEmpty())
            qDebug() << "Python Output:" << pythonOutput;

        if (!error.isEmpty())
            qDebug() << "Python Error:" << error;

        pythonOutput.replace("None", "");
        return pythonOutput;
    }
    else
    {
        qDebug() << "Failed to execute Python file.";
        return QString();
    }
}
