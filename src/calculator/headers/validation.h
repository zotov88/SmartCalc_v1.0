#ifndef SRC_CALCULATOR_HEADERS_VALIDATION_H_
#define SRC_CALCULATOR_HEADERS_VALIDATION_H_

enum { FAILURE, SUCCESS };

#include <stdio.h>
#include <string.h>

/**
 @brief Главная функция определения валидности выражения
 @details В функции агрегируются все посимвольные проверки. Если они успешно
 завершаются, проверяется валидность расстановки скобок
 @param str строка с выражением
 @return 1/0 в случае успеха/неудачи
*/
int isValid(const char *str);

/**
 @brief Функция проверки правильности расположения скобок
 @param str строка с выражением
 @return 1/0 в случае успеха/неудачи
*/
int isBraketsValid(const char *str);

/**
 @brief Функция проверки оставшихся скобок в выражении
 @details Алгоритм проверки валидности скобок предполагает проверку на наличие
 оставшихся скобок в выражении, если цикл прервался
 @param str строка с выражением
 @return 1/0 в случае успеха/неудачи
*/
int isNoMoreBrakets(const char *str);

/**
 @brief Функция проверки наличия "пустых" скобок
 @param str строка с выражением
 @return 1/0 в случае успеха/неудачи
*/
int isBraketsNotEmpty(const char *str);

/**
 @brief Функция проверки цифры
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isDigit(char c);

/**
 @brief Функция проверки x
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isX(char c);

/**
 @brief Функция проверки операторов +*-/
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isOperator(char c);

/**
 @brief Функция проверки унарных операторов +-
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isUnar(char c);

/**
 @brief Функция проверки оператора возведения в степень
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isPow(char c);

/**
 @brief Функция проверки открывающейся скобки
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isLBracket(char c);

/**
 @brief Функция проверки закрывающейся скобки
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isRBracket(char c);

/**
 @brief Функция проверки точки
 @param c символ из строки
 @return 1/0 в случае успеха/неудачи
*/
int isPoint(int c);

/**
 @brief Функция проверки оператора остатка от деления
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int isMod(const char *str, int index);

/**
 @brief Функция проверки функции (sin, cos ...)
 @param str выражение
 @param index индекс строки
 @param func указатель на хранилище для полученной функции из выражения
 @return 1/0 в случае успеха/неудачи
*/
int isFunc(const char *str, int index, char *func);

/**
 @brief Функция сверяет полученный отрезок из строки с массивом функций
 @param str выражение
 @param index индекс строки
 @param func указатель на хранилище для полученной функции из выражения
 @return указатель на хранилище для полученной функции
*/
char *subFu(const char *str, int index, char *func);

/**
 @brief Функция проверки валидности цифры
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkDigit(const char *str, int index);

/**
 @brief Функция проверки валидности 'x'
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkX(const char *str, int index);

/**
 @brief Функция проверки валидности оператора
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkOperator(const char *str, int index);

/**
 @brief Функция проверки валидности точки
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkPoint(const char *str, int index);

/**
 @brief Функция проверки валидности оператора mod
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkMod(const char *str, int index);

/**
 @brief Функция проверки валидности возведения степени
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkPow(const char *str, int index);

/**
 @brief Функция проверки валидности открывающейся скобки
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkLBraket(const char *str, int index);

/**
 @brief Функция проверки валидности закрывающейся скобки
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkRBraket(const char *str, int index);

/**
 @brief Функция проверки валидности унарных +/-
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkUnar(const char *str, int index);

/**
 @brief Функция проверки валидности названия функции
 @param str выражение
 @param start индекс первого символа функии в строке
 @param end индекс последнего символа функии в строке
 @return 1/0 в случае успеха/неудачи
*/
int chekFunc(const char *str, int start, int end);

/**
 @brief Функция проверки операторов справа и слева от унарных +/-
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int checkOperatorsLandR(const char *str, int index);

/**
 @brief Функция проверки наличия еще одной точки в числе
 @param str выражение
 @param index индекс строки
 @return 1/0 в случае успеха/неудачи
*/
int isPointExist(const char *str, int index);

/**
 @brief Функция проверки первой буквы фнкуции
 @param c выражение
 @return 1/0 в случае успеха/неудачи
*/
int isFirstLetFunc(char c);

#endif  // SRC_CALCULATOR_HEADERS_VALIDATION_H_
