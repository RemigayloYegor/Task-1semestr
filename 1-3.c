#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <float.h>
/**
 * @brief функция написана, чтобы пользователи вводили значение и проверять его
 * на то, что он является числом
 * @param  нет
 * @return введеное значения пользователя
 */
float scan_f();

/**
 * @brief Проверяет существования силы тока 2-ой лампы
 * @param I - общая сила тока
 * @param I1 - сила тока первой лампы
 * @return I2 силу тока второй лампы
 */
float Check(float I, float I1);

/**
 * @brief считает сопротивление лампы
 * @param I2 - сила тока второй лампы
 * @return сопротивление лампы
 */
float resistance(float I2);

/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main() {
  float I1, I2, I, R2;
  I = scan_f();
  I1 = scan_f();
  I2 = Check(I, I1);
  R2 = resistance(I2);
  printf("%s %f\n %s %f", "Сила тока второй лампы =", I2, "Сопротивление второй лампы =", R2);
}

float resistance(float I2) {
  float const U = 220;
  return U / I2;
}

float scan_f() {
  int result;
  float get;
  result = scanf("%f", &get);
  if (result != 1)
  {
    errno = EIO;
    perror("Error :");
    abort();
  }
  return get;
}

float Check(float I, float I1) {
  float I2;
  I2 = I - I1;
  if (I2 < DBL_EPSILON)
  {
    abort();
  } 
  return I2;
}
