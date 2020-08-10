//***********************************************************************************************************************************
//*                                          Header files used in this Project
//***********************************************************************************************************************************
#include<ctime>
#include<iostream>
#include<string.h>
#include<fstream>                /*THis project is made by Akash khandelwal*/
#include<iomanip>                //Emailid:-skykhandelwal1999@gmail.com
#include<Windows.h>
#include<conio.h>
#include<stdlib.h>
#define ENTER 13
#define TAB 9
#define BKSP 8
#define SPACE 32

using namespace std;
/********************************************************************************************************************************
*                                                                                                                               *
*                                                                                                                               *
*                                              START PROJECT                                                                    *                                           
*                                                                                                                               * 
*                                                                                                                               *
***********************************************************************************************************************************/
 


//Class declaration:
class Atm
{
  private://Variable declaration:
    string user,account,password,birthdate;
    int id,age;
    char email[100];
    char number[100];
    long int amount;
    char gender;
    string username;
    int currentid;
  public: //Function declration:
    void design();
    void admininfo();
    void allusersdetails();
    void deleteusersdetails();
    void searchusersdetails(); 
    void blacklistdetails();
    void blockuser();
    void adminlogin();
    
    //void balanceupdate(int,int);
 /*CUSTOMER FUNCTIONS DEFINITION*/
    void dep(int);
    void check(int,int);
    void modify();
    void withdraw(int);   
    void customerlogin();
    void createAccount();
    void withdrawmoney(int); 
    void depositmoney(int);
    void profile();
    void transfermoney(int);
    void deleteaccount(int);
    void currentbalance(int);
    void mainpanel();
    void mainmenu(int,string);
    void adminpanel();
    void unblockAccount();
    void modifydetails(int);
    int getid(){ return id;  }
    string getpassword(){ return password;}
}obj;
//Functions definition:
/*This is desiging part of the main function*/
void Atm::dep(int x)
{
  amount+=x;
}
void Atm::withdraw(int x)
{
  if(x>amount || amount<=200)
  {
     cout<<"\n you can't withdraw your amount balance getting low(less than or equal to 200)";
  }
  else
  {
  amount-=x;
  }
}
void Atm::design()
 {
   system("cls");
   system("color 5B");
   for(int i=0;i<=5;i++)
   {
    system("cls");
    Sleep(200);
    system("color A");
    cout<<"          \t\t\t\n|=============================================================================================================================|";
    cout<<endl;
    cout<<"          \t\t\t\n|*****************************************************************************************************************************|";
    cout<<endl;
    cout<<"          \t\t\t\n|*********************************************WELCOME*************************************************************************|";
    cout<<endl;
    cout<<"          \t\t\t\n|**********************************************TO*****************************************************************************|";
    cout<<endl;
    cout<<"          \t\t\t\n|*******************************************BANK SERVICES**********************************************************************|";
    cout<<endl;
    cout<<"          \t\t\t\n|*****************************************************************************************************************************|";
    cout<<endl;
    cout<<"          \t\t\t\n|=============================================================================================================================|";
    cout<<endl;
    Sleep(200);
 }
}
//ADMINISTRATOR SECTION FUNCTIONS Definition Start*************************************************************************************//
//*********************************************************************************************************************//

/*This is Administrator information****************************************-*/
void Atm::admininfo()
{
system("cls");
cout<<"\n \t\t\t\t\t****************Administrator information*****************************";
cout<<"\n ADMIN NAME is: Akash khandelwal"<<endl;
cout<<"\n ADMINISTRATOR ID is:492600"<<endl;
cout<<"\n Password is:akash26";
cout<<endl;
cout<<"Press any key to continue:";
getch();

}

