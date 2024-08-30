#pragma once
#include"shape.h"
#include "point.h"
#include<iostream>

//овал
class oval: public shape {
    point O;
    point A;
    point B;
public:
    oval(){};
    oval(point o,point a,point b,std::string color1){
        O = o;
        A = a;
        B = b;
        color = color1;
    };
    float calculateSquare() const override{
        float yy = abs(std::sqrt((A.x - O.x) * (A.x - O.x) + (A.y - O.y) * (A.y - O.y)));
        float xx = abs(std::sqrt((B.x - O.x) * (B.x - O.x) + (B.y - O.y) * (B.y - O.y)));
        return yy*xx*3.14159265359;
    }
    std::string getType() const override{return "Овал";}
    void printHeads() const override{}
};