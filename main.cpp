#include<iostream>   
#include<windows.h>      
#include<conio.h>         // For getch() function
#include<string.h>
#include<time.h>
#include<fstream>           // for handling the files
#define enter 13            // ASCII value of enter key
void allTransactions();
void gotoxy(int x,int y);
using namespace std;
void gotoxy (int x, int y)	                                             //defining/initializing to predefined objects
{
	COORD coord;
    coord.X = x;
    coord.Y = y;                                                       // X and Y coordinates
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
char *date_time()
{
	time_t t;
	time(&t);
	char *loc=ctime(&t);
	return loc;	                                                 //returns local time and date
}
void flow(char *ch)	                                           //flow of instructions
{
	char *str=ch;
	for(int i=0;i<strlen(str);i++)
	{
		Sleep(20);
		cout<<str[i];
	}
}
void load(void)
{ 
	gotoxy(40,14);
	cout<<"Loading! Please wait";
	for(int i=1000;i<4000;i=i+1000)
	{
		Sleep(i);
		cout<<".";
	}
	system("cls");
}
void getWelcomeFrame()
{
    system("color e0");
	int a=2;
   for(int i=79;i>45;i-=10)
   {
   gotoxy(i,24-a);cout<<"      ";
   cout<<"WELCOMES YOU HERE.";
   Sleep(40);
   a+=3;
   } 
   a=2;
   for(int j=6;j<45;j+=10)
   {
    gotoxy(j,24-a);
    cout<<"  ";
    cout<<"RBI ATM SERVICE ";
    Sleep(40);
    a+=3;
//     if(j==26)
//   	system("cls");
   }
//    Sleep(1000);
	for(int i=0;i<=25;i++)
	{  
		gotoxy(5,i);
		cout<<"|";
		Sleep(20);
		gotoxy(105,i);
		cout<<"|";
		Sleep(20);
	}
	for(int j=0;j<=110;j++)
	{
	gotoxy(j,5);
	cout<<"-";
	Sleep(5);
	gotoxy(j,25);
	cout<<"-";
	Sleep(5);
   }
   gotoxy(70,26);
   flow("Developed By: Sudhanshu Rawat");
   cout<<endl;
   gotoxy(70,27);
   flow("Email id: sr363298@gmail.com");
   cout<<endl;
   gotoxy(70,28);
   flow("Ph No: 9936566389");
}
  void mainFrame()
{
	int i,j=105;
	for(i = 5;i<108,j>=5;i++,j--)
	{
		gotoxy(i,3);
		Sleep(10);
		cout<<"_";
		gotoxy(j,22);
		Sleep(10);
		cout<<"_";
	}
	gotoxy(80,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;                         // Date will be shown on the right top of every frame 	
}
  void getFixedFrame()	//instead of flow line fixing the frame
{
	int i,j=105;
	for(i = 5;i<105,j>=5;i++,j--)
	{
		gotoxy(i,3);
		cout<<"_";
		gotoxy(j,22);
		cout<<"_";
	}
	gotoxy(80,2);
	char s[20];
	strcpy(s,date_time());
	cout<<s;
}
class Confidencial                                 // Class to store the confidencial details of customer
{
	public:
      long int accountNumber,pinNumber;
	  char customerName[40];
	  void storeConfidencialDetails();
	  void showConfidencialDeatails();
	  void showTransactionDetails();
	  void readConfidencialDetails();
	  void showAccountMemberDetails();
};
void Confidencial::storeConfidencialDetails()
{
	ofstream store;
	store.open("confidencial.txt",ios::app|ios::binary);
	store.write((char*)this,sizeof(*this));
	store.close();	
}
//void Confidencial::showConfidencialDetails()
//{
//	cout<<customerName<<"                    "<<accountNumber<<"                    "<<pinNumber<<endl;
//}
void Confidencial::readConfidencialDetails()
{
	ifstream fin;
	fin.open("confidencial.txt",ios::in|ios::binary);
	fin.read((char*)this,sizeof(*this));
	while(!fin.eof())
	{
//		showConfidencialDetails();
		fin.read((char*)this,sizeof(*this));
	}
	fin.close();
}
class ATM
{
	protected:
	  char fullName[40], email[40]; 
	  char fatherName[40],accountType[3],dob[15],city[40];
	  long int pincode,initAmt,actNo,pinNo,balance;
	  int index=1;
	public:
		void mainMenu();
		void subMenu();
		void help();
		void exit();
		void createAccount();
		void cashWithdraw(long int);
		void withdraw(long int,long int);
		void withdrawFund(long int,long int);
		void fastCash(long int);
		void balanceEnquiry(long int);
		void pinChange(long int, long int);
		void pinGenerate();
		void otherServices();
		void fundTransfer(long int,long int);
		void admin();
		void proceed();	
	    void storeCustomerDetails();
	    void showCustomerDetails();
	    void readCustomerDetails();
	    void searchCustomerDetails(long int,long int);	
	    void deposite(long int,long int);
};

void ATM::storeCustomerDetails()
{   
	    ofstream store;
	    store.open("UserDetails.txt",ios::app);
	    store.write((char*)this,sizeof(*this));
//    	store<<"\n";
       store.close();
    }
    void ATM::otherServices()
    {
	system("COLOR 70");
	for(int i=0;i<25;i++)
	{
		gotoxy(5,i);
		cout<<"|";
		gotoxy(90,i);
		cout<<"|";
	}
	
	gotoxy(7,0);
	cout<<"Good to see here ";

	gotoxy(32,1);
	cout<<"POINTS TO NOTE";gotoxy(7,3);
	flow("Ensure that you change the PIN number after first using your card also");gotoxy(7,4);
	flow("frequently change PIN number");
	gotoxy(7,6);
	flow("Ensure that nobody else can see you entering your PIN number at the ATM.");
	gotoxy(7,8);
	flow("Do not use the ATM machine when strangers are inside the ATM counter.");
	gotoxy(7,10);
	flow("Do not seek the assistance of strangers while operating the ATM machine.");
	gotoxy(7,12);
	flow("Should you notice anything strange or suspicious at the ATM counter please");
	gotoxy(7,13);
	flow("refrain from using  the same.");
	gotoxy(7,15);
	flow("Ensure that you check your account statement from time to time.");
	gotoxy(7,17);
	flow("In case you lose your ATM card call 1800-425-3800 to block your card and ");
	gotoxy(7,18);
	flow("this avoid misuse of the card.");
	gotoxy(7,20);
	flow("Do not disclose your PIN number to others IBO/RBI or any other Government,");
	gotoxy(7,21);
	flow("Banking institutions will never require you to disclose your PIN number.");
//	play(3);
	gotoxy(3,23);
	flow("-------------------------------");
	gotoxy(45,23);
	flow("--------------------------------");
	gotoxy(35,23);
	cout<<" THANK YOU ";Sleep(2000);
	gotoxy(78,24);cout<<"";
	system("cls");
	system("color 2F");
	gotoxy(18,13);
	cout<<"       TRANSACTION COMPLETED SUCCESSFULLY       \a\a";
	Sleep(2000);
	}
void ATM::pinChange(long int accountNumber,long int pinNumber)
{
	fstream pinChange;
	pinChange.open("userDetails.txt",ios::in|ios::out|ios::ate|ios::binary);
	if(!pinChange)
	{
 		cout<<"File does not exists.";
 	}
    else
 	{
	 	pinChange.seekg(0);
		pinChange.read((char*)this,sizeof(*this));
		while(!pinChange.eof())
		{
			if(accountNumber==actNo&&pinNumber==pinNo)
			{
				system("cls");
				gotoxy(40,14);
				cout<<"Enter your New pin Number";
				long int newPin,rnewPin;
				gotoxy(45,16);
				cin>>newPin;
				system("cls");
		    	gotoxy(40,15);
				cout<"Confirm pin Number";
				gotoxy(45,16);
				cin>>rnewPin;
				if(newPin==rnewPin)
				{
					pinNo=newPin;
					pinChange.seekp(pinChange.tellp()-sizeof(*this));
					pinChange.write((char*)this,sizeof(*this));
					system("cls");
					getFixedFrame();
					gotoxy(35,15);
					cout<<"Your pin has been changed successfully";
					gotoxy(35,17);
					cout<<"your new pin number is:   "<<pinNo;
					cin.ignore();
					cin.get();
				}
				else
				{
					system("cls");
					gotoxy(35,14);
					cout<<"enterd pin did not match to the confirmation pin.";
					Sleep(1000);
					mainMenu();
				}
			}
			pinChange.read((char*)this,sizeof(*this));
		}	
		pinChange.close();
	}

}
    void ATM::fundTransfer(long int accountNumber,long int balance)
    {
    	fstream fund;
    	fund.open("userDetails.txt",ios::in|ios::ate|ios::binary|ios::out);
    	if(!fund)
    	{
    		cout<<"File does not exists.";
		}
		else
		{
			fund.seekg(0);
			fund.read((char*)this,sizeof(*this));
			while(!fund.eof())
			{
				if(accountNumber==actNo)
				{
					initAmt=initAmt+balance;
					fund.seekp(fund.tellp()-sizeof(*this));
					fund.write((char*)this,sizeof(*this));
					system("cls");
					getFixedFrame();
					gotoxy(34,13);
					cout<<"Fund is being transfered.";
					for(int i=10;i<80;i++)
					{
						gotoxy(i,15);
						cout<<"#";
						Sleep(500);
					}
					system("cls");
					getFixedFrame();
					gotoxy(35,16);
					cout<<"Fund is tranfered successFully";
				}
				fund.read((char*)this,sizeof(*this));
			}
			fund.close();
		}
	}
    void ATM::balanceEnquiry(long int accountNumber)
    {
    	system("cls");
    	ifstream enquiry;
    	enquiry.open("userDetails.txt",ios::in|ios::binary);
    	if(!enquiry)
    	{
    		cout<<"File does not exists";
		}
		else
		{
			enquiry.read((char*)this,sizeof(*this));
			while(!enquiry.eof())
			{
				if(accountNumber==actNo)
				{
					gotoxy(35,14);
					cout<<"Your account balance is:  "<<initAmt;
					gotoxy(34,16);
					cout<<"Press Enter to continue.";
					cin.get();
				}
				enquiry.read((char*)this,sizeof(*this));
			}
			enquiry.close();
		}
    }
    void ATM::withdrawFund(long int accountNumber,long int balance)
    {
    	fstream file;
    	file.open("userDetails.txt",ios::in|ios::out|ios::ate|ios::binary);
    	if(!file)
    	  cout<<"file does not exists";
    	else
    	{
    		file.seekg(0);
    		file.read((char*)this,sizeof(*this));
    		while(!file.eof())
    		{
    			if(accountNumber==actNo)
    			{
    					initAmt=initAmt-balance;
    				    file.seekp(file.tellp()-sizeof(*this));
    				    file.write((char*)this,sizeof(*this));
    				    system("cls");
    				    getFixedFrame();
    				    gotoxy(35,13);
    				    cout<<"your Available account balance is:  "<<initAmt;
    				    Sleep(2000);
						    
				}
			
				file.read((char*)this,sizeof(*this));
			}
		}
			file.close();
	}				
	
    void ATM::withdraw(long int accountNumber,long int balance)
    {
    	fstream file;
    	file.open("userDetails.txt",ios::in|ios::out|ios::ate|ios::binary);
    	if(!file)
    	  cout<<"file does not exists";
    	else
    	{
    		file.seekg(0);
    		file.read((char*)this,sizeof(*this));
    		while(!file.eof())
    		{
    			if(accountNumber==actNo)
    			{
    				if(balance<initAmt)
    				{
    					initAmt=initAmt-balance;
    				    file.seekp(file.tellp()-sizeof(*this));
    				    file.write((char*)this,sizeof(*this));
    				    system("cls");
    				    getFixedFrame();
    				    gotoxy(35,13);
    				    cout<<"Transaction is in order to proceed.";
    				    Sleep(800);
    				    gotoxy(35,15);
    				    cout<<"Please collect your cash.";
    				    Sleep(1000);
    				    system("cls");
    				    getFixedFrame();
    				    gotoxy(35,13);
    				    cout<<"your Available account balance is:  "<<initAmt;
    				    Sleep(2000);
						    
					}
					else
					  {
					  	system("cls");
					  	gotoxy(20,14);
					  	cout<<"Sorry We could not proceed due to insufficient balance in your account.";
					  	Sleep(1500);
					  }
				}
				file.read((char*)this,sizeof(*this));
			}
			file.close();
		}				
	}
    void ATM::fastCash(long int accountNumber)
    {
     Sleep(500);
   	system("cls");
  	getFixedFrame();
  	gotoxy(14,10);
  	cout<<"1. 500";
  	gotoxy(14,13);
  	cout<<"2. 1000";
  	gotoxy(14,16);
  	cout<<"3. 1500";
  	gotoxy(14,19);
  	cout<<"4. 2000";
  	gotoxy(70,10);
  	cout<<"5. 2500";
  	gotoxy(70,13);
  	cout<<"6. 3000";
  	gotoxy(70,16);
  	cout<<"7. 3500";
  	gotoxy(70,19);
  	cout<<"8. 4000";
  	Sleep(500);
  	gotoxy(45,4);
  	flow("Please choose the amount.");
  	int choice;
	gotoxy(45,27);
	cin>>choice;
	switch(choice)
	{
		case 1:
			withdraw(accountNumber,500);
			break;
		case 2:
			withdraw(accountNumber,1000);
			break;
		case 3:
			withdraw(accountNumber,1500);
			break;
		case 4:
			withdraw(accountNumber,2000);
			break;
		case 5:
			withdraw(accountNumber,2500);
			break;
		case 6:
			withdraw(accountNumber,3000);
			break;
		case 7:
			withdraw(accountNumber,3500);
			break;
		case 8:
			withdraw(accountNumber,4000);
			break;
		default:
			system("cls");
			gotoxy(40,14);
			cout<<"Sorry Wrong input: ";
			mainMenu();
			break;
		}	
	}
    void ATM::deposite(long int userActNo,long int bal)
    {
    	cin.ignore();
    	fstream file;
    	file.open("userDetails.txt",ios::in|ios::out|ios::ate|ios::binary);
    	if(!file)
    	  cout<<"file does not exists";
    	else
    	{
    		file.seekg(0);
    		file.read((char*)this,sizeof(*this));
    		while(!file.eof())
    		{
    			if(userActNo==actNo)
    			{
    				initAmt=initAmt+bal;
    				file.seekp(file.tellp()-sizeof(*this));
    				file.write((char*)this,sizeof(*this));
    				system("cls");
    				getFixedFrame();
    				Sleep(1000);
    				gotoxy(40,15);
					cout<<"your amount has been deposited successfully.";
					gotoxy(45,18);
					cout<<"your new account balance is:  "<<initAmt;
					Sleep(2000);
				}
				file.read((char*)this,sizeof(*this));
			}
			file.close();
		}
	}
	

void ATM::searchCustomerDetails(long int userActNo,long int userPin )  // function to handle Sub menu.
{
	char choice;
	fstream searchKey;
	searchKey.open("userDetails.txt",ios::in|ios::binary);
	searchKey.read((char*)this,sizeof(*this));
	while(!searchKey.eof())
	{
		if(userActNo==actNo&&userPin==pinNo)
		{
			int opt;
			subMenu();
			gotoxy(5,2);
			cout<<"Hello "<<fullName;
     		gotoxy(55,27);
     	    cin>>opt;
			switch(opt)
				{
					case 1:
						system("cls");
						gotoxy(45,15);
						cout<<"Enter the amount you want to deposite";
						gotoxy(50,20);
						cin>>balance;
					    deposite(actNo,balance);
						searchCustomerDetails(userActNo,userPin);
						break;
					case 2:
					    long int accountNumber,fundAmount;
						system("cls");
						gotoxy(40,14);
						cout<<"Enter the account number :   ";
						cin>>accountNumber;
						gotoxy(40,16);
						cout<<"Enter the fund Amount:   ";
						cin>>fundAmount;
						if(fundAmount<initAmt&&accountNumber!=actNo)
						{
							fundTransfer(accountNumber,fundAmount);
							getch();
							withdrawFund(userActNo,fundAmount);
						}
						else if(fundAmount<initAmt&&accountNumber==actNo)
						{
							system("cls");
							gotoxy(35,14);
							cout<<"You can not transfer the fund in your own account.";
							Sleep(1500);
							searchCustomerDetails(userActNo,userPin);
						}
						else
						{
							system("cls");
							gotoxy(35,15);
							cout<<"You do not have sufficient Balance in your account.";
							Sleep(1500);
							searchCustomerDetails(userActNo,userPin);
						}
                       	system("cls");
    				    gotoxy(35,13);
    				    cout<<"Do you want to contineu ?";
    				    gotoxy(40,15);
    				    cout<<"y. for Yes n. for No:    ";
						gotoxy(45,17);
						choice=getch();
						if(choice=='y'||choice=='Y')
						{
							system("cls");
							searchCustomerDetails(userActNo,userPin);
						}
						else if(choice=='n'||choice=='N')
						{
							mainMenu();
						}
						else
						{
							system("cls");
							gotoxy(35,14);
							cout<<"Invalid Choice.";
							Sleep(2000);
							exit();
							getch();
							mainMenu();
						}
						break;
					case 3:
						system("cls");
						gotoxy(34,14);
						cout<<"Enter your old Pin number:    ";
						long int oldPin;
						cin>>oldPin;
						pinChange(actNo,oldPin);
						mainMenu();
						break;
					case 4:
						system("cls");
						gotoxy(59,0);
                    	cout<<"Mr."<<fullName;                                //name of user on top right
                    	otherServices();
                    	Sleep(1000);
                    	searchCustomerDetails(userActNo,userPin);
						break;
					case 5:
						fastCash(userActNo);
						system("cls");
    				    gotoxy(35,13);
    				    cout<<"Do you want to contineu ?";
    				    gotoxy(40,15);
    				    cout<<"y. for Yes n. for No:    ";
						gotoxy(45,17);
						choice=getch();
						if(choice=='y'||choice=='Y')
						{
							system("cls");
							searchCustomerDetails(userActNo,userPin);
						}
						else if(choice=='n'||choice=='N')
						{
							mainMenu();
						}
						else
						{
							system("cls");
							gotoxy(35,14);
							cout<<"Invalid Choice.";
							Sleep(2000);
							exit();
							getch();
							mainMenu();
						}
						break;
					case 6:
						system("cls");
						gotoxy(30,12);
						cout<<"Enter the amount in multiple of 100";
						gotoxy(30,14);
						cout<<"the amount should not be greater than 10000";
						gotoxy(30,15);
						cout<<"otherwise your money can stuck in the machine";
						long int amount;
						gotoxy(35,17);
						cin>>amount;
						if(amount<=10000)
						{
					    	withdraw(userActNo,amount);
							Sleep(2000);
							system("cls");
    				    gotoxy(35,13);
    				    cout<<"Do you want to contineu ?";
    				    gotoxy(40,15);
    				    cout<<"y. for Yes n. for No:    ";
						gotoxy(45,17);
						choice=getch();
						if(choice=='y'||choice=='Y')
						{
							system("cls");
							searchCustomerDetails(userActNo,userPin);
						}
						else if(choice=='n'||choice=='N')
						{
							mainMenu();
						}
						else
						{
							system("cls");
							gotoxy(35,14);
							cout<<"Invalid Choice.";
							Sleep(2000);
							exit();
							getch();
							mainMenu();
						}
    				    
    		           }
				   		else
				   		{
				   			gotoxy(35,14);
				   			cout<<"the amount is greater than 1000";
				   			system("cls");
				   			searchCustomerDetails(userActNo,userPin);
					   }
						break;
					case 7:
                        balanceEnquiry(userActNo);
                        cin.get();
                        Sleep(500);
                        searchCustomerDetails(userActNo,userPin);
						break;
					case 8:
						break;
					default:
						system("cls");
						cout<<"Sorry You have entered invalid value";
						getch();
						subMenu();
						break;
				}
			}
			searchKey.read((char*)this,sizeof(*this));
		}
		if(userActNo!=actNo||userPin!=pinNo)
		{
			getFixedFrame();
			gotoxy(30,15);
			cout<<"You do not have an account in our bank.";
			Sleep(1000);
			mainMenu();
    	}
		searchKey.close();	
} 
/* 
void ATM::searchCustomerDetails(long int accountNumber,long int pinNumber)
{
	fstream searchkey;
	searchkey.open("userDetails.txt",ios::in|ios::binary);
	searchkey.read((char*)this,sizeof(*this));
	showCustomerDetails();
	if(accountNumber==actNo&&pinNumber==pinNo)
	{
		cout<<"hey you got it";
	}
	else 
	   cout<<"sorry";
}  */
void ATM::showCustomerDetails()
{
	cout<<index<<"\t";
	cout<<actNo<<"\t   ";
//   cout<<pinNo<<"\t ";
	cout<<fullName<<"\t   ";
	cout<<fatherName<<"\t";
	cout<<dob<<"\t     ";
	cout<<email<<"\t   ";
	cout<<initAmt<<endl;
}
void ATM::readCustomerDetails()
{
	ifstream fin;
	fin.open("UserDetails.txt",ios::in);
	if(!fin)
	{
		cout<<"file does not exits\n";
	}
	else
	{
		fin.read((char*)this,sizeof(*this));
		while(!fin.eof())
		{
		showCustomerDetails();
		fin.read((char*)this,sizeof(*this));
     	}
     	fin.close();
	}
	
}
  void Confidencial::showAccountMemberDetails()
  {
  	system("cls");
  	ATM a;
    cout<<"index\tA/c No\t  Customer Name\t  Father Name\tDate of Birth\t\tGmail Of Customer\tA/c Balance"<<endl;
    a.readCustomerDetails();
    
  }


  void ATM::mainMenu()
  {
  	
  	system("color 2E");
  	system("cls");
  	mainFrame();
  	gotoxy(48,10);
  	cout<<"CREATE AN ACCOUNT";
  	Sleep(100);
  	gotoxy(35,14);
  	cout<<"IF YOU HAVE AN ACCOUNT THEN PRESS P TO PROCEED";
  	gotoxy(85,20);
  	cout<<"HELP";
  	gotoxy(10,20);
  	cout<<"EXIT";
  	gotoxy(5,24);
  	cout<<"C: CREATE A NEW ACCOUNT     ";
  	cout<<"P: PROCEED TO YOUR ACCOUNT";
  	Sleep(500);
    gotoxy(5,26);
    cout<<"H:  HELP  ";
    cout<<"A: LOGIN AS ADMIN  ";
    cout<<"E: EXIT";
    gotoxy(6,2);
	cout<<"Admin";
	gotoxy(70,25);
     cout<<"";
    char choice = getch();
    if(choice == 'C' || choice == 'c')
    	createAccount();
    else if(choice == 'P' || choice == 'p')
        proceed();
    else if(choice == 'H'|| choice == 'h')
        help();
    else if(choice=='E'|| choice=='e')
        exit();	
    else if(choice == 'A'|| choice == 'a')
        admin();
    else
       {
       	gotoxy(80,25);
       	cout<<"INVALID OPTION";
       	Sleep(2000);
       	mainMenu();
	   }
  }
  
  void ATM::admin()
  {
  	
	char password[16],adminName[16];
	char pass[]="Sudhanshu1234",admName[]="Anshudhanshu";
	char ch;
	int i=0;
  	system("cls");
  	system("color 2E");
  	gotoxy(20,14);
  	cout<<"Enter the username of Admin:      ";
  	cin>>adminName;
  	system("cls");
  	gotoxy(20,14);
  	cout<<"Enter the password:               ";
  	while(true)
   {
   	    ch=getch();
   	    if(ch==enter)                     // If enter key  is pressed
			break;	
		cout<<"*";
  		password[i]=ch;                    
  		i++;
	  }
	  password[i]=NULL;
  	system("cls");
//  	cout<<"your user name is  "<<adminName<<endl;
//  	cout<<"your password is  "<<password<<endl; 
   if(!strcmp(password,"Sudhanshu@1234")&&!strcmp(adminName,"Anshudhanshu"))
{
	admin:
    gotoxy(45,5); 	
  	cout<<"WELCOME ADMIN";
  	gotoxy(40,6);
  	flow("------------------------------");
  	Sleep(500);
  	gotoxy(30,10);
  	cout<<"d. for details of Account members";
  	gotoxy(30,13);
  	cout<<"t. details of all transactions";
  	gotoxy(30,16);
  	cout<<"m. for main menu";
  	gotoxy(70,25);
  	cout<<"Please Select your option:  ";
  	char ch=getch();
  	if(ch=='d'||ch=='D')
  	{   Confidencial conf;
     	conf.showAccountMemberDetails();
  	    getch();
  	    system("cls");
  	    goto admin;
	  }
	else if(ch=='t'||ch=='T')
	  {
	  	allTransactions();
	  	cin.get();
  	    goto admin;
	  }
	else if(ch=='m'||ch=='M')
	    mainMenu();
	else 
	  {
	  	gotoxy(45,15);
	  	cout<<"SORRY! you did not enter the right choice.";
	  	mainMenu();
	   } 
  }
  else
  {
  	gotoxy(30,12);
  	cout<<"you have not entered a valide username or password";
  	gotoxy(34,14);
  	cout<<"press enter to try again or m for main menu";
  	char o;
  	o=getch();
  	if(o=='M'||o=='m')
  	  mainMenu();
  	else if(o==enter)                              // 13 is used to detect the enter key
  	  admin();
  	else
  	{
  		gotoxy(35,15);
  	  cout<<"Sorry you have not entered a valid key.";
  	  getch();
	  exit();	
	  }
  }   
  }

  void allTransactions()
  {
  	system("cls");
  	cout<<"transaction details welcomes you.";
  }
  void ATM::exit()
  {
  	system("cls");
  	system("color 70");
  	gotoxy(6,6);
  	cout<<"HELLO FRIENDS. GOOD TO SEE YOU.";
  	gotoxy(6,10);
  	cout<<"THIS IS THE PROJECT OF ATM MACHINE SYSTEM DONE IN MY SECOND SEMESTER.";
  	gotoxy(6,11);
  	cout<<"THE PROJECT HAVE BEEN CODED IN C/C++ LANGUAGE.";
  	gotoxy(6,12);
  	cout<<"THE CONCEPT OF OBJECT ORIENTED PROGRAMING IN C++ HAS ALSO BEEN USED IN THIS PROJECT.";
  	gotoxy(6,13);
  	cout<<"I AM IN PROGRESS OF MAKING THIS PROJECT MORE EFFICIENT.";
  	gotoxy(6,17);
  	cout<<"THANK YOU.";
  	gotoxy(6,20);
  	cout<<"for any suggession or any contribution in this project,";
  	gotoxy(6,21);
  	cout<<"PLEASE CONTACT AT: sr363298@gmail.com.";
  	gotoxy(6,22);
  	cout<<"or CALL AT: 9936566389.";
  	gotoxy(80,28);
  	cout<<"-SUDHANSHU RAWAT";
  	cin.get();
  	system("cls");
  	system("color 07");
  	gotoxy(45,15);
  	cout<<"THANK YOU FOR USING RBI ATM.";
  	gotoxy(1,27);
  	cout<<" ";
  }
  void ATM::help()
  {    
    system("cls");
    system("color 70");
  		for(int i=0;i<29;i++)
  	{
  		gotoxy(25,i);
  		cout<<"|";
  		gotoxy(95,i);
  		cout<<"|";
	  }
	    gotoxy(26,26);
	  cout<<"For more information, contact:";
	  gotoxy(26,27);
	  cout<<"Call our 24x7 helpline through toll free number 1800 100 2400";
	  gotoxy(26,28);
	  cout<<"contact at sr363298@gmail.com";  
	  gotoxy(26,2);
	  flow("In oreder to use our ATM services please be sure that,");
	  gotoxy(26,4);
	  flow("you might have opened an account previously.");
	  gotoxy(26,8);
	  flow("ATM services");
	  gotoxy(26,12);
	  flow("Cash Withdrawal:  Use this service to wothdraw amount(40,000/-per day)");
	  gotoxy(26,14);
	  flow("Fast Cash:  This enables to withdraw your prefered amount in a touch.");
	  gotoxy(26,16);
	  flow("Pin Change:  Use this option to change your pin number.");
	  gotoxy(26,18);
	  flow("Balance Enquiry:  To check the current balance in your account.");
	  gotoxy(26,20);
	  flow("Mini Statment:  Keep track the record of your all transactions.");
	  gotoxy(26,22);
	  flow("Fund Transfer:  Transfers amount instantly to your loved once.");
	  gotoxy(65,28);
	  cin.get();
	  mainMenu();	
  }
  void ATM::proceed()
  {
  	start:
  	long int userPin,userActNo;
  	system("cls");
  	system("color 5F");
  	mainFrame();
  	int testNumber;
  	char option;
  	gotoxy(6,5);
  	cout<<"enter any number ";
  	gotoxy(6,7);
	cout<<"between 10 and 99";
	gotoxy(6,9);
	cout<<"for e.g. 25";
	gotoxy(6,13);
  	cout<<"press y if the";
  	gotoxy(6,15);
  	cout<<"number is displayed";
  	gotoxy(6,19);
  	cout<<"press n if the";
  	gotoxy(6,21);
  	cout<<"number is not displayed"; 
  	gotoxy(60,25);
	cin>>testNumber;
	gotoxy(60,15);
	option=getch();
	if(testNumber<=99&&testNumber>=10&&option=='y')
	{
		system("cls");
    	gotoxy(30,15);
		cout<<"ENTER YOUR ACCOUNT NUMBER:   ";
		cin>>userActNo;
		system("cls");
		getFixedFrame();
		gotoxy(45,2);
		cout<<"RBI ATM SERVICE";
		gotoxy(8,12);
		cout<<"YOUR PIN IS CONFIDENCIAL";
		gotoxy(8,14);
		cout<<"NO BODY SHOULD SEE THE PIN";
		gotoxy(8,16);
		cout<<"WHILE YOU ARE ENTERING IT.";
	    gotoxy(8,18);
	    cout<<"MAKE YOUR PIN MORE BY";
	    gotoxy(8,20);
	    cout<<"BY CHANGING IT FREQUENTLY.";
		gotoxy(50,7);
		cout<<"ENTER YOUR PIN:";
		gotoxy(60,15);
		cin>>userPin;	
		system("cls");
		searchCustomerDetails(userActNo,userPin);
	}
	else if(testNumber<=99&&testNumber>=10&&option=='n')
	mainMenu();
	else 
	{
		gotoxy(59,27);
		cout<<"Please Enter as you are Instructed above";
		Sleep(1500);
		goto start;
	}
  }
  void ATM::subMenu()
  {
  	system("cls");
  	getFixedFrame();
  	gotoxy(14,10);
  	cout<<"1. CASH DEPOSITE";
  	gotoxy(14,13);
  	cout<<"2. FUND TRANSFER";
  	gotoxy(14,16);
  	cout<<"3. PIN CHANGE";
  	gotoxy(14,19);
  	cout<<"4. OTHER SERVICES";
  	gotoxy(70,10);
  	cout<<"5. FAST CASH";
  	gotoxy(70,13);
  	cout<<"6. CASH WITHDRAWL";
  	gotoxy(70,16);
  	cout<<"7. BALANCE INQUIRY";
  	gotoxy(70,19);
  	cout<<"8. MINI STATEMENT";
  	Sleep(500);
  	gotoxy(45,4);
  	flow("Select your option.");
  }
  void ATM::createAccount()
  {
//  	HANDLE color = GetStdHandle(STD_OUTPUT_HANDLE);
  	system("cls");
  	system("color 60");
  	for(int i=0;i<29;i++)
  	{
  		gotoxy(25,i);
  		cout<<"|";
  		gotoxy(95,i);
  		cout<<"|";
	  }
//  	SetConsoleTextAttribute(color,14);
    gotoxy(50,2);
    flow("APPLICATION FORM");
    gotoxy(48,3);
    flow("---------------------");
    Sleep(500);
    cin.ignore();
    gotoxy(45,5);
    cout<<"Full Name:     ";
	cin.getline(fullName,39);
    gotoxy(45,7);
   	cout<<"Father/Guardian Name:    ";
	cin.getline(fatherName,39);
	gotoxy(45,9);
    cout<<"Date of Birth(dd/mm/yyyy):    ";
    cin.getline(dob,14);
	gotoxy(45,11);  
	cout<<"Account Type(S/C):  ";
	cin.getline(accountType,2);
	 gotoxy(45,13);
	cout<<"Pincode:  ";
	cin>>pincode;
	cin.ignore(); 
	 gotoxy(45,15);
	cout<<"City:   ";
	cin.getline(city,39);
	 gotoxy(45,17);
	cout<<"Email:   ";
	cin.getline(email,39);
	 gotoxy(45,19);
	cout<<"Enter Initial Amount(>=500): ";
	cin>>initAmt;
	cin.ignore();
	 gotoxy(65,21);
	cout<<"PRESS ENTER TO SUBMIT";
	cin.get();
	 ifstream getActNo;
    getActNo.open("confidencial.txt",ios::in|ios::binary);
    Confidencial c;
    c.pinNumber=rand()%5000;
    getActNo.seekg(0,ios::end);
	if(getActNo.tellg()==0)
	{
	  c.accountNumber=4419981;
	  strcpy(c.customerName,fullName);                             // function to copy one string from another string
	  c.storeConfidencialDetails();
	} 
    else
    {   
        strcpy(c.customerName,fullName);
    	c.readConfidencialDetails();
    	c.accountNumber=c.accountNumber+1;
    	c.pinNumber=c.pinNumber+rand()%5;
        c.storeConfidencialDetails();
		index=index+1; 	
   }
   pinNo=c.pinNumber;                                         // transfer the generated pin into customer details file.
   actNo=c.accountNumber;                        // copy the generated account number to the customer details file.
   storeCustomerDetails();
   getActNo.close();
    system("cls");
    system("color 5F");
    gotoxy(40,15);
    cout<<"Creating Account";
    for(int i=57;i<60;i++)
    {
    	gotoxy(i,15);
    	cout<<".";
    	Sleep(800);
	}
	system("cls");
	getFixedFrame();
    gotoxy(40,8);
    cout<<"YOUR ACCOUNT HAS BEEN CREATED SUCCESSFULLY.";
    gotoxy(40,10);
	cout<<"YOUR ACCOUNT NUMBER IS:        "<<c.accountNumber;
    gotoxy(45,12);
    cout<<"YOUR ATM PIN IS:          "<<c.pinNumber;
    gotoxy(10,20);
    cout<<"NOTE: THESE ARE ACCOUNT CREDIENCIALS FOR USING ATM SERVICES.";
    getch();
	system("cls");
//	readCustomerDetails();
    gotoxy(50,24);
    cout<<"MAIN MENU:   PRESS ENTER.";
    cin.get();
    mainMenu();
  }
int main()
{
	ATM key;
//	int second =50;
    load();
   Sleep(500);
   getWelcomeFrame();
   gotoxy(7,7);
   flow("The random number generated range 1 to 100 is:");
   cout<<" "<<rand()%100 +1;
   Sleep(1000);
   key.mainMenu();
   getch();
   
}

