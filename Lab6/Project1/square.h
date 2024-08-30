#pragma once
#include"shape.h"
#include "point.h"
#include<iostream>
//квадрат (из трапеции)
class square: public shape{
    point A;
    point B;
    point C;
    point D;
public:
    square(point a,point b,point c,point d,std::string& color1){
        A = a;
        B = b;
        C = c;
        D = d;
        color = color1;
    };
    float calculateSquare() const override{
        return (std::sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y))* std::sqrt((B.x - A.x) * (B.x - A.x) + (B.y - A.y) * (B.y - A.y)));
    }
    std::string getType() const override{
        return "Квадрат";
    }
    void printHeads() const override{
        printf("Вершины: A(%.2f,%.2f),B(%.2f,%.2f),C(%.2f,%.2f),D(%.2f,%.2f)\n",A.x,A.y,B.x,B.y,C.x,C.y,D.x,D.y);
    }
};