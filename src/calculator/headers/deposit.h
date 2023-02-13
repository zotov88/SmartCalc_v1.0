#ifndef SRC_CALCULATOR_HEADERS_DEPOSIT_H_
#define SRC_CALCULATOR_HEADERS_DEPOSIT_H_

#include <stdio.h>
#include <string.h>

#define MONTH 30.4167
#define WORD "нет"

/**
 @brief Структура для хранения данных, необходимых для депозитного калькулятора
*/
typedef struct DataDep {
  int period;
  double deposit_start, deposit_end, rate, key_rate, tax_type, replenish,
      percent, tax;
  char *payout, *replenishment, *capital;
} DataDep;

/**
 @brief Функция для вычисления данных о депозите
 @param deposit_start сумма вклада в начале срока
 @param period срок депозита
 @param rate ставка по вкладу
 @param key_rate ключевая ставка
 @param capital параметр капитализации вклада
 @param payout периодичность выплат
 @param replenishment периодичность пополнения
 @param tax_type налоговая ставка
 @param replenish сумма пополнения
 @param data структура для хранения данных, необходимых для депозитного
 калькулятора
*/
void depositCalc(double deposit_start, int period, double rate, double key_rate,
                 char* capital, char* payout, char* replenishment,
                 double tax_type, double replenish, DataDep* data);

/**
 @brief Функция, подсчитывающая проценты с капитализацией
 @param data структура для хранения данных, необходимых для депозитного
 калькулятора
*/
void withCapitalisation(DataDep* data);

/**
 @brief Функция, подсчитывающая проценты без капитализации
 @param data структура для хранения данных, необходимых для депозитного
 калькулятора
*/
void withoutCapitalisation(struct DataDep* data);

/**
 @brief Функция, подсчитывающая уплаченные налоги
 @param data структура для хранения данных, необходимых для депозитного
 калькулятора
*/
void calculateTax(DataDep* data);

/**
 @brief Функция, подсчитывающая проценты с периодичными пополгнениями без
 капитализации
 @param data структура для хранения данных, необходимых для депозитного
 калькулятора
*/
void calcReplWithoutCapitalisation(DataDep* data);

/**
 @brief Функция, определяющая периодичность события
 @param str статус события в виде строки
 @return периодичность события в числовом виде
*/
int getStatus(char* str);

/**
 @brief Функция, подсчитывающая процет по вкладу
 @param str статус события в виде строки
 @return периодичность события в числовом виде
*/
double calculatePercent(int deposit_start, double rate, int period);

#endif  // SRC_CALCULATOR_HEADERS_DEPOSIT_H_
