#include<iostream>
#include"oval.h"//����
#include"square.h"//�������
#include"point.h"

void FigureInfo(shape& figure){
    std::cout<<"���: "<<figure.getType()<<std::endl;
    std::cout<<"����: "<<figure.getColor()<<std::endl;
    //std::cout<<"�������: "<<figure.printHeads()<<std::endl;
    figure.printHeads();
    std::cout<<"�������: "<<figure.calculateSquare()<<std::endl;
    std::cout<<std::endl;
}
int main(){
    system("chcp 1251");

    point a(4,0);//6
    point b(0,6);//8
    point c(4,2);
    point d(8,2);
    point o(0, 0);
    std::string color = "�������������";
    std::string color2 = "����-����-���������";

    
    oval ova(o,a,b,color);
    square squ(a,b,c,d,color2);

    const int numShapes = 2;
    shape* shapes[numShapes] = { &ova,&squ };
    for (int i = 0; i < numShapes; ++i) {
        FigureInfo(*shapes[i]);
    }
    for (int j = 0; j < numShapes; j++) {
        shapes[j] = nullptr;
        delete shapes[j];
    }
    return 0;
}