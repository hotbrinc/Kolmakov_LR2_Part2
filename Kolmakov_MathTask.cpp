#include <iostream>
#include "Kolmakov_MathTask.h"

using namespace std;

//Вариант 15 - Колмаков

//Метод рекурсии для ввода корректного значения
double InputDoubleRec(string description)
{
    static string tempStrBuf; //Строка-буфер для хранения ввода
    cout << description << endl;
    getline(cin, tempStrBuf);

    if(!UserInput(tempStrBuf))
        return InputDoubleRec(description);

    return stod(tempStrBuf);
}

int main()
{
    //Ввод
    double x = InputDoubleRec("Enter X:");
    double y = InputDoubleRec("Enter Y:");
    double z = InputDoubleRec("Enter Z:");

    //Считаем
    cout << "Integer of sum: " << CalcIntSumPart(x, y, z) << endl;
    cout << "Fractional part of AVG: " << CalcFractPart(x, y, z) << endl;
}