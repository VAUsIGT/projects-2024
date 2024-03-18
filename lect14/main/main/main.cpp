#include <iostream>
#include <math.h>

//главное отличие struct от class - у стр можно получить доступ к переменным изначально
struct Point {
    //Переменные, в составе структуры - поля
    int x;
    int y;
};

struct Circle{
private:
    //поля
    float r;//радиус
    Point p;//центр
public:
    //функции в структуре - методы
    Circle(float r, Point p) { //этот метод - коструктор, т.к. ничего не возвращает и имеет имя структуры
        std::cout << "Constr" << std::endl;
        this->r = r;//указатель. но можно было подписать их изначально как m_r и m_p (member)
        p = p;
    }

    ~Circle() {//см.ниже
        std::cout << "Destr" << std::endl;
    }

    void SetR(float r) { //устанавливает поля класса = сеттер
        if (r < 0) {
            std::cout << "Negative" << std::endl;
            return;
        }
        this->r = r;
    }
    
    float getR() {// получает поля класса = геттер
        return this->r;
    }

    float Square() {//считает площадь
        return acos(-1) * this->r * this->r;
    }
};

void Dist(Point p1, Point p2) {
    float coop1 = sqrt(p1.x ^ 2 + p1.y ^ 2);
    float coop2 = sqrt(p2.x ^ 2 + p2.y ^ 2);
    float dp = abs(coop1 - coop2);
    std::cout << dp << std::endl;
}

void f(Circle c) {
    std::cout << c.Square() << std::endl;
}

int main()
{
    Point p1 = { 2,3 };//объект точка
    p1.x;
    p1.y;

    Point p2 = { 4,5 };
    p2.x;
    p2.y;

    //circle - класс, c - объект/экземпляр
    Circle c(1,p1); // создан в стеке, но т.к. это сложная переменная, то нужен спец метод ~Circle для удаления
    c.SetR(-10);

    std::cout << c.getR() << std::endl;
    std::cout << c.Square() << std::endl;

    return 0;
}
