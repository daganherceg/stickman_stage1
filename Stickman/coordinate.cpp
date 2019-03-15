#include "coordinate.h"

Coordinate::Coordinate(unsigned int x,
                       unsigned int y,
                       unsigned int frameHeight,
                       unsigned int frameWidth):
    m_x(x),
    m_y(y),
    m_frameHeight(frameHeight),
    m_frameWidth(frameWidth)
{

}

void Coordinate::changeInX(double change) {
    m_x += change;
}

void Coordinate::changeInY(double change) {
    m_y += change;
}
