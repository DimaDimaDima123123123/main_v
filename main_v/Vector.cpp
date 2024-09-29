#include "Vector.h"
#include <iostream>
#include <Windows.h>
using namespace std;

Vector::Vector() 
{
    arr = nullptr;
    size = 0;
}

Vector::Vector(int s) 
{
    size = s;
    arr = new int[size] {0};
}

Vector::~Vector()
{
    cout << "Destructor \n";
    delete[] arr;
    size = 0;
}

Vector::Vector(const Vector& obj)
{
    cout << "Copy constructor \n";
    this->size = obj.size;
    this->arr = new int[size];
    for (int i = 0; i < size; i++) 
    {
        this->arr[i] = obj.arr[i];
    }
}

void Vector::InputRand()
{
    for (int i = 0; i < size; i++) 
    {
        arr[i] = rand() % 41 - 20; // [-20, +20]
    }
}

void Vector::Print() 
{
    for (int i = 0; i < size; i++) 
    {
        cout << arr[i] << "\t";
    }
    cout << "\n---------------------------------------------------\n";
}

void Vector::PushBack(int a) 
{
    int* temp = new int[size + 1];

    for (int i = 0; i < size; i++) 
    {
        temp[i] = arr[i];
    }
    temp[size] = a;

    delete[] arr;
    arr = temp;
    size++;
}

int Vector::PopBack() 
{
    if (size == 0) return -1;
    int* temp = new int[size - 1];
    for (int i = 0; i < size - 1; i++)
    {
        temp[i] = arr[i];
    }
    int el = arr[size - 1];
    delete[] arr;
    arr = temp;
    size--;

    return el;
}

// перегруженные операторы
Vector Vector::operator-(int a) 
{
    Vector rez(size - a); // создание нового объекта
    for (int i = 0; i < rez.size; i++) 
    {
        rez.arr[i] = this->arr[i];
    }
    return rez;
}

// префиксный инкремент
Vector& Vector::operator++()
{
    PushBack(0);  // добавление нуля в конец
    return *this;
}

// постфиксный инкремент
Vector Vector::operator++(int) 
{
    Vector temp = *this;
    PushBack(0);  // доавбление нуля в конец
    return temp;
}

// префиксный декремент
Vector& Vector::operator--() 
{
    if (size > 0) 
    {
        PopBack();  // удаляем последний элемент
    }
    return *this;
}

// постфиксный декремент
Vector Vector::operator--(int) 
{
    Vector temp = *this;
    if (size > 0) {
        PopBack();  // удаление последнего элемента
    }
    return temp;
}

// оператор += для добавления n элементов
Vector& Vector::operator+=(int n) 
{
    for (int i = 0; i < n; ++i) 
    {
        PushBack(0);  // добавление n элементов, инициализированных нулями
    }
    return *this;
}

// оператор -= для удаления n элементов
Vector& Vector::operator-=(int n) 
{
    if (size >= n) {
        for (int i = 0; i < n; ++i) 
        {
            PopBack();  // удаление n элементов
        }
    }
    return *this;
}

// оператор *= для умножения всех элементов на n
Vector& Vector::operator*=(int n) 
{
    for (int i = 0; i < size; ++i) 
    {
        arr[i] *= n;  // умножение каждого элемента
    }
    return *this;
}
