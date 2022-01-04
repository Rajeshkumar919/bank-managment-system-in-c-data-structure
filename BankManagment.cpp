#include<iostream>
#include<fstream>
#include <conio.h>
#include<iomanip>
#include<ctime>
#include <string>
using namespace std;
struct childTree;
struct account{
	int accountNo;
	string accontName;
	string accountType;
	string adderess;
    double previousBalance;
    double balance;
    double currentBalance;
	account *right;
	account *left;
};
account *acroot;
struct childTree{
    ifstream objRead;
    ofstream objWrite;
	string accountName,accountType;
	char op;
	int id, balance;
	string adderess;
	char check,atm;
	childTree()
	{
		acroot=NULL;
	}
	void insert()
	{       system("cls");
	        objWrite.open("BANKData.txt",ios::app);
		    account *current,*previous;
		    account *childNode=new account;
		    cout<<"\t\t\t\tWelcome in ALLIED BANK Limited "<<endl;
		    again:	
		  	cout<<"\t\tEnter Acount No: ";
		     cin>>id;
		    if(id<0)
		    {
			cout<<"\t\tinvalid input"<<endl;
			goto again;
		    }
    	   cout<<"\t\tEnter Name: ";
    	   cin.ignore();
           getline(cin,accountName);
    	   cout<<"\t\tEnter Adderess: ";    	
		   getline(cin,adderess); 
    	   cout<<"\t\tAccount Type s/c:  ";
    	   getline(cin,accountType);
    	   up:
    	   cout<<"\t\tEnter Balance: ";
    	   cin>>balance;
    	  if(balance<=0)
    	  {
    		cout<<"Invalid Balance\n";
    		goto up;
	     }
	    childNode->accountNo=id;
        childNode->accontName=accountName;
        childNode->accountType=accountType;
        childNode->adderess=adderess;
        childNode->balance=balance;
        cout<<"\t\tDo you want to issue checkBook: y/n ";
        cin>>check;
        if(check=='y')
        {
        	system("cls");
        	cout<<"\t\t***************************************************************"<<endl;  
        	cout<<"\t\t Allied Bank                   "<<"Cheque No___________________"<<endl;
            cout<<"                                Date     ___________________"<<endl; 
            cout<<"\t\t Pay    ______________________________________or bearer"<<endl;  
            cout<<"\t\t Rupees __________________________________"<<" PKR_____________"<<endl; 
            cout<<"\t\t  __________________________________________________________ "<<endl;      
            cout<<" \t\t For ____________________"<<endl<<endl;
	        cout<<"                            Signed __________________________ "<<endl;
	        cout<<"\t\t***************************************************************"<<endl;  
		}
		cout<<"\t\tDo you want to ATM Card: y/n ";
    	cin>>atm;
    	if(atm=='y')
    	{
    	cout<<"\t\t**************************************************"<<endl;  	
    	cout<<"\t\t              Allied Bank"<<endl;
		cout<<"\t\tDEBIT CARD:  "<<endl; 
	    cout<<"\t\tCard Number "<<childNode->accountNo<<endl;
	    time_t now;
    	struct tm nowLocal;
	    now=time(NULL);
		nowLocal=*localtime(&now);
		cout<<"\t\tValid From:    "<<nowLocal.tm_mday<<" "<<nowLocal.tm_mon+1<<" "<<nowLocal.tm_year+1900<<"\tValid Thru: "<<nowLocal.tm_mday<<" "<<nowLocal.tm_mon+1<<" "<<nowLocal.tm_year+1900+5<<endl;

        cout<<"\t\tCARDHOLDER NAME:  "<<childNode->accontName<<endl;
		cout<<"\t\tThank you using allied ATM           PayPak"<<endl;
		cout<<"\t\t**************************************************"<<endl; 
		}
		
    	childNode->right=NULL;
    	childNode->left=NULL;
    	if(acroot==NULL)
    	{
    		acroot=childNode;
    	
		}
		else
		{
			current=acroot;
			while(current!=NULL)
			{
				previous=current;
				if(current->accountNo==id)
				{
					cout<<"Duplicate account is not allowded: "<<endl;
					return;
				}
				else if(current->accountNo>id)
				current=current->left;
				else
				current=current->right;
				
			}
			if(previous->accountNo>id)
			previous->left=childNode;
			else
			previous->right=childNode;
			
	       }
	 
		   }
		   void deposit()
		   {
		   	system("cls");
		   	cout<<"\t\t************************************"<<endl;
		   	cout<<"\t\t*             Deposit              *"<<endl;
		   	cout<<"\t\t*                                  *"<<endl;
		   	cout<<"\t\t************************************"<<endl;
		   	int id;
	        int amount;
	        account *current=acroot;
			account *previous;
	        cout<<"\t\tEnter AccountNo: ";
            cin>>id;
           
            if(current==NULL)
            {
            	cout<<"Account folder is empty"<<endl;
            	return;
	         }
	         else
	         {
	        
	         	while(current!=NULL)
	         	{
	         		previous=current;
	         		if(current->accountNo==id)
	         		{
	         			re:
	         			cout<<"\t\tEnter amount: ";
	         			cin>>amount;
	         			
	         			
	         			if(amount<0)
	                     {
		                 cout<<"\t\tAmount is  negative please ReEnter: ";
		                 goto re;
	                    }
	                  
                       	else
	                   {
	                   	
	                   	current->previousBalance=current->balance;
	         			current->balance+=amount;
	         			current->currentBalance=current->balance;
	         			cout<<"\t\t**************************************************"<<endl;  
		               cout<<"\t\tAllied Bank "<<endl;
		               time_t now;
    	               struct tm nowLocal;
	                   now=time(NULL);
	                   nowLocal=*localtime(&now);
	                   cout<<"\t\tDate:"<<nowLocal.tm_mday<<" "<<nowLocal.tm_mon+1<<" "<<nowLocal.tm_year+1900<<endl;
	                   cout<<"\t\tTime: "<<nowLocal.tm_hour<<" "<<nowLocal.tm_min<<" "<<nowLocal.tm_sec<<endl;
	               	   cout<<"\t\tAccount No: "<<current->accountNo<<endl;
		               cout<<"\t\tPrevious Balance: "<<current->previousBalance<<endl;
		               cout<<"\t\tCurrent Balance: "<<current->currentBalance<<endl;
		               cout<<"\t\t**************************************************"<<endl;
				
		               break;
	                }
				}
				else if(current->accountNo>id)
				current=current->left;
				else
				current=current->right;	
			}	
			 } 	
		   	
		   	
		   }
		   void withdraw()
		   {
		   		system("cls");
		   	account *current=acroot;
		   	account *previous;
		 
		   	cout<<"\t\t************************************"<<endl;
		   	cout<<"\t\t*             Withdraw             *"<<endl;
		   	cout<<"\t\t*                                  *"<<endl;
		   	cout<<"\t\t************************************"<<endl;
		   	int id;
	        int amount;
	       
	        cout<<"\t\tEnter AccountNo: ";
            cin>>id;
            if(current==NULL)
            {
            	cout<<"\t\tAccount folder is empty: "<<endl;
           	return;
	         }
	         else
	         {
	        
	         	while(current!=NULL)
	         	{
	         		previous=current;
	         		if(current->accountNo==id)
	         		{
	         			cout<<"\t\tEnter amount: ";
	         			cin>>amount;
	         			
	         			if(amount>balance)
                       {
	                   cout<<"\t\twithdraw Amount is Exceed from Balance: ";
	                    }
                       	else
	                   {
	                   	current->previousBalance=current->balance;
	         			current->balance-=amount;
	         			current->currentBalance=current->balance;
	                   	
	                   	cout<<"\t\t**************************************************"<<endl;  
		               cout<<"\t\tAllied Bank "<<endl;
		               time_t now;
    	               struct tm nowLocal;
	                   now=time(NULL);
	                   nowLocal=*localtime(&now);
	                  cout<<"\t\tDate:"<<nowLocal.tm_mday<<" "<<nowLocal.tm_mon+1<<" "<<nowLocal.tm_year+1900<<endl;
	                  cout<<"\t\tTime: "<<nowLocal.tm_hour<<" "<<nowLocal.tm_min<<" "<<nowLocal.tm_sec<<endl;
	               	  cout<<"\t\tAccount No: "<<current->accountNo<<endl;
		              cout<<"\t\tPrevious Balance: "<<current->previousBalance<<endl;
		               cout<<"\t\tCurrent Balance: "<<current->currentBalance<<endl;
		               cout<<"\t\t**************************************************"<<endl; 
					    
	                }
	                break;
				}
				else if(current->accountNo>id)
				current=current->left;
				else
				current=current->right;	
			}	
			 } 		
		
		   }
		   void BalanceEnquiry()
		   {
		   	
		   	system("cls");
		   	account *current=acroot;
	        account *previous;
		   	int id;
	        int amount;
	        cout<<"\t\t************************************"<<endl;
		   	cout<<"\t\t*           Balance Enquiry        *"<<endl;
		   	cout<<"\t\t*                                  *"<<endl;
		   	cout<<"\t\t************************************"<<endl;
	        cout<<"\t\tEnter AccountNo: ";
            cin>>id;
            
            if(current==NULL)
            {
            	cout<<"\t\tAccount folder is empty"<<endl;
            	return;
	         }
	         else
	         {
	        
	         	while(current!=NULL)
	         	{
	         		previous=current;
	         		if(current->accountNo==id)
	         		{
	                   	
	                   cout<<"\t\t**************************************************"<<endl;  	
		               cout<<"\t\tAllied Bank "<<endl;
		               time_t now;
    	               struct tm nowLocal;
	                   now=time(NULL);
	                   nowLocal=*localtime(&now);
	                  cout<<"\t\tDate:"<<nowLocal.tm_mday<<" "<<nowLocal.tm_mon+1<<" "<<nowLocal.tm_year+1900<<endl;
	                  cout<<"\t\tTime: "<<nowLocal.tm_hour<<" "<<nowLocal.tm_min<<" "<<nowLocal.tm_sec<<endl;
	               	  cout<<"\t\tAccount No: "<<current->accountNo<<endl;
		               cout<<"\t\tCurrent Balance: "<<current->balance<<endl;
		               cout<<"\t\t**************************************************"<<endl;
					   break;
	                }
				
				else if(current->accountNo>id)
				current=current->left;
				else
				current=current->right;	
			}	
			 } 	
		   	
		   }
		   	
		   
		   void Preorder(account *node)
         {
   	      if(node==NULL)
        	return;
         cout<<"\t\t**************************************************"<<endl;  	
   	     cout<<node->accountNo<<" "<<node->accontName<<" "<<node->accountType<<" "<<node->adderess<<" "<<node->balance<<endl;
   	     cout<<"\t\t**************************************************"<<endl;  
          Preorder(node->left);
   	      Preorder(node->right);
          }
    account *close(account *acroot,int id)
   {
    if(acroot==NULL) return acroot;
    else if(id<acroot->accountNo) acroot->left=close(acroot->left,id);
    else if(id>acroot->accountNo) acroot->right=close(acroot->right,id);
    else
    {
        if(acroot->left==NULL && acroot->right==NULL)
        {
            delete acroot;
            acroot=NULL;
            return acroot;
        }
        else if(acroot->left==NULL)
        {
            account *temp=acroot;
            acroot=acroot->left;
            delete temp;
        }
        else {
            account *temp=FindMin(acroot->right);
            acroot->accountNo=temp->accountNo;
            acroot->right=close(acroot->right,temp->accountNo);
        }
    
        
    }
    return acroot;
    
}
account * FindMin(account* node) 
{ 
    account* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 	
};


struct Bank{

