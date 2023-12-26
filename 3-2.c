#include <stdio.h>
#include <float.h>
#include <errno.h>
#include <stdlib.h>
#include <math.h>

/**
 * @brief Функция присваивает целочисленное значение переменной
 * @param - сообщение для пользователя
 * @return целочисленная цифра
*/
int scan_f(const char* const message);
/**
 * @brief Функция присваивает целочисленное значение переменной
 * @return целочисленная цифра
*/
double GetE();
/**
* @brief Функция расчитывающая сумму членов последовательности.
* @param length - количество членов последовательности.
* @return cумма последовательности.
*/
double Suma(int length);
/**
* @brief Функция расчитывающая сумму членов последовательностиначиная с E.
* @param length - количество членов последовательности.
* @param E - начальный член последовательности.
* @return cумма последовательности.
*/
double SumaE(int E, int length);
/**
* @brief Функция расчитывающая рекурентный член последовательности.
* @param number - номер члена последовательности.
* @return Значение рекурентного члена последовательности.
*/
double recurent(int number);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
  int length = scan_f("Введите длину последовательности: ");
  printf("Сумма до %d равна %lf \n", length, Suma(length));
  double E = GetE();
  printf("%lf \n", SumaE(E, length));
  return 0;
}

int scan_f(const char* const message)
{
  int length;
  printf("%s", message);
  int result = scanf("%d", &length);
  if (result != 1 || length < )
  {
    errno = EIO;
    perror("Error :");
    abort();
  }
  return length;
}

double GetE()
{
  double value;
  int result = scanf("%lf", &value);
  if ((result != 1) || (value < DBL_EPSILON) || (value - 1 > DBL_EPSILON))
  {
    errno = EIO;
    perror("Error :");
    abort();
  }
  return value;
}
double Suma(int length)
{
  double current = 1;
  double result = current;
  for(int k = 0; k < length; k++)
  {
      current *= recurent(k);
      result += current;
  }
  return result;
}

double SumaE(int E, int length)
{
  double current = 1;
  double result = 0;
  for(int k = 0; fabs(current) - E < DBL_EPSILON; k++)
  {
      result += current;
      current *= recurent(k);
  }
  return result;
}
double recurent(int number)
{
  return 1.0 / (4 * pow(number, 2) + 6 * number + 2);
}
