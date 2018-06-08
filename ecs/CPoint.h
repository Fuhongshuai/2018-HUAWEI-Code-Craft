//
// Created by 付洪帅 on 2018/3/18.
//

#ifndef ECS_CPOINT_H
#define ECS_CPOINT_H
class CPoint
{
public:
    double x;
    double y;

    CPoint()
    {
        x = 0.0;
        y = 0.0;
    }
    CPoint(double x, double y)
    {
        this->x = x;
        this->y = y;
    }
    double getX()
    {
        return x;
    }
    double getY()
    {
        return y;
    }
};
#endif //SDK_GCC_CPOINT_H
