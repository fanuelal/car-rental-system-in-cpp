#include <iostream>
#include <conio.h>
#include <windows.h>
#include <string.h>
#include <fstream>
using namespace std;
void graphics();
void adminPage();
void customerMenu();
void listCar();
void employee();
void rentedInfo();
void importanE();
void adminMenu();
void rentedCarDetail();
void developers();
string carList[40]={ "Maruti Suzuki Alto 800"," Renault Kwid T4056","Hyundai Grand i10"};
int index=1;
void employee(){
	string nameDataE[50]={"Abera 011","Belaynesh 012","Daniel 013","Elias 014"};
	int totalE = 4,recent=2,backTo;
	system("cls");
	cout<<"\n\n\n\n\t\t\t\t NAME OF CURRENT EMPLOYEE\n\n";
	for(int i=0;i<4;i++){
	   cout<<"\t\t\t\t"<<nameDataE[i]<<endl;
	}
	cout<<"\n\n\n\t\t see more"<<endl;
	cout<<"\t\t\t\n\n\n 0 TO RETURN  BACK TO MENU: ";cin>>backTo;
	if(backTo==0){
		adminMenu();
	}
	else adminMenu();
}
void rentedInfo(){
	system("cls");
 	 string carList[40]={ "Maruti Suzuki Alto 800"," Renault Kwid T4056","Hyundai Grand i10"};
 	 int rentedAmount[40]={2,0,1},n;
 	  cout<<"\n\n\n\n\t\t\t OUR AVAILABLE CAR LIST"<<endl;
 cout<<"\t\t MODEL \t\t\t\t NUMBER OF RENTED"<<endl<<endl;
 	  for(int i=0;i<3;i++){
 		cout<<"\t\t "<<carList[i]<<"\t\t\t\t "<<rentedAmount[i]<<endl<<endl;	 
 }
 	 cout<<"\t\t ENTER ANY NUMBER TO RETURN BACk ";	cin>>n;
 	 adminMenu();
 	 
}
void importanE(){
	system("cls");
	string emailist="";
	int n;
	ifstream emailList("emailData.1");
	cout<<"\t\t\t\t\t\t\t\n\n\n EMAILS FROM YOUR BUISSNESS PARTNERS"<<endl;
	if(emailList.is_open()){
	while(getline(emailList,emailist)){
		cout<<"EMAIL LISTS"<<endl;
		cout<<emailist;
		
	}
	emailList.close();}
	else{
		cout<<"\n\n\t\t\t\t Database is not available\n\n\n";
	}
	 cout<<"\t\t ENTER ANY NUMBER TO RETURN BACk ";	cin>>n;
	 adminMenu();
}
void rentCar(){
	string location="",drivingl="";
	string fulName="",payment="";
	int Dtime,phoneNum,timeCalc,carChoice;
	char ch[1];
	float distance=0.0;
	ofstream rentalDatabase;
	
	system("cls");
	cout<<"\n\n\n\n\t\t PLEASE TAKE A MOMENT AND FILL OUT THE FORM"<<endl;
	cout<<"\t\t\t\t FULL NAME: ";cin>>fulName;
	cout<<"\t\t\t\t Phone number: ";cin>>phoneNum;
	cout<<"\t\t\t\t Driving license number: ";cin>>drivingl;
	cout<<"\t\t\t\t Take date and time: ";cin>>Dtime;
	cout<<"\t\t\t\t Locatio to drive: ";cin>>location;
	if(location=="A.A" || location=="D.B"){
		distance=4905;
		cout<<"\t\t\t\t  YOUR DISTANSE IS: "<<distance<<"M"<<endl;
	}
	else{
		cout<<"\t\t\t  UNKOWN PLACE PLEASE TRY TO TYPE YOUR DISTANCE BY NUMBER IN METER : ";cin>>distance;
		cout<<"\t\t\t\t  YOUR DISTANSE IS: "<<distance<<"M"<<endl;
	}
	cout<<"\t\t\t\t FOR HOW LONG IN  DAY: ";cin>>timeCalc;
	system("cls");
	cout<<"\n\n\n\n\t\t PLEASE SELECT CAR MODEL LISTED BELOW BY THEIR ORDER STARTING FROM 1 \n\n";
	for(int i=0;i<4;i++){
			cout<<carList[i]<<endl;
	}
	carch:
 cin>>carChoice;
 if(carChoice>0 && carChoice<=4){
 	cout<<"\t\t\t\t\t\n YOUR CAR CHOICE IS: "<<carList[carChoice];
 	float paymentamount=(distance/1000)*50.50+Dtime*400;
 	cout<<"\t\t\t\t\n\n  YOUR PAYMENT AMOUNT IS "<<paymentamount;
 	cout<<"\t\t\t\t\n ENTER YOUR PAYMENT DETAILS SEPARETED BY COMMA , : ";cin>>payment;
 	cout<<"\t\t\t\t\n YOUR PAYMENT DETAIL IS: "<<payment;
 	rentalDatabase.open("rentalData.txt");
  if(!rentalDatabase){
 	cout<<"\t\t\t\t ops the database is failed";
 }
 
 else{
 	rentalDatabase<<fulName<<"\n"<<phoneNum<<"\n"<<drivingl<<"\n"<<Dtime<<"\n"<<location<<"\n"<<distance<<"\n"<<timeCalc<<"\n"<<paymentamount<<"\n------------------------";
 	rentalDatabase.close();
 }
 	cout<<"\t\t\t\t\n THANKS FOR USING OUR SERVICE YOU CAN HAVE YOUR CAR NOW"<<endl;
 	cout<<"\t\t\t\t TO RETURN BACK TO MENU PRESS ANY LETTER: ";cin>>ch;
 	customerMenu();
 }
 else goto carch;

	
}
void listCar(){
	char ch;
 string carList[40]={ "Maruti Suzuki Alto 800"," Renault Kwid T4056","Hyundai Grand i10"};
 int available[40][2]={{2,1},{4,3},{8,2}};
 cout<<"\n\n\n\n\t\t\t OUR AVAILABLE CAR LIST"<<endl;
 cout<<"\t\t CAR MODEL \t\t NUMBERS OF CAR \t\t DRIVED YEAR (USE AGE)"<<endl<<endl;
 //display available or not rented
 for(int i=0;i<3;i++){
 		cout<<"\t\t "<<carList[i]<<"\t\t "<<available[i][0]<<"\t\t\t\t"<<available[i][1]<<endl<<endl;	 
 }
 	cout<<"\t\t\t\t TO RETURN BACK TO MENU PRESS ANY LETTER: ";cin>>ch;
	customerMenu();
}
void rentedCar(){
	string userName,passwordsec;
	char ch;
	ifstream passwordFile ("customerLogin.1");
	cout<<"\n\n\n\n\n\n\t\t\t\t	SIGNIN PAGE FOR YOUR DETAILS"<<endl<<endl;
	cout<<"\t\t\t\t\t Username: ";cin>>userName;
	      if(userName=="custom"){
	system("cls");
	pass:
		string password="";
	cout<<"\n\n\n\n\n\n\t\t\t\t	SIGNIN PAGE FOR YOUR DETAILS"<<endl<<endl;
	cout<<"\t\t\t\t\t Password: ";
	ch = _getch();
	while(ch != 13){//character 13 is enter
	password.push_back(ch);
      cout << '*';
      ch = _getch();}
      ifstream passwordFile ("customerLogin.1");
       if (passwordFile.is_open())
  {
    while ( getline (passwordFile,passwordsec) )
    {
 if(password == passwordsec){
 	system("cls");
      	rentedCarDetail();
	  }
	else{
	  	system("cls");
	  	cout<<"INVALID PASSWORD"<<endl;
		goto pass;
	  }
    }
    passwordFile.close();
  }

  else cout << "Unable to open file";
}
else{
	index=index+1;
	cout<<"\t\t\t\t INVALID USERNAME";
	if(index<=3){
		rentedCar();
	}
			
	else{
		system("cls");
			cout<<"\n\n\n\t OOPS YOU TRIED FOR MANY TIMES PLEASE COME BACK AFTER 5 MIN"<<endl;
			system("pause");
	}

} 
	
}
void rentedCarDetail(){
	int days=3;
	char ch;
	cout<<"\n\n\n\t\t\t\t\t\ DETAILS ABOUT YOUR CAR"<<endl;
	cout<<"\t\t\t\t YOU HAVE "<<days<<" DAYS LEFT"<<endl;
	cout<<"\t\t\t\t CURRENTLY YOU ARE 3790M AWAY FROM THE OFFICE \n ";
	cout<<"\t\t\t\t PAYMENT ADD FROM THE LAST PAYMENT: "<<0<<endl;
	cout<<"\t\t PLEASE ENTER ANY LETTER TO BACK TO MENU: ";cin>>ch;
	customerMenu();
}