//this module admin to unblock his account
void Atm::unblockAccount()
{
system("cls");
int n,flag=0;
cout<<"\n Enter user id to blocked:\n ";
cin>>n;
ifstream fin;
ofstream tout,fout;
fin.open("blacklist.dat",ios::in|ios::binary);
tout.open("templist.dat",ios::out|ios::binary);
fout.open("Credential.dat",ios::out|ios::app|ios::binary);
if(fin)
{
while(fin.read((char*)&obj,sizeof(obj)))
    { 
       if(n==getid())
       {   
         flag++;
         fout.write((char*)&obj,sizeof(obj));
       }
       else
       {

         tout.write((char*)&obj,sizeof(obj));
       }
    } 
    fin.close();
    fout.close();
    tout.close();
    remove("blacklist.dat");
    rename("templist.dat","blacklist.dat");
    if(flag==0)
    {
      cout<<"\n Invalid user id";
    }
}   
  else
  {
    system("cls");
    Sleep(200);
    cout<<"Unable to process your request bcoz file doesn't  exist";
  }   
}   

/*All user details this is Administrator section */
void Atm::allusersdetails()
{
 system("cls");
 cout<<"\t\t\t\t\t\t\t\n******************ALL USER DETAILS*****************************";
 ifstream fin;
 fin.open("Credential.dat",ios::in|ios::binary);
 if(fin)
 {
 while(fin.read((char*)&obj,sizeof(obj)))
 {
  obj.profile();
 }
 fin.close();
 cout<<"\n\nData Reading from File Successfully Done....\n";
 cout<<endl;
 cout<<"\n Press any key to continue...............................";
 getch();
 }
 else
 {
   cout<<"\n File doesn't exist";
   cout<<endl;
   cout<<"\n Press any key to continue..............................";
   getch();
 }
}

/* It is all user detais this is Administrator section*/
void Atm::deleteusersdetails()
{
 //Delete all users
 char ch;
 cout<<"\n Are your sure it will erase all data as well as file(y/n)";
 cin>>ch;
 ifstream fin;
 fin.open("Credential.dat",ios::in|ios::binary);
 if(fin)
 {
 if(ch=='y'|| ch=='Y')
 {
  fin.close(); 
  remove("Credential.dat");
 }
 cout<<"\n DATA DELETD SUCCESSFULLY";
  cout<<endl;
  cout<<"\n Press any key to continue..............................";
  getch();

 }
 else
 {
   cout<<"file doesn't exist";
    cout<<endl;
    cout<<"\n Press any key to continue..............................";
    getch();
 }
}


/*It gives Specific users by search this is Administrator section*/
void Atm::searchusersdetails()
{
//Search Specific users in file:
int n;
int flag=0;
cout<<"\n Enter to search specific users by id:";
cin>>n;
ifstream fin;
fin.open("Credential.dat",ios::in|ios::binary);
if(fin)
{
while(fin.read((char*)&obj,sizeof(obj)))
 {
  if(n==getid())
  {
     obj.profile();
     flag++;
  }
 }
 fin.close();
 if(flag==0)
 {
   cout<<"\n This user doesn't exist or invalid user ";
    cout<<endl;
    cout<<"\n Press any key to continue..............................";
   getch();
 }
}
else
 {
     cout<<"file doesn't exist";
      cout<<endl;
      cout<<"\n Press any key to continue..............................";
      getch();
 } 
}

/*Black list details Admin section*/
void Atm::blacklistdetails()
{
system("cls");
cout<<"\n*****************************BLACK LIST SECTION***************************************";
ifstream fin;
fin.open("blacklist.dat",ios::binary|ios::in);
if(fin)
{
while(fin.read((char*)&obj,sizeof(obj)))
{
obj.profile();
}
fin.close();
 cout<<endl;
 cout<<"\n Press any key to continue..............................";
 getch();
}
else
{
  cout<<"\n the file doesn't exist";
   cout<<endl;
   cout<<"\n Press any key to continue..............................";
   getch();
}

}
//Block any user by id admin section:
void Atm::blockuser()
{
system("cls");
int n,flag=0;
cout<<"\n*****************************BLOCK ANY USER***************************************";
cout<<"\n Enter user id no. moved to blacklist";
cin>>n;
ifstream fin;
ofstream fout,bout;
bout.open("blacklist.dat",ios::binary|ios::out|ios::app);
fout.open("TempCredential.dat",ios::binary|ios::out|ios::app);
fin.open("Credential.dat",ios::in|ios::binary);
if(fin)
{
while(fin.read((char*)&obj,sizeof(obj)))
 {
  if(n==getid())
  {
     cout<<"\n this customer details going to blacklist section";    
     obj.profile();
     bout.write((char*)&obj,sizeof(obj));
     flag++;
  }
  else
  {
   fout.write((char*)&obj,sizeof(obj));
  }
 }
 fin.close();
 fout.close();
 bout.close();
 if(flag==0)
 {
   cout<<"\n This user doesn't exist or invalid user ";
 }
 remove("Credential.dat");
 rename("TempCredential.dat","Credential.dat");
}
 else
 {

   cout<<"\n The file doesn't exist";
 }
}

