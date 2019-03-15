#ifndef STICKMAN_H
#define STICKMAN_H

#include "coordinate.h"

#include <iostream>
#include <cmath>
#include <QPainter>
#include <QTime>
#include <QPoint>
#include <QPen>

class StickMan
{
public:
    StickMan(unsigned int sizeOffset,
             Coordinate m_coordinate,
             double velocity);

    ~StickMan(){}

    double calculateYCoordinate(double k, double h, double x, int radius);
    void render(QPainter &painter, unsigned int time);
    QPoint getBase(){ return m_base; }
    bool isCollision();

    private:
        unsigned int m_sizeOffset;
        Coordinate m_coordinate;
        double m_velocity;
        QPoint m_base;
};


#endif // STICKMAN_H
