#include<iostream>
#include<string>
using namespace std;

int inverse();
int k;
int encryption();
int decryption();
string msg;
int a,b,n;
int ch;


int main()
{
	
	
	cout<<"enter the msg in lower case:";	
	cin>>msg;
	cout<<"enter the coefficient of x(alpha) such that gcd(alpha,26) is 1:";
	cin>>a;
	cout<<"enter the value of beta:";
	cin>>b;
	cout<<"enter 1 for encyption and 2 for decryption:";
	cin>>n;
	switch (n)
	{
		case 1:
			encryption();
			break;
		case 2:
		    decryption();
			break;	
	}
}
int encryption()
{
	for(int i=0;i<msg.size();i++)
	{
		ch=a*(msg[i]-97)+(b%26);
		ch=ch%26+97;
		msg[i]=ch;
		
	
	}
	cout<<"the encrypted msg is:"<<endl;
	for(int i=0;i<msg.size();i++)
	cout<<msg[i];
	
}	int decryption()
{
	
	for(int i=0;i<msg.size();i++)
	{
		ch=((inverse()*(msg[i]-b-97 ))%26);
		ch=ch+97;
		msg[i]=ch;
	}
	cout<<"the decrypted msg is:"<<endl;
	for(int i=0;i<msg.size();i++)
	cout<<msg[i];
}
int inverse()
{
	for(int i=0;i<a;i++)
	{
		if(i*a%26==1)
		{
			k=i;
		}
	}
	return k;
	
	
	
	
}

