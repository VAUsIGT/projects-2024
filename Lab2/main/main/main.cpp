#include <math.h>
#include <string>
#include <iostream>

namespace ua {

    class Rect {//единичный прямогольник
    private:
        int a, b;
    public:
        Rect() {
            this->a = 1;
            this->b = 1;
        }

        Rect(int a, int b) : Rect() {//проверка правильности данных и вызов единичного заранее
            if (a <= 0 || b <= 0) {
                std::cout << "Invalid rectangle sides: " + std::to_string(a) + ", " + std::to_string(b) << std::endl;
            }
            else {
                this->a = a;
                this->b = b;
            }

        }

        Rect(const Rect& t) { //копирование, получает ссылку на объект (const на всякий)
            this->a = t.a;
            this->b = t.b;
        }

        Rect(int a) : Rect(a, a) {}

        int getMaxSide() {
            return std::max(a,b);
        }

        int RectPeri() {
            return a*2+b*2;
        }

        std::string getInfo() {
            return "Rectangle: a = " + std::to_string(a) + ", b = " + std::to_string(b) + ", periemeter = " + std::to_string(RectPeri())
                +", max side = " + std::to_string(getMaxSide());
        }

        ~Rect() {
            std::cout << "Class deleted" << std::endl;
        }
    };
}

int main() {
    ua::Rect t(3, 4);
    ua::Rect t2(t);
    ua::Rect t3(-2, 3);
    std::cout << t.getInfo() << std::endl;
    std::cout << t2.getInfo() << std::endl;
    std::cout << t3.getInfo() << std::endl;
    return 0;
}