#include "stickman.h"

StickMan::StickMan(unsigned int sizeOffset,
                   Coordinate coordinate,
                   double velocity):
    m_sizeOffset(sizeOffset),
    m_coordinate(coordinate),
    m_velocity(velocity)
{

}

double StickMan::calculateYCoordinate(double h, double k, double x, int radius)
{
    return k+sqrt(- ( h * h ) + 2 * h * x + radius * radius - x * x);
}

bool StickMan::isCollision()
{
    if (m_coordinate.getY() >= m_coordinate.getHeight()) {
        return true;
    }
    return false;
}

void StickMan::render(QPainter &painter, unsigned int time)
{

    m_velocity += -5.8/100.0;
    m_coordinate.changeInY(m_velocity);
    if (isCollision()) {
        m_coordinate.setY(0);


    } else {
        time = 0;
    }
    painter.setRenderHint(
        QPainter::Antialiasing);

    QPen pen;
    painter.setPen(pen);
    pen.setWidth(400);

    int h = int(m_coordinate.getX());
    int k = int(m_coordinate.getY());

    int sizeOffset = 50;

    QPoint pelvis = QPoint(h, k);

    // Calculate knee coordinates
    double x_leftKnee = h - (sizeOffset/4) + int(time) % sizeOffset;
    double y_leftKnee = calculateYCoordinate(h, k, x_leftKnee, sizeOffset);

    double x_rightKnee = h + (sizeOffset - sizeOffset/4) - int(time) % int(sizeOffset);
    double y_rightKnee = calculateYCoordinate(h, k, x_rightKnee, sizeOffset);

    QPoint leftKnee = QPoint(int(x_leftKnee), int(y_leftKnee));
    QPoint rightKnee = QPoint(int(x_rightKnee), int(y_rightKnee));


    // Calculate foot coordinates
    double x_leftFoot = leftKnee.x() - sizeOffset + int(time) % sizeOffset;
    double y_leftFoot = calculateYCoordinate(leftKnee.x(), leftKnee.y(), x_leftFoot, sizeOffset);

    double x_rightFoot = x_rightKnee + sizeOffset / 4 - int(time) % sizeOffset;
    double y_rightFoot = calculateYCoordinate(x_rightKnee, y_rightKnee, x_rightFoot, sizeOffset);

    QPoint leftFoot = QPoint(int(x_leftFoot), int(y_leftFoot));
    QPoint rightFoot = QPoint(int(x_rightFoot), int(y_rightFoot));

    // Offset to place stickman from feet (not head)
    double heightOffset = fmin(k - y_leftFoot, k - y_rightFoot);

    leftFoot.setY(int(leftFoot.y() + heightOffset));
    rightFoot.setY(int(rightFoot.y() + heightOffset));
    leftKnee.setY(int(leftKnee.y() + heightOffset));
    rightKnee.setY(int(rightKnee.y() + heightOffset));
    pelvis.setY(int(pelvis.y() + heightOffset));

    // Draw legs
    painter.setPen(Qt::black);
    painter.drawLine(pelvis, leftKnee);
    painter.drawLine(leftKnee, leftFoot);

    painter.drawLine(pelvis, rightKnee);
    painter.drawLine(rightKnee, rightFoot);

    QPoint neck = QPoint(pelvis.x() + sizeOffset/10, pelvis.y() - sizeOffset * 2);
    painter.drawLine(pelvis, neck);

    // Draw head
    painter.setBrush(Qt::yellow);
    painter.drawEllipse(neck, sizeOffset/4, sizeOffset/4);


}

