#include <stdio.h>
#include <stdlib.h>

#ifndef SRC_CALCULATOR_HEADERS_STACK_H_
#define SRC_CALCULATOR_HEADERS_STACK_H_

/**
 @brief Структура стека
 @details Структура необходима для определения валидности скобок, используется
 при подготовке обратной нотации для хранения символов операторов, а при
 подсчете выражения хранит в себе числовые значения
 @param c символ оператора
 @param d числовое значение
 @param next указатель на следующий узел стека
*/

typedef struct Stack {
  char c;
  double d;
  struct Stack *next;
} Stack;

/**
 @brief Функция добавления символа в новый элемент стека
 @param c символ оператора
 @return указатель на стек
*/
Stack *push_c(Stack *stack, char c);

/**
 @brief Функция добавления числового значения в новый элемент стека
 @param d числовое значение
 @return указатель на стек
*/
Stack *push_d(Stack *stack, double d);

/**
 @brief Функция получения символа из вершины стека. Вершина стека удаляется
 @param stack указатель на стек
 @return символ оператора
*/
char pop_c(Stack **stack);

/**
 @brief Функция получения числа из вершины стека. Вершина стека удаляется
 @param stack указатель на стек
 @return число
*/
double pop_d(Stack **stack);

/**
 @brief Функция получения символа из вершины стека. Вершина стека сохраняется
 @param stack указатель на стек
 @return символ
*/
char peek_c(Stack *stack);

/**
 @brief Функция получения количества узлов стека
 @param stack указатель на стек
 @return размер стека
*/
int size(Stack *stack);

/**
 @brief Функция, обозначающая заполненность стека
 @param stack указатель на стек
 @return 1/0 если в стеке есть хотя бы 1 элемент/стек пуст
*/
int isEmpty(Stack *stack);

/**
 @brief Функция для удаления стека
 @param stack указатель на стек
*/
void destroy(Stack *stack);

#endif  // SRC_CALCULATOR_HEADERS_STACK_H_
