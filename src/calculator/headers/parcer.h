#ifndef SRC_CALCULATOR_HEADERS_PARCER_H_
#define SRC_CALCULATOR_HEADERS_PARCER_H_

#include "stack.h"
#include "validation.h"

/**
 @brief Функия парсинга выражения в обратную польскую нотацию
 @param expression проверенное на валидность выражение
 @details внутри функции выделяется динамическая память под указатель чаров, он
 же и возвращается. Соответственно полученный указатель нужно очищать.
 @return указатель на выражение в обратной польской нотации
*/
char* parcer(const char* expression);

/**
 @brief Функия удаления лишних пробелов в обратной польской нотации
 @param rpn обратная польская нотация
*/
void deleteExtraSpases(char* rpn);

/**
 @brief Функия определения буквы функции, помещаемой в польскую нотацию
 @param function указатель на начало функции в выражении
 @return символ, определяющий функцию в обратной польской нотации
*/
char getLetFun(char* function);

/**
 @brief Функия определения приоритета между операторами
 @param inExp символ из выражения
 @param inSt символ из стека
 @return 1 в случае, если опертор из выражения имеет меньший или равный
 приоритет в сравнении с опреатором из стека. 0 в противном случае
*/
int checkPriority(char inExp, char inSt);

/**
 @brief Функия определения приоритета оператора
 @param c оператор
 @return значение приоритета
*/
int getPriority(char c);

#endif  // SRC_CALCULATOR_HEADERS_PARCER_H_
