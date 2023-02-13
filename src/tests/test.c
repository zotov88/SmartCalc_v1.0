#include <check.h>

#include "../calculator/headers/calculation.h"
#include "../calculator/headers/credit.h"
#include "../calculator/headers/deposit.h"

#ifdef NAN
/* NAN is supported */
#endif

double getResult(char* expression) {
  double result = 0;
  if (isValid(expression)) {
    char* rpn = parcer(expression);
    result = calculation(rpn, 0);
    free(rpn);
  }
  return result;
}

START_TEST(test_1) {
#line 20
  char* expression = "-12.3++44--0.123/(60mod21*2.5)";
  ck_assert_double_eq(getResult(expression), 31.70273333333333);
}
END_TEST

START_TEST(test_2) {
#line 24
  char* expression = "-12.3++44--0.123/(60.mod21*2.5)";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_3) {
#line 28
  char* expression = "sosinus(x)";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_4) {
#line 32
  char* expression = "cos(1)";
  ck_assert_double_eq(getResult(expression), 0.5403023058681398);
}
END_TEST

START_TEST(test_5) {
#line 36
  char* expression = "-(4.01^sqrt(81))";
  ck_assert_double_eq(getResult(expression), -268101.5677574709);
}
END_TEST

START_TEST(test_6) {
#line 40
  char* expression = "-(4.01^-sqrt(81))";
  ck_assert_double_eq(getResult(expression), -0.000003729929699272093);
}
END_TEST

START_TEST(test_7) {
#line 44
  char* expression = "1---1";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_8) {
#line 48
  char* expression = "1+1/";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_9) {
#line 52
  char* expression = "*6+5";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_10) {
#line 56
  char* expression = "()+(45+1)";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_11) {
#line 60
  char* expression = "(3*(6000-(223.12/(2^(1+sqrt(16))))))";
  ck_assert_double_eq(getResult(expression), 17979.0825);
}
END_TEST

START_TEST(test_12) {
#line 64
  char* expression = "-(3*(6000-(223.12/(2^(1+sqrt(16))))))";
  ck_assert_double_eq(getResult(expression), -17979.0825);
}
END_TEST

START_TEST(test_13) {
#line 68
  char* expression = "(3*(6000-(223.12/(2^(1+sqrt(16))))))*0";
  ck_assert_double_eq(getResult(expression), 0);
}
END_TEST

START_TEST(test_14) {
#line 72
  char* expression = "(3*(6000-((223.12/(2^(1+sqrt(16))))))";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_15) {
#line 76
  char* expression = "acos(1)";
  ck_assert_double_eq(getResult(expression), 0);
}
END_TEST

START_TEST(test_16) {
#line 80
  Stack* stack = {0};
  char c = pop_c(&stack);
  destroy(stack);
  ck_assert_int_eq(c, 0);
}
END_TEST

START_TEST(test_17) {
#line 86
  char* expression = "-sin(cos(tan(sqrt(6mod2*(-2-4)))))";
  ck_assert_double_eq(getResult(expression), -0.8414709848078965);
}
END_TEST

START_TEST(test_18) {
#line 90
  char* expression = "3^3";
  ck_assert_double_eq(getResult(expression), 27);
}
END_TEST

START_TEST(test_19) {
#line 94
  char* expression = "3^-3";
  ck_assert_double_eq(getResult(expression), 0.037037037037037035);
}
END_TEST

START_TEST(test_20) {
#line 98
  char* expression = "-3^3";
  ck_assert_double_eq(getResult(expression), -27);
}
END_TEST

START_TEST(test_21) {
#line 102
  char* expression = "-3^-3";
  ck_assert_double_eq(getResult(expression), -0.037037037037037035);
}
END_TEST

START_TEST(test_22) {
#line 106
  char* expression = "-(-3^-3)";
  ck_assert_double_eq(getResult(expression), 0.037037037037037035);
}
END_TEST

START_TEST(test_23) {
#line 110
  char* expression = "1111111111111111111111111111111111111111111+1";
  ck_assert_double_eq(getResult(expression), 1.1111111111111111e+42);
}
END_TEST

START_TEST(test_24) {
#line 114
  char* expression = "6/2*(1+2)";
  ck_assert_double_eq(getResult(expression), 9);
}
END_TEST

START_TEST(test_25) {
#line 118
  char* expression = "1111111111111111111111111+1111111111111111111111111";
  ck_assert_double_eq(getResult(expression), 2.2222222222222222e+24);
}
END_TEST

START_TEST(test_26) {
#line 122
  ck_assert_double_eq_tol(getResult("1-0.7"), 0.3, 1e-3);
}
END_TEST

