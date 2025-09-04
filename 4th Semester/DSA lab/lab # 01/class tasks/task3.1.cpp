#include <iostream>
using namespace std;
/*The greatest common divisor (g.c.d.) of two nonnegative integers is the 
largest integer that divides evenly into both. In the third century B.C.,
 the Greek mathematician Euclid discovered that the greatest common 
 divisor of x and y can always be computed as follows: 
•	If x is evenly divisible by y, then y is the greatest common divisor. 
•	Otherwise, the greatest common divisor of x and y is always equal to
 the greatest common divisor of y and the remainder of x divided by y.Use Euclid’
 s insight to write a recursive function GCD(x,y) that computes the greatest common divisor of x and y. 
*/
int greatest_common_divisor(int x,int y){
    if (y==0)return x;
    else{
        return greatest_common_divisor(y,x%y);
    }



}
int main() {
    int x, y;
    cout << "Enter two nonnegative integers: ";
    cin >> x >> y;
    cout << "GCD of " << x << " and " << y << " is " << greatest_common_divisor(x, y) << endl;
    return 0;
}