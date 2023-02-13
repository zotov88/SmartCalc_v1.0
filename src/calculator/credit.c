#include "headers/credit.h"

void creditCalc(double sum, int month, double rate, int type, DataCred* data) {
  if (type == 1) {
    anuitet(sum, month, rate, data);
  } else {
    different(sum, month, rate, data);
  }
}

void anuitet(double sum, int month, double rate, DataCred* data) {
  double R_m = rate / 12 / 100;
  double K_a = R_m * pow(1 + R_m, month) / (pow(1 + R_m, month) - 1);
  data->payment = sum * K_a;
  data->total_payment = data->payment * month;
  data->overpayment = data->total_payment - sum;
}

void different(double sum, int month, double rate, DataCred* data) {
  double main_deb_month = sum / month;
  data->first_payment = 0;
  data->last_payment = 0;
  data->total_payment = 0;
  data->overpayment = 0;
  double main_rest = sum;
  rate /= 100;
  for (int i = 0; i < month; i++) {
    double percent_month = 0;
    percent_month = main_rest * rate * MONTH / 365;
    double platez = main_deb_month + percent_month;
    if (i == 0) {
      data->first_payment = platez;
    }
    if (i == month - 1) {
      data->last_payment = platez;
    }
    data->total_payment += platez;
    main_rest -= main_deb_month;
  }
  data->overpayment = data->total_payment - sum;
}
