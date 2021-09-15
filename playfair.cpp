#include <iostream>
#include <string>
#include <algorithm>
	
using namespace std;

string key, msg, encrypt_msg,decrypt_msg,de_msg,res="";
char mat[5][5];
int msg_len,choice;
int i,j,k,c,l,a,b,d,z;
string remove_duplicate(string);
string pren(string);
string prde(string);
string encryption(char [5][5], string);
string decryption(char [5][5], string);
string remove_spaces(string);
int main()
{

	cout << "enter the key: ";
	cin >> key;
	cout << "enter the message: ";
	cin.ignore(100, '\n');

getline(cin, msg);
msg_len=msg.size();
	msg = remove_spaces(msg);
	cout << "Msg without spaces: "<< msg << "\n";

	key+="abcdefghiklmnopqrstuvwxyz";
	key = remove_duplicate(key);

	for(i=0,k=0;i<5;i++){
		for(j=0;j<5;j++){
		  mat[i][j]=key[k];
		  k++;
		}
	}

	for(i=0;i<5;i++){
		for(j=0;j<5;j++){
			if(mat[i][j]=='i'){
				cout << "i/j";
			}
			else{
				cout << mat[i][j];
		  }
			cout << " ";
		}
		cout << "\n";
	}
cout<<"enter your choice 1 for encryption 2 for decryption";
	cin>>choice;
	switch(choice)
		{

		case 1:
			cout<< "encryption"<<endl;
			 msg = pren(msg);
	        cout <<"message to be encrypted is:\t"<<  msg << endl;
			encrypt_msg = encryption(mat, msg);
			cout<<"the encrypted msg is:\t";
	        cout << encrypt_msg << endl;
	        break;
	    case 2:
	    	cout << "decryption" << endl;
	    	de_msg=decryption(mat,msg);
				cout <<"message to be decrypted with 'x' is:" <<de_msg << endl;
	    	 decrypt_msg=prde(de_msg);
	    	 cout<<"the decrypted msg is:\t";
	    	 cout << decrypt_msg << endl;
	    	 break;
}


}

string remove_duplicate(string key){
	string res = "";
	for(int i=0; i<key.size(); i++){
		if(res.find(key[i]) == string::npos){
			res+=key[i];
		}
	}
	return res;
}

string remove_spaces(string msg){
	res = "";
	for(int i = 0; i < msg.size(); i++){
		if(msg[i] == ' ')
			continue;
		else
			res += msg[i];
	}
	return res;
}

	string pren(string msg){
  for(int i = 0; i < msg.size()-1; i+=2){
    if(msg[i]==msg[i+1]){
      msg.insert(i+1, "x");
    }
  }
  if(msg.size()%2 != 0){
    msg += "x";
  }	
  return msg;
}

string encryption(char mat[5][5], string msg){
	string res = "";
	for(int l = 0; l < msg.size()-1; l+=2){
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if(msg[l] == mat[i][j]){
					a = i;
					b = j;
				}
				if(msg[l+1] == mat[i][j]){
					c = i;
					d = j;
				}
			}
		}

		if(c==a){
			res += mat[a][(b+1)%5];
			res += mat[c][(d+1)%5];
		}
		else if(b==d){
			res += mat[(a+1)%5][b];
			res += mat[(c+1)%5][d];
		}
		else{
			res += mat[a][d];
			res += mat[c][b];
		}
	}
	return res;
}
string decryption(char mat[5][5], string msg)
{
	res = "";
	for(int l = 0; l < msg.size()-1; l+=2){
		for (int i = 0; i < 5; i++){
			for (int j = 0; j < 5; j++){
				if(msg[l] == mat[i][j]){
					a = i;
					b = j;
				}
				if(msg[l+1] == mat[i][j]){
					c = i;
					d = j;
				}
			}
		}

		if(c==a){
			res += mat[a][(b+4)%5];
			res += mat[c][(d+4)%5];
		}
		else if(b==d){
			res += mat[(a+4)%5][b];
			res += mat[(c+4)%5][d];
		}
		else{
			res += mat[a][d];
			res += mat[c][b];
		}
	}
	return res;
}

string prde(string de_msg)
{
	string::iterator it = de_msg.begin() + 1;
	while(it != de_msg.end()-1) {
		if(*it == 'x' && *(it-1) == *(it+1))
			de_msg.erase(it);
		it++;
	}
	if(*(it) == 'x')
		de_msg.erase(it);
	return de_msg;
}



