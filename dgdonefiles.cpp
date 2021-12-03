/*  Paul Cabrera
This program simulates a Drink Machine Simulator */
#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>
#include <fstream>
using namespace std;


const int size=5;
const float priceone=0.75;
const float pricetwo=0.80;           // declaration of size;


struct Drink{            //declaration of struct
	string Name;
	float Cost;
	int amount;
	
} info[size];



void operation();                 // Functions prototypes
void input(Drink[size],float& money,int& numofdrink,bool&soldstatus,float&quantity,int&a);
void input2(Drink[size],float& money,int& numofdrink,bool&soldstatus,float&quantity,int&a);
void calc(Drink[size],float&change, float& money, int& numofdrink , float&quantity, bool&soldstatus,int&a);
void inventoty(Drink[size]);
void Run(Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a);
void Run2(Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a,int&x);
void output(Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a);
void output2(Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a,int&x);
void menu(int&,Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a,int&x);
void write(Drink[size],float&quantity,int&a,const int&size,int&numofdrink,bool&soldstatus);
void read(int& x);

	

int main(int argc, char** argv) {

char option;

float quantity=0;                    // declaration of varariables
float money=0;
int numofdrink=0;
float change=0;
int a=0;
bool soldstatus=true;
int choice=0;
int choice2=0;
int x=0;



menu(choice,info,change,money,numofdrink,quantity,option,soldstatus,a,x);







return 0;
}


void inventoty(Drink[size])
{
		info[0].Name="Cola";
info[1].Name="Root Beer";
info[2].Name="Lemon-Lime";
info[3].Name="Grape Soda";
info[4].Name="Cream Soda";          // Machine data
info[0].amount=20;
info[1].amount=20;
info[2].amount=20;
info[3].amount=20;
info[4].amount=20;
info[0].Cost=priceone;
info[1].Cost=priceone;
info[2].Cost=priceone;
info[3].Cost=pricetwo;
info[4].Cost=pricetwo;	
}

void Run(Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a)
{
	
 while(tolower(option) !='n')       // loop that keeps doing the same until the user wants
 {
 	
operation();
cout << endl;
input(info, money,numofdrink,soldstatus,quantity,a);
calc(info,change,money,numofdrink,quantity,soldstatus,a);   // calling func and struct
cout << endl;
output(info,change,money,numofdrink,quantity,option,soldstatus,a);
 }
	
}




void operation()
{
int numofdrink=0;
int money=0;                   // screen
cout << setprecision(2) << fixed << showpoint;

	cout << "     Drink Machine Simulator " << endl;
	cout << " ==================================" << endl;
	cout << " DrinkName" << setw(12) << "Cost" << setw(15) << "#InMachine" << endl;
	cout << " =========" << setw(12) << "====" << setw(15) << " ==========" << endl;
	
		for(int i=0;i<size;i++)
	{
		cout << i+1 << ")" << setw(10) <<  info[i].Name << setw(6) <<"$" << info[i].Cost << setw(10) << info[i].amount << endl;
	}
	
	
}

void input(Drink[size],float &money,int &numofdrink,bool&soldstatus,float&quantity,int&a) //input func
{
	 
		cout << "Enter the # of the Drink:  /#6 to exit: ";
	cin >> numofdrink;

	
	 while(numofdrink<=0 || numofdrink>6)
	 {
	 	cout <<"Invalid Entry.. Try it again" << endl;
	 	cin >> numofdrink;
	 	soldstatus=false;
	 	
	 	
	 }
	 
	  if (numofdrink==6)
	  {
	  	cout << setprecision(2) << fixed << showpoint;
	  	cout << "THE MACHINE EARNED: $" << quantity << endl;
	  	cout << "THE MACHINE SOLD: #" << a << " DRINKS" << endl;
	  	exit(0);
	  }
	  
	 
	 	while (info[numofdrink-1].amount <=0)
	{
		cout<< "Sold out.. Try another one";
		cin >> numofdrink;
		soldstatus=false;
	}
	cout << setprecision(2) << fixed << showpoint;

	cout << "Enter the amount of money: $";
	cin >> money;
	cout << endl;
	
	while(money<=0 || money>1.00  )
	 {
	 	cout <<"Invalid Entry.. Try it again: $" << endl;
	 	cin >> money;
	 	soldstatus=false;
	 }
	 
	  while (money<info[numofdrink-1].Cost )
	  {
	  	cout <<"No funds.. try it again $";
	  	cin >> money;
	  	soldstatus=false;
	  	
	  }
	  
	 
	  
	   	
}

void input2(Drink[size],float& money,int& numofdrink,bool&soldstatus,float&quantity,int&a)
{
	
	
		cout << "Enter the # of the Drink:  /#6 to exit: ";
	cin >> numofdrink;

	
	 while(numofdrink<=0 || numofdrink>6)
	 {
	 	cout <<"Invalid Entry.. Try it again" << endl;
	 	cin >> numofdrink;
	 	soldstatus=false;
	 	
	 	
	 }
	 
	  if (numofdrink==6)
	  {
	  cout <<"AMOUNT OF DRINK LEFT / SOLD DRINKS / AMOUNT EARNED has been sucessfully saved in file\n" << endl;
	   write(info,quantity,a,size,numofdrink,soldstatus);	
	  	exit(0);
	  }
	  
	 
	 	while (info[numofdrink-1].amount <=0)
	{
		cout<< "Sold out.. Try another one";
		cin >> numofdrink;
		soldstatus=false;
	}
	cout << setprecision(2) << fixed << showpoint;

	cout << "Enter the amount of money: $";
	cin >> money;
	cout << endl;
	
	while(money<=0 || money>1.00  )
	 {
	 	cout <<"Invalid Entry.. Try it again: $" << endl;
	 	cin >> money;
	 	soldstatus=false;
	 }
	 
	  while (money<info[numofdrink-1].Cost )
	  {
	  	cout <<"No funds.. try it again $";
	  	cin >> money;
	  	soldstatus=false;
	  	
	  }
	  
}

