#include "headers/parcer.h"

char* parcer(const char* expression) {
  Stack* stack = {0};
  char* rpn = calloc(512, sizeof(char));
  int i = 0;
  int j = 0;
  char c;
  while ((c = expression[i]) != '\0') {
    if (isLBracket(c)) {
      stack = push_c(stack, c);
    }
    if (isDigit(c) || isX(c)) {
      while (isDigit(c) || isPoint(c) || isX(c)) {
        rpn[j++] = c;
        c = expression[++i];
      }
      rpn[j++] = ' ';
    }
    if (isRBracket(c)) {
      while (stack != NULL && !isLBracket(peek_c(stack))) {
        rpn[j++] = pop_c(&stack);
      }
      pop_c(&stack);
    }
    if (c != '\0' && (isOperator(c) || isPow(c) || isMod(expression, i))) {
      if (isUnar(c) && checkUnar(expression, i)) {
        c = (c == '-') ? '~' : c;
      }
      if (peek_c(stack) == '\0' || isLBracket(peek_c(stack))) {
        stack = push_c(stack, c);
      } else {
        if (checkPriority(c, peek_c(stack))) {
          rpn[j++] = pop_c(&stack);
          rpn[j++] = (peek_c(stack) == '~') ? pop_c(&stack) : ' ';
          stack = push_c(stack, c);
        } else {
          stack = push_c(stack, c);
        }
      }
    }
    if (c != '\0' && isFirstLetFunc(c)) {
      char tmp[6] = {0};
      subFu(expression, i, tmp);
      stack = push_c(stack, getLetFun(tmp));
      i += strlen(tmp) - 1;
    }
    if (c == '\0') break;
    i++;
  }
  while (stack != NULL) {
    rpn[j++] = pop_c(&stack);
  }
  deleteExtraSpases(rpn);
  destroy(stack);
  return rpn;
}

void deleteExtraSpases(char* rpn) {
  char ptr[1000] = {0};
  strcpy(ptr, rpn);
  char* delim = strtok(ptr, " ");
  while (delim != NULL) {
    strcpy(rpn, delim);
    rpn += strlen(delim);
    *rpn++ = ' ';
    delim = strtok(NULL, " ");
  }
  *rpn = '\0';
}

char getLetFun(char* function) {
  char c = '\0';
  if (!strcmp(function, "sin")) c = 's';
  if (!strcmp(function, "cos")) c = 'c';
  if (!strcmp(function, "tan")) c = 't';
  if (!strcmp(function, "asin")) c = 'S';
  if (!strcmp(function, "acos")) c = 'C';
  if (!strcmp(function, "atan")) c = 'T';
  if (!strcmp(function, "ln")) c = 'l';
  if (!strcmp(function, "log")) c = 'L';
  if (!strcmp(function, "sqrt")) c = 'q';
  return c;
}

int checkPriority(char inExp, char inSt) {
  return getPriority(inExp) <= getPriority(inSt);
}

int getPriority(char c) {
  int result = 0;
  if (c == '*' || c == '/') result = 1;
  if (c == 'm') result = 2;
  if (isPow(c)) result = 3;
  if (isFirstLetFunc(c)) result = 4;
  if (c == '~') result = 5;
  return result;
}
