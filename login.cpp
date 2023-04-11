#include "login.h"
#include "ui_login.h"

Login::Login(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Login)
{
    ui->setupUi(this);
    this->setWindowTitle("这是一个新标题");
    //下面红字的是把输入的文本显示为“密码模式”，“密码模式”是把输入的文本换成星号
    ui->lepassword->setEchoMode(QLineEdit::Password);
}

Login::~Login()
{
    delete ui;
}
void Login::on_pushButton_clicked()
{
    //通过qDebug()来输出调试的内容
    if(ui->lepassword->text()=="123"&&ui->leusername->text()=="王子硕"){
        //静态方法可以通过双冒号访问，下面弹出窗口之后，直到把下面的通知消息窗口关掉之后，才能让代码继续执行下面的代码
        QMessageBox:: information(this,"通知消息","登录成功,呦西呦西");
        //已经将home提到全局变量里面去了
        home.show();
        //把this从内存中清除
        this->close();

    }else {
        qDebug()<<"用户名或密码错误";
        QMessageBox:: information(this,"通知消息","用户名或密码错误");
    }
}