START_TEST(test_27) {
#line 125
  ck_assert_int_eq(isValid("sin(x)"), 1);
}
END_TEST

START_TEST(test_28) {
#line 128
  ck_assert_int_eq(isValid("1"), 1);
}
END_TEST

START_TEST(test_29) {
#line 131
  char* expression = "";
  ck_assert_int_eq(isValid(expression), 0);
}
END_TEST

START_TEST(test_30) {
#line 135
  ck_assert_int_eq(isValid("1x"), 0);
}
END_TEST

START_TEST(test_31) {
#line 138
  ck_assert_int_eq(isValid("1+2(3)"), 0);
}
END_TEST

START_TEST(test_32) {
#line 141
  ck_assert_int_eq(isValid("3-xsin(3)"), 0);
}
END_TEST

START_TEST(test_33) {
#line 144
  ck_assert_int_eq(isValid("x"), 1);
}
END_TEST

START_TEST(test_34) {
#line 147
  ck_assert_int_eq(isValid("123"), 1);
}
END_TEST

START_TEST(test_35) {
#line 150
  ck_assert_int_eq(isValid("xx"), 0);
}
END_TEST

START_TEST(test_36) {
#line 153
  ck_assert_int_eq(isValid("3*-xsin(3)"), 0);
}
END_TEST

START_TEST(test_37) {
#line 156
  ck_assert_int_eq(isValid("3-/xsin(x)"), 0);
}
END_TEST

START_TEST(test_38) {
#line 159
  ck_assert_int_eq(isValid("--"), 0);
}
END_TEST

START_TEST(test_39) {
#line 162
  ck_assert_int_eq(isValid("(-)"), 0);
}
END_TEST

START_TEST(test_40) {
#line 165
  ck_assert_int_eq(isValid("3^x"), 1);
}
END_TEST

START_TEST(test_41) {
#line 168
  ck_assert_int_eq(isValid("(12mod^2)"), 0);
}
END_TEST

START_TEST(test_42) {
#line 171
  ck_assert_int_eq(isValid("(-12(1))"), 0);
}
END_TEST

START_TEST(test_43) {
#line 174
  ck_assert_int_eq(isValid("(11)3"), 0);
}
END_TEST

START_TEST(test_44) {
#line 177
  ck_assert_int_eq(isValid("(11)x"), 0);
}
END_TEST

START_TEST(test_45) {
#line 180
  ck_assert_int_eq(isValid("-1-"), 0);
}
END_TEST

START_TEST(test_46) {
#line 183
  ck_assert_int_eq(isValid("x1"), 0);
}
END_TEST

START_TEST(test_47) {
#line 186
  ck_assert_int_eq(isValid("cos(x)1"), 0);
}
END_TEST

START_TEST(test_48) {
#line 189
  ck_assert_int_eq(isValid("cos(1)x"), 0);
}
END_TEST

START_TEST(test_49) {
#line 192
  DataCred data = {0};
  creditCalc(300000, 24, 20, 1, &data);
  ck_assert_double_eq_tol(data.overpayment, 66449.8, 1e-1);
  ck_assert_double_eq_tol(data.payment, 15268.7, 1e-1);
  ck_assert_int_eq(data.total_payment, 366449);
}
END_TEST

START_TEST(test_50) {
#line 199
  DataCred data = {0};
  creditCalc(300000, 24, 20, 2, &data);
  ck_assert_double_eq_tol(data.overpayment, 62500.1, 1e-1);
  ck_assert_int_eq(data.first_payment, 17500);
  ck_assert_double_eq_tol(data.last_payment, 12708.3, 1e-1);
  ck_assert_int_eq(data.total_payment, 362500);
}
END_TEST

START_TEST(test_51) {
#line 207
  DataDep data = {0};
  depositCalc(100000, 12, 20, 7, "ежемесячно", "в конце", WORD, 4, 5, &data);
  ck_assert_int_eq(data.percent, 21939);
  ck_assert_int_eq(data.deposit_end, 121939);
  ck_assert_int_eq(data.tax, 0);
}
END_TEST

START_TEST(test_52) {
#line 214
  DataDep data = {0};
  depositCalc(200000, 10, 25, 7.5, "ежемесячно", "в конце", "ежемесячно", 11,
              1000, &data);
  ck_assert_double_eq_tol(data.percent, 57018.5, 1e-1);
  ck_assert_int_eq(data.deposit_end, 257018);
  ck_assert_int_eq(data.tax, 0);
}
END_TEST

