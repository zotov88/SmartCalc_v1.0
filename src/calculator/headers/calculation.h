#ifndef SRC_CALCULATOR_HEADERS_CALCULATION_H_
#define SRC_CALCULATOR_HEADERS_CALCULATION_H_

#define UNAR_OP "-+/*^m"
#define BINAR_OP "sctSCTlLq"

#include <math.h>

#include "parcer.h"
#include "stack.h"
#include "validation.h"

/**
 @brief Функия подсчета распарсенного выражения
 @param rpn выражение в польской нотации
 @param x значение x
 @return результат выражения
*/
double calculation(const char* rpn, double x);

/**
 @brief Функия для конвертации строки из массива чаров в double
 @param rpn выражение в польской нотации
 @return сконвертированное число
*/
double getDigit(const char** rpn);

/**
 @brief Функия для определения унарного минуса в строке
 @param c символ из строки
 @return 1/0 в случае успеха/не успеха
*/
int isUnarMinus(char c);

/**
 @brief Функия для определения бинарного оператора ("-+/^m*")
 @param c символ из строки
 @return 1/0 в случае успеха/не успеха
*/
int isBinarOperator(char c);

/**
 @brief Функия для определения унарного оператора ("cos, sin ...")
 @param c символ из строки
 @return 1/0 в случае успеха/не успеха
*/
int isUnarOperator(char c);

/**
 @brief Функия подсчета выражения с участием бинарного оператора
 @param c символ из строки
 @return указатель на стек
*/
Stack* binarCalc(char c, Stack* stack);

/**
 @brief Функия подсчета выражения с участием унарного оператора
 @param c символ из строки
 @param stack стек для хранения числовых значений
 @return указатель на стек
*/
Stack* unarCalc(char c, Stack* stack);

#endif  // SRC_CALCULATOR_HEADERS_CALCULATION_H_
