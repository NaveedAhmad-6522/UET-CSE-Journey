#include <iostream>
#include <conio.h>
#include <stdlib.h>
using namespace std;
int cost;
 struct Cars {

    string mark [10] = {"Hyundai","BMW","Mercedes","Audi","Tesla","Skoda","Volkswagun","Toyota","Ford"};

    string model [10]= {"2016MD","2018AS","2018DS","2017LA","2018OW","2005Ps","2008PW","2010QW","2016SA"};

    string color [10]={"Red","black","yellow","Blue","Red","Brown","Silver","Black","grey"};

    string maxs_peed [10]={"100 Km/h ","150 Km/h","150 Km/h","170 Km/h","130 Km/h","140 Km/h","130 Km/h","120 Km/h","150 Km/h"};

    int price [ 10 ] ={10,20,30,50,20,25,40,60,90} ;

    int date [10] = {2010,2012,2013,2017,2018,2005,2008,2010,2014};



   };

   struct Lessee {

   string Name [10];
   string Natio_ID [10] ;
   int payment_acc [ 10] ;
   };


 Cars car ;
 Lessee lessee ;


   void carlist ()
 {


   int num=1;
 for(int i=0 ;i<9;++i)
 {
 	cout<<"\t\t\t";
    cout<<"Enter " <<num<<"\t- To Select  "<<car.mark[i]<<endl;
    num++ ;
 }

 }


 void Details (int theChoice)
  {
   	system("CLS");
  	 cout<<"\n\n\n\t\t\t-----------------------------\n";
     cout<<"\t\t\tYou Have Selected - "<<car.mark[theChoice-1]<<endl;
     cout<<"\t\t\t-----------------------------\n\n\n";
     cout<<"\t\t\tModel : "<<car.model[theChoice-1]<<endl;
     cout<<"\t\t\tColor : "<<car.color[theChoice-1]<<endl;
     cout<<"\t\t\tMaximum Speed : "<<car.maxs_peed[theChoice-1]<<endl;
     cout<<"\t\t\tPrice : "<<car.price[theChoice-1]<<"K per week"<<endl;


  }


   void check (int j ,int cost )
  {  system("CLS");
      if(lessee.payment_acc[j]  >= cost)
           cout<<"\n\n\n\t\t\tProcess has been done successfully!! " <<endl;
           else
              cout<<"\n\n\n\t\t\t Insufficient amount sorry :(" <<endl;
 
 
  }

  void user_input (int theChoice , int weeks)
   {
   	 system("CLS");
        int j=theChoice-1 ;
         
       
          cout<<"\n\n\t\t\t----------------------------------------------------------\n";
        cout<<"\t\t\tRenting the  "<<car.mark[theChoice-1] <<" for "<<weeks<<" weeks will cost ";
	 cost = car.price[theChoice-1]*weeks*100 ;
	 cout<<cost<<"Rs\n";
	   cout<<"\t\t\t----------------------------------------------------------\n";
	 	
	 

        
       cout<<"\t\t\t----------------------------------------\n";
       cout<<"\t\t\tPlease Provide Your Personal Details  : \n";
       cout<<"\t\t\t----------------------------------------\n\n";
       cout<<"\n\tNOTE: PROVIDE FIRST NAME ONLY, DONOT ENTER SPACE WHILE PROVIDING NAME,\n\tPAYMENT WON'T PROCEED IF THE GIVEN AMOUNT IS LESS THEN THE RATE OF CAR\n\n\n\n";
       cout<<"\t\t\tEnter Your Name (NOTE:WITHOUT SPACES) : ";
       cin>>lessee.Name[j];
       cout<<"\t\t\tEnter Your National ID : ";
       cin>>lessee.Natio_ID[j] ;
       cout<<"\t\t\tPayment Amount: " ;
       cin>>lessee.payment_acc[j] ;


     check( j ,cost ) ;
    
 
 
} 


int main()
{
	int login();
    login();
			int theChoice ;
				int weeks;
         string decide ="yes" ;
     cout<<"\t\t\t----------------------------------------------\n";
     cout<<"\t\t\t\tTHE CAR RENT SHOP \n";
     cout<<"\t\t\tWelcome to Our Company ,Choose from the menu : "<<endl;
     cout<<"\t\t\t----------------------------------------------\n";
     while(decide!="exit")
     {
         carlist();
            a:
     cout<<"\n\n\n\t\t\tYour Choice: ";
 

     cin>>theChoice ;
     if (theChoice < 1 || theChoice > 9 ){ cout<< "invalid input please try again \n";
	 goto a;
	 }
     Details(theChoice);
     cout<<"\n\n\n\t\t\tAre You Sure, you want to rent this Car? (yes /no ) : ";
     cin>>decide ;
     if(decide=="yes") {
     	cout<<"\n\n\n\t\t\t How many weeks will the car be rented sir/maam? :  ";
     
     	cin>>weeks;
     	cout<<endl;
        user_input(theChoice , weeks );
        cout<<"\n\n\t\t\t For continue renting cars enter 'yes' and if not please enter 'no' so your recipt can be handed out :) (yes/no) ";
        cin>>decide;
        if (decide=="no") break ;
system("CLS");
     }

  
     

   }
   system("CLS");
     cout<<"\n\n\t\t\t----------------------------------------------------------\n";
     cout<<"\n\t\t\t\t\t THE CAR RENT SHOP ";
     cout<<"\n\t\t\t customer name : "<<lessee.Name[theChoice-1];
     cout<<"\n\t\t\t customer ID : "<<lessee.Natio_ID[theChoice-1] ;
     cout<<"\n\t\t\t car rented  : "<<car.mark[theChoice-1] <<"("<<car.model[theChoice-1]<<","<<car.color[theChoice-1]<<")";
     cout<<"\n\t\t\t customer payment : "<<lessee.payment_acc[theChoice-1] <<"Rs" ;
     cout<<"\n\t\t\t total cost of rent : "<<cost<<"Rs";
	 cout<<"\n\t\t\t Paid weeks of rent : "<<weeks;
	 cout<<"\n\t\t\t remaining balance in account : "<<lessee.payment_acc[theChoice-1] - cost<<"Rs" ;
	 cout<<"\n\t\t\tNOTE : Your remaining balance will be stored in your account with returning of the car you may cash it out or keep in account as per wish  ";
	 cout<<"\n\t\t\tAnd if any type of damage is caused  to the car deduction will be made in balance";
	 cout<<"\n\t\t\t HAVE A SAFE JOURNEY THANKS FOR COMMING BY 'THE CAR SHOP' ;)";
    cout<<"\n\n\t\t\t----------------------------------------------------------\n";
     


    return 0;
}

int login(){
   string pass ="";
   char ch;
   cout <<"\n\n\n\n\n\n\n\t\t\t\t\t  THE CAR RENT SHOP system Login";
   cout << "\n\n\n\n\n\n\n\t\t\t\t\t\tEnter Password: ";
   ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
   }
   if(pass == "needmoney"){
      cout << "\n\n\n\n\t\t\t\t\t  Access Granted! Welcome To Our System \n\n";
      system("PAUSE");
      system("CLS");

   }else{
      cout << "\n\n\n\n\t\t\t\t\tAccess Aborted...Please Try Again!!\n";
      system("PAUSE");
      system("CLS");
      login();
   }
}