/*THIS Admin  Login validation Section:*/
void Atm::adminlogin() 
{
  int Adminid,i=0;
  char password[100],ch;
  string temppass;
  system("cls");
  cout<<"\t\t\n**********************************Administrator Login************************************";
  cout<<"\t\t\t\t\t\t\t\t\nEnter your Adminstrator id:";
  cin>>Adminid;
  cout<<"\t\t\t\t\t\t\t\t\nEnter your Password:";
  while(1)//using password encryption
{
   ch=getch();
   if(ch==ENTER)
    {
       password[i]='\0';
       break;
    }
   else if(ch==BKSP)
   {
   if(i>0)
   {
       i--;
       cout<<"\b\b";
   }
  }
  else if(ch==TAB || ch==SPACE)
  {
   continue;
  }
  else
  {
     password[i]=ch;
     i++;
     cout<<"*";
   }
}
temppass=string(password);
system("cls");
cout<<"\n Wait some moment validating:";
Sleep(300);
system("cls");
 if(Adminid==492600 && temppass=="akash26")
{
  obj.adminpanel();
}
else
 {
   cout<<"\n Invalid Adminid and password:";
   cout<<"\n\n Try Again:";
   Sleep(300);
   obj.mainpanel();
 }

} 

/*ADMINISTRATION SECTION END*************************************************///
//*************************************************************************************


/*Customer Section functions definiton Start****************************///
//******************************************************************************************************///