START_TEST(test_53) {
#line 222
  DataDep data = {0};
  depositCalc(300000, 18, 5, 7, WORD, "ежемесячно", "ежемесячно", 13, 1500,
              &data);
  ck_assert_double_eq_tol(data.percent, 23456.3, 1e-1);
  ck_assert_int_eq(data.deposit_end, 348956);
  ck_assert_int_eq(data.tax, 0);
}
END_TEST

START_TEST(test_54) {
#line 230
  DataDep data = {0};
  depositCalc(300000, 18, 15, 7, WORD, "ежемесячно", WORD, 8, 0, &data);
  ck_assert_double_eq_tol(data.percent, 64620.1, 1e-1);
  ck_assert_int_eq(data.deposit_end, 364620);
  ck_assert_int_eq(data.tax, 2880);
}
END_TEST

START_TEST(test_55) {
#line 237
  DataDep data = {0};
  depositCalc(300000, 18, 15, 7, "6 месяцев", "3 месяца", "1 год", 8, 0, &data);
  ck_assert_int_eq(data.percent, 72689);
  ck_assert_int_eq(data.deposit_end, 372689);
  ck_assert_int_eq(data.tax, 0);
}
END_TEST

START_TEST(test_56) {
#line 244
  DataDep data = {0};
  depositCalc(300000, 18, 15, 7, WORD, WORD, "3 месяца", 8, 0, &data);
  ck_assert_double_eq_tol(data.percent, 64620.1, 1e-1);
  ck_assert_int_eq(data.deposit_end, 364620);
  ck_assert_int_eq(data.tax, 2880);
}
END_TEST

int main(void) {
  Suite* s1 = suite_create("Core");
  TCase* tc1_1 = tcase_create("Core");
  SRunner* sr = srunner_create(s1);
  int nf;

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, test_1);
  tcase_add_test(tc1_1, test_2);
  tcase_add_test(tc1_1, test_3);
  tcase_add_test(tc1_1, test_4);
  tcase_add_test(tc1_1, test_5);
  tcase_add_test(tc1_1, test_6);
  tcase_add_test(tc1_1, test_7);
  tcase_add_test(tc1_1, test_8);
  tcase_add_test(tc1_1, test_9);
  tcase_add_test(tc1_1, test_10);
  tcase_add_test(tc1_1, test_11);
  tcase_add_test(tc1_1, test_12);
  tcase_add_test(tc1_1, test_13);
  tcase_add_test(tc1_1, test_14);
  tcase_add_test(tc1_1, test_15);
  tcase_add_test(tc1_1, test_16);
  tcase_add_test(tc1_1, test_17);
  tcase_add_test(tc1_1, test_18);
  tcase_add_test(tc1_1, test_19);
  tcase_add_test(tc1_1, test_20);
  tcase_add_test(tc1_1, test_21);
  tcase_add_test(tc1_1, test_22);
  tcase_add_test(tc1_1, test_23);
  tcase_add_test(tc1_1, test_24);
  tcase_add_test(tc1_1, test_25);
  tcase_add_test(tc1_1, test_26);
  tcase_add_test(tc1_1, test_27);
  tcase_add_test(tc1_1, test_28);
  tcase_add_test(tc1_1, test_29);
  tcase_add_test(tc1_1, test_30);
  tcase_add_test(tc1_1, test_31);
  tcase_add_test(tc1_1, test_32);
  tcase_add_test(tc1_1, test_33);
  tcase_add_test(tc1_1, test_34);
  tcase_add_test(tc1_1, test_35);
  tcase_add_test(tc1_1, test_36);
  tcase_add_test(tc1_1, test_37);
  tcase_add_test(tc1_1, test_38);
  tcase_add_test(tc1_1, test_39);
  tcase_add_test(tc1_1, test_40);
  tcase_add_test(tc1_1, test_41);
  tcase_add_test(tc1_1, test_42);
  tcase_add_test(tc1_1, test_43);
  tcase_add_test(tc1_1, test_44);
  tcase_add_test(tc1_1, test_45);
  tcase_add_test(tc1_1, test_46);
  tcase_add_test(tc1_1, test_47);
  tcase_add_test(tc1_1, test_48);
  tcase_add_test(tc1_1, test_49);
  tcase_add_test(tc1_1, test_50);
  tcase_add_test(tc1_1, test_51);
  tcase_add_test(tc1_1, test_52);
  tcase_add_test(tc1_1, test_53);
  tcase_add_test(tc1_1, test_54);
  tcase_add_test(tc1_1, test_55);
  tcase_add_test(tc1_1, test_56);

  srunner_run_all(sr, CK_ENV);
  nf = srunner_ntests_failed(sr);
  srunner_free(sr);

  return nf == 0 ? 0 : 1;
}