void calc(Drink[size],float&change, float& money, int& numofdrink, float&quantity,bool&soldstatus,int&a)
{
	

	
	if (soldstatus=true)
	 {                           // calc funct
	 	
	 change=	money-info[numofdrink-1].Cost;		
	a++; // controlling # of drink sold
	quantity = quantity + info[numofdrink-1].Cost;
	info[numofdrink-1].amount -= 1;
	 	 
	 	   
	 	  
	 } 
}

void output(Drink[size],float&change, float& money, int& numofdrink,float&quantity,char&option,bool&soldstatus,int&a)
{
		cout << "[" << info[numofdrink-1].Name << "]" << " was sold" << endl;
		cout << setprecision(2) << fixed << showpoint;
	cout << "CHANGE: $" << change << endl;
	
	
	
	cout <<"Would you like to buy another Drink (y/n) ";
	 cin >> option;
	 cout << endl;
	  if (option=='n' || option=='N')
	  {
	  	cout << setprecision(2) << fixed << showpoint;
	  	cout << "THE MACHINE EARNED: $" << quantity << endl;
	  	cout << "THE MACHINE SOLD: #" << a << " DRINKS" << endl;
	  }

}

void output2(Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a,int& x)
{
	cout << "[" << info[numofdrink-1].Name << "]" << " was sold" << endl;
		cout << setprecision(2) << fixed << showpoint;
	cout << "CHANGE: $" << change << endl;
	
	
	
	cout <<"Would you like to buy another Drink (y/n) ";
	 cin >> option;
	 cout << endl;
	  if (option=='n' || option=='N')
	  {
	  	cout <<"AMOUNT OF DRINK LEFT / SOLD DRINKS / AMOUNT EARNED has been sucessfully saved in file\n" << endl;
	  	 write(info,quantity,a,size,numofdrink,soldstatus);	
	  	 read(x);
	  	exit(0);
	  }
}

void menu(int& choice,Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a,int&x)
{
	cout <<":::::MENU::::::\n";
	cout << "Press #1 to save data in a file\n";
	cout <<"Press #2 to show data in the screen\n";
	cout << "Press #3 to save/show the data\n";
	cin >> choice;
	
	if (choice==2)
{
		inventoty(info);  // machine data
Run(info,change,money,numofdrink,quantity,option,soldstatus,a);  // function that call others
}

 else if(choice==3)
 {
 		inventoty(info);  // machine data
Run(info,change,money,numofdrink,quantity,option,soldstatus,a);  // function that call others
write(info,quantity,a,size,numofdrink,soldstatus);
 read(x);
 }

 else if(choice==1)
 
 {
 			inventoty(info);  // machine data
 			
 		Run2(info,change,money,numofdrink,quantity,option,soldstatus,a,x);  // function that call others	 
 		

}
	


}



void write(Drink[size],float&quantity,int&a,const int&size,int& numofdrink,bool& soldstatus)
{
	ofstream myfile;
	myfile.open("data.txt",ios::out);
	if(myfile.fail())
{
	cout <<"Sorry the file is not avaible\n";
	}	
	
	myfile << "THE MACHINE EARNED: $" << quantity << endl;
	myfile << "THE MACHINE SOLD: #" << a << " DRINKS" << endl;
	
	for (int i=0;i<5;i++)
	{
		myfile << "THE MACHINE HAS #" << info[i].amount << " " <<  info[i].Name << endl;
	}
	
	myfile.close();
		
}

void Run2(Drink[size],float&change, float&money, int&numofdrink, float&quantity,char&option, bool&soldstatus,int&a,int&x)
{
	
	while(tolower(option) !='n')       // loop that keeps doing the same until the user wants
 {
 	
operation();
cout << endl;
input2(info, money,numofdrink,soldstatus,quantity,a);
calc(info,change,money,numofdrink,quantity,soldstatus,a);   // calling func and struct
cout << endl;
output2(info,change,money,numofdrink,quantity,option,soldstatus,a,x);

 }
	
}

 void read(int& x)
 {
 	 cout <<"Press #9 to read the data from the file or #1 to exit" << endl;
 cin >> x;
 
  if (x==9)
  {
  	 cout << "::::::READING DATA FROM THE FILE::::::" << endl;
  	ifstream myfile;
 	string text;
 	myfile.open("data.txt",ios::in);
 	if(myfile.fail())
{
	cout <<"the file was not found\n";
	 } 	
	 
	 while(!myfile.eof()) 
{
	getline(myfile,text);
	cout << text << "\n";
	 } 	
	 myfile.close();
  }
   else if (x==1)
   {
   	exit(0);
   }
  
 
 }