/*Customer validation section*/
void Atm::customerlogin()
{
  int userid,i=0;
  int login=0;
  char password[100],ch;
  string temppass,username;
do
 { 
  system("cls");
  cout<<"\t\t\t\t\t\t\n**************Customer Login***************************";
  cout<<"\t\t\t\t\t\t\n Enter your userid:"<<endl;
  cin>>userid;
  cout<<"\t\t\t\t\t\t\nEnter your password:"<<endl;
  while(1)//using password encryption
  {
   ch=getch();
   if(ch==ENTER)
   {
       password[i]='\0';
       break;
   }
   else if(ch==BKSP)
  {
   if(i>0)
   {
       i--;
       cout<<"\b\b";
   }
  }
  else if(ch==TAB || ch==SPACE)
  {
   continue;
  }
  else
  {
     password[i]=ch;
     i++;
     cout<<"*";
  }
}
 temppass=string(password); 
 cout<<"\n \tWait some moments validating......";
  Sleep(500);
  int  flag=0;
  ifstream fin;
  fin.open("Credential.dat",ios::in|ios::binary);
  while(fin.read((char*)&obj,sizeof(obj)))
  { 
   if(userid==id && temppass==password)
   {
    username=user;
    flag++;
   }
  }
  fin.close();
  if(flag>0)
  {
    system("cls");
    cout<<"\t \t \n You redirected to Customer page...";     
    for(int j=0;j<=100;j++)
    {
     cout<<"\t Wait some moments";
     cout<<j<<"%"<<"Completed";
     cout<<".................";
     Sleep(20);
     system("cls");  
    }
    obj.mainmenu(userid,username);
  }
 else
 {
   system("cls");
   cout<<"\n your userid and password wrong:try again:";
   login++;
   if(login==1 || login==2)
  {   system("cls");
      cout<<"\n It seems that you are not register yet or Block by Bank......";
      cout<<endl;
      cout<<"\n Press any key to continue:";
      getch();
      obj.mainpanel();
   }
   if (login>=4)
   {
     cout<<"\n \n You have too many attempts now program  terminate";
     exit(0); 
   }
  }
 }
  while(1);
}

 void Atm::createAccount() /*THIS Creates a account this Customer section*/
  {
   system("cls");
   cout<<" \n Redirected to Create Account page:";
   cout<<"\n \n";
   for(int i=0;i<=50;i++)
  {
   Sleep(100);
   system("color 49");
   cout<<char(219);
  } 
   system("cls");
   cout<<"\t\t\t\\t\t\t\t\n**************************Create Account******************************";
   cout<<"\t\t\t\t\t\t\t\t\n---------------------------------------------------------------------";
   int min,max,n;
   min=1000;
   max=min+99;
   srand(time(0));
   n=rand()%10+min; 
   y:
   ifstream fin;
   fin.open("Credential.dat",ios::in|ios::binary);
   if(fin)
   {
   while(fin.read(reinterpret_cast<char *> (&obj), sizeof(Atm)))
   {
     if(n==getid())
     {
        fin.close();
        goto y;
     }
   }
   fin.close();
   }
   id=n;
   cout<<"\t\t\t\nThis is your Unique id given by Bank(it also your login id):"<<id<<endl;
   
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Username :"<<endl;
   cin>>user;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your gender(M/F):"<<endl;
   cin>>gender;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your birthdate:"<<endl;
   cin>>birthdate;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Age:"<<endl;
   cin>>age;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Email(Exclude spaces):"<<endl;
   cin>>email;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your mobile number:"<<endl;
   cin>>number;
   cout<<"\t\t\t\t\t\t\t\t\nEnter Your choice Saving or current:"<<endl;
   cin>>account;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Bank password:"<<endl;
   cin>>password;
   x:
   cout<<"\t\t\t\t\t\t\t\t\nEnter Amount to be deposit(Amount should be greater than or equal to 300 to maintain the decorum of the bank):"<<endl;
   cin>>amount;
   if(amount>=300){    
   ofstream fout;
   fout.open("Credential.dat",ios::binary|ios::out|ios::app);
   fout.write((char*)&obj,sizeof(obj));
   fout.close();
   cout<<"\n\nAccount Creation Successfull....\n";
   cout<<"\n Press any key to continue";
   getch();
   }
   else

   {
          cout<<"Invalid amount";
          goto x;
   }
  }
