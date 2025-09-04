#include <iostream>
using namespace std;



float percentage(int marks) {
    return float(marks)/100 *100;
}

float gpa(int marks) {
    if (marks >=90 && marks<=100) {
        return 4.0;
    } else if (marks>=80 && marks<90) {
        return 3.7;
    } else if (marks>=70 && marks<80) {
        return 3.3;
    } else if (marks>=60 && marks<70) {
        return 3.0;
    } else if (marks>=50 && marks<60) {
        return 2.7;
    } else if (marks>=40 && marks<50) {
        return 2.3;
    } else if (marks>= 30 && marks<40) {
        return 2.0;
    } else {
        return 0.0;
    }
}

void caller(int marks, float (*func)(int)){
    float result = func(marks);
    cout<<"Result " <<result<<endl;
}

int main(){
    int marks;
    cout<<"Enter marks: ";
    cin>>marks;
    if(marks>100){
    	cout<<"marks must be less then 101 \n";
    	return 0;
	}

    int choice;
   cout<<"Choose an option:"<<endl;
     cout<<"enter 1 to calculate percentage"<<endl;
  cout<<"enter 2 to calculate GPA"<<endl;
    cin>>choice;

    switch(choice){
        case 1:
            caller(marks, percentage);
            break;
        case 2:
            caller(marks,gpa);
            break;
        default:
          cout<<"Invalid choice"<<endl;
            break;
    }

    return 0;
}
