#ifndef DIALOG_H
#define DIALOG_H

#include "stickman.h"

#include <QDialog>
#include <QTimer>
#include <QDialog>
#include <QPainter>
#include <QPen>
#include <QBrush>
#include <QPolygon>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

protected:
    void paintEvent(QPaintEvent *event);

private:
    Ui::Dialog *ui;
    StickMan m_man;
    unsigned int m_counter;
};

#endif // DIALOG_H
