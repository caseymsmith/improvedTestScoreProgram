#ifndef STUDENT_CPP
#define STUDENT_CPP
#include "implementation.h"

StudentArray::StudentArray(ifstream& infile)
{
    Student temp;

    int i = 0;
    while(infile.good()){
        infile >> temp;
        i++;
    }  //counts to create the array size

    array=new Student[i]; //creates the array

    if (array!=NULL)
        size=i;
    else
        size=0;

    infile.clear();
    infile.seekg(infile.beg);
    readFile(infile);
}

//The following function prints out onto the file
void StudentArray::writeFile(ostream& out)
{

    out << "\t\t\t\t\t" << "Student Grade Report" << endl
            << "--------------------------------------------------------" << endl
            << "\t\t\tStudent Name \t Average \t     Grade" <<
            endl << "--------------------------------------------------------" << endl;

    for (int i=0; i < size; i++){
        out << array[i];
    }

    out << "--------------------------------------------------------" << endl;

    int count;

    highest(count);

    out << "\n\t\tThe students with the highest grades are:" << endl << endl;

    displayHighest(highest(count), count, out);
}

//The following function reads in the infromation to the array
void StudentArray::readFile (ifstream& infile) {

    Student student;

    for (int i = 0; i < size && infile.good(); i++) {
        infile >> student;
        array[i]=student;
        array[i].calcAvg();
        array[i].calcLetterGrade();
    }
}

//The following function yields the size of the array
StudentArray::StudentArray(int amount){
    array=new Student[size];
    if(array!=NULL)
        size=amount;
    else
        size=00;
}

//The following function returns the size.
int StudentArray::getSize() const{
    return size;
}

//The following function returns the array.
Student& StudentArray::get(int i){
    return array[i];
}

//The following function sets up the array .
void StudentArray::set(int i, Student student){
    array[i]=student;
}

//The following is a destructor
StudentArray::~StudentArray(){
    if (array!=NULL)
        delete [] array;
}

//The following sets the variables as a copy constructor
Student::Student(Student& student){

    first=student.first;
    last=student.last;
    for(int i=0; i<5; i++) {
        score[i] = student.score[i];
    }
    average=student.average;
    grade=student.grade;
}

//The following returns the input stream
istream& operator >> (istream& left, Student& right) {

    left >> right.first >> right.last >> right.score[0] >> right.score[1] >> right.score[2]
            >> right.score[3] >> right.score[4];

    right.calcLetterGrade();

    return left;
}

//The following returns the output stream
ostream& operator << (ostream& right, const Student& left){

    string word=left.last + ", " + left.first;

    if (left.average!=-1)
        right << setw(23) << word  << setw(10)
                << left.average << setw(15) << left.grade << endl;
    else
        right << setw(23) << word
                << " " << setw(20) << left.grade << endl;

    return right;

}

//The following is a free function to compare 2 students to see if they are the same
bool operator == (const Student & A, const Student & B) {
    if (A.getLast() != B.getLast()) {
        return false;
    }
    if (A.getFirst() != B.getFirst()) {
        return false;
    }
    for (int i = 0; i < 5; i++) {
        if (A.getScores(i) != B.getScores(i))
            return false;
    }

    if(A.getAverage() != B.getAverage()) {
        return false;
    }

    if(A.getGrade() != B.getGrade()) {
        return false;
    }

    return true;
}

//The following is a free function that copares the last names of 2 students
bool operator > (const Student & A, const Student & B)
{
    if(A.getLast() > B.getLast())
        return true;
    else if (A.getLast() == B.getLast() && A.getFirst() < B.getFirst())
        return true;
    else
        return false;
}

//The following is a free function that compares the last names of 2 students
bool operator < (const Student & A, const Student & B)
{
    if (A.getLast() < B.getLast())
        return true;
    else if (A.getLast() == B.getLast() && A.getFirst() < B.getFirst())
        return true;
    else
        return false;
}

//The following is a member function that allows us to directly assign one student object to another
//student object. This assignment will copy all the private data members
//(including five test scores) for the student class
Student& Student::operator = (const Student & right)
{
    first=right.first;
    last=right.last;
    for(int i=0; i<5; i++) {
        score[i] = right.score[i];
    }
    average=right.average;
    grade=right.grade;
    calcLetterGrade();
    return *this;
}

//The following is a constructor for the member variables
Student::Student(){
    first="";
    last="";
    for(int i=0; i<5; i++) {
        score[i] = -1;
    }
    average=-1;
    grade="I";
}

//This allows access and sets the first name
void Student::setFirst(string fir){
    first=fir;
}

//This allows access and sets the last name
void Student::setLast(string las) {
    last=las;
}

//This allows access and sets the scores
void Student::setScores(int scor[]) {
    for(int i=0; i<5; i++){
        score[i]=scor[i];
    }
}

//This allows access and sets the average
void Student::setAverage(double avg){
    average=avg;
}

//This allows access and sets the grade
void Student::setGrade(string grad){
    grade=grad;
}

//This allows access and sets the first name
string Student::getFirst()const {
    return first;
}

//This allows access and sets the last name
string Student::getLast()const {
    return last;
}

//This allows access and sets the scores
int Student::getScores(int i)const{
    return score[i];
}

//This allows access and sets the averages
double Student::getAverage()const{
    return average;
}

//This allows access and sets grade
string Student::getGrade()const{
    return grade;
}

//This enables the grade to be determined
string Student::calcLetterGrade(){

    for (int x=0; x<5; x++){
        if (score[x] > 100 || score[x] < 0)
            average = -1;
    }

    if(average>=90 && average <= 100) {
        grade = 'A';
    }
    else if (average<90 && average >= 80){
        grade='B';
    }
    else if (average<80 && average >= 70){
        grade='C';
    }
    else if (average<70 && average >= 60){
        grade='D';
    }
    else if (average<60 && average>=0){
        grade='F';
    }
    else
        grade="\t\t\t\t\t   I Invalid Test Score!";

    return grade;
}

//This calculates the average
int Student::calcAvg() {
    double total = 0;
    for (int test=0; test<5; test++) {
        total = total + score[test];
    }
    average = ceil(total / 5);

    return average;
}

//This sorts the array
void StudentArray::sort() {
    int seek;
    int minCount;

    Student minValue;

    for(seek=0; seek<(size); seek++){
        minCount=seek;
        minValue=*(array+seek);

        for(int index=seek+1; index < size; index++)
        {
            if(array[index] < (minValue))
            {
                minValue=array[index];
                minCount=index;
            }
        }
        Student temp = array[minCount];
        array[minCount]=array[seek];
        array[seek]= temp;
    }

}

//This finds the student(s) with the highest score(s)
int StudentArray::highest(int& count) {
    count=1;
    int highest=array[0].getAverage();
    for (int i=1; i<size; i++) {
        if(highest==array[i].getAverage()){
            count++;
        }
        else if (array[i].getAverage()>highest){
            highest=array[i].getAverage();
            count=1;
        }
    }

    return highest;
}

//This displays the student(s) with the highest score(s)
void StudentArray::displayHighest(int highest, int count, ostream& out) {

    for (int i = 0; i < size; i++){
        if (array[i].getAverage() >= highest) {
            string word=array[i].getFirst() + " " + array[i].getLast();
            out << setw(23) << word  << setw(10)
                    << highest << setw(15) << array[i].getGrade() << endl;
        }
    }

}

#endif
