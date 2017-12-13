//
//  Binary.hpp
//  BinaryOperations
//
//  Created by Hentai Princess on 22.11.2017.
//  Copyright © 2017 Hentai Princess. All rights reserved.
//

#ifndef Binary_hpp
#define Binary_hpp

#include <stdio.h>
#pragma once
#include <iostream>
#include <string>

using namespace std;
extern unsigned char num[3];
extern unsigned char one[100];
extern unsigned char zero[100];
class Binary {
    
public:
    unsigned char number[100];
    int Size;
    //объявление через массив символов
    Binary(unsigned char num[100] = zero);
    //объявление через строку
    Binary(string s);
    //возвращает длину числа
    int size();
    //инициализация через массив символов
    void Init(unsigned char num[100]);
    //инициализация через строку
    void Init(string s);
    //перевод в десятичное
    int BinaryToDec();
    
    //проверка корректности числа
    bool isCorrect();
    //считывание с клавиатуры
    void Read();
    //перевод в вид строки
    string ToString();
    //показать в консоли, вывести за ним дополнительную строку (если надо)
    void Display(string str="");
    
    
    
    //определяет равно ли
    bool operator == (Binary b);
    //возвращает правду если больше
    bool operator > (Binary b);
    //больше либо равно
    bool operator >= (Binary b);
    //меньше
    bool operator < (Binary b);
    //меньше либо равно
    bool operator <=(Binary b);
    //сумма
    Binary operator + (Binary b);
    //разность
    Binary operator - (Binary b);
    //деление (как для целых)
    Binary operator / (Binary b);
    //умножение
    Binary operator * (Binary b);
    Binary operator ++(int);
    Binary operator --(int);
    
    friend ostream& operator<<(ostream& os, Binary& binary);
};
//остаток от деления, % почему то не читается

Binary Mod(Binary a, Binary b);

#endif /* Binary_hpp */
