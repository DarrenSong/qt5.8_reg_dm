//#include "mainwindow.h"
#include "dialog.h"
#include <QApplication>
//需添加的头文件
#include<QDir>
#include<QProcess>
#include<QAxWidget>  //需在Pro文件中添加QT += axcontainer
void AutoRegCom();
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    // MainWindow w;
     AutoRegCom();
     //创建activex对象指针
     QAxWidget *fla=new QAxWidget();
     //初始化大漠对象
     fla->setControl(QString::fromUtf8("{26037A0E-7CBD-4FFF-9C63-56F2D0770214}"));
     //通过dynamicCall调用大漠里面的函数，格式如下
     fla->dynamicCall("MoveTo(int,int)",200,200);

    // w.show();
      fla->show();//qt串口显示
      fla->dynamicCall("Beep(int,int)",100,5000);
    return a.exec();
}
//自动注册大漠插件
void AutoRegCom()
{
     QString path;
     path=QCoreApplication::applicationDirPath();//获取程序运行路径
     QString cmdStr="Regsvr32 "+path+"/dm.dll /s";
     QProcess p(0);
     p.start("cmd",QStringList()<<"/c"<<cmdStr);
     p.waitForStarted();
     p.waitForFinished();

}
