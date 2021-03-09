#ifndef SMARTPOINTER_H
#define SMARTPOINTER_H
#include<iostream>


template <typename T>
class SmartPointer {
public:
    SmartPointer(T data) : p(new T) {
        *p = data;
        std::cout << "Выделена память, записан элемент " << data << std::endl;
    };

    ~SmartPointer(){
        if(p != nullptr){
            std::cout << "Освобождена память. Удаляется элемент " << *p << std::endl;
            delete p;
        }
    }

    SmartPointer(const SmartPointer<T> &smartPointer) = delete;

    SmartPointer(SmartPointer<T> && smartPointer): p(smartPointer.p) {
        std::cout << "Выполняется перенос элемента " << *p << std::endl;
        smartPointer.p = nullptr;
    }

    SmartPointer<T>& operator =(const SmartPointer<T> &smartPointer) = delete;

    SmartPointer<T>& operator =(SmartPointer<T> && smartPointer){
        if(&smartPointer == this){
            return *this;
        }

        delete p;

        p = smartPointer.p;
        smartPointer.p = nullptr;

        return *this;
    }


    T* get() {
        return p;
    }


private:
    T* p;
};

#endif // SMARTPOINTER_H