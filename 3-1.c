#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief функция написана, чтобы пользователи вводили значение и проверять его
 * на то, что он является числом
 * @return введеное значения пользователя
 */
float fun_scan();

/**
 * @brief Считает уравнение с проверкой истиности fun_check и выводит итоговое
 * значение уравнения или выводит Решение отсутствует и текущее значение х
 * @param x - значение числа в диапазоне
 * @return ничего
 */
float fun_example(float x);

/**
 * @brief Проверяет существующие значения х в данном уравнение
 * @param x - значение числа в диапазоне
 * @return Если не существует значение х возращает false, иначе true
 */
bool fun_check(float x);

int main() {
  float d_x, x, x_max;
  x = fun_scan();
  x_max = fun_scan();
  d_x = fun_scan();
  while (x <= x_max) {
    fun_example(x);
    x = x + d_x;
  }
  return 0;
}

float fun_example(float x) {
  float example;
  if (fun_check(x) == true) {
    example = 3 * sin(sqrtf(x)) + 0.39 * x - 3.8;
    printf("%f\n", example);
  } else {
    printf("%f %s\n", x, "Решение отстутствует");
  }
  return 0;
}

float fun_scan() {
  int a;
  float ret;
  a = scanf("%f", &ret);
  if (a != 1) {
    abort();
  }
  return ret;
}

bool fun_check(float x) {
  if (x < 0) {
    return false;
  } else {
    return true;
  }
}
