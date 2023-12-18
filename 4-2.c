#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>
#include <math.h>
/**
 * @brief Функция присваивает целочисленное значение переменной
 * @param - сообщение для пользователя
 * @return целочисленная цифра
*/
int scan_f(const char* const message);
/**
 * @brief Функция выделяет память под массив
 * @param size длина массива
 * @return array указатель на пустой массив
*/
int* get_array(const int size);
/**
 * @brief Функция заполняет массив, которые вводит пользователь
 * @param array указатель на заполняемый массив
 * @param size длина массива
*/
void FillArrayUser(int* const array, const size_t size);
/**
 * @brief Функция заполняет массив рандомными числами в диапазоне [begin : end]
 * @param array указатель на заполняемый массив
 * @param size длина массива
*/
void FillArrayRandom(int* const array, const size_t size);
/**
 * @brief Функция присваивает переменной целочисленное значение и проверяет его на положителность
 * @return number положительное число
*/
size_t get_size();
/**
 * @brief Функция выводит массив на экран
 * @param array указатель на заполняемый массив
 * @param size длина массива
*/
void print_array(const int* const  array, const size_t size);
/**
 * @brief Функция копирующая элементы одного массива в другой
 * @param Current исходный массив
 * @param Copy пустой массив
 * @param size длина массива
*/
void copy_array(int* const current, int* copy, const size_t size);
/**
 * @brief Функция считаетс колличество четных элементов, оканчивающихся на ноль в массиве
 * @param array указатель на массив
 * @param size размерность массива
 * @return колличество четных элементов
*/
int EvenNumbers(int* const array, const size_t size);
/**
 * @brief Функция меняет предпоследний элемент массива на максимальный по модулю.
 * @param array указатель на массив
 * @param size размерность массива
 * @return результат
*/
int *task1(int* array, const size_t size);
/**
 * @brief Фунция находит количество тех элементов, значения которых делятся на заданное число N без остатка.
 * @param array указатель на массив
 * @param size размерность массива
 * @return 0
*/
int *task2(int* array, size_t size);
/**
 * @brief Функция находит номер первой пары соседних элементов с разными знаками.
 * @param array указатель на массив
 * @param size размерность массива
 * @return Итоговый ответ для третьего задания
*/
int *task3(int* array, const size_t size);
/**
 * @brief Функция, освобождающая массив
 * @param array указатель на массив
*/
void free_array(int* array);
/**
 * @brief структура хранит константы, указывающие выбор пользователя заполнить массив
 * @brief User хранит значение, вызывающее ввод массива вручную
 * @brief Random хранит значение, вызывающее ввод массива случайными числами
*/
enum Choices
{
    User = 1,
    Random = 2
};
/**
 * @brief точка входа в программу
 * @return код ошибки (0 - успех)
 */
int main() 
{
  srand(time(NULL)); 
  size_t size = get_size(); 
  int *Array = get_array(size);
  int choice = scan_f("Выберите способ заполнения массива\n 1. Вручную, 2. Автозаполнение\n");
  switch ((enum Choices)choice)
  {
      case User:
              FillArrayUser(Array, size);
          break;
      case Random:
              FillArrayRandom(Array, size);
          break;
      default:
          puts("Insert a valid choice!\n");
          return 1;
  }
  puts("Исходный массив:");
  print_array(Array, size);
  print_array(task1(Array, size), size);
  print_array(task2(Array, size), size + EvenNumbers(Array, size));
  print_array(task3(Array, size), size);
  free_array(Array);
  return 0;
}

int scan_f(const char* const message)
{
    int value = 0;
    printf("%s", message);
    int result = scanf("%d", &value);
    if (result != 1)
    {
        errno = EIO;
        perror("Error :");
        abort();
    }
    return value;
}

size_t get_size()
{
   int size =  scan_f("Введите размер массива: ");
   if (size <= 0)
   {
       errno = ERANGE;
       perror("Error :");
       abort();
   }

   return (size_t)size;
}

int* get_array(const int size)
{
  int* array = malloc(size * sizeof(int));
  if (NULL == array)
  {
      errno = ENOMEM;
      perror("Error :");
      abort();
  }
  return array;
}

void FillArrayUser(int* const array, const size_t size)
{
    puts("Введите элементы массива: ");
    for (size_t i = 0; i < size; i++)
    {
        array[i] = scan_f("Введите элемент = ");           
    }
}

void FillArrayRandom(int *const array, const size_t size) 
{
  int begin = scan_f("Введите нижнюю границу диапазона: "), 
      end = scan_f("Введите верхнюю границу диапазона: ");
  for (size_t i = 0; i < size; i++)
  {
    array[i] = begin + rand() % (end - begin + 1);
  }
}

void print_array(const int* const  array, const size_t size)
{
    for(size_t i = 0; i < size; i++)
    {
        printf("Элемент %zu = %d\n", i, array[i]);
    }
}

int EvenNumbers(int* const array, const size_t size)
{
  int count = 0;
  for (size_t i = 0; i < size; i++)
  {
    if(array[i] % 10 == 0)
    {
      count++;
    }
  }
  return count;
}


void copy_array(int* const current, int* copy, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
          copy[i] = current[i];
    }
}

int *task1( int* array, const size_t size)
{
   int temp = abs(array[0]);
   for (size_t i = 1; i < size; i++)
     {
       if (abs(array[i]) > temp)
       {
         temp = array[i];
       }
     }
  int* new_array = get_array(size);
  copy_array(array, new_array, size);
  new_array[size - 2] = temp;
  return new_array;
}

int *task2(int* array, size_t size)
{
  int k = 0, CountEven = EvenNumbers(array, size), number = scan_f("Введите число которое нужно вставить после всех четных элементов, оканчивающихся на ноль: ");
  puts("Массив для Задания 2:");
  int* new_array = get_array(size + CountEven);
  for (size_t i = 0; k < size + CountEven; i++) 
  {
    if (array[i] % 10 == 0)
    {
      new_array[k] = array[i];
      new_array[k + 1] = number;
      k = k + 2;
    }
    else
    {
      new_array[k] = array[i];
      k++;
    }
  }
  return new_array;
}

int *task3(int* array, const size_t size)
{
  puts("Массив для Задания 3:");
  int* new_array = get_array(size);
  int temp = 0, k = 0;
  for (size_t i = 0; i < size; i++) 
  {
    if (i == 0 || i == size - 1) 
    {
      new_array[i] = 0;
    }
    else 
    {
      new_array[i] = array[i] * i * i;
    }
  }
  return new_array;
}

void free_array(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}
