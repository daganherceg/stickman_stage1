#ifndef COORDINATE_H
#define COORDINATE_H

class Coordinate
{
public:
    Coordinate(unsigned int x,
                   unsigned int y,
                   unsigned int frameHeight,
                   unsigned int frameWidth);

    unsigned int getX(){ return m_x; }
    unsigned int getY(){ return m_frameHeight - m_y; }
    void setX(unsigned int x){ m_x = x; }
    void setY(unsigned int y){ m_y = y; }
    unsigned int getHeight(){ return m_frameHeight; }
    unsigned int getWidth(){ return m_frameWidth; }

    void changeInX(double change);
    void changeInY(double change);

private:
    unsigned int m_x;
    unsigned int m_y;
    unsigned int m_frameHeight;
    unsigned int m_frameWidth;
};

#endif // COORDINATE_H
