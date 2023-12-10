#include <float.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief функция написана, чтобы пользователи вводили значение и проверять его
 * на то, что он является числом
 * @param  нет
 * @return введеное значения пользователя
 */
double scan_f();

/**
 * @brief Проверяет существование х 
 * @param х - переменная, которую ввел пользователь
 * @return возвращает true or false
 */
bool func_check(double x);

/**
 * @brief Вычисляет значение для 1 условия
 * @param х - переменная, которую ввел пользователь
 * @return возвращает вычисление для 1 условия
 */
double get_result1(double x);

/**
 * @brief Вычисляет значение для 2 условия
 * @param х - переменная, которую ввел пользователь
 * @return возвращает вычисление для 2 условия
 */
double get_result2(double x);

/**
 * @brief Вычисляет значение для 3 условия
 * @param х - переменная, которую ввел пользователь
 * @return возвращает вычисление для 3 условия
 */
double get_result3(double x);

/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main() 
{
  double x = scan_f();
  const double value = 1.2;


  double result;
  if (fabs(x - value) <= DBL_EPSILON) 
  {
      result = get_result2(x);
  } 
  else 
    if (x - value > -DBL_EPSILON) 
    {
      result = get_result1(x);
    } 
    else 
      {
        if (func_check(x))
        {
          result = get_result3(x);
        }
        else
        {
          printf("%s", "Function not exist ");
          return 1;
        }
      }
  
    printf("%s %lf", "Result is ", result);
  return 0;
}

bool func_check(double x) 
{
  if (fabs(sin(pow(x,2)))<=DBL_EPSILON)
  {
    return false;
  }
  return true;
}

double scan_f() 
{
  double value;
  int result = scanf("%lf", &value);
  if (result != 1) 
  {
    printf("%s", "error");
    abort();
  }
  return value;
}

double get_result1(double x)
{
  return log10(x) * M_PI;
}

double get_result2(double x)
{
  return 3;
}

double get_result3(double x)
{
  const double a = 1.1;
  return (cos(pow(x, 2)) / sin(pow(x, 2))) + a * pow(x, 2) / 2;
}
