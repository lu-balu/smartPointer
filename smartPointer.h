#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include<iostream>


template <typename T>
class SmartPointer {
public:
    
    SmartPointer(const T& data);
    SmartPointer(const SmartPointer<T> &smartPointer) = delete;
    SmartPointer(SmartPointer<T> && smartPointer);

    ~SmartPointer();

    T* get() { return p; }

    SmartPointer<T>& operator =(const SmartPointer<T> &smartPointer) = delete;
    SmartPointer<T>& operator =(SmartPointer<T> && smartPointer);
    T& operator*();

private:
    T* p;
};

template <typename T>
SmartPointer<T>::SmartPointer(const T& data) : p(new T) {
    *p = data;
    std::cout << "Выделена память, записан элемент " << data << std::endl;
};

template <typename T>
SmartPointer<T>::~SmartPointer(){
    if(p != nullptr){
        std::cout << "Освобождена память. Удаляется элемент " << *p << std::endl;
        delete p;
    }
}

template <typename T>
SmartPointer<T>::SmartPointer(SmartPointer<T> && smartPointer): p(smartPointer.p) {
    std::cout << "Выполняется перенос элемента " << *p << std::endl;
    smartPointer.p = nullptr;
}

template <typename T>
SmartPointer<T>& SmartPointer<T>::operator =(SmartPointer<T> && smartPointer){
    if(&smartPointer == this){
        return *this;
    }

    delete p;

    p = smartPointer.p;
    smartPointer.p = nullptr;

    return *this;
}

template <typename T>
T& SmartPointer<T>::operator* (){
    return *p;
}

#endif // SMARTPOINTER_H