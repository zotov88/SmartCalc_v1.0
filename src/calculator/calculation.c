#include "headers/calculation.h"

double calculation(const char* rpn, double x) {
  Stack* stack = {0};
  char c;
  while ((c = *rpn) != '\0') {
    if (isDigit(c)) stack = push_d(stack, getDigit(&rpn));
    if (isX(c)) stack = push_d(stack, x);
    if (isUnarMinus(c)) stack->d *= -1;
    if (isBinarOperator(c)) stack = binarCalc(*rpn, stack);
    if (isUnarOperator(c)) stack = unarCalc(*rpn, stack);
    rpn++;
  }
  double result = stack->d;
  destroy(stack);
  return result;
}

double getDigit(const char** rpn) {
  char num[300] = {0};
  size_t len = strspn(*(rpn), "0123456789.");
  strncpy(num, *(rpn), len);
  *(rpn) += len;
  return atof(num);
}

int isUnarMinus(char c) { return c == '~'; }

Stack* binarCalc(char c, Stack* stack) {
  double d2 = pop_d(&stack);
  double d1 = pop_d(&stack);
  if (c == '+') stack = push_d(stack, d1 + d2);
  if (c == '-') stack = push_d(stack, d1 - d2);
  if (c == '*') stack = push_d(stack, d1 * d2);
  if (c == '/') stack = push_d(stack, d1 / d2);
  if (c == '^') stack = push_d(stack, pow(d1, d2));
  if (c == 'm') stack = push_d(stack, fmod(d1, d2));
  return stack;
}

Stack* unarCalc(char c, Stack* stack) {
  double d = pop_d(&stack);
  if (c == 's') stack = push_d(stack, sin(d));
  if (c == 'c') stack = push_d(stack, cos(d));
  if (c == 't') stack = push_d(stack, tan(d));
  if (c == 'S') stack = push_d(stack, asin(d));
  if (c == 'C') stack = push_d(stack, acos(d));
  if (c == 'T') stack = push_d(stack, atan(d));
  if (c == 'l') stack = push_d(stack, log(d));
  if (c == 'L') stack = push_d(stack, log10(d));
  if (c == 'q') stack = push_d(stack, sqrt(d));
  return stack;
}

int isBinarOperator(char c) {
  return strchr(UNAR_OP, c) == NULL ? FAILURE : SUCCESS;
}

int isUnarOperator(char c) {
  return strchr(BINAR_OP, c) == NULL ? FAILURE : SUCCESS;
}