/*this gives a profile of specic user and all users this is adminstrator or customer both section*/
 void Atm::profile()
 {
  cout<<"\t\t\t\t\t\t\n*****************************User Profile********************************"<<endl;
  cout<<"\t\t\t\t\t\t\nYour Unique id is:"<<id<<endl;
  cout<<"\t\t\t\t\t\t\t\t\n Your Username is:"<<user<<endl;
  cout<<"\t\t\t\t\t\t\t\t\n Your gender is:"<<gender<<endl;
  cout<<"\t\t\t\t\t\t\t\t\n Your Age is:"<<age<<endl;
  cout<<"\t\t\t\t\t\t\t\t\n Your Email is:"<<email<<endl;
  cout<<"\t\t\t\t\t\t\t\t\n Your mobile number:"<<number<<endl;
  cout<<"\t\t\t\t\t\t\t\t\n Your Account type:"<<account<<endl;
  cout<<"\t\t\t\t\t\t\t\t\nYour Balance is: rs"<<amount<<endl;
  cout<<"\t\t\t\t\t\t\t\t\n Your password is:"<<password<<endl;
}
void read(int n)//read function to read accountinfo of customer by Customer only:
{
  system("cls");
  system("color 6A");
  cout<<"\n \n \n****************Fetching Data Wait**************************";
  cout<<"\n \n";
       for(int i=0;i<=50;i++)
         {
           Sleep(50);
           system("color 9");
           cout<<char(219);
         }
  system("cls");
  ifstream fin;
  fin.open("Credential.dat",ios::in|ios::binary);
  while(fin.read((char*)&obj,sizeof(obj)))
  {
    if(n==obj.getid())
    {
    obj.profile();
    }
  }
 fin.close();
 getch();
}
//Withdraw money section:-
void Atm::withdrawmoney(int n)
{
  int flag=0;
  int withd;
  system("cls");
  cout<<"\n How much amount you want to withdraw:"<<endl;
  cin>>withd;
  fstream file;
  file.open("Credential.dat",ios::in|ios::binary|ios::out);
  while(file.read(reinterpret_cast<char *> (&obj), sizeof(Atm)))
  {
    
    if(n==obj.getid())
    {
    flag++;
    obj.withdraw(withd);
    int pos=(-1)*static_cast<int>(sizeof(obj));
		file.seekp(pos,ios::cur);
    file.write(reinterpret_cast<char *> (&obj), sizeof(Atm));
    Sleep(500);
    }
   }
  file.close();
   cout<<"Press any key to continue:...............................";
   getch(); 
 
}
//Deposit money section:-
void Atm::depositmoney(int n)
{
   int addam=0,tempamount=0;
   int flag=0;  
   system("cls");
   cout<<"\n How much amount you want to add in a account:"<<endl;
   cin>>addam;
   fstream file;
   file.open("Credential.dat",ios::in|ios::binary|ios::out);
   while(file.read(reinterpret_cast<char *> (&obj), sizeof(Atm)))
   {
    
    if(n==obj.getid())
    {
    flag++;
    obj.dep(addam);
    int pos=(-1)*static_cast<int>(sizeof(obj));
		file.seekp(pos,ios::cur);
    file.write(reinterpret_cast<char *> (&obj), sizeof(Atm));
    Sleep(500);
    }
   }
 file.close();
 cout<<"Press any key to continue....................";
 getch();
}
void Atm::currentbalance(int n)
{ 
   system("cls");
   int tempamount=0;  
   ifstream fin;
   fin.open("Credential.dat",ios::in|ios::binary);
   while(fin.read((char*)&obj,sizeof(obj)))
   {
    if(n==obj.getid())
    {
    tempamount=amount;
    }
  }
 fin.close();
  cout<<"\n \n Your current balance is:"<<tempamount;
  cout<<endl;
  cout<<"\n Press any key to continue.........................";
  getch();
}


//Delete customer account by useritself:
void Atm::deleteaccount(int n)
{
  char ch;
  int flag=0;
  system("cls");
  cout<<"Your account going to delete are you sure(y/n)?";
  cin>>ch;
  if(ch=='y' || ch=='Y')
  {
    ifstream fin;
    ofstream fout;
    fin.open("Credential.dat",ios::in|ios::binary);
    fout.open("TempStud.dat",ios::out|ios::app|ios::binary);
    while(fin.read((char*)&obj,sizeof(obj)))
    { 
       if(n==getid())
       {   cout<<"\n Your Account permanetely deleted:";
             Sleep(200);
            obj.profile();
            flag++;
       }
       else
       {

         fout.write((char*)&obj,sizeof(obj));
       }
   }
  fin.close();
  fout.close();
  remove("Credential.dat");
  rename("TempStud.dat","Credential.dat");
  }
  if(flag==1)
  {   
      system("cls");    
      obj.mainpanel();
  }
  cout<<"\n Press any key to continue......";
  getch();
}

