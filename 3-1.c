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
float scan_f();

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

/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main()
{
  float d_x = scan_f(), x = scan_f(), x_max = scan_f();
  while (x - x_max <= DBL_EPSILON) 
  {
    fun_example(x);
    x = x + d_x;
  }
  return 0;
}

float fun_example(float x) {
  if (fun_check(x) == true)
  {
    printf("%f\n", 3 * sin(sqrtf(x)) + 0.39 * x - 3.8);
  } else {
    printf("%f %s\n", x, "Решение отстутствует");
  }
  return 0;
}

float scan_f() {
  int result;
  float get;
  result = scanf("%f", &get);
  if (result != 1) 
  {
    abort();
  }
  return get;
}

bool fun_check(float x) {
  if (x < DBL_EPSILON)
  {
    return false;
  }
  return true;
}
