#include<iostream>
#include<string>
using namespace std;
struct student{

string name ;
int id;
float grade1;
float grade2;
float grade3;
float average;
};
int main(){

student students[5];
    

    int highestIndex = 0;

    for (int i = 0; i < 5; i++) {

        cout << "Enter student name ";
        cin >> students[i].name;

        cout << "Enter student ID";
        cin >> students[i].id;

        cout << "Enter 3 grades: ";
        cin >> students[i].grade1
            >> students[i].grade2
            >> students[i].grade3;

        students[i].average =
            (students[i].grade1 +
             students[i].grade2 +
             students[i].grade3) / 3;
            };
            

       for (int i=1;i<5;i++) {
    int highestIndex = 0;

        if (students[i].average > students[highestIndex].average) {
            highestIndex = i;
        }
    }

    cout << "Student with the highest average: ";
    
        cout << students[highestIndex].average << endl;
cout <<"name:"<<students[highestIndex].name<<endl;

    return 0;
}