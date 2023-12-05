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
 * @brief Проверяет в какой из дипазон входит значение и решает уравнение к
 * этому дипазону
 * @param х - переменная, которую ввел пользователь
 * @return возвращает значение уравнения, которое считало
 */
double func_check(double x);

/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main() 
{
  double x = scan_f();
  printf("%lf", func_check(x));
  return 0;
}

double func_check(double x) {
  double a = 1.1;
  if (x - 1.2 == DBL_EPSILON) {
    return 3;
  } else if (x - 1.2 > -DBL_EPSILON) {
    return log10(x) * M_PI;
  } else if (x - 1.2 < DBL_EPSILON) {
    return (cos(pow(x, 2)) / sin(pow(x, 2))) + a * pow(x, 2) / 2;
  }
}

double scan_f() {
  int result;
  double get;
  result = scanf("%lf", &get);
  if (result != 1) {
    abort();
  }
  return get;
}
