#include<iostream>
#include<sstream>
#include<fstream>
#include<windows.h>
using namespace std;
 class Account{
private:
string AccNo, Password;
int balance;
public:
Account():AccNo(""),Password(""),balance(0){}
 void setAccountNo(string id){
    AccNo=id;
}
void setPassword(string pw){
    Password=pw;
}
void setBalance(int Balance){
  balance=Balance;
}

string getAccountNo(){
   return AccNo;
}
string getPassword(){
   return Password;
}
int getBalance(){
   return balance;
}
 };
 void addCash(){
system("cls");
string id;
cout<<"\tEnter Account No: "<<endl;
cin>>id;
ifstream infile("D:/Account.txt");
ofstream outfile("D:/Account Tempt.txt");
if(!infile || !outfile){
    cout<<"\tError: File Cannot Open"<<endl;
}
string line;
bool found=false;
while(getline(infile,line)){
    stringstream ss;
    ss<<line;
    string userID,userPw;
    int userBalance;
    char delimiter;
    ss>>userID>>delimiter>>userPw>>delimiter>>userBalance;
    if(id==userID){
found=true;
int cash;
cout<<"\tEnter Cash: ";
cin>>cash;
int newBalance=userBalance+cash;
userBalance=newBalance;
outfile<<"\t"<<userID<<" : "<<userPw<<" : "<<userBalance<<endl;
    cout<<"\tNew Balance is: "<<userBalance<<endl;
    }
    else{
        outfile<<line<<endl;
    }
}
if(!found){
    cout<<"\tEnter Valid Account No"<<endl;
}
outfile.close();
infile.close();
remove("D:/Account.txt");
rename("D:/Account Temp.txt","D:/Account.txt");
Sleep(5000);
 }
 void openAccount(Account user){
system("cls");
string id,pw;
cout<<"\tEnter Account Number : ";
cin>>id;
user.setAccountNo(id);

cout<<"\tEnter a Strong Password";
cin>>pw;
user.setPassword(pw);
user.setBalance(0);
ofstream outfile("D:/Account.txt",ios::app);
if(!outfile){
    cout<<"\tError: File Can't Open!"<<endl;
}
else{
    outfile<<"\t"<<user.getAccountNo()<<" : "<<user.getPassword()<<" : "<<user.getBalance()<<" : "<<endl<<endl;
cout<<"\tAccount Created Successfully"<<endl;
}
outfile.close();
Sleep(5000);
 }
 void withdrawCash(){
    system("cls");
    string id,pw;
    cout<<"\tEnter Account No: ";
    cin>>id;

    cout<<"\tEnter Password ";
    cin>>pw;
    ifstream infile("D:/Account.txt");
    ofstream outfile("D:/Account Temp.txt");
    if(!infile || !outfile){
        cout<<"\tError: File Can't Open"<<endl;
    }
    string line;
bool found=false;
while(getline(infile,line)){
    stringstream ss;
    ss<<line;
    string userID,userPw;
    int userBalance;
    char delimiter;
    ss>>userID>>delimiter>>userPw>>delimiter>>userBalance;
    if(id==userID && pw==userPw){
        found=true;
int cash;
cout<<"\tEnter cash to be withdrawn";
cin>>cash;
if(cash<=userBalance){
    int newBalance = userBalance -cash;
    userBalance=newBalance;
    outfile<<"\t"<<userID<<" : "<<userPw<<" : "<<userBalance<<endl;
    cout<<"\tTransaction is successful"<<endl;
    cout<<"\tRemaining Balance: "<<userBalance<<endl;
}
else{
    cout<<"\tInsufficient Balance"<<endl;
    cout<<"\tTransacttion Failed"<<endl;
    outfile<<"\t"<<userID<<" : "<<userPw<<" : "<<userBalance<<endl;

}
 }
 else{
    outfile<<line<<endl;
 }
}
if(!found){
    cout<<"\tInvalid Account No or Password"<<endl;
}
outfile.close();
infile.close();
remove("D:/Account.txt");
rename("D:/Account Temp.txt","D:/Account.txt");
Sleep(5000);
 }
 int main(){
    Account user;
    bool exit=false;
    while(!exit){
system("cls");
int val;
cout<<"\t\tBank Account Management System"<<endl;
cout<<"\t***************************************"<<endl;
cout<<"\t1.Open New Account"<<endl;
cout<<"\t2.Add Cash"<<endl;
cout<<"\t3.Withdraw Cash"<<endl;
cout<<"\t4.Exit"<<endl;
cout<<endl<<endl;
cout<<"\tEnter Your Choice";
cin>>val;
if(val==1){
openAccount(user);
}
else if(val==2){
addCash();
}
else if(val==3){
withdrawCash();
}
else if(val==4){
    system("cls");
    exit=true;
    cout<<"\tGood Luck"<<endl;
    Sleep(2000);
}
Sleep(3000);
    }
 }