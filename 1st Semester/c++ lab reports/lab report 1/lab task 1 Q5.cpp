 //Write a program that prompts a user to input their name and then display their name.
 #include <iostream>
  #include <string>
 using namespace std;
 main()
 {
 string name;
 	cout<<"enter your name: \n";
 	getline(cin,name);
 	cout<<"your name is: "<<name<<endl;
 	return 0;
 }
