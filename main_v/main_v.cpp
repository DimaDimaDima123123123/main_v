#include <iostream>
#include "Vector.h"
using namespace std;

int main() 
{
    srand(time(0));

    Vector obj1(5); // инициализация вектора
    obj1.InputRand();
    obj1.Print();

    Vector obj3 = obj1 - 2; // уменьшение размера на 2
    obj3.Print();
    obj1.Print();

    // тестирование инкремента
    Vector obj4 = ++obj1;  // префиксный инкремент
    obj4.Print();
    obj1.Print();

    Vector obj5 = obj1++;  // постфиксный инкремент
    obj5.Print();
    obj1.Print();

    // тестирование декремента
    obj1--;
    obj1.Print();
    --obj1;
    obj1.Print();

    // тестирование операторов +=, -=, *=
    Vector obj6(3); // инициализация вектора размером 3
    obj6.InputRand();
    obj6.Print();

    obj6 += 5;  // добавление 5 элементов
    obj6.Print();
    obj6 -= 5;  // удаление 5 элементов
    obj6.Print();
    obj6 *= 5;  // умножение всех элементы на 5
    obj6.Print();

    return 0;
}
