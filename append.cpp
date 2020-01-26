//program to append data in binary file
#include<iostream.h>
#include<fstream.h>

class stu{

    int rollno;
    char name[25];
    char Class[4];
    float marks;
    char grade ;
 public:
 void getdata()
 {
     cout << "rollno:"; cin >> rollno;
     cout << "name:"; cin >> name;
     cout << "class: "; cin >> Class ;
     cout << "Marks: "; cin >> marks ;
     if (marks >=75) grade = 'A';
     else if(marks>=60) grade = 'B';
     else if(marks>=50) grade = 'C';
     else if(marks>=40) grade = 'D';
     else grade = 'F';
 }
 void putdata()
 {
     cout << name << ", rollno" << rollno << "has"<< marks
     << "% marks and"<< grade << "grade."<< endl;
 }
 int getrno()// accessor function
 {
     return rollno;
 } 
} s1;

int main()
{
    ofstream fo("stu.dat", ios::app | ios::binary);
    char ans ='y';
    while (ans == 'y')
    {
        s1.getdata();
        fo.write((char*) &s1, sizeof(s1));
        cout << "Record added to file. \n";
        cout << "want to enter more records?(y/n)..";
        cin>> ans;
    }
    fo.close();
    return 0;
}