//This program will read students' names and their five test scores from a data file, calculate the
//average of the five test score and determine their letter grade based on the average, and then outputs
//students' names, their average test score and the relevant grade (A, B, C, D, or F) according to the
//alphabetical order of their last names (or if their last name are the same, sort according to their first
//names). The program will also find and print the average test score of the class, and highest test score and
//the name(s) of the students having the highest test score.

//Casey Smith
//May 10, 2015

#include "implementation.h"

const string FILE_PATH = "/Users/Casey/Documents/";

int main() {


    ifstream infile;
    ofstream outfile;

    infile.open(FILE_PATH+"grade.dat");
    outfile.open(FILE_PATH+"prog3.out");

    StudentArray students(infile);
    students.sort();
    students.writeFile(cout);

    students.writeFile(outfile);

    infile.close();
    outfile.close();
    return 0;
}
