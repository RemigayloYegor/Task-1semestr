#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief функция написана, чтобы пользователи вводили значение и проверять его
 * на то, что он является числом
 * @param  нет
 * @return введеное значения пользователя
 */
float fun_scan();

/**
 * @brief Функция выбирает вариант перевести угол из радианов в градусы или из
 * градусов в радины
 * @param  corner - угол, varible - вариант перевода
 * @return угол в градусах или радианах
 */
float fun_variable(int variable, float corner);

int main() {
  float number;
  int variable;
  printf("%s\n", "Если хотите перевести из радианов в градусы введите 1, если "
                 "из градусов в радины то 2.");
  variable = fun_scan();
  printf("%s\n", "Введите колличество");
  number = fun_scan();
  fun_variable(variable, number);
}

float fun_variable(int variable, float corner) {
  if (variable == 1) {
    return printf("%f", corner * 180 / M_PI);
  } else if (variable == 2) {
    return printf("%f", corner * M_PI / 180);
  } else {
    abort();
  }
}

float fun_scan() {
  float corner;
  int a;
  a = scanf("%f", &corner);
  if (a != 1) {
    abort();
  } else {
    return corner;
  }
}
