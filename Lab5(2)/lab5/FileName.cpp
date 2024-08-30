#define _USE_MATH_DEFINES
#include <iostream>
#include <cmath>

class R_Complex
{//свой тип данных
public:
    float r_ = 0;
    float y_ = 0;
    R_Complex() {}//по умолчанию

    R_Complex(float r, float y)//полного заполнения
    {
        if (r < 0)
        {//радиус отрицателен
            //std::cout << "radius <0" << std::endl;
            r = abs(r);
        }
        r_ = r;
        y_ = y;
    }
    R_Complex(R_Complex& number)//	Конструктор копирования
    {
        r_ = number.r_;
        y_ = number.y_;
    }
    ~R_Complex() // деструктор 
    {
        // std::cout<<"destruktor"<<std::endl;
    }


    void print()
    {
        std::cout << r_ << " " << y_ << " " << r_ * (cos(y_ * M_PI / 180) + sin(y_ * M_PI / 180)) << std::endl;
    }

    //----------
    R_Complex operator +=(int num)
    {
        float nm1 = r_ * cos(y_ * M_PI / 180) + num;
        float nm2 = r_ * sin(y_ * M_PI / 180);
        r_ = pow(pow(nm1, 2) + pow(nm2, 2), 0.5);
        return *this;
    }
    R_Complex operator +=(const R_Complex& num) //складываем два числа в полярной форме
    {
        //избавляемся от лишних кругов
        float angle1 = y_ - ((int)(y_ / 360) * 360);
        float angle2 = num.y_ - ((int)(num.y_ / 360) * 360);
        //точки концов векторов A(x1,y1) у вектора this
        //                      B(x2,y2) у вектора num
        float x1, x2, y1, y2;

        //находим координаты точки А
        x1 = r_ * cos(y_ * M_PI / 180);
        y1 = r_ * sin(y_ * M_PI / 180);
        //находим координаты точки В
        x2 = num.r_ * cos(num.y_ * M_PI / 180);
        y2 = num.r_ * sin(num.y_ * M_PI / 180);
        //находим координаты точки C=A+B
        float x3 = x1 + x2;
        float y3 = y1 + y2;
        //находим длину вектора OC, где О(0,0)
        r_ = pow(pow(x3, 2) + pow(y3, 2), 0.5);
        //находим угол вектора ОС
        y_ = atan(sin(y3 / r_) / cos(x3 / r_));
        //перевод из радиан
        y_ = y_ / M_PI * 180;
        //перевод из отриц знач в полож
        if (y_ < 0) {
            y_ = 360 + y_;
        }
        return *this;
    }
    R_Complex operator + (int num)
    {
        float nm1 = r_ * cos(y_ * M_PI / 180) + num;
        float nm2 = r_ * sin(y_ * M_PI / 180);
        r_ = pow(pow(nm1, 2) + pow(nm2, 2), 0.5);
        return *this;
    }
    R_Complex operator +(const R_Complex& num)
    {
        R_Complex* new_number = new R_Complex;

        float angle1 = y_ - ((int)(y_ / 360) * 360);
        std::cout << "ugol = " << angle1 << std::endl;
        float angle2 = num.y_ - ((int)(num.y_ / 360) * 360);
        float x1, x2, y1, y2;


        x1 = r_ * cos(y_ * M_PI / 180);
        y1 = r_ * sin(y_ * M_PI / 180);

        x2 = num.r_ * cos(num.y_ * M_PI / 180);
        y2 = num.r_ * sin(num.y_ * M_PI / 180);

        //std::cout<<(int)angle1/90+1<<"\n"<<x1<<" "<<y1<<"\t\t"<<x2<<" "<<y2<<std::endl;
        float x3 = x1 + x2;
        float y3 = y1 + y2;
        new_number->r_ = pow(pow(x3, 2) + pow(y3, 2), 0.5);

        //std::cout<<x3<<" "<<y3<<std::endl;
        //std::cout<<(sin(y3/new_number->r_)/cos(x3/new_number->r_))<<std::endl;
        new_number->y_ = atan(sin(y3 / new_number->r_) / cos(x3 / new_number->r_));
        new_number->y_ = new_number->y_ / M_PI * 180;
        if (new_number->y_ < 0)
        {
            new_number->y_ = 360 + new_number->y_;
        }
        return *new_number;
    }
    //----------

    R_Complex operator *= (int num)
    {
        r_ *= abs(num);
        return *this;
    }
    R_Complex operator *=(R_Complex& number)
    {
        r_ *= abs(number.r_);
        y_ += number.y_;
        return *this;
    }
    R_Complex operator * (int num)
    {
        r_ *= abs(num);
        return *this;
    }
    R_Complex operator *(R_Complex& number)
    {
        r_ *= abs(number.r_);
        y_ += number.y_;
        return *this;
    }
    R_Complex& operator++ ()
    {
        r_ = r_++;
        return *this;
    }
    R_Complex operator++ (int)
    {
        ++(*this);
        return *this;
    }
    R_Complex operator = (const R_Complex& number)
    {
        r_ = number.r_;
        y_ = number.y_;
        return *this;
    }
    friend std::ostream& operator << (std::ostream& stream, const R_Complex& number)
    {
        stream << "Radius: " << number.r_ << "\tAngle: " << number.y_;
        stream << "\tNumber: " << (number.r_ * cos(number.y_ * M_PI / 180)) << " + (" << number.r_ * sin(number.y_ * M_PI / 180) << ")i";
        return stream;
    }
    friend std::istream& operator >> (std::istream& stream, R_Complex& number)
    {
        stream >> number.r_ >> number.y_;
        return stream;
    }
};
//--------------------------------
R_Complex max_number(R_Complex num1, R_Complex num2);
int quadrant(R_Complex num);
float multiply(R_Complex num1, R_Complex num2);

//--------------------------------
//макс число
R_Complex max_number(R_Complex num1, R_Complex num2)
{
    if (num1.r_ >= num2.r_)
    {
        return num1;
    }
    else if (num1.r_ < num2.r_)
    {
        return num2;
    }
}
//квадрант
int quadrant(R_Complex num)
{
    if (num.r_ == 0)
    {
        return 1;
    }
    int angle = num.y_ - ((int)(num.y_ / 360) * 360);
    return angle / 90 + 1;
}
//скалярное произведение
float multiply(R_Complex num1, R_Complex num2)
{
    float new_angle = (num1.y_ - num2.y_);
    std::cout << new_angle << std::endl;
    return(num1.r_ * num2.r_ * cos(new_angle * M_PI / 180));
}
int main()
{
    R_Complex;
    R_Complex a(sqrt(2), 45);
    R_Complex b(2, 180);
    std::cout << "max_number = " << max_number(a, b) << std::endl;
    std::cout << "quadrant = " << quadrant(a) << std::endl;
    std::cout << "sum= " << a + b << std::endl;// сумм 
    R_Complex c;
    std::cout << "C= " << (c = a + b);
    std::cout << "\nC= " << c << std::endl;
    std::cout << "multiply(b, a) = " << multiply(b, a) << std::endl;
    std::cout << "multiply(a, b) = " << multiply(a, b) << std::endl;
    std::cout << " += "; a += b;
    std::cout << a << std::endl;
    return 0;
}