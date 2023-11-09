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
double fun_scan();

/**
 * @brief Проверяет в какой из дипазон входит значение и решает уравнение к
 * этому дипазону
 * @param х - переменная, которую ввел пользователь
 * @return возвращает значение уравнения, которое считало
 */
double func_check(double x);

int main() {
  double x;
  x = fun_scan();
  printf("%lf", func_check(x));
  return 0;
}

double func_check(double x) {
  double a = 1.1;
  if (x == 1.2) {
    return 3;
  } else if (fmin(x, 1.2) == 1.2) {
    return log10(x) * M_PI;
  } else {
    return (cos(pow(x, 2)) / sin(pow(x, 2))) + a * pow(x, 2) / 2;
  }
}

double fun_scan() {
  int result;
  float get;
  result = scanf("%lf", &get);
  if (result != 1) {
    abort();
  }
  return get;
}
