#include <stdio.h>
#include <errno.h>
#include <math.h>
#include <stdlib.h>
#include <float.h>

/**
* @brief Функция для вычисления рекуррентного члена ряда.
* @param x Параметр функции, аппроксимируемой рядом.
* @param k Индекс члена ряда.
* @return Значение рекуррентного члена.
*/
double GetRecurrent(double x, double k);

/**
* @brief Функция для вычисления суммы ряда.
* @param x Показатель степени.
* @return Значение 3 в степени x.
*/
double GetSeriesSuma(double x, double e);

/**
* @brief Функция для вычисления значения функции.
* @param x - аргумент функции.
* @return Значение функции.
*/
double GetFunction(double x);

/**
* @brief Функция проверки ввода шага на правильность.
* @param step - шаг функции.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
*/
void CheckStep(double step);

/**
* @brief Функция проверки шага на правильность.
* @param message - сообщение пользователю.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Возвращает значение в случае успеха.
*/
double scan_f(const char* message);

/**
* @brief Функция проверки отрезка на существование.
* @param a - начало отрезка.
* @param b - конец
отрезка.
*/
void CheckSegment(const double begin, const double end);

/**
* @brief Функция проверки на правильность точности вычислений.
* @remarks Экстренное завершение программы, в случае неправильного ввода.
* @return Возвращает значение в случае успеха.
*/
void CheckEpsilon(double e, double x);

/**
* @brief Функция расчёта первого элемента последовательности.
* @param x - аргумент функции.
* @return Возвращает значение первого элемента последовательности.
*/
double GetElement(double x);

/**
* @brief Точка входа в программу.
* @return Возвращает 0 в случае успеха.
*/
int main()
{
  const double begin = scan_f("Введите начало интервала: ");
  const double end = scan_f("Введите конец интервала: ");
  CheckSegment(begin, end);
  const double step = scan_f("Введите шаг функции: ");
  CheckStep(step);
  double x = begin;
  const double e = scan_f("Введите точность вычислений: ");
  CheckEpsilon(e, x);

  while (x - end <= DBL_EPSILON)
  {
    printf("%10.2lf | %25.15lf | %.15lf \n", x, GetFunction(x), GetSeriesSuma(x, e));
    x += step;
  }

  return 0;
}


double GetSeriesSuma(double x, double e)
{
  double current = 1;
  double sum = current;
  double k = 0;

  while (GetFunction(x) - sum > e + DBL_EPSILON)
  {
    current *= GetRecurrent(x, k);
    sum += current;
    k++;
  }
  return sum;
}

double GetRecurrent(double x, double k)
{
  return pow(x, 2) / ((2 * k + 2) * (2 * k + 1));
}

double GetFunction(double x)
{
    return (exp(x) + exp(-x)) / 2;
}

void CheckStep(double step)
{
  if (step < DBL_EPSILON)
  {
    puts("Неверно введено значение!");
    abort();
  }
}

void CheckSegment(const double begin, const double end)
{
  if (begin - end > -DBL_EPSILON)
  {
    puts("Неверно введен интервал.");
    abort();
  }
}

double scan_f(const char* message)
{
  double value;
  printf("%s", message);
  int result = scanf("%lf", &value);

  if (result != 1)
  {
    errno = EIO;
    perror("Ошибка ввода");
    abort();
  }
  return value;
}

void CheckEpsilon(double e, double x)
{
  if (e < DBL_EPSILON || e - GetElement(x) > DBL_EPSILON)
  {
    printf("Неверно введена тосность!");
    abort();
  }
}

double GetElement(double x)
{
  return pow(x, 2) / 2;
}
