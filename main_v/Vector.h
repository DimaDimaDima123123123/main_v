#pragma once
class Vector 
{
    int* arr;
    int size;
public:
    Vector();
    ~Vector();
    Vector(const Vector& obj);

    Vector(int s);
    void InputRand();   // инициализация случайными числами
    void Print();   // вывод на консоль

    void PushBack(int a);
    int PopBack();

    Vector operator-(int a);

    Vector& operator++();   // префиксный инкремент
    Vector operator++(int); // постфиксный инкремент
    Vector& operator--();   // префиксный декремент
    Vector operator--(int); // постфиксный декремент

    Vector& operator+=(int n);  // добавление n элементов
    Vector& operator-=(int n);  // уменьшение размера на n элементов
    Vector& operator*=(int n);  // умножение всех элементов на n
};
