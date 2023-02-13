#ifndef SRC_CALCULATOR_HEADERS_CREDIT_H_
#define SRC_CALCULATOR_HEADERS_CREDIT_H_

#include <math.h>
#include <stdio.h>
#include <string.h>

#define MONTH 30.4167

/**
 @brief Структура для хранения данных, необходимых для кредитного калькулятора
*/
typedef struct DataCred {
  double payment, overpayment, total_payment, first_payment, last_payment;
} DataCred;

/**
 @brief Функция для вычисления данных о кредите
 @param sum сумма кредита
 @param month срок кредита
 @param rate процентная ставка по кредиту
 @param data структура для хранения данных
*/
void creditCalc(double sum, int month, double rate, int type, DataCred* data);

/**
 @brief Функция, вычисляющая аннуитетные платежи
 @param sum сумма кредита
 @param month срок кредита
 @param rate процентная ставка по кредиту
 @param data структура для хранения данных
*/
void anuitet(double sum, int month, double rate, DataCred* data);

/**
 @brief Функция, вычисляющая дифференцированные платежи
 @param sum сумма кредита
 @param month срок кредита
 @param rate процентная ставка по кредиту
 @param data структура для хранения данных
*/
void different(double sum, int month, double rate, DataCred* data);

#endif  // SRC_CALCULATOR_HEADERS_CREDIT_H_
