#pragma once
#include <iostream>
using namespace std;

template <typename T>
struct TemplatedClass
{
    T data;

    TemplatedClass();
    TemplatedClass(T data);
    void Print();
    T GetData();
};

template <typename T>
TemplatedClass<T>::TemplatedClass(T data)
{
    this->data = data;
}

template <typename T>
void TemplatedClass<T>::Print()
{
    cout << data << endl;
}

template <typename T>
T TemplatedClass<T>::GetData()
{
    return data;
}
