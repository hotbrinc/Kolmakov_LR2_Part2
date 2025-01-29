#include <cstring>
#include <cmath>

using namespace std;

bool UserInput(string input)
{
    if(input.empty()) return false;

    try
    {
        int number = stod(input);
    }
    catch(...)
    {
        return false;
    }

    return true;
}

int CalcIntSumPart(double numA, double numB, double numC)
{
    double sum = numA + numB + numC;
    return (int)sum;
}

double CalcFractPart(double numA, double numB, double numC)
{
    //Модули чисел
    double mA = abs(numA);
    double mB = abs(numB);
    double mC = abs(numC);

    //Среднее геометрическое
    double gavg = pow(mA * mB * mC, (double)1 / 3);

    double result = gavg - (int)gavg;

    return result;
}