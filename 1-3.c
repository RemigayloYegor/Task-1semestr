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
 * @brief Проверяет существования силы тока 2-ой лампы
 * @param I - общая сила тока
 * @param I1 -  сила тока первой лампы
 * @return I2 силу тока второй лампы
 */
float fun_check(float I, float I1);

int main() {
  float I1, I2, I, R2, U = 220;
  I = fun_scan();
  I1 = fun_scan();
  I2 = fun_check(I, I1);
  R2 = U / I2;
  printf("%s %f\n %s %f", "Сила тока второй лампы =", I2,
         "Сопротивление второй лампы =", R2);
}

float fun_scan() {
  int a;
  float b;
  a = scanf("%f", &b);
  if (a != 1) {
    abort();
  } else {
    return b;
  }
  return 0;
}

float fun_check(float I, float I1) {
  float I2;
  I2 = I - I1;
  if (I2 >= 0) {
    return I2;
  } else {
    abort();
  }
}
