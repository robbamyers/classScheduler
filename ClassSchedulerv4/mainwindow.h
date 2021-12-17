#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QtCore"
#include "QtGui"
#include "course.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_prerequisiteBool_toggled(bool checked);
    void addItemToTable(course* courseToAdd);
    void setRequiredToHidden();
    void addToComboBox(course* courseToAdd);
    void on_addClassButton_clicked();
    void on_removeButton_clicked();

private:
    Ui::MainWindow *ui;
    courseContainer *sessionCourseContainer;
};
#endif // MAINWINDOW_H
