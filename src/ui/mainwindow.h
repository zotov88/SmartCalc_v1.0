#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <creditcalc.h>
#include <depositcalc.h>

#include <QMainWindow>
#include <QTimer>
#include <QVector>

extern "C" {
#include "../calculator/headers/calculation.h"
}

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void getValueFromButtonFunc();
  void getValFromButtonOther();
  void on_bt_equal_clicked();
  void on_bt_AC_clicked();
  void on_bt_bcsp_clicked();
  void on_bt_up_clicked();
  void printGraph(const char *rpn);
  void on_depoz_triggered();
  void on_action_triggered();

 private:
  Ui::MainWindow *ui;
  Creditcalc *cWindow;
  Depositcalc *dWindow;
};

#endif  // MAINWINDOW_H
