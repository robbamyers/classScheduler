#ifndef COURSE_H
#define COURSE_H
#include "QtCore"
#include "QtGui"

// course class declaration
class course{
public:
    course(QString courseNameInput, int courseCreditsInput, bool prereqInput, course *prereqCourseInput);
    course(QString courseNameInput, int courseCreditsInput, bool prereqInput);
    QString getCourseName();
    int getCourseCredits();
    bool isPrereq();
    QString getPrereqCourseName();
    course getPreqCourse();
private:
    QString courseName;
    int courseCredits;
    bool prereq;
    course *prereqCourse;
    QString prereqCourseName;
};

// semester class declaration
class semester
{
public:
    semester(QString semesterNameInput, int semesterYearInput);
    void addCourseToSemester(course courseToAdd);
    QString getSemesterName();
    int getSemesterYear();
    QVector<course> getSemesterCourses();
private:
    QString semesterName;
    int semesterYear;
    QVector<course> semesterCourses;
};

// career class declaration
class career{
public:
    career();
    void addSemesterToCareer(semester* semesterToAdd);
    QVector<semester> getCareerSemesters();
    QDate getAnticipatedGraduationDate();
private:
    QVector<semester> careerSemesters;
    QDate anticipatedGraduationDate;
};

// course container class declaration
class courseContainer{
public:
    bool isCourseInContainer(QString courseNameToSearch);
    course findCourseInContainer(QString courseNameToSearch);
    void addToCourseContainer(course *courseToInsert);
    void removefromCourseContainer(QString courseNameToRemove);
    void print();
private:
    QVector<course> courseVector;
};




#endif // COURSE_H

