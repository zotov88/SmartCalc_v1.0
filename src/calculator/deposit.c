#include "headers/deposit.h"

void depositCalc(double deposit_start, int period, double rate, double key_rate,
                 char* capital, char* payout, char* replenishment,
                 double tax_type, double replenish, DataDep* data) {
  data->deposit_start = deposit_start;
  data->period = period;
  data->rate = rate;
  data->key_rate = key_rate;
  data->capital = capital;
  data->payout = payout;
  data->replenishment = replenishment;
  data->tax_type = tax_type;
  data->replenish = replenish;

  data->percent = 0;
  data->deposit_end = data->deposit_start;
  data->tax = 0;

  if (!strcmp(data->capital, WORD)) {
    withoutCapitalisation(data);
  } else {
    withCapitalisation(data);
  }
}

void withCapitalisation(DataDep* data) {
  int period_capit = getStatus(data->capital);
  int period = 0;
  if (strcmp(data->replenishment, WORD) != 0) {
    period = getStatus(data->replenishment);
  }
  for (int i = period_capit; i <= data->period; i += period_capit) {
    if (strcmp(data->replenishment, WORD) != 0 && i >= period) {
      data->deposit_end += data->replenish;
    }
    data->deposit_end +=
        calculatePercent(data->deposit_end, data->rate, period_capit);
  }
  data->percent = data->deposit_end - data->deposit_start;
}

void withoutCapitalisation(struct DataDep* data) {
  data->percent =
      calculatePercent(data->deposit_start, data->rate, data->period);
  data->deposit_end = data->deposit_start + data->percent;
  if (strcmp(data->replenishment, WORD) != 0) {
    calcReplWithoutCapitalisation(data);
  }
  if (data->rate > data->key_rate) {
    calculateTax(data);
  }
}

void calculateTax(DataDep* data) {
  double tax_dif = 0;
  tax_dif = calculatePercent(data->deposit_start, data->key_rate, data->period);
  data->tax = data->tax_type / 100.0 * (data->percent - tax_dif);
  data->percent -= data->tax;
  data->deposit_end -= data->tax;
}

void calcReplWithoutCapitalisation(DataDep* data) {
  int period = getStatus(data->replenishment);
  double added_percent = 0;
  int additional_deposit = 0;
  for (int i = period; i < data->period; i += period) {
    additional_deposit += data->replenish;
    added_percent += calculatePercent(data->replenish, data->rate, i);
  }
  data->percent += added_percent;
  data->deposit_end += added_percent + additional_deposit;
}

int getStatus(char* str) {
  int res = 0;
  if (!strcmp(str, "ежемесячно")) {
    res = 1;
  } else if (!strcmp(str, "3 месяца")) {
    res = 3;
  } else if (!strcmp(str, "6 месяцев")) {
    res = 6;
  } else if (!strcmp(str, "1 год")) {
    res = 12;
  }
  return res;
}

double calculatePercent(int deposit_start, double rate, int period) {
  return deposit_start * rate / 100.0 * period * MONTH / 365;
}
