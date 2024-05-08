#include <iostream>
#include <cstring>
#include <string>
using namespace std;
class Account
{
private:
	string name;
	int accno;
	char acctype[5];
	double accbal;

public:
	Account() {}

	Account(string cname, int accno, char *type, double bal)
	{
		setName(cname);
		setAccno(accno);
		setAcctype(type);
		addInitialbalance(bal);
	}
	void addInitialbalance(double bal)
	{
		if (bal < 5000){
			cerr << "minimum account opening balance will be rs.5000/" << endl;
			exit(0);
		}
		else
			accbal = bal;
	}
	void setName(string cname)
	{
		name = cname;
	}
	void setAccno(int accno)
	{
		this->accno = accno;
	}
	void setAcctype(char *type)
	{
		strcpy(acctype, type);
	}
	void deposit(double bal)
	{
		accbal += bal;
		cout<<"updated account balance:"<<accbal<<endl;
		cout<<"\n";
	}
	void withdraw(double bal)
	{

		if ((accbal - bal) < 5000)
			cerr << "Account should be maintain minimum rs.5000/" << endl;
		else
			accbal -= bal;
			cout<<"updated account balance:"<<accbal<<endl;
			cout<<"\n";
	}
	int getaccountno()
	{
		return accno;
	}
	double getbalance()
	{
		return accbal;
	}
	string getName(){
		return name;
	}
	void getaccdetails()
	{
		cout << "name:" << name << endl;
		cout << "Acount no:" << accno << endl;
		cout << "Acount type:" << acctype << endl;
		cout << "Acount Balance:" << accbal << endl;
		cout<<"\n";
	}
	
	
};
   
   int findaccount(Account acc[], int n, int accno)
	{
		for (int i = 0; i < n; i++)
		{
			if (acc[i].getaccountno() == accno)
				return i;
		}
	}


   void maxAccbalance(Account acc[],int n){
		 double max=acc[0].getbalance();
		 int index=0;
		for (int i = 1; i < n; i++)
		{
			if (acc[i].getbalance()> max){
				max=acc[i].getbalance();
				index=i;
			}
		}
		cout<<"Account holder with Max Account balance is:"<<acc[index].getName()<<endl;
		cout<<"\n";
	}
	
int main()
{
    string name;
	int accno;
	char type[5];
	double amount;
	int n;
    cout << "enter the no of account want to create:" << endl;
	cin >> n;
	Account acc[n];
	
	for (int i = 0; i < n; i++)
	{
		cout << "Account-" << i + 1 << " enter the name:";
		cin.ignore();
		getline(cin, name);
		cout << "Account-" << i + 1 << " enter account number:";
		cin >> accno;
		cout << "Account-" << i + 1 << " enter account type:";
		cin >> type;
		cout << "Account-" << i + 1 << " enter initial opning amount:";
		cin >> amount;
		acc[i].setName(name);
		acc[i].setAccno(accno);
		acc[i].setAcctype(type);
		acc[i].addInitialbalance(amount);
		cout<<endl;
	}
	
	maxAccbalance(acc,n);
	
	int choice;
	int tempaccno;
	double tempbalance;

do{
		cout<<"1.check balance.\n2.Deposit money\n3.Withdrow money\n4.get account details\n5.Exit\nEnter your choice:"<<endl;
    	cin>>choice;
	
	switch(choice){
	
		
		case 1:cout<<"Enter account number"<<endl;
		cin>>tempaccno;
	    cout<<"Account balance will be:"<<acc[findaccount(acc,n,tempaccno)].getbalance()<<endl;
	    break;
	    
		case 2:cout<<"Enter account number"<<endl;
		cin>>tempaccno;
		cout<<"Enter amount:"<<endl;
		cin>>tempbalance;
	    acc[findaccount(acc,n,tempaccno)].deposit(tempbalance);
	    break;
	   
	    case 3:cout<<"Enter account number"<<endl;
		cin>>tempaccno;
		cout<<"Enter amount:"<<endl;
		cin>>tempbalance;
	    acc[findaccount(acc,n,tempaccno)].withdraw(tempbalance);
	    break;
	   
	    case 4:cout<<"Enter account number"<<endl;
		cin>>tempaccno;
	    acc[findaccount(acc,n,tempaccno)].getaccdetails();
	    break;
	   
	    case 5:cout<<"Exit";
	    exit(0);
	    break;
	   
	    default:cout<<"Wrong choice"<<endl;
	    break;
		
	}
	
}while(choice!=5);
	

	return 0;
}