//Transfer money by useritself:
void Atm::transfermoney(int n)
{ 
  system("cls");
  int transamt,num,flag=0;
  string name;  
  cout<<"\n***********************************************Transfer Money section:************************************************";
  cout<<"\n Enter Beneficary Name:";
  cin>>name;
  x:
  cout<<"\n Enter Beneficary Unique id";
  cin>>num;
  if(num==n)
  { 
    cout<<"\n It looks your id you can't transfer in your account:";
    Sleep(500);
    goto x;
  
  };
  check(num,n);
  cout<<"\n Enter Amount to Transfer: ";
  cin>>transamt;
  fstream file;
 file.open("Credential.dat",ios::in|ios::binary|ios::out);
 while(file.read(reinterpret_cast<char *> (&obj), sizeof(Atm)))
 {
 if(n==getid())
 {
  flag++;
  obj.withdraw(transamt);
  int pos=(-1)*static_cast<int>(sizeof(obj));
	file.seekp(pos,ios::cur);
  file.write(reinterpret_cast<char *> (&obj), sizeof(Atm));
  Sleep(500);
 }
 }
 file.close();
 if(flag==1)
 { 
    fstream file;
    file.open("Credential.dat",ios::in|ios::binary|ios::out);
    while(file.read(reinterpret_cast<char *> (&obj), sizeof(Atm)))
    {
      if(num==getid())
      {
          obj.dep(transamt);
          int pos=(-1)*static_cast<int>(sizeof(obj));
	        file.seekp(pos,ios::cur);
          file.write(reinterpret_cast<char *> (&obj), sizeof(Atm));
          Sleep(500);
          cout<<"\n AMOUNT TRANSFER SUCCESSFULLY";
          Sleep(300);
       }
    }
  }
  file.close();    
  cout<<"\t Press any key to Continue..................";
}
//Check section::
void Atm::check(int n,int num)
{
  int flag=0;
  ifstream fin;
  fin.open("Credential.dat",ios::in|ios::binary);
while(fin.read(reinterpret_cast<char *> (&obj), sizeof(Atm)))
{

  if(n==getid())
 {
    flag++;

 }

}
fin.close();
if(flag==0)
{
  cout<<"\n this id is not EXIST";
  Sleep(200);
  obj.transfermoney(num);
}

}

//Modify user details by useritself:
void Atm::modify()
{
   cout<<"\n************************************************Modify section*************************************************************";  
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Username :"<<endl;
   cin>>user;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your gender(M/F):"<<endl;
   cin>>gender;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your birthdate:"<<endl;
   cin>>birthdate;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Age:"<<endl;
   cin>>age;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Email(Exclude spaces):"<<endl;
   cin>>email;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your mobile number:"<<endl;
   cin>>number;
   cout<<"\t\t\t\t\t\t\t\t\nEnter Your choice Saving or current:"<<endl;
   cin>>account;
   cout<<"\t\t\t\t\t\t\t\t\nEnter your Bank password:"<<endl;
   cin>>password;
  
}
void Atm::modifydetails(int n)
{
  system("cls");
  fstream file;
  file.open("Credential.dat",ios::in|ios::binary|ios::out);
  while(file.read(reinterpret_cast<char *> (&obj), sizeof(Atm)))
  {
    if(n==getid())
   {
    
    obj.modify();
    int pos=(-1)*static_cast<int>(sizeof(obj));
	  file.seekp(pos,ios::cur);
    file.write(reinterpret_cast<char *> (&obj), sizeof(Atm));
   }
 }
 file.close();
 cout<<"\n your details are modified:.............";
 Sleep(300);
}

//CUSTOMERS FUNCTIONS DEFINITION END*************************************************///
//****************************************************************************************************************///


/*This is Admin panel he has full Privileges*/
void Atm::adminpanel()
 {
    int n;  
    do
    { system("cls");
      cout<<"\t\t\t\t\t\t\n*****************************Administrator panel****************************************";
      cout<<endl;
      cout<<"\t\t\t\t\t\t\n========================================================================================";
      cout<<endl;
      cout<<"\t\t\t\t\t\t\n1>All User details:";
      cout<<"\t\t\t\t\t\t\n2>Search for User:";
      cout<<"\t\t\t\t\t\t\n3>Delete All User:";
      cout<<"\t\t\t\t\t\t\n4>Admininfo:";
      cout<<"\t\t\t\t\t\t\n5>Block any user by id:";
      cout<<"\t\t\t\t\t\t\n6.Unblock any user by id";
      cout<<"\t\t\t\t\t\t\n7>Block list:";
      cout<<"\t\t\t\t\t\t\n8>Back to Main menu(mainpanel):";
      cout<<"\t\t\t\t\t\t\n======================================================================================";
      cout<<endl;
      cout<<"\t\t\t\t\t\nEnter your Choice:";
      cin>>n;
      switch(n)
      {
         case 1:obj.allusersdetails();
                break;
              
         case 2:obj.searchusersdetails();
                break;

         case 3:obj.deleteusersdetails();
                break;

         case 4:obj.admininfo();
                break;
          
         case 5:obj.blockuser();
                 break;
         
         case 6:obj.unblockAccount();
                 break;
         case 7:obj.blacklistdetails();
                 break;

         case 8:obj.mainpanel();
                break;

      }
    }
   while(1);
 }
 //*********************************************************************************//
