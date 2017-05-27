#include "dialog.h"
#include <QApplication>
#include <QLibrary>
#include <QMessageBox>
#include <QAxWidget>
#include <QDebug>


#include <QSettings>
typedef long  (*pcom_open)(); //定义函数指针
int main(int argc, char *argv[])
{

    //Q_OBJECT
    QApplication a(argc, argv);
  //  Dialog w;
    //使用RegDll注册大漠插件
    QLibrary mylib("RegDll.dll");
   // QLibrary mylib("ts.dll");
    if(mylib.load())
    {
        qDebug() << "load ok!";
        pcom_open open=(pcom_open)mylib.resolve("DllRegisterServer");
        if(open)
        {
            open();
            qDebug() << "load hello ok!";
        }
        else
        {
            qDebug() << "load hello fail!";
        }
    }
   //Call Funcation
    QAxWidget *flash = new QAxWidget(0,0);
   // flash->resize(500,80);
    //使用VC++6.0查看class_ID
    //flash->setControl(QString::fromUtf8("{F3F54BC2-D6D1-4A85-B943-16287ECEA64C}"));
    flash->setControl(QString::fromUtf8("{F3E95C10-606A-474E-BB4A-B9CCBF7DB559}"));

    flash->dynamicCall("MoveTo(int,int)",100,100);

   // flash->show();


  //  w.show();

   // return a.exec();
}

