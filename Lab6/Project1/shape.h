#pragma once
#include<iostream>
class shape{
protected:
    std::string color;
public:
    shape(){};
    virtual float calculateSquare() const {std::cout<<"No points for figure"<<std::endl;
        return 0;};
    virtual std::string getType() const{return "Фигура";};
    virtual void printHeads() const{};
    std::string& getName(){};
    std::string& getColor(){ return color;};
};