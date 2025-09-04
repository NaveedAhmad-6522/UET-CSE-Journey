//Write a program that takes the temperature in Fahrenheit from the user and convert it to 
//Celsius And Kelvin:
//K = C + 273
//C = (F – 32) / 1.8 .


#include <iostream>
using namespace std;

int main() {
  
 float f, c = (f - 32) / 1.8, k = c+ 273;

  cout << "Enter the temperature in Fahrenheit: ";
  cin >> f;

  cout << "The temperature in Celsius is: " << c << endl;
  cout << "The temperature in Kelvin is: " << k << endl;

  return 0;
}

