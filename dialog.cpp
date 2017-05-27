#include "dialog.h"
#include <QLibrary>

//yypedef long (*pcom_open)(QString); //定义函数指针
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
{
    //RegisterDm();
}

Dialog::~Dialog()
{

}
//void Dialog::RegisterDm()
//{
//    QLibrary mylib("RegDll.dll");
//    if(mylib.load())
//    {

//        pcom_open open=(pcom_open)mylib.resolve(”Reg”);
//        if(open)
//        {
//            open("dm.dll");
//        }

//    }

//}
