#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @param - сообщение для пользователя
 * @return целочисленная цифра
*/
int scan_f(const char* const message);
/**
 * @brief Функция переводит угол из радианов в градусы 
 * @param  corner - угол
 * @return угол в градусах
 */
float Radians_Degrees(float corner);
/**
 * @brief Функция переводит угол из градусов в радины
 * @param  corner - угол
 * @return угол в радианах
 */
float Degrees_Radians(float corner);
/**
 * @brief структура хранит константы, указывающие выбор пользователя заполнить массив
 * @brief RadiansToDegrees хранит значение, вызывающее функцию перевода радиан в градусы
 * @brief DegreesToRadians хранит значение, вызывающее функцию перевода градусов в радианы
*/
enum Choices
{
    RadiansToDegrees = 1,
    DegreesToRadians = 2
};
/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main()
{
  const int choice = scan_f("Если хотите перевести из радианов в градусы введите 1, если из градусов в радины то 2.\n");
  float corner = scan_f("Введите число: ");
  switch ((enum Choices)choice)
  {
      case RadiansToDegrees:
              printf("%f", Radians_Degrees(corner));
          break;
      case DegreesToRadians:
              printf("%f", Degrees_Radians(corner));
          break;
      default:
          puts("Insert a valid choice!\n");
          return 1;
  }
  return 0;
}

float Radians_Degrees(float corner)
{
  return corner * 180 / M_PI;
}
float Degrees_Radians(float corner)
{
  return corner * M_PI / 180;
}
int scan_f(const char* const message)
{
    int value = 0;
    printf("%s", message);
    int result = scanf("%d", &value);
    if (result != 1)
    {
        errno = EIO;
        perror("Error :");
        abort();
    }
    return value;
}