/*Customer  panel main menu it's only shows to customers*/
void Atm::mainmenu(int currentid, string username)
  { 
  int n;
  do
  {
  system("cls");
  cout<<"\n WELCOME BACK::"<<username<<"\t"<<"Unique id ::"<<currentid;
  cout<<"\t\t\t\t\t\t\t\n**********************-:Welcome to Atm services:-*********************"<<endl;
  cout<<"\t\t\t\t\t\t\t\n======================================================================"<<endl;
  
     cout<<"\t\t\t\t\t\t\n>1.Balance Enquiry"<<endl;
     cout<<"\t\t\t\t\t\t\n>2.Withdraw Money:"<<endl;
     cout<<"\t\t\t\t\t\t\n>3.Deposit Money:"<<endl;
     cout<<"\t\t\t\t\t\t\n>4.View your profile:"<<endl;
     cout<<"\t\t\t\t\t\t\n>5.Delete your Account:"<<endl;
     cout<<"\t\t\t\t\t\t\n>6.Transfer money:"<<endl;
     cout<<"\t\t\t\t\t\t\n>7.Modify your bank details:"<<endl;
     cout<<"\t\t\t\t\t\t\n>8.Back to Mainpanel"<<endl;
 cout<<"\t\t\t\t\t\t\t\n======================================================================"<<endl;   
     cout<<"#Enter your choice:"<<endl;
  
     cin>>n;
     switch(n)
     {
         case 1:obj.currentbalance(currentid);
                break;

         case 2:obj.withdrawmoney(currentid);
                break;

         case 3:obj.depositmoney(currentid);
                break;

         case 4:read(currentid);
                break;

         case 5:obj.deleteaccount(currentid);
                break;

         case 6:obj.transfermoney(currentid);
                 break;
       
         case 7:obj.modifydetails(currentid);
                break;     

         case 8:obj.mainpanel();
                 break;
                

     default:
            cout<<"\n Wrong number input"<<endl;       

  }
 }
 while(1); 
}
//****************************************************************MAIN PANEL**********************************************************//
void Atm::mainpanel()
{
  int n;     
  do
  {
  system("cls");
  cout<<"\t\t\t\t\t\t\t\t\t\n********************WELCOME TO ATM SERVICES***************************************";
  cout<<"\t\t\t\t\t\t\t\t\t\n Press 1 for Adminstrator Login:";
  cout<<"\t\t\t\t\t\t\t\t\t\n Press 2 for Customer Login:";
  cout<<"\t\t\t\t\t\t\t\t\t\n Press 3 for Create Account:";
  cout<<"\t\t\t\t\t\t\t\t\t\n Press 4 for exit";
  cout<<"\t\t\t\t\t\t\t\n*************************************************************************************";
  cout<<"\t\t\t\t\t\t\t\t\nEnter your choice:";
  cin>>n;
  switch(n)
  {
     case 1:obj.adminlogin();
            break;
     case 2:obj.customerlogin();
            break;
     case 3:obj.createAccount();
            break;
     case 4:cout<<"\n Thankx for using this program:)";
            exit(0);
     default:
           cout<<"\n Wrong input:";
  }
  }
  while(1); 
}



/********************************************************************MAIN FUNCTION***************************************/
//*******************************************************************************************************************//
int main()
{        
         system("color 1F");
         cout<<"\nPress Any key to start:";
         getch();
         system("cls");   //this is program loading function:
         cout<<"\n\n\n.................................... Program being Loading .......................";
         cout<<"\n\n";
         for(int i=0;i<=50;i++)
         {
           Sleep(80);
           cout<<char(219);
         }
         system("cls");
         obj.design();
         obj.mainpanel();
         return 0;
}
//***********************************************::::THIS IS END OF PROJECT::::************************************************************///