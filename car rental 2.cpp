#include <iostream>  
#include <fstream>		
#include <unistd.h>   
#include <iomanip> 
#include <ctime>	
#include<conio.h>

using namespace std;

class login{
public:
	void loginpage();
    void registr();
    void admin ();
};

class welcome_menu{
	public :
		void login_menu();
};

class Customer    
{
	public:
		string customer_Name; 
	    int car_model;
	    int car_Number;
	  //  int Car_No;
};

class Rent : public Customer 
{
	private:
		int numberOfDays;
		int rent_Fee;
		string mobile;
		char str[200];		
	public:	
		void rented();
		void fileReader(char carFile[20]);
		void data();
		void invoiceAmount(int,int);	
		void invoiceRecord(int,int,int);
		void login_menu();  		
};

void welcome()
{
welcome_menu m;	
ifstream inputFile("welcome.txt");
	if(!inputFile) 
	{
		cout << "Cannot open input file.\n";
	}
	char str[1000];
	while(inputFile) 
	{
		inputFile.getline(str, 1000);  
		if(inputFile) 
			cout << str << endl;
  	}
  	inputFile.close();
  	 sleep(1);  

	cout<<"\n WEL COME TO DVA CAR'S RENTAL SYSTEM....."<<endl;
	
	cout<<"\nloading up files....."<<endl;
	system ("CLS"); 
	m.login_menu();	 
}
void Rent::fileReader(char carFile[20])
{
	ifstream inputFile;
	inputFile.open(carFile); 
	if(!inputFile)
	{
		cout << "Error in printing file. File not found!" << endl;
	}
	while(inputFile) 
	{
		inputFile.getline(str, 200);  
		if(inputFile) 
			cout << str << endl;
	}
}
void login :: loginpage()
{
	    Rent rent;
        int count;
        string user,pass,u,p;
        system("cls");
        cout<<"please enter the following details"<<endl;
        cout<<"USERNAME :";
        cin>>user;
        cout<<"PASSWORD :";
        cin>>pass;       
        ifstream input("database.txt");
        while(input>>u>>p)
        {
                if(u==user && p==pass)
                cout<<'*';
                
                {
                        count=1;
                        system("cls");
                }
        }
        input.close();
        if(count==1)
        {
                cout<<"\n Hello  "<<user<<"\n LOGIN SUCESS\n We come to DVA Car.\n";
                cin.get();
                cin.get();
                rent.data();
        }
        else
        {
                cout<<"\nLOGIN ERROR\nPlease check your username and password\n";       
        }
}
void login:: registr()
{
        Rent rent;
        welcome_menu m;
        string reguser,regpass,ru,rp;
        system("cls");
        cout<<"Enter the username :";
        cin>>reguser;
        cout<<"\nEnter the password :";
        cin>>regpass;
        
        ofstream reg("database.txt",ios::app);
        reg<<reguser<<' '<<regpass<<endl;
        system("cls");
        cout<<"\nRegistration Sucessful\n";
        system("cls");
        m.login_menu();       
}
void login:: admin()
{
	 string admuser,admpass;
        system("cls");
        char adminID[]="DVA", password[]="1225", id[20], p[20];
        int n=1, x, y;

         printf("\nAdmin_ID:");
                   scanf("%s", &id);
                   fflush(stdout);
                    printf("\nPassword:");
                   scanf("%s", &p);
                   fflush(stdout);
                    x=strcmp(id, adminID);
                    y=strcmp(p, password);
                   if(x==0 && y==0)
				   {
                    printf("\nSucessfully Logged In\n\n");
                }
                 else 
				   {
                    printf("\nWrong Password, try again", 5-n);
                    getch();
            n++;   }
         if(n>3)
		 {
          printf("\nAccess Denied");
          getch();
         }
         {
		 
         ifstream infile;
         infile.open("bill.txt",ios::in);
        
        if(!infile){
        	cout<<"Error opening file";
		}
		string avi;
		while(!infile.eof()){
			
			infile>>avi;
	    	cout<<"Customer Name : "<<avi<<endl;
	    	infile>>avi;
	    	cout<<"Mobile Number : "<<avi<<endl;
	    	infile>>avi;
	    	cout<<"Car Model : "<<avi<<endl;
	    	infile>>avi;
	    	cout<<"Car No : "<<avi<<endl;
	    	infile>>avi;
	    	cout<<"Number of days : "<<avi<<endl;
	    	infile>>avi;
	    	cout<<"Rental Amount : "<<avi<<endl<<endl;

		}
	     infile.close();
	    getch();
	    system("cls");
	    ifstream fileReader("thanks.txt");
//	    string avi;
	    while(!fileReader.eof())
	    {
	    	
	    	getline(fileReader,avi);
	    	cout<<avi<<endl;
		}
		fileReader.close();
		getch();
	 }
	 
     
}
void welcome_menu :: login_menu()
{
		a:
		system("cls");
        int choice;
        login page;
        cout<<"***********************************************************************\n\n\n";
        cout<<"                      Welcome to  DVA Car Rental                               \n\n";
        cout<<"*******************        MENU        *******************************\n\n";
        cout<<                         "1.LOGIN"<<endl;                                    
        cout<<                         "2.REGISTER"<<endl;
        cout<<                         "3.ADMIN USERNAME"<<endl;
        cout<<                          "4.Exit"<<endl;
        cout<<"\nEnter your choice :";
        cin>>choice;
        cout<<endl;
        switch(choice)
        {
                case 1:
                        page.loginpage();
                        break;
                case 2:
                        page.registr();
                        break;
                case 3:
                        page.admin();
                        break;
                case 4:

                        cout<<"Thanks from DVA Cars";
                        exit(0);
                default:
                        system("cls");
                        cout<<"You've made a mistake , give it a try again\n"<<endl;                        
        }
        goto a;
}
		