//Menu for system for admin and user 
void userType(){
	string usertype;
	system("cls");
	cout<<"\n\n\n";
	cout<<" ***              ***  ********  ***         *********	  **********       ****      ***      ********"<<endl;
	cout<<"  ***    ***     ***   **		***        ***            **        **    ***  ****  ***      **"<<endl;
	cout<<"   ***   ***    ***    ********  ***		  ***	         **         **   ***    ***   ***     ********"<<endl;
	cout<<"    ***  ***   ***     **		***		   ***	          **	   **   ***            ***    **"<<endl;
	cout<<"      *** *** ***      ********  **********  *********     **********   ***              ***   ********"<<endl;
	cout<<"\t\t\t\t\t WELCOME TO CAPITAL CAR RENAT "<<endl<<endl;
	cout<<"\t\t\t\t\t HEY ARE YOU CUSTOMER OR ADMIN? C/A: ";
	cin>>usertype;
	if(usertype == "A" || usertype == "a"){
		system("cls");
		adminPage();
	}
	    
	else if(usertype == "C" || usertype == "c"){
		system("cls");
		customerMenu();	
	}	
	else {
		system("cls");
			cout<<"please try to enter correct letter";
	userType();
	}


}
//admin login page
void adminPage(){

	string userName,passwordsec;
	char ch;
	ifstream passwordFile ("username.1");
	cout<<"\n\n\n\n\n\n\t\t\t\t	SIGNIN PAGE FOR ADMINISTRATOR"<<endl<<endl;
	cout<<"\t\t\t\t\t Username: ";cin>>userName;
	      if(userName=="admin"){
	system("cls");
	pass:
		string password="";
	cout<<"\n\n\n\n\n\n\t\t\t\t	SIGNIN PAGE FOR ADMINISTRATOR"<<endl<<endl;
	cout<<"\t\t\t\t\t Password: ";
	ch = _getch();
	while(ch != 13){//character 13 is enter
	password.push_back(ch);
      cout << '*';
      ch = _getch();}
      ifstream passwordFile ("password.1");
       if (passwordFile.is_open())
  {
    while ( getline (passwordFile,passwordsec) )
    {
 if(password == passwordsec){
      	adminMenu();
	  }
	else{
	  	system("cls");
	  	cout<<"INVALID PASSWORD"<<endl;
		goto pass;
	  }
    }
    passwordFile.close();
  }

  else cout << "Unable to open file";
}
else{
	index=index+1;
	cout<<"\t\t\t\t INVALID USERNAME";
	if(index<=3){
		adminPage();
	}
			
	else{
		system("cls");
			cout<<"\n\n\n\t OOPS YOU TRIED FOR MANY TIMES PLEASE COME BACK AFTER 5 MIN"<<endl;
			system("pause");
	}

} 
}
void adminMenu(){
	int adminchoose;
	system("cls");
	cout<<"\n\n\n\n\n\n\t\t\t\t	WHAT TO MANAGE?"<<endl;
	cout<<"\t\t\t\t 1. ABOUT THE EMPLOYEES"<<endl;
	cout<<"\t\t\t\t 2. RENTED AND RETURNED CARS"<<endl;
	cout<<"\t\t\t\t 3. IMPORTANT EMAIL FILTERS "<<endl;
	cout<<"\t\t\t\t 4. SIGNOUT \n \t\t\t : ";
 	cin>>adminchoose;
 	switch(adminchoose){
 		case 1:
		  employee();
		  break;
		case 2:
	 		rentedInfo();
	 		break;
	 	case 3:
	 		importanE();
	 		break;
	 	case 4:
	 		userType();
	 		break;
	 	default:
	 			cout<<"INVALID INPUT";
	 }
	 

		
}
//custemor menu page 
void customerMenu(){
	int menu;
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t WHAT DO YOU WANT?"<<endl;
	cout<<"\t\t\t\t\t 1. To rent car"<<endl;
	cout<<"\t\t\t\t\t 2. List of available cars"<<endl;
	cout<<"\t\t\t\t\t 3. About rented car"<<endl;
	cout<<"\t\t\t\t\t 4. Back to menu"<<endl;
	cout<<"\t\t\t\t\t 5. About Developers"<<endl;
	cout<<"\t\t\t\t\t : ";
	cin>>menu;
	if(menu==1){
		rentCar();
	}
	else if(menu==2){listCar();
	}
	else if(menu==3){rentedCar();
	}
	else if(menu==4){userType();
	}
	else if(menu==5){developers();
	}
	else {cout<<"invalid input";}
	
}
void developers(){
	char ch; 
	system("cls");
	cout<<"\n\n\n\n\n\t\t\t\t\t SOFTWARE DEVELOPED BY \t\t\t\t ID"<<endl;
	cout<<"\t\t\t\t\t FANUEL ALMAW \t\t\t\t    BDU-1207418"<<endl;
	cout<<"\t\t\t\t\t KIDIST MAMAYE \t\t\t\t   BDU-1207423"<<endl;
	cout<<"\t\t\t\t\t HANNA ALEMAYEHU \t\t\t\t BDU-1201926"<<endl;
	cout<<"\t\t\t\t\t GEBEYEHU ASSEGA \t\t\t\t BDU-1201767"<<endl;
	cout<<"\t\t\t\t\t ADERAW MOLLA \t\t\t\t    BDU-1200811"<<endl;
	cout<<"\t\t\t\t\t YAREGAL MIHRETU \t\t\t\t BDU-1203295"<<endl;


	cout<<"TO RETURN BACK PRESS ANY LETTER: ";cin>>ch;
	
	
}
int main(){
	system("color 97");
	userType();
	return 0;
}
