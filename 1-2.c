#include <math.h>
#include <stdio.h>
#include <stdlib.h>

/**
 * @brief функция написана, чтобы пользователи вводили значение и проверять его
 * на то, что он является числом
 * @return введеное значения пользователя
 */
double fun_scan();
/**
 * @brief перевод из радианов в градусы
 * @param  corner - угол
 * @return угол в градусах
 */
double fun_degrees(double corner);
/**
 * @brief перевод из радианов в минуты
 * @param  corner - угол
 * @return угол в минутах
 */
double fun_minutes(double corner);
/**
 * @brief перевод из радианов в секунды
 * @param  corner - угол
 * @return угол в секундах
 */
double fun_seconds(double corner);

int main() {
  double seconds, corner, minutes, degrees;
  corner = fun_scan();
  degrees = fun_degrees(corner);
  minutes = fun_minutes(corner);
  seconds = fun_seconds(corner);
  printf(" Градусы - %lf\n Минуты - %lf\n Секунды - %lf\"\n", degrees, minutes,
         seconds);
}

double fun_scan() {
  int result;
  double get;
  result = scanf("%lf", &get);
  if (result != 1) {
    abort();
  }
  return get;
}

double fun_degrees(double corner) {
  return corner * 180 / M_PI;
}

double fun_minutes(double corner) {
  return corner * (60 * 180) / M_PI;
}

double fun_seconds(double corner) {
  return corner * (3600 * 180) / M_PI;
}
