//
// Created by Administrator on 2018/7/6.
//

#ifndef TESTSO2_GEORELATION_H
#define TESTSO2_GEORELATION_H

/* 基本几何结构 */
struct POINT
{
    double x;
    double y;
    POINT(double a=0, double b=0) { x=a; y=b;} //constructor
};
struct LINESEG
{
    POINT s;
    POINT e;
    LINESEG(POINT a, POINT b) { s=a; e=b;}
    LINESEG() { }
};
struct LINE           // 直线的解析方程 a*x+b*y+c=0  为统一表示，约定 a >= 0
{
    double a;
    double b;
    double c;
    LINE(double d1=1, double d2=-1, double d3=0) {a=d1; b=d2; c=d3;}
};

class GeoRelation {
public:
    bool equal_point(POINT p1,POINT p2);
    bool online(LINESEG l,POINT p);
};


#endif //TESTSO2_GEORELATION_H
