#include "smartPointer.h"
#include <iostream>
#include <vector>
#include <memory>

void test(){
    // Создание вектора указателей
    std::vector<int*> vector;
    for(int i = 0; i < 20; i++){
        int* p = new int;
        *p = i;
        vector.push_back(p);
    }

    // Вывод всех элементов вектора
    for(int i = 0; i < vector.size(); i++){
        std::cout << *vector[i] << " ";
    }
    std::cout << std::endl;

    // !!! утечка памяти !!!
    // vector.erase(vector.begin()+4);

    // Правильное удаление элемента
    delete vector[2];
    vector.erase(vector.begin()+2);

    // Вывод всех элементов вектора
    for(int i = 0; i < vector.size(); i++){
        std::cout << *vector[i] << " ";
    }
    std::cout << std::endl;
}

void test2(){
    // Создание и заполнение вектора умных указателей
    std::vector<SmartPointer<int>> vector;
    for(int i = 0; i < 5; ++i){
        SmartPointer<int> p(i);
        vector.push_back(std::move(p));
    }

    // Вывод всех элементов вектора
    for(int i = 0; i < vector.size(); i++){
        std::cout << *(vector[i].get()) << " ";
    }
    std::cout << std::endl;

    // Удаление элементов происходит без предварительной очистки памяти, так как у нас вектор
    // умных указателей, и память очистится сама при удалении умного указателя, так как это 
    // указано в деструкторе умного указателя
    vector.erase(vector.begin()+2);

    // Вывод всех элементов вектора
    for(int i = 0; i < vector.size(); i++){
        std::cout << *(vector[i].get()) << " ";
    }
    std::cout << std::endl;
}

int main(){
    test();
    test2();

    return 0;
}