	int branchCode;
	string BranchAdderess;
	string BranchMobileNo;
	string Branchcity;	
    childTree acc;
	Bank *right;
	Bank *left;
};
Bank *root;
struct Tree{
	int maxSize;
	int currSize;
	Bank ob;
	int id,choice;
	ofstream outData;
	ifstream inData;
	public:
	tree()
	{
		root=NULL;
		maxSize=100;
		currSize=0;
		
	}
	
	void insert(int branch,string BranchM,string BranchCity,string BranchA)
    {   
	    outData.open("Branch.txt",ios::app);
    	Bank *curr;
    	Bank *prev;
    	
    	Bank *newNode=new Bank;
    	newNode->branchCode=branch;
    	newNode->BranchMobileNo=BranchM;
    	newNode->Branchcity=BranchCity;
    	newNode->BranchAdderess=BranchA;
    	newNode->right=NULL;
    	newNode->left=NULL;
    	if(root==NULL)
    	{
    		root=newNode;
		}
		else
		{
			curr=root;
			while(curr!=NULL)
			{
				prev=curr;
				if(curr->branchCode==branch)
				{
					cout<<"Duplicate Branch is not allowded: "<<endl;
					return;
				}
				else if(curr->branchCode>branch)
				curr=curr->left;
				else
				curr=curr->right;
				
			}
			if(prev->branchCode>branch)
			prev->left=newNode;
			else
			prev->right=newNode;
		
		}
	     outData<<branch<<" ";
		outData<<" "<<BranchM<<" "<<BranchCity<<" "<<BranchA<<endl;
		outData.close();
}
   void search(int branch)
   {
   	
   	account *current;
	account *previous;
   	Bank *curr=root;
   	int id=branch;
    int op;
    char start;
   	inData.open("Branch.txt");
   	if(curr==NULL)
   {
   	cout<<"Branch folder is empty ";
   	return;
   }
   
   else
   	{
   	
   		while(curr!=NULL)
   		{
   			
   			if(curr->branchCode==branch)
   			{
   				system("cls");
   			do{
			start:   
			cout<<"\t\t**************************************************"<<endl;   		   
   			cout<<"\t\tContact: "<<curr->BranchMobileNo<<endl;
			cout<<"\t\tAdereess: "<<curr->BranchAdderess<<endl;
			cout<<"\t\tCity:     "<<curr->Branchcity<<endl;
			cout<<"\t\t**************************************************"<<endl;
			cout<<"\t\tpress 1 to Open Account: "<<endl;  
	        cout<<"\t\tpress 2 to Deposit:    "<<endl;
	        cout<<"\t\tpress 3 to Withdrawal:" <<endl;
	        cout<<"\t\tpress 4 to Balance Enquiry: "<<endl;
 	        cout<<"\t\tpress 5 to Close Account:  "<<endl;
	        cout<<"\t\tpress 6 All AccountsDetail: "<<endl;
	        cout<<"\t\tpress 7 return Back to Manu: "<<endl;
	        cout<<"\t\tpress 8 to Exit: "<<endl;
	        cout<<"\t\tSelection option"<<endl;
	        cin>>op;
	        if(op==1)
	        {
	        	ob.acc.insert();
			}
			else if(op==2)
			{
				ob.acc.deposit();
			}
			else if(op==3)
			{
				ob.acc.withdraw();
			}
			else if(op==4)
			{
				ob.acc.BalanceEnquiry();
				
			}
	        else if(op==5)
	        {
	        	
	         cout<<"Enter Account No to Close: ";
		     cin>>id;
		     ob.acc.close(acroot,id);
			}
			else if(op==6)
			{
				ob.acc.Preorder(acroot);
			}
			else if(op==7)
			{
				goto start;
			}
			else 
			{
				exit(0);
			}
	      } while(true);
	       break;
		   }
 	
			else if(curr->branchCode>branch)
			curr=curr->left;
			else
			curr=curr->right;
   			
		}
	}
}
   Bank *Delete(Bank *root,int branch)
   {
    if(root==NULL) return root;
    else if(branch<root->branchCode) root->left=Delete(root->left,branch);
    else if(branch>root->branchCode) root->right=Delete(root->right,branch);
    else
    {
        if(root->left==NULL && root->right==NULL)
        {
            delete root;
            root=NULL;
            return root;
        }
        else if(root->left==NULL)
        {
            Bank *temp=root;
            root=root->left;
            delete temp;
        }
        else {
            Bank *temp=FindMin(root->right);
            root->branchCode=temp->branchCode;
            root->right=Delete(root->right,temp->branchCode);
        }
    
        
    }
    return root;
    
}
Bank * FindMin( Bank* node) 
{ 
    Bank* current = node; 
  
    while (current && current->left != NULL) 
        current = current->left; 
  
    return current; 
} 
bool login(string password)
   {
   	
   string pass ="";
   char ch;
   cout << "\t\tEnter password : ";
    ch = _getch();
   while(ch != 13){
      pass.push_back(ch);
      cout << '*';
      ch = _getch();
  }
      
      
      
   
   if(pass == password){
      cout << "\n\t\tAccess granted... \n";
      return true;
      
   }else{
      cout << "\n\t\tAccess aborted...\n";
      return false;
   }
   
   }
   void printPreorder(Bank *node)
   {
   	
   	if(node==NULL)
   	return;
   	
   	cout<<"Branch code: "<<node->branchCode<<"   Adderess:  "<<node->BranchAdderess<<"  Mobile:  "<<node->BranchMobileNo<<"   Branch City: "<<node->Branchcity<<endl;
   	
   	printPreorder(node->left);
   	printPreorder(node->right);
   }
   
	
};



int main()
{
	//system("color 97");
	cout<<"\t\t**************************************************"<<endl;
	cout<<"\t\t**************************************************"<<endl;
	cout<<"\t\t**                                              **"<<endl;
	cout<<"\t\t**           ALLIED BANK LIMITED                **"<<endl;
    cout<<"\t\t**                                              **"<<endl;
	cout<<"\t\t**************************************************"<<endl;
	cout<<"\t\t**************************************************"<<endl;

    Tree o;
    int BNo,id,choice;
    childTree account;
   string password;
    cout<<"Enter passward for login: ";
    cin>>password;
    if(o.login(password)==true)
    {
	
    int op;
	o.insert(5,"0301-8690438","Hyderabad","Haji Adam Rehmani Centre,Saddar");	
    o.insert(3,"0301-8630135","Karachi","M.A.JINNAH ROAD");
    o.insert(4,"0301-8460783","Quetta"," SHAHEED PLAZA new ZARGHOON ROAD");
    o.insert(7,"0301-8660450","Sukkur"," MUHAMMAD BINQASIM PARK");
    o.insert(6,"0301-8680812","Dera Allahyar"," QUETTA ROAD TEHSIL JHATPHAT");
    o.printPreorder(root);
    cout<<"\n\n"<<endl;
	do{
	start:	
    cout<<"\t\tPress 1 to Search Branch of Allied Bank: "<<endl;
    cout<<"\t\tPress 2 to Delete Branch of Allied Bank: ";
    cin>>choice;
    if(choice==1)
    {
    	cout<<"\t\tEnter Branch Code to Search: ";
    	cin>>BNo;
    	o.search(BNo);
	}
	else if(choice==2)
	{
		cout<<"\t\tEnter Branch Code to Delete: ";
		cin>>BNo;
		o.Delete(root,BNo);
	}
	
	
}
     while(true);
} 

else
{
	cout<<"Sorry Try again "<<endl;
}
    return 0;
}
