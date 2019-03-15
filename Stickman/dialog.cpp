#include "dialog.h"
#include "ui_dialog.h"

unsigned int HEIGHT = 600;
unsigned int WIDTH = 1000;

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    m_man(StickMan(1,Coordinate(WIDTH/2, HEIGHT/3, HEIGHT, WIDTH),1)),
    m_counter(0)
{
    ui->setupUi(this);
    this->resize(int(WIDTH),int(HEIGHT));
}

void Dialog::paintEvent(QPaintEvent *event)
{
    this->setStyleSheet("background-color: #82CAFF;");
    QPainter painter(this);
    m_man.render(painter, m_counter);
    m_counter++;
}

Dialog::~Dialog()
{
    delete ui;
}
