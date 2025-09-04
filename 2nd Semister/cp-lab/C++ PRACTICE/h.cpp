#include <iostream>
#include <string>
using namespace std;
 void grade();
 float grade(int marks);
 char grade(float percentage);
  void grade(){
  	int marks ;
  	cin>>marks;
  	float percentage=grade(marks);
  	cout<<"ur grde"<<" "<<grade(percentage);
  	
  }
  float grade(int marks){
  	float percentage=float  (marks)/150*100;
  	return percentage;
  }
  char grade(float percentage) {
    char gradeobt;
    if (percentage >= 90) {
        return 'A';
    } else if (percentage >= 80) {
        return 'B';
    } else if (percentage >= 70) {
        return 'C';
    } else if (percentage >= 60) {
        return 'D';
    } else {
        return 'F';
    }
}

int main() {
    grade();
    return 0;
}

