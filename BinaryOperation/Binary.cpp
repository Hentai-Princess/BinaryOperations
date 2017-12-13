//
//  Binary.cpp
//  BinaryOperations
//
//  Created by Hentai Princess on 22.11.2017.
//  Copyright © 2017 Hentai Princess. All rights reserved.
//

#include "Binary.hpp"


unsigned char num[3] = "01";
unsigned char one[100] = { '1', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };
unsigned char zero[100] = { '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0',
    '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '\0' };


Binary::Binary(unsigned char num[100]) {
    Init(num);
}
//объявление через строку
Binary::Binary(string s) {
    Init(s);
}
//возвращает длину числа
int Binary::size() {
    int j = 98;
    for (; j > 0 && number[j] == '0'; j--);
    return j + 1;
}
//инициализация через массив символов
void Binary::Init(unsigned char num[100]) {
    for (int i = 0; i<100; i++)
        number[i] = num[i];
    Size = size();
    
}
//инициализация через строку
void Binary::Init(string s) {
    int i = 0;
    int j = 0;
    int len = s.length();
    for (; j < len && s[j] == ' '; j++);
    i = j;
    j = len - 1;
    for (; j >= 0 && s[j] == ' '; j--);
    
    for (; i <= j; i++) {
        number[i] = s[len - i - 1];
    }
    for (int j = i; j < 100; j++) {
        number[j] = '0';
    }
    Size = size();
    
}
//перевод в десятичное
int Binary::BinaryToDec() {
    int res = 0;
    for (int i = 0; i < Size; i++) {
        res = res * 2 + number[i];
    }
    return res;
}


//проверка корректности числа
bool Binary::isCorrect() {
    bool res = true;
    
    for (int i = 0; i < Size && res; i++) {
        res = (number[i] == '0' || number[i] == '1');
    }
    return res;
}
//считывание с клавиатуры
void Binary::Read() {
    string s;
    cin >> s;
    Init(s);
}
//перевод в вид строки
string Binary::ToString() {
    string s = "";
    
    for (int i = 0; i < Size; i++) {
        s += number[Size - i - 1];
    }
    return s;
}
//показать в консоли, вывести за ним дополнительную строку (если надо)
void Binary::Display(string str) {
    
    cout << ToString() << str;
}

//определяет равно ли
bool Binary::operator == (Binary b) {
    if (Size != b.Size) return false;
    int i = 0;
    for (; i < Size && number[i] == b.number[i]; i++);
    return (i == Size);
    
}
//возвращает правду если больше
bool Binary::operator > (Binary b) {
    if (Size > b.Size)
        return true;
    if (Size < b.Size)
        return false;
    int i = Size - 1;
    while (i >= 0 && number[i] == b.number[i]) {
        i--;
    }
    if (i < 0) return false;
    if (number[i] > b.number[i])
        return true;
    return false;
}
//больше либо равно
bool Binary::operator >= (Binary b) {
    if (Size > b.Size)
        return true;
    if (Size < b.Size)
        return false;
    int i = Size - 1;
    while (i >= 0 && number[i] == b.number[i]) {
        i--;
    }
    if (i < 0) return true;
    if (number[i] > b.number[i])
        return true;
    return false;
}
//меньше
bool Binary::operator < (Binary b) {
    return (b > *this);
}
//меньше либо равно
bool Binary::operator <=(Binary b) {
    return (b >= *this);
}
//сумма
Binary Binary::operator + (Binary b) {
    
    Binary res;
    Binary minn;
    Binary maxx;
    if (Size > b.Size) {
        minn.Init(b.number);
        maxx.Init(number);
    }
    else {
        minn.Init(number);
        maxx.Init(b.number);
    }
    
    int x = 0;
    int i = 0;
    int j = 0;
    for (; i < minn.Size; i++, j++) {
        int t = number[i] + b.number[i] + x;
        res.number[j] = num[t % 2];
        x = t / 2;
    }
    for (; i <= maxx.Size && i<99; i++, j++) {
        int t = maxx.number[i] + '0'  + x;
        res.number[j] = num[t % 2];
        x = t / 2;
    }
    res.Size = res.size();
    return res;
}
//разность
Binary Binary::operator - (Binary b) {
    Binary Zero;
    if ((*this < b)) return Zero;
    Binary res;
    int x = 0;
    int i = 0;
    for (; i < b.Size; i++) {
        int t = number[i] - b.number[i] + x;
        if (t >= 0) {
            res.number[i] = num[t];
            x = 0;
        }
        else {
            t += 2;
            x = -1;
            res.number[i] = num[t];
        }
        
    }
    for (; i < Size; i++) {
        int t = number[i] - '0' + x;
        if (t >= 0) {
            res.number[i] = num[t];
            x = 0;
        }
        else {
            t += 2;
            x = -1;
            res.number[i] = num[t];
        }
    }
    for (; i < 100; i++) {
        res.number[i] = '0';
    }
    res.Size = res.size();
    return res;
    
}
//деление (как для целых)
Binary Binary::operator / (Binary b) {
    Binary Zero;
    Binary One(one);
    
    if (!(b == Zero)) {
        Binary copya = *this;
        Binary D;
        while (copya >= b) {
            copya = copya - b;
            D = D + One;
        }
        D.Size = D.size();
        return D;
    }
    else
        return Zero;
    
}

//умножение
Binary Binary::operator * (Binary b) {
    Binary Zero;
    Binary One(one);
    Binary minn;
    Binary maxx;
    if (*this > b) { minn = b; maxx = *this; }
    else {
        minn = *this;
        maxx = b;
    }
    
    Binary res;
    for (; minn > Zero; minn = minn - One) {
        res = res + maxx;
    }
    res.Size = res.size();
    return res;
}

Binary Binary::operator ++(int) {
    Binary temp = *this;
    Binary One(one);
    temp= temp + One;
    return temp;
}
Binary Binary::operator --(int) {
    Binary temp = *this;
    Binary One(one);
    temp = temp - One;
    return temp;
}

ostream& operator<<(ostream& os, Binary& binary)
{
    os << binary.ToString();
    return os;
}


Binary Mod(Binary a, Binary b) {
    Binary Zero;
    Binary One(one);
    if (!(b == Zero)) {
        Binary copya = a;
        
        while (copya >= b) {
            copya = copya - b;
            
        }
        copya.Size = copya.size();
        return copya;
    }
    else
        return Zero;
}