void Rent::data()
{
	Rent rent;
	do
	{
		l:
		system("cls");
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\t\t\t\tChoose a Car from the options below. \n ";
	    cout <<	"\t\t\t\tChoose a number corresponding to the car you want to Select." << endl; 
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
		cout << "\t\t\t\t1. Toyota 2021."<<endl;
	    cout << "\t\t\t\t2. Hyundai 2019."<<endl;
	    cout << "\t\t\t\t3. Ford 2020."<<endl;
	    cout <<"\t\t\t\t4. BMW 2022."<<endl;
	    cout <<"\t\t\t\t5. Bullet 350."<<endl;
	    cout <<"\t\t\t\t6. duke 250."<<endl;
	    cout <<"\t\t\t\t7. Thar."<<endl;
	    cout <<"\t\t\t\t8. skoda."<<endl;
	    cout <<"\t\t\t\t9. bullero."<<endl;
	    cout <<"\t\t\t\t10. Jeep."<<endl;
	    cout << endl;
	    cout << "\t\t\t\t__________________________________________________________________"<<endl;
	    cout << "\n\t\t\t\tChoose: ";
	    cin >> car_Number;
	    cout << endl;
	 		
		string c,mb;
		int n,md,r,d;	
		ifstream file("bill.txt");
	while(!file.eof()){
		file >> c  ;
	    file >> mb ;
	    file >> md ;
	    file >> n ;
	 	file >> d ;
	 	file >> r ;
	    
	    if(n==car_Number){
	    	cout<<"Car is already Book\n";
	    	getch();
	    	goto l;
		}

	}
	file.close();
		
	 	switch(car_Number)
		 {
	 		case 1:
	 			system("CLS");
	 			cout<<"You have choosed Toyota model 2021"<<endl;
	 			fileReader("Toyota.txt");
				sleep(1);
				break;
			case 2:
				system("CLS");
	  			cout<<"You have choosed Hyundai model 2019"<<endl;
				fileReader("Hyundai.txt");
		     	sleep(1);
				break;	
			case 3:
		     	system("CLS");
		     	cout<<"You have choosed Ford model 2020"<<endl;
			    fileReader("Ford.txt");
		     	sleep(1);
		   		break; 
			case 4:
			    system("CLS");
		     	cout<<"You have choosed BMW model 2022"<<endl;
			    fileReader("Bmw.txt");
		     	sleep(1);
		   		break;	
			case 5:
			    system("CLS");
		     	cout<<"You have choosed Bullet model 2022"<<endl;
			    fileReader("Bullet.txt");
		     	sleep(1);
		   		break;	
		    case 6:
			    system("CLS");
		     	cout<<"You have choosed duke model 2022"<<endl;
			    fileReader("duke.txt");
		     	sleep(1);
		   		break;
			case 7:
			    system("CLS");
		     	cout<<"You have choosed Thar model 2022"<<endl;
			    fileReader("thar.txt");
		     	sleep(1);
		   		break;
				   
			case 8:
			    system("CLS");
		     	cout<<"You have choosed Thar model 2022"<<endl;
			    fileReader("skoda.txt");
		     	sleep(1);
		   		break;
				   	
			case 9:
			    system("CLS");
		     	cout<<"You have choosed Thar model 2022"<<endl;
			    fileReader("bullero.txt");
		     	sleep(1);
		   		break;
				   	
			 case 10:
			    system("CLS");
		     	cout<<"You have choosed Thar model 2022"<<endl;
			    fileReader("Jeep.txt");
		     	sleep(1);
		   		break;				
			default:
		     	cout<<"Invaild Car Model. Please try again!"<<endl;
		     	sleep(1.5);
		     	goto l;
		}
		
		
 }



    while(car_model < 1 && car_model > 3);
	
	cout<<"________________________________________________________________________________________________"<<endl;
  	cout << "Please provide following information : "<<endl; 
	    	
	        

	
	cout<<"Number of days you wish to rent the car : ";
	cin >> numberOfDays;
	
	rent.invoiceAmount(numberOfDays,car_Number);
	cout<<endl;
}

