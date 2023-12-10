#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <time.h>
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
 * @brief Функция заполняет массив рандомными числами в диапазоне [-30:70]
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
 * @brief Функция меняет предпоследний элемент массива на максимальный по модулю.
 * @param array указатель на массив
 * @param size размерность массива
 * @return результат
*/
int task1(int* array, const size_t size);
/**
 * @brief Фунция находит количество тех элементов, значения которых делятся на заданное число N без остатка.
 * @param array указатель на массив
 * @param size размерность массива
 * @return 0
*/
int task2(const int* const array, const size_t size);
/**
 * @brief Функция находит номер первой пары соседних элементов с разными знаками.
 * @param array указатель на массив
 * @param size размерность массива
 * @return Итоговый ответ для третьего задания
*/
int task3(const int* const array, const size_t size);
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
  task1(Array, size);
  print_array(Array, size);
  printf("Second task: %d\n", task2(Array, size));
  printf("third task: %d\n", task3(Array, size));
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
  void* array = malloc(size * sizeof(int));
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

void FillArrayRandom(int* const array, const size_t size)
{
    puts("Введите элементы массива: ");
    for (size_t i = 0; i < size; i++)
    {
        array[i] = -30 + rand() % 101;          
    }
}

void print_array(const int* const  array, const size_t size)
{
    puts("Элементы массива: ");
    for(size_t i = 0; i < size; i++)
    {
        printf("Элемент %zu = %d\n", i, array[i]);
    }
}

int task1( int* array, const size_t size)
{
   int temp = 0;
   for (int i = 0; i < size; i = i + 1)
     {
       if (abs(array[i]) > temp)
       {
         temp = array[i];
       }
     }
   array[size - 2] = temp;
  return 0;
}

int task2(const int* const array, const size_t size)
{
  int temp = 0, number = scan_f("Введите число на которое должно делится без остатка: ");
  for (int i = 0; i < size; i = i + 1) 
  {
    if (array[i] % number == 0)
    {
      temp += 1;
    }
  }
  return temp;
}

int task3(const int* const array, const size_t size)
{
  int temp = 0, k = 0;
  for (int i = 0; i < size && size >= 2; i++) 
  {
    if ((array[i] >= 0 && array[i + 1] < 0 ) || (array[i] < 0 && array[i + 1] >= 0)) 
    {
        temp = i;
        k = 1;
        break;
    }
  }
  if (k == 0)
  {
    printf("%s\n", "Число для 3 задания не найдено");
    abort();
  } 
  else
  {
      return temp;
  }
}

void free_array(int* array)
{
    if (NULL != array)
    {
        free(array);
    }
}
