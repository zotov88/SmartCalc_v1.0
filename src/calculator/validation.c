#include "headers/validation.h"

#include "headers/stack.h"

int isValid(const char *str) {
  int status = 0;
  char c;
  int index = 0;
  while ((c = str[index]) != '\0') {
    status = 0;
    status += isDigit(c) && checkDigit(str, index);
    status += isX(c) && checkX(str, index);
    status += isOperator(c) && checkOperator(str, index);
    status += isUnar(c) && checkUnar(str, index);
    status += isLBracket(c) && checkLBraket(str, index);
    status += isRBracket(c) && checkRBraket(str, index);
    status += isPow(c) && checkPow(str, index);
    status += isPoint(c) && checkPoint(str, index);
    if (isMod(str, index) && checkMod(str, index)) {
      status++;
      index += 2;
    }
    char fun[5] = "";
    if (isFunc(str, index, fun) && chekFunc(str, index, index + strlen(fun))) {
      status++;
      index += strlen(fun) - 1;
    }
    index++;
    if (!status) break;
  }
  return isBraketsValid(str) && isBraketsNotEmpty(str) ? status : 0;
}

int isBraketsValid(const char *str) {
  int result = FAILURE;
  Stack *stack = NULL;
  char c;
  while ((c = *str) != '\0') {
    if (c == '(') {
      stack = push_c(stack, ')');
    }
    if (c == ')' && (isEmpty(stack) || pop_c(&stack) != c)) {
      break;
    }
    str++;
  }
  if (isNoMoreBrakets(str) && isEmpty(stack)) {
    result = SUCCESS;
  } else {
    destroy(stack);
  }
  return result;
}

int isNoMoreBrakets(const char *str) {
  return strchr(str, ')') == NULL && strchr(str, '(') == NULL;
}

int isBraketsNotEmpty(const char *str) { return strstr(str, "()") == NULL; }

int isDigit(char c) { return c >= '0' && c <= '9'; }

int isX(char c) { return c == 'x'; }

int isOperator(char c) { return strchr("+-*/", c) == NULL ? 0 : 1; }

int isUnar(char c) { return c == '+' || c == '-'; }

int isPow(char c) { return c == '^'; }

int isLBracket(char c) { return c == '('; }

int isRBracket(char c) { return c == ')'; }

int isPoint(int c) { return c == '.'; }

int isMod(const char *str, int index) {
  int result = -1;
  if (index >= 0 && index < (int)strlen(str)) {
    result = strncmp("mod", str + index, 3);
  }
  return result == 0 ? 1 : 0;
}

int isFunc(const char *str, int index, char *func) {
  subFu(str, index, func);
  return strcmp(func, "") != 0;
}

char *subFu(const char *str, int index, char *func) {
  char *functions[9] = {"sqrt", "cos",  "sin", "tan", "acos",
                        "asin", "atan", "ln",  "log"};
  for (int i = 0; i < 9; i++) {
    const char *stmp = str + index;
    if (strspn(functions[i], stmp) == strlen(functions[i]) &&
        !strncmp(stmp, functions[i], strlen(functions[i]))) {
      strcpy(func, functions[i]);
      break;
    }
  }
  return func;
}

int checkDigit(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0) {
    char l = str[index - 1];
    left = isDigit(l) + (isOperator(l) || isUnar(l)) + isLBracket(l) +
           isPow(l) + isPoint(l) + isMod(str, index - 3) - isX(l);
  }
  if (index != length - 1) {
    char r = str[index + 1];
    right = isDigit(r) + isOperator(r) + isRBracket(r) + isPow(r) + isPoint(r) +
            isMod(str, index + 1) - isLBracket(r) - isX(r) - isFirstLetFunc(r);
  }
  return left + right > 0 || length == 1;
}

int checkX(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0) {
    char l = str[index - 1];
    left = (isOperator(l) || isUnar(l)) + isLBracket(l) + isPow(l) +
           isMod(str, index - 3);
  }
  if (index != length - 1) {
    char r = str[index + 1];
    right = isOperator(r) + isRBracket(r) + isPow(r) + isMod(str, index + 1) -
            isLBracket(r) - isX(r) - isFirstLetFunc(r);
  }
  return left + right > 0 || length == 1;
}

