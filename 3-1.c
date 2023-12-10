#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief функция написана, чтобы пользователи вводили значение и проверять его
 * на то, что он является числом
 * @return введеное значения пользователя
 */
float scan_f(const char* const message);

/**
 * @brief Считает уравнение с проверкой истиности Check и выводит итоговое
 * значение уравнения или выводит Решение отсутствует и текущее значение х
 * @param x - текущее значение числа в диапазоне
 * @param d_x - значение шага в диапазоне
 * @param x_max - максимальное значение в диапазоне
 */
float Example(float x, float d_x, float x_max);

/**
 * @brief Проверяет существование всех аргументов
 * @param x - текущее значение числа в диапазоне
 * @param d_x - значение шага в диапазоне
 * @param x_max - максимальное значение в диапазоне
 * @return true или выкидывает из программы
 */
bool CheckArguments(float x, float d_x, float x_max);
/**
 * @brief Проверяет существование х для уравнения
 * @param x - текущее значение числа в диапазоне
 * @return Если не существует значение х возращает false, иначе true
 */
bool CheckFunction(float x);

/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main() 
{
  float d_x = scan_f("Введите значение шага в диапазоне: "), x = scan_f("Введите текущее значение числа в диапазоне: "), 
  x_max = scan_f("Введите максимальное значение в диапазоне: ");
  CheckArguments(x, d_x, x_max);
  while (x - x_max < DBL_EPSILON)
  {
    Example(x, d_x, x_max);
    x = x + d_x;
  }
  return 0;
}

float Example(float x, float d_x, float x_max)
{
  if (CheckFunction(x))
  {
    printf("%f\n", 3 * sin(sqrtf(x)) + 0.39 * x - 3.8);
  }
  else 
  {
    printf("%f %s\n", x, "Решение отстутствует");
  }
  return 0;
}

float scan_f(const char* const message) 
{
  int result;
  float get;
  printf("%s", message);
  result = scanf("%f", &get);
  if (result != 1)
  {
    abort();
  }
  return get;
}

bool CheckArguments(float x, float d_x, float x_max)
{
  if (d_x < DBL_EPSILON || x - x_max > -DBL_EPSILON)
  {
    printf("%s", "Error");
    abort();
  }
  return true;
}
bool CheckFunction(float x)
{
  if (x < DBL_EPSILON)
  {
    return false;
  }
  return true;
}
