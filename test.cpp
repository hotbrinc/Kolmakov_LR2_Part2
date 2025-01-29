#include "CUTE/cute/cute.h"
#include "CUTE/cute/ide_listener.h"
#include "CUTE/cute/cute_runner.h"
#include "Kolmakov_MathTask_v1_cpp" 

using namespace cute;

void test_input_x_empty() {
    std::string empty_string = "";
    std::stringstream ss(empty_string);
    std::cin.rdbuf(ss.rdbuf());
    
    inputX(); // Вызываем функцию ввода числа x
    ASSERT_THROW(inputX(), std::invalid_argument); // Пустой ввод 
}

void test_input_x_invalid_negative_number() {
    double input_value = -10.5;
    std::stringstream ss;
    ss << input_value;
    std::cin.rdbuf(ss.rdbuf());
    
    inputX(); // Вызываем функцию ввода числа x
    ASSERT_EQUAL_DOUBLE(-10.5, x); // Проверяем, сохранила ли программа значение х
}

void test_input_x_invalid_letter() {
    char input_char = 'A';
    std::stringstream ss;
    ss << input_char;
    std::cin.rdbuf(ss.rdbuf());
    
    inputX(); // Вызываем функцию ввода числа x
    ASSERT_THROW(inputX(), std::invalid_argument); // Проверка на написание буквы вместо цифры
}

void test_input_y_invalid_negative_number() {
    double input_value = -20.25;
    std::stringstream ss;
    ss << input_value;
    std::cin.rdbuf(ss.rdbuf());
    
    inputY(); // Вызываем функцию ввода числа y
    ASSERT_EQUAL_DOUBLE(-20.25, y); // Проверяем, сохранила ли программа значение х
}

void test_input_y_invalid_letter() {
    char input_char = 'B';
    std::stringstream ss;
    ss << input_char;
    std::cin.rdbuf(ss.rdbuf());
    
    inputY(); // Вызываем функцию ввода числа y
    ASSERT_THROW(inputY(), std::invalid_argument); // Ожидаем исключение при попытке ввести букву
}

void test_input_z_invalid_negative_number() {
    double input_value = -30.75;
    std::stringstream ss;
    ss << input_value;
    std::cin.rdbuf(ss.rdbuf());
    
    inputZ(); // Вызываем функцию ввода числа z
    ASSERT_EQUAL_DOUBLE(-30.75, z); // Проверяем, что значение было успешно сохранено
}

void test_input_z_invalid_letter() {
    char input_char = 'C';
    std::stringstream ss;
    ss << input_char;
    std::cin.rdbuf(ss.rdbuf());
    
    inputZ(); // Вызываем функцию ввода числа z
    ASSERT_THROW(inputZ(), std::invalid_argument); // Ожидаем исключение при попытке ввести букву
}

void test_find_integer_part_sum() {
    x = 1.23;
    y = 45.67;
    z = -9.01;
    findIntegerPartSum();
    ASSERT_EQUAL_INT(38, integer_part_sum); // Проверка результата целой части суммы
}

void test_find_fractional_part_geometric_mean_positive_numbers() {
    x = 8.0;
    y = 27.0;
    z = 125.0;
    findFractionalPartGeometricMean();
    ASSERT_APPROX_EQUAL_DOUBLE(0.5, fractional_part_geometric_mean, 0.001); // Проверка дробной части среднего геометрического
}

void test_find_fractional_part_geometric_mean_negative_numbers() {
    x = -8.0;
    y = -27.0;
    z = -125.0;
    findFractionalPartGeometricMean();
    ASSERT_APPROX_EQUAL_DOUBLE(0.5, fractional_part_geometric_mean, 0.001); // Проверка дробной части среднего геометрического
}

int main() {
    suite s;
    s.push_back(CUTE(test_input_x_empty));                 // Новый тест на пустой ввод для x
    s.push_back(CUTE(test_input_x_invalid_negative_number)); // Тестирование ввода отрицательного значения для x
    s.push_back(CUTE(test_input_x_invalid_letter));          // Тестирование ввода буквы вместо числа для x
    s.push_back(CUTE(test_input_y_invalid_negative_number)); // Тестирование ввода отрицательного значения для y
    s.push_back(CUTE(test_input_y_invalid_letter));          // Тестирование ввода буквы вместо числа для y
    s.push_back(CUTE(test_input_z_invalid_negative_number)); // Тестирование ввода отрицательного значения для z
    s.push_back(CUTE(test_input_z_invalid_letter));          // Тестирование ввода буквы вместо числа для z
    s.push_back(CUTE(test_find_integer_part_sum));           // Тестирование вычисления целой части суммы
    s.push_back(CUTE(test_find_fractional_part_geometric_mean_positive_numbers)); // Тестирование вычисления дробной части среднего геометрического положительных чисел
    s.push_back(CUTE(test_find_fractional_part_geometric_mean_negative_numbers)); // Тестирование вычисления дробной части среднего геометрического отрицательных чисел

    ide_listener<> listener;
    makeRunner(listener)(s, "All Math Task Tests");

    return 0;
}