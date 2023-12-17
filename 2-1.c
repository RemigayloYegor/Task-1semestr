#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdbool.h>
#include <errno.h>

/**
 * @brief Функция присваивает целочисленное значение переменной и проверяет 
 * @param - сообщение для пользователя
 * @return целочисленная цифра
*/
double scan_f(const char* const message);
/**
 * @brief Функция проверяет существование треугольника
 * @param - side1, side2, side3 - стороны треугольника
 * @return площадь треугольника
*/
bool TriangleExistence(double side1, double side2, double side3);
/**
 * @brief Функция считает площадь треугольника
 * @param - side1, side2, side3 - стороны треугольника
 * @return площадь треугольника
*/
double TriangleSquare(double side1, double side2, double side3);
/**
 * @brief Функция считает площадь прямоугольника
 * @param - side1, side2 - стороны прямоугольника
 * @return площадь прямоугольника
*/
double RectangleSquare(double side1, double side2);
/**
 * @brief структура хранит константы, указывающие выбор фигуры
 * @brief Rectangle хранит значение, вызывающее функцию площади прямоугольника
 * @brief Triangle хранит значение, вызывающее функцию площади треугольника
*/
enum Values
{
Rectangle = 1,
Triangle = 2
};
/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main()
{
    double side1, side2, side3;
    puts("Прямоугольник - 1. Треугольник - 2");
    int choice = scan_f("Введите номер фигуры: ");
    switch ((enum Values)choice)
    {
      case Rectangle:
              side1 = scan_f("Длинна стороны 1: ");
              side2 = scan_f("Длинна стороны 2: ");
              printf("%s %lf", "Площадь треугольника =", RectangleSquare(side1, side2));
          break;
      case Triangle:
              side1 = scan_f("Длинна стороны 1: ");
              side2 = scan_f("Длинна стороны 2: ");
              side3 = scan_f("Длинна стороны 3: ");
              TriangleExistence(side1, side2, side3);
              printf("%s %lf", "Площадь треугольника =", TriangleSquare(side1, side2, side3));
          break;
      default:
          puts("Insert a valid choice!\n");
          return 1;
    }
    return 0;
}

bool TriangleExistence(double side1, double side2, double side3)
{
    if (side1 + side2 <= side3 || side1 + side3 <= side2 || side2 + side3 <= side1)
    {
        return false;
        abort();
    }
  
    return false;
}


double TriangleSquare(double side1, double side2, double side3)
{
  double Perimeter = (side1 + side2 + side3) / 2;
  return sqrt(Perimeter*(Perimeter - side1) * (Perimeter - side2) * (Perimeter -side3));
}

double RectangleSquare(double side1, double side2)
{
  return side1 * side2;
}

double scan_f(const char* const message)
{
    int value = 0;
    printf("%s", message);
    int result = scanf("%d", &value);
    if (result != 1 || value <= 0)
    {
      printf("Error: insert a valid number!\n");
      abort();
    }
    return value;
}

