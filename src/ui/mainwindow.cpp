#include "mainwindow.h"

#include "creditcalc.h"
#include "depositcalc.h"
#include "ui_creditcalc.h"
#include "ui_depositcalc.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);

  cWindow = new Creditcalc();
  dWindow = new Depositcalc();
  connect(cWindow, &Creditcalc::firstWindow, this, &MainWindow::show);
  connect(dWindow, &Depositcalc::secondWindow, this, &MainWindow::show);

  connect(ui->bt_one, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_two, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_three, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_four, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_five, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_six, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_seven, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_eight, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_nine, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_zero, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_x, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_mult, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_div, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_minus, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_plus, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_pow, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_mod, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_point, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_lb, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));
  connect(ui->bt_rb, SIGNAL(clicked()), this, SLOT(getValFromButtonOther()));

  connect(ui->bt_sin, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_cos, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_tan, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_asin, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_acos, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_atan, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_log, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_ln, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
  connect(ui->bt_sqrt, SIGNAL(clicked()), this, SLOT(getValueFromButtonFunc()));
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::getValFromButtonOther() {
  QPushButton *button = (QPushButton *)sender();
  ui->le_input->setText(ui->le_input->text() + button->text());
}

void MainWindow::getValueFromButtonFunc() {
  QPushButton *button = (QPushButton *)sender();
  ui->le_input->setText(ui->le_input->text() + button->text() + "(");
}

void MainWindow::on_bt_equal_clicked() {
  std::string expression = ui->le_input->text().toStdString();
  QString str = QString::fromStdString(expression);
  const char *exp = expression.c_str();
  if (isValid(exp)) {
    const char *rpn = parcer(exp);
    if (strchr(exp, 'x') != NULL) {
      printGraph(rpn);
    } else {
      double result = calculation(rpn, 0);
      ui->lb_output->setText(QString::number(result, 'g', 7));
      free((char *)rpn);
    }
  } else {
    ui->lb_output->setText("Error");
  }
}

void MainWindow::printGraph(const char *rpn) {
  ui->widget->clearGraphs();
  double h = 0.01;
  double result = 0;
  int N;
  int x_max = ui->sp_Xmax->value();
  int x_min = ui->sp_Xmin->value();
  int y_max = ui->sp_Ymax->value();
  int y_min = ui->sp_Ymin->value();

  ui->widget->xAxis->setRange(x_max, x_min);
  ui->widget->yAxis->setRange(y_max, y_min);
  N = (x_max - x_min) / h;
  QVector<double> x(N), y(N);

  double val = x_min;
  for (int i = 0; i < N; i++) {
    result = calculation(rpn, val);
    if (result <= y_min || result >= y_max) {
      val += h;
      x[i] = val;
      y[i] = NAN;
    } else {
      x[i] = val;
      y[i] = result;
      val += h;
    }
  }

  free((char *)rpn);
  ui->lb_output->setText("Function graph");
  ui->widget->addGraph();
  ui->widget->graph(0)->addData(x, y);
  ui->widget->replot();
}

void MainWindow::on_bt_AC_clicked() {
  ui->le_input->setText("");
  ui->lb_output->setText("");
  ui->widget->clearGraphs();
  ui->widget->replot();
}

void MainWindow::on_bt_bcsp_clicked() {
  QString str = ui->le_input->text();
  if (str.length() > 0) {
    ui->le_input->setText(str.remove(str.length() - 1, str.length()));
  }
}

void MainWindow::on_bt_up_clicked() {
  ui->le_input->setText(ui->lb_output->text());
}

void MainWindow::on_depoz_triggered() {
  cWindow->ui->sp_sum->setValue(1);
  cWindow->ui->sp_month->setValue(1);
  cWindow->ui->db_sp_percent->setValue(1);
  cWindow->ui->le_total->setText("");
  cWindow->ui->le_overpayment->setText("");
  cWindow->ui->le_payment->setText("");
  cWindow->ui->le_payment_first->setText("");
  cWindow->ui->le_payment_last->setText("");
  cWindow->ui->le_payment_first->setVisible(false);
  cWindow->ui->label_6->setVisible(false);
  cWindow->ui->le_payment_last->setVisible(false);
  cWindow->ui->label_7->setVisible(false);
  cWindow->ui->le_payment->setVisible(false);
  cWindow->ui->label_5->setVisible(false);

  cWindow->show();
}

void MainWindow::on_action_triggered() { dWindow->show(); }
