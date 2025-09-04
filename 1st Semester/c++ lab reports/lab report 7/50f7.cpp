#include <iostream>
using namespace std;
void grade();
float grade(int marks);
char grade(float percentage);


void grade(){
    int marks;
    cout<<"Enter marks out of 150: ";
    cin>>marks;
    float percent = grade(marks);
    char gradeLetter = grade(percent);
    cout<<"Marks: "<<marks<<endl;
    cout<<"Percentage: "<<percent<<"%"<<endl;
    cout<<"Grade: "<<gradeLetter<<endl;
}

float grade(int marks){
    float percent = (float)marks/150*100;
    return percent;
}

char grade(float percent){
    if (percent >= 90) {
        return 'A';
    } else if (percent >= 80) {
        return 'B';
    } else if (percent >= 70) {
        return 'C';
    } else if (percent >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main(){
    grade();
    return 0;
}

