#include <iostream>
#include <cmath>

// Прототипы функций
void inputX();
void inputY();
void inputZ();
void findIntegerPartSum();
void findFractionalPartGeometricMean();

; // Глобальные переменные для хранения введённых чисел
double x, y, z;

; // Основная функция
int main() {
    int choice;

    do {
        std::cout << "\nМеню:\n";
        std::cout << "1. Ввести вещественное число x\n";
        std::cout << "2. Ввести вещественное число y\n";
        std::cout << "3. Ввести вещественное число z\n";
        std::cout << "4. Найти целую часть суммы трех чисел\n";
        std::cout << "5. Найти дробную часть среднего геометрического модулей трех чисел\n";
        std::cout << "0. Выход\n";
        std::cout << "Введите Ваш выбор: ";

        std::cin >> choice;

        switch (choice) {
            case 1:
                inputX();
                break;
            case 2:
                inputY();
                break;
            case 3:
                inputZ();
                break;
            case 4:
                findIntegerPartSum();
                break;
            case 5:
                findFractionalPartGeometricMean();
                break;
            case 0:
                std::cout << "Выход из приложения." << std::endl;
                break;
            default:
                std::cout << "Некорректный ввод. Повторите попытку." << std::endl;
        }
    } while (choice != 0);

    return 0;
}

// Реализация функций
void inputX() {
    std::cout << "Введите вещественное число x: ";
    std::cin >> x;
}

void inputY() {
    std::cout << "Введите вещественное число y: ";
    std::cin >> y;
}

void inputZ() {
    std::cout << "Введите вещественное число z: ";
    std::cin >> z;
}

void findIntegerPartSum() {
    double sum = x + y + z;
    int integer_part_sum = static_cast<int>(sum);
    std::cout << "Целая часть суммы: " << integer_part_sum << std::endl;
}

void findFractionalPartGeometricMean() {
 double geometric_mean = cbrt(fabs(x) * fabs(y) * fabs(z));
    double fractional_part_geometric_mean = geometric_mean - floor(geometric_mean);
    std::cout << "Дробная часть среднего геометрического модулей: " << fractional_part_geometric_mean << std::endl;
}