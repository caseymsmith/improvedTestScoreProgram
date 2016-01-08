#ifndef STUDENT_H
#define STUDENT_H
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;


class Student{

private:
    string first;
    string last;
    int score[5];
    double average;
    string grade;
    //private data members to keep all student information.

public:
    void setFirst(string fir);
    void setLast(string las);
    void setScores(int scor[]);
    void setAverage(double avg);
    void setGrade (string grad);

    string getFirst() const;
    string getLast() const;
    int getScores(int) const;
    double getAverage() const;
    string getGrade() const;

    friend istream& operator >> (istream& left, Student& right);
    friend ostream& operator << (ostream& right,const Student& left);

    Student& operator = (const Student & right);

    string calcLetterGrade();
    int calcAvg();

    Student(Student& student);
    Student(); //default constructor

    //member functions to assign and retrieve the student information

};

//This class wrapper around the class Student.
class StudentArray{

private:
    Student * array;
    int size;

public:
    StudentArray(int amount);
    int getSize() const;
    Student& get(int i);
    void set(int i, Student student);
    void readFile(ifstream& infile);
    ~StudentArray();
    StudentArray(ifstream&);
    void writeFile(ostream&);
    void sort();
    int highest(int&);
    void displayHighest(int, int, ostream&);
};

#endif
