#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include "QLabel"
#include <math.h>
int status=0;
double log_first;
double logMain_first=0;
double logDigit_first=0;
double Stepen1;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pushButton0,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton1,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton2,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton3,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton4,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton5,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton6,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton7,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton8,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton9,SIGNAL(clicked()),this,SLOT(digits_numbers()));
    connect(ui->pushButton_plus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_minus,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_delenie,SIGNAL(clicked()),this,SLOT(math_operations()));
    connect(ui->pushButton_umonzhenie,SIGNAL(clicked()),this,SLOT(math_operations()));

    ui->pushButton_plus->setCheckable(true);
    ui->pushButton_minus->setCheckable(true);
    ui->pushButton_delenie->setCheckable(true);
    ui->pushButton_umonzhenie->setCheckable(true);
    ui->pushButton_stepen->setCheckable(true);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::digits_numbers()
{
    if((status==0)||(status==2)){
   QPushButton *button= (QPushButton *) sender();
   double all_numbers;
   QString new_label;
   all_numbers=(ui->Log_Digit->text()+button->text()).toDouble();
   new_label=QString::number(all_numbers,'g',15);
   ui->Log_Digit->setText(new_label);
   logMain_first=all_numbers;
}
    if((status==1)||(status==3))
    {
        QPushButton *button= (QPushButton *) sender();
        double all_numbers;
        QString new_label;
        all_numbers=(ui->Log_Main->text()+button->text()).toDouble();
        new_label=QString::number(all_numbers,'g',15);
        ui->Log_Main->setText(new_label);
        logDigit_first=all_numbers;
    }
    if(status==-1)
    {
        QPushButton *button= (QPushButton *) sender();
        double all_numbers;
        QString new_label;
        all_numbers=(ui->Stepen->text()+button->text()).toDouble();
        new_label=QString::number(all_numbers,'g',15);
        ui->Stepen->setText(new_label);
        Stepen1=all_numbers;
    }

}

void MainWindow::on_pushButtonVvod_clicked()
{
    status=status+1;
}


void MainWindow::math_operations()
{
  QPushButton *button= (QPushButton *) sender();
  log_first= log(logMain_first) / log(logDigit_first);
  logMain_first=0; logDigit_first=0;
  ui->Log_Digit->setText("0");
  ui->Log_Main->setText("0");
  button  ->setChecked(true);
}

void MainWindow::on_pushButton_stepen_clicked()
{
  QPushButton *button= (QPushButton *) sender();
  log_first= log(logMain_first) / log(logDigit_first);
  ui->Kryshka->setText("^");
  status=-1;
  button -> setChecked(true);
}
void MainWindow::on_pushButton_equal_clicked()
{
   double labelNumber,log_second;
   QString new_label;
   log_second=log(logMain_first) / log(logDigit_first);
   if((logMain_first==0)||(logDigit_first==0)||(logDigit_first==1)){
       ui->Kryshka->setText("");
       ui->Stepen->setText("");
       ui->Log_Name->setText("");
       ui->Log_Digit->setText("");
       ui->Log_Main->setText("");
       ui->result_show->setText("ERROR");
       status=-99;
   } else
   if(ui->pushButton_plus->isChecked())
   {
       labelNumber=log_first+log_second;
       new_label=QString::number(labelNumber,'g',15);
       ui->Log_Digit->setText("");
       ui->Log_Name->setText("");
       ui->Log_Main->setText("");
       ui->result_show->setText(new_label);
       ui->pushButton_plus->setChecked(false);
       status=-3;
   } else if(ui->pushButton_minus->isChecked())
   {
       labelNumber=log_first-log_second;
       new_label=QString::number(labelNumber,'g',15);
       ui->Log_Digit->setText("");
       ui->Log_Name->setText("");
       ui->Log_Main->setText("");
       ui->result_show->setText(new_label);
       ui->pushButton_minus->setChecked(false);
       status=-3;
   }
   else if(ui->pushButton_delenie->isChecked())
      {
       if(log_second!=0){
          labelNumber=log_first/log_second;
          new_label=QString::number(labelNumber,'g',15);
          ui->Log_Digit->setText("");
          ui->Log_Name->setText("");
          ui->Log_Main->setText("");
          ui->result_show->setText(new_label);
          ui->pushButton_delenie->setChecked(false);
          status=-3;
       }
       else
       {
           ui->Log_Digit->setText("");
           ui->Log_Name->setText("");
           ui->Log_Main->setText("");
           ui->result_show->setText("ERROR");
           ui->pushButton_delenie->setChecked(false);
       }
      }
   else if(ui->pushButton_umonzhenie->isChecked())
      {
          labelNumber=log_first*log_second;
          new_label=QString::number(labelNumber,'g',15);
          ui->Log_Digit->setText("");
          ui->Log_Name->setText("");
          ui->Log_Main->setText("");
          ui->result_show->setText(new_label);
          ui->pushButton_umonzhenie->setChecked(false);
          status=-3;
      }
   else if(ui->pushButton_stepen->isChecked())
      {
          labelNumber=pow(log_first,Stepen1);
          new_label=QString::number(labelNumber,'g',15);
          ui->Log_Digit->setText("");
          ui->Log_Name->setText("");
          ui->Log_Main->setText("");
          ui->Kryshka->setText("");
          ui->Stepen->setText("");
          ui->result_show->setText(new_label);
          ui->pushButton_stepen->setChecked(false);
          status=-3;
      }
   else if((!(ui->pushButton_stepen->isChecked()))||(!(ui->pushButton_minus->isChecked()))||(!(ui->pushButton_plus->isChecked()))||(!(ui->pushButton_umonzhenie->isChecked()))||(!(ui->pushButton_delenie->isChecked())))
   {
       log_first= log(logMain_first) / log(logDigit_first);
       labelNumber=log_first;
       new_label=QString::number(labelNumber,'g',15);
       ui->Log_Digit->setText("");
       ui->Log_Name->setText("");
       ui->Log_Main->setText("");
       ui->result_show->setText(new_label);
       status=-3;
   }

}

void MainWindow::on_pushButton_AC_clicked()
{
    ui->pushButton_stepen->setChecked(false);
    ui->pushButton_umonzhenie->setChecked(false);
    ui->pushButton_delenie->setChecked(false);
    ui->pushButton_minus->setChecked(false);
    ui->pushButton_plus->setChecked(false);
    ui->result_show->setText("");
    ui->Kryshka->setText("");
    ui->Stepen->setText("");
    ui->Log_Name->setText("Log");
    ui->Log_Digit->setText("0");
    ui->Log_Main->setText("0");
     logMain_first=0;
     logDigit_first=0;
    status=0;
}

void MainWindow::on_pushButtontochka_clicked()
    {
       if((status==0)||(status==2))
       {
           if(!( ui->Log_Digit->text().contains('.')))
        ui->Log_Digit->setText(ui->Log_Digit->text()+".");
       }
        if((status==1)||(status==3))
        {
            if(!( ui->Log_Main->text().contains('.')))
         ui->Log_Main->setText(ui->Log_Main->text()+".");
        }
        if(status==-1)
        {
            if(!( ui->Stepen->text().contains('.')))
         ui->Stepen->setText(ui->Stepen->text()+".");
        }

    }

