#include<iostream>
 
using namespace std;
int encryption();
int decryption();
char message[100], ch;
int key,choice;

 
int main()
{
    
    cout<<" Playfair Cipher ";
    cout << "Enter a message ";
    cin.getline(message,100);
    cout << "Enter key: ";
    cin >> key;
    cout<<"enter your choice:\n 1 for encryption \n 2 for decryption \n";
    cin>>choice;
    switch(choice){
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
	for(int i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch + key;
            if(ch>='a' && ch<='z')
            {
            	message[i] = ch;
			}
			else{
				message[i] = ch-26;
			}
}
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch + key;
            if(ch>='A' && ch<='Z')
            {
            	message[i] = ch;
			}
			else{
				message[i] = ch-26;
			}
            
            
            
            
        }
    }
    
    cout << "Encrypted message: " << message;
    return 0;
    
    
}
int decryption()
{
for(int i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        
        if(ch >= 'a' && ch <= 'z'){
            ch = ch - key;
            
            
            
            message[i] = ch;
        }
        else if(ch >= 'A' && ch <= 'Z'){
            ch = ch - key;
            
            
            
            message[i] = ch;
        }
    }
    
    cout << "Encrypted message: " << message;
    return 0;
}