int checkOperator(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0) {
    char l = str[index - 1];
    left = isDigit(l) + isX(l) + isRBracket(l);
  }
  if (index != length - 1) {
    char r = str[index + 1];
    right = isDigit(r) + isX(r) + isLBracket(r) + isFirstLetFunc(r) + isUnar(r);
  }
  return left + right == 2;
}

int checkPoint(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0 && index != length - 1) {
    char l = str[index - 1];
    char r = str[index + 1];
    left = isDigit(l);
    right = isDigit(r);
  }
  int result = left + right;
  result = isPointExist(str, index + 1) ? 0 : result;
  return result == 2;
}

int checkMod(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0) {
    char l = str[index - 1];
    left = isDigit(l) + isX(l) + isRBracket(l);
  }
  if (index + 2 != length - 1) {
    char r = str[index + 3];
    right = isDigit(r) + isX(r) + isLBracket(r) + isFirstLetFunc(r) + isUnar(r);
  }
  return left + right == 2;
}

int checkPow(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0 && index != length - 1) {
    char l = str[index - 1];
    char r = str[index + 1];
    left = isDigit(l) + isX(l) + isRBracket(l);
    right = isDigit(r) + isX(r) + isLBracket(r) + isFirstLetFunc(r) + isUnar(r);
  }
  return left + right == 2;
}

int checkLBraket(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0 && index != length - 1) {
    char l = str[index - 1];
    left = isOperator(l) + isLBracket(l) + isPow(l) + isMod(str, index - 3) -
           isRBracket(l);
  }
  if (index != length - 1) {
    char r = str[index + 1];
    right = isDigit(r) + isX(r) + isLBracket(r) + isFirstLetFunc(r) + isUnar(r);
  }
  return left + right > 0;
}

int checkRBraket(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0) {
    char l = str[index - 1];
    left = isDigit(l) + isX(l) + isRBracket(l);
  }
  if (index != length - 1 && index != 0) {
    char r = str[index + 1];
    right = isOperator(r) + isRBracket(r) + isPow(r) + isMod(str, index + 1) -
            isLBracket(r);
  }
  return left + right > 0;
}

int checkUnar(const char *str, int index) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (index != 0) {
    int l = str[index - 1];
    left = isOperator(l) + isLBracket(l) + isMod(str, index - 3) - isDigit(l) -
           isX(l) - isRBracket(l);
  }
  if (index != length - 1) {
    int r = str[index + 1];
    right = isDigit(r) + isX(r) + isLBracket(r) + isFirstLetFunc(r) + isPow(r);
  }
  int result = left + right;
  result = checkOperatorsLandR(str, index) ? result : 0;
  return result > 0;
}

int chekFunc(const char *str, int start, int end) {
  int left = 0;
  int right = 0;
  int length = strlen(str);
  if (start != 0) {
    char l = str[start - 1];
    left = isOperator(l) + isPow(l) + isLBracket(l) + isMod(str, start - 3);
  }
  if (end != length - 1) {
    char r = str[end];
    right = isLBracket(r);
  }
  return left + right > 0;
}

int checkOperatorsLandR(const char *str, int index) {
  int result = SUCCESS;
  if (index - 1 >= 0 && index + 1 < (int)strlen(str)) {
    if ((isOperator(str[index - 1]) && isOperator(str[index - 2])) ||
        isOperator(str[index + 1])) {
      result = FAILURE;
    }
  }
  return result;
}

int isPointExist(const char *str, int index) {
  int result = FAILURE;
  if (index < (int)strlen(str)) {
    while (isDigit(str[index]) && str[index] != '\0') {
      index++;
    }
    result = (str[index] != '\0') ? isPoint(str[index]) : FAILURE;
  }
  return result;
}

int isFirstLetFunc(char c) {
  return strchr("cstal", c) == NULL ? FAILURE : SUCCESS;
}
