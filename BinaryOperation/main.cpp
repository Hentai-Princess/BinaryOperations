//
//  main.cpp
//  Laba2
//
//  Created by Hentai Princess on 22.11.2017.
//  Copyright © 2017 Hentai Princess. All rights reserved.
//

#include "Binary.hpp"
#include <iostream>
#include <string>


/*Задание: реализовать операции с целыми неотрицательными двоичными числами, представить их в виде массива
 из 100 беззнаковых символов*/
using namespace std;

//меню
int Menu() {
    cout << "---------------------------------------" << endl;
    cout << "                 МЕНЮ                  " << endl;
    cout << "---------------------------------------" << endl;
    cout << "1 - Сложить" << endl;
    cout << "2 - Вычесть" << endl;
    cout << "3 - Разделить" << endl;
    cout << "4 - Умножить" << endl;
    cout << "5 - Вычислить остаток от деления" << endl;
    cout << "---------------------------------------" << endl;
    int n;
    cin >> n ;
    return n;
}


int main() {
    setlocale(LC_ALL, "Russian");
    cout << "Введите два двоичных числа:" << endl;
    Binary a, b;
    a.Read();
    if (!a.isCorrect()) {
        cout << "Введенное значение неверно. Повторите ввод." << endl;
        getchar();
        getchar();
        return 0;
    }
    b.Read();
    if (!b.isCorrect()) {
        cout << "Введенное значение неверно. Повторите ввод."<<endl;
        getchar();
        getchar();
        return 0;
    }
    Binary res;
    int n = Menu();
    switch (n)
    {
        case 1:res = a + b;  break;
        case 2: res = a - b;  break;
        case 3: res = a / b;  break;
        case 4: res = a * b;  break;
        case 5: res = Mod(a, b);  break;
        default: cout << "Введенное значение неверно. Повторите ввод." << endl;
            getchar();
            getchar();
            return 0;
    }
    res.Display();
    getchar();
    getchar();
    
    return 0;
}