void Rent::invoiceAmount(int numberOfDays,int car_Number)
{

	Rent rent;
	sleep(0.5);
	system ("CLS");
	cout<<"Calculating rent. Please wait......"<<endl;
	sleep(1);
	if(car_Number == 1)
		rent_Fee = numberOfDays*150;
	if(car_Number == 2)
		rent_Fee = numberOfDays*160;
	if(car_Number == 3)
		rent_Fee = numberOfDays*175;
	if(car_Number == 4)
		rent_Fee = numberOfDays*500;
	if(car_Number == 5)
		rent_Fee = numberOfDays*270;
	if(car_Number == 6)
		rent_Fee = numberOfDays*350;
	if(car_Number == 7)
		rent_Fee = numberOfDays*500;
	if(car_Number == 8)
		rent_Fee = numberOfDays*800;
	if(car_Number == 9)
		rent_Fee = numberOfDays*150;
	if(car_Number == 10)
		rent_Fee = numberOfDays*450;
    
	rent.invoiceRecord(rent_Fee,numberOfDays,car_Number);
}
	   
void Rent::invoiceRecord(int rent_Fee,int numberOfDays,int car_Number)
{
	a1:
		system("cls");
	  cout << "Enter your personal details"<<endl;
	cout << "Enter Mobile Number : ";
	cin.sync();
	getline(cin,mobile);
	int length=mobile.length();
	if(length==10){
		
	}
	else{
		cout<<"Invalid Mobile No.    ";
		getch();
		goto a1;
	}
	
	cout<<"Enter your name: ";
	cin.sync();
	cin >> customer_Name;
	time_t now  = time(0);		
	char *date = ctime(&now); 
	cout << setw(80) << date << endl;
	cout << "\n\t\t                       CAR RENTAL - CUSTOMER INVOICE                  "<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	| Customer Name "<<"				|"<< setw(10) <<customer_Name<<" |"<<endl;
	cout << "\t\t	| Car Model  "<<"					|"<< setw(10) <<car_model<<" |"<<endl;    
	cout << "\t\t	| Mobile No.  "<<"					|"<< setw(10) <<mobile<<" |"<<endl;
	cout << "\t\t	| Number of days  "<<"				|"<< setw(10) <<numberOfDays<<" |"<<endl;
	cout << "\t\t	| Rental Amount  "<<"				|"<< setw(10) <<rent_Fee<<" |"<<endl;  
	cout << "\t\t	|___________________________________________________________|"<<endl;
	cout << "\t\t	| Total Rental Amount    "<<"			|"<<setw(6)<<"R " << rent_Fee<<" |"<<endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
	cout << "\t\t	 NOTE: This is a computer generated invoce. "<<endl;
	cout << "\t\t	       It does not require an authorised signture."<<endl;
	cout << "\t\t	***********************************************************" << endl;
	cout << "\t\t	You are advised to pay up the amount before due date."<<endl;
	cout << "\t\t	Otherwise penelty fee will be applied"<<endl;
	cout << "\t\t	***********************************************************" << endl;
   
      ofstream file("bill.txt",ios::app); 
    if (!file.is_open())
 { 
   cout << "Failed to open file"; 
   
} 
     file <<endl<<customer_Name<<endl;
     file << mobile << endl;
     file << car_model << endl;
     file << car_Number << endl;
     file << numberOfDays << endl;
     file << rent_Fee;
     file.close(); 
     cout << "Bill stored successfully"; 
	system("PAUSE");
	system ("CLS");
	fileReader("thanks.txt");
}
void welcome();
int main()
{

	Rent rent;	 
	 welcome();
	return 0;
}

