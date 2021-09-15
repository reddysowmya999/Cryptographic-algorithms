
#include<iostream>
#include<math.h>
 
using namespace std;
 int gcdh;
 int count;
 int gcd(int a, int h);
int gcd(int a, int h)
{

    for(int i=1; i <= a && i <= h; ++i)
    {
        // Checks if i is factor of both integers
        if(a%i==0 && h%i==0)
            gcdh= i;
    }


    return gcdh;
}
 
int main()
{
	double p;
	double q;
    double n;
	double e;
	double msg;
	double totient;
	cout<<"enter a number to be encrypted :";
	cin>>msg;
	cout<<"enter p:";
	cin>>p;
	cout<<"enter q:";
	cin>>q;
	n=p*q;
	totient=(p-1)*(q-1);
	cout<<"enter e such that gcd(e,totient)=1:";
	cin>>e;
    
 
    //for checking co-prime which satisfies e>1
    while(e<totient){
    count = gcd(e,totient);
    if(count==1)
        break;

	else
        e++;
    }
 
    //private key
    //d stands for decrypt
    double d;
 
    
    double k = 2;
 
    //choosing d such that it satisfies d*e = 1 + k * totient
    d = (1 + (k*totient))/e;
    
    double c = pow(msg,e);
    double m = pow(c,d);
    // Encryption c = (msg ^ e) % n
    c=fmod(c,n);
   
 
    cout<<"Message data = "<<msg;
    cout<<"\n"<<"p = "<<p;
    cout<<"\n"<<"q = "<<q;
    cout<<"\n"<<"n = pq = "<<n;
    cout<<"\n"<<"totient = "<<totient;
    cout<<"\n"<<"e = "<<e;
    cout<<"\n"<<"d = "<<d;
    cout<<"\n"<<"Encrypted data = "<<c;
    
    
 
    return 0;
}




