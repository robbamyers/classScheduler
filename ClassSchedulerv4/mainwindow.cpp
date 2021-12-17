#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "course.h"
#include "QtCore"
#include "QtGui"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setRequiredToHidden();
    sessionCourseContainer = new courseContainer;
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_prerequisiteBool_toggled(bool checked)
{
    ui->prerequisiteCourseDropdown->setHidden(!checked);
    ui->prerequisiteLabel->setHidden(!checked);
    if(ui->prereqCourseRequired->isHidden() == false){
        ui->prereqCourseRequired->setHidden(true);
    }
}
void MainWindow::addItemToTable(course* courseToAdd){
    QString boolean;
    if(courseToAdd->isPrereq() == true){
        boolean = "Yes";
    }
    else{
        boolean = "No";
    }
    int currentRow = ui->classListTable->rowCount();
    ui->classListTable->insertRow(currentRow);
    ui->classListTable->setItem(currentRow,0, new QTableWidgetItem(courseToAdd->getCourseName()));
    ui->classListTable->setItem(currentRow,1, new QTableWidgetItem(QString::number(courseToAdd->getCourseCredits())));
    ui->classListTable->setItem(currentRow,2, new QTableWidgetItem(boolean));
    ui->classListTable->setItem(currentRow,3, new QTableWidgetItem(courseToAdd->getPrereqCourseName()));

}
void MainWindow::setRequiredToHidden()
{
    ui->prerequisiteLabel->setHidden(true);
    ui->prereqBoolRequired->setHidden(true);
    ui->prereqCourseRequired->setHidden(true);
    ui->prerequisiteCourseDropdown->setHidden(true);
}
void MainWindow::addToComboBox(course* courseToAdd){
    ui->prerequisiteCourseDropdown->addItem(courseToAdd->getCourseName());
}
void MainWindow::on_addClassButton_clicked()
{
    if(ui->prerequisiteBool->isChecked() == false){
        ui->prereqCourseRequired->setHidden(true);
        course tempCourse(ui->classNameInput->text(), ui->creditsInput->text().toInt(), ui->prerequisiteBool->isChecked());
        sessionCourseContainer->addToCourseContainer(&tempCourse);
        addItemToTable(&tempCourse);
        addToComboBox(&tempCourse);
    }
    else if(ui->prerequisiteBool->isChecked() == true && ui->prerequisiteCourseDropdown->currentText() == "--None--"){
        ui->prereqCourseRequired->setHidden(false);
    }
    else if(ui->prerequisiteBool->isChecked() == false && ui->prerequisiteCourseDropdown->currentText() != "--None--"){
        ui->prereqCourseRequired->setHidden(false);
    }
    else if(ui->prerequisiteBool->isChecked() == true && ui->prerequisiteCourseDropdown->currentText() != "--None--"){
        if(sessionCourseContainer->isCourseInContainer(ui->prerequisiteCourseDropdown->currentText())){
            ui->prereqCourseRequired->setHidden(true);
            course prereqCourse = sessionCourseContainer->findCourseInContainer(ui->prerequisiteCourseDropdown->currentText());
            course tempCourse1(ui->classNameInput->text(), ui->creditsInput->text().toInt(), ui->prerequisiteBool->isChecked(), &prereqCourse);
            sessionCourseContainer->addToCourseContainer(&tempCourse1);
            addItemToTable(&tempCourse1);
            addToComboBox(&tempCourse1);
        }
    }
    sessionCourseContainer->print();
}


void MainWindow::on_removeButton_clicked()
{
    sessionCourseContainer->removefromCourseContainer(ui->classListTable->item(ui->classListTable->currentRow(),0)->text());
    ui->prerequisiteCourseDropdown->removeItem(ui->prerequisiteCourseDropdown->findText(ui->classListTable->item(ui->classListTable->currentRow(),0)->text()));
    ui->classListTable->removeRow(ui->classListTable->currentRow());
    sessionCourseContainer->print();
}


