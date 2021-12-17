#include "QtCore"
#include "QtGui"
#include "course.h"

course::course(QString courseNameInput, int courseCreditsInput, bool prereqInput, course *prereqCourseInput){
    courseName = courseNameInput;
    courseCredits = courseCreditsInput;
    prereq = prereqInput;
    prereqCourse = prereqCourseInput;
    prereqCourseName = prereqCourseInput->getCourseName();
}
course::course(QString courseNameInput, int courseCreditsInput, bool prereqInput){
    courseName = courseNameInput;
    courseCredits = courseCreditsInput;
    prereq = prereqInput;
}

QString course::getCourseName(){
    return courseName;
}
int course::getCourseCredits(){
    return courseCredits;
}
bool course::isPrereq(){
    return prereq;
}
QString course::getPrereqCourseName(){
    return prereqCourseName;
}
course course::getPreqCourse(){
    return *prereqCourse;
}
QString semester::getSemesterName(){
    return semesterName;
}
int semester::getSemesterYear(){
    return semesterYear;
}
QVector<course> semester::getSemesterCourses(){
    return semesterCourses;
}

bool courseContainer::isCourseInContainer(QString courseNameToSearch){
    for(int i=0; i < courseVector.size(); i++){
        if(courseVector[i].getCourseName() == courseNameToSearch){
            return true;
        }
    }
    return false;
}
course courseContainer::findCourseInContainer(QString courseNameToSearch){
    for(int i=0; i < courseVector.size(); i++){
        if(courseVector[i].getCourseName() == courseNameToSearch){
            return courseVector[i];
        }
    }
}
void courseContainer::addToCourseContainer(course *courseToInsert){
    courseVector.push_back(*courseToInsert);
}
void courseContainer::print(){
    for(int i=0; i < courseVector.size(); i++){
        if(!courseVector[i].isPrereq()){
            qDebug() << courseVector[i].getCourseName() << courseVector[i].getCourseCredits();
        }
       else if(courseVector[i].isPrereq()) {
            qDebug() << courseVector[i].getCourseName() << courseVector[i].getCourseCredits() << courseVector[i].isPrereq() << courseVector[i].getPrereqCourseName();
        }
    }
}
void courseContainer::removefromCourseContainer(QString courseNameToRemove){
    qDebug() << " ";
    int courseLocation = 0;
    for(int i=0;i<courseVector.size();i++){
        if(courseNameToRemove == courseVector[i].getCourseName()){
            courseLocation = i;
        }
    }
    courseVector.remove(courseLocation);
}



