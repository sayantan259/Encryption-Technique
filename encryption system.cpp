//Encryption model
#include<bits/stdc++.h>
#include<fstream>
using namespace std;

//Random string generater for noise
string printRandomString(){
	const int MAX = 67;
	char alphabet[MAX] = { 'a', 'b', 'c','\\', 'd', 'e', 'f', 'g','h', 'i', 'j', 'k', 'l', 'm',
						   'n','o', 'p', 'q', 'r','\\', 's', 't', 'u','v', 'w', 'x', 'y', 'z',
						   'A', 'B', 'C', 'D', 'E', 'F','\\', 'G','H', 'I', 'J', 'K', 'L', 'M',
						   'N','O', 'P', 'Q', 'R', 'S', 'T', 'U','\\','V', 'W', 'X', 'Y', 'Z',
						   '0', '1', '2', '3', '4', '5', '6','7', '8', '9','\\'};//charecter space for random string
	string res="";
	srand(time(0));
	for (int i = 0; i < 1000; i++) res = res + alphabet[rand() % MAX];
	return res;
}

//Function for encryption
	string encrypt(string &s){
	vector<char> source{'=', 'b', 'c', '{', 'e', '.', 'g','h', 'i', '>', 'k', '9', 'm',
					    'n','o', 'B', 'q', 'r', '4', 't', '6','v', 'w', 'x', 'L', 'z',
						'A', 'p', 'C', '!', 'E', 'F', 'G',')', 'I', 'J', 'K', 'y', 'M',
						'N','O', 'P', 'Q', 'R', 'S', '%', 'U','V', 'W', 'X', 'Y', 'Z',
						'D', '@', '#', '$', 'T', '^', '&','*', '(', 'H', 'd', '}', '[',
						']', '|', ';', ':', ',', '<','f', 'j', '?', '/', '~',
						'`',' ','0','1','2','3','s','5','u','7','8','l','-','_','+','a','\''};//key for encryption
    //compressing string before encryption                    
	string q1 = "%1";
	string q2 = "%2";
	int n = s.size();
	if(n > 4){
		for (int i = 0; i < s.size()-4; i++){
			if (s[i] == ' ' && s[i+1] == 't' && s[i+2] == 'h' && s[i+3] == 'e' && s[i+4] == ' '){
				s.replace(i+1, 3, q1);
				i-=2;
			}
			if (s[i] == ' ' && s[i+1] == 'a' && s[i+2] == 'n' && s[i+3] == 'd' && s[i+4] == ' '){
				s.replace(i+1, 3, q2);
				i-=2;
			}
		}
	}
	//encryption process
	for (int i = 0; i < s.size(); i++){
        if(i >= 93 && s[i] == ' '){
            s[i] = '\\';
        }else{
			auto it = find(source.begin(), source.end(), s[i]);
			s[i] = source[((it - source.begin()) + i) % 93];
        }
	}
	//generating noise string
	string s1;
	int h = 0;
	s1 = printRandomString();
	//adding noise into encrypted string
	for (int i = 0; i < s.size(); i++){
		if (i%2 == 0){
			s.insert(i, s1.substr(h, 1));
			h = (h + 1) % 1000;
		}
	} 
	return s;//encrypted string
}

//Function for decryption
string decrypt(string &s){
	vector<char> source{'=', 'b', 'c', '{', 'e', '.', 'g','h', 'i', '>', 'k', '9', 'm',
					    'n','o', 'B', 'q', 'r', '4', 't', '6','v', 'w', 'x', 'L', 'z',
						'A', 'p', 'C', '!', 'E', 'F', 'G',')', 'I', 'J', 'K', 'y', 'M',
						'N','O', 'P', 'Q', 'R', 'S', '%', 'U','V', 'W', 'X', 'Y', 'Z',
						'D', '@', '#', '$', 'T', '^', '&','*', '(', 'H', 'd', '}', '[',
						']', '|', ';', ':', ',', '<','f', 'j', '?', '/', '~',
						'`',' ','0','1','2','3','s','5','u','7','8','l','-','_','+','a','\''};

	string t = "";
	//removing noise
	for (int i = 0; i < s.size(); i++){
        if(i%2!=0) t+=s[i];
    } 
    //decrypting the string
	for (int i = 0; i < t.size(); i++){
        if(i >=93 && t[i] == '\\'){
            t[i]=' ';
        }else{
			auto it = find(source.begin(), source.end(), t[i]);
			int k = (it - source.begin() + 930000000 - i) % 93;
		t[i] = source[k];
        }
	}
	//decompressing the string
	string q1 = "the";
	string q2 = "and";
	int n = t.size();
	if(n > 3){
		for (int i = 0; i < t.size()-3; i++){
			if (t[i] == ' ' && t[i+1] == '%' && t[i+2] == '1' && t[i+3] == ' '){
				t.replace(i+1, 2, q1);
				i-=1;
			}
			if (t[i] == ' ' && t[i+1] == '%' && t[i+2] == '2' && t[i+3] == ' '){
				t.replace(i+1, 2, q2);
				i-=1;
			}
		}
	}
	return t;//decrypting the string

}

//Function that encrypts data in a selected file
void encryptfromfile(string &s){
    string line = "", temp;
	string encline;//encline=encrypted line
	//object for reading file
	ifstream fin(s, ios::in);
	
	if(!fin){
		cout << "file not found";
	}else{
		//if file found,input is taken
        while(fin.eof() == 0){
           getline(fin, temp);
           line+=temp;
        }
		fin.close();
	    encline = encrypt(line);
	    //object created to write in file
	    ofstream fout(s);
	    fout << encline << endl;
	    fout.close();
    }
    cout << "\nEncryption successfull" << endl;
}

//Function that decrypts data in a selected file
void decryptfromfile(string s){
    string line = "", temp;
	string encline;
	//object for reading file
    ifstream fin1(s,ios::in);
	//if file found,input is taken
	if(!fin1){
        cout << "file not found";
	}else{
        while(fin1.eof() == 0){
          	getline(fin1,temp);
           	line+=temp;
        }
        fin1.close();
        encline = decrypt(line);
        //object created to write in file
        ofstream fout1(s);
        fout1 << encline << endl;
        fout1.close();
    }
    cout << "\nDecryption successful" << endl;
}

int main(){

    int ch;
    while(1){
        cout << "\nChoose any one option";
        cout << "\n1. Encrypt file";
        cout << "\n2. Decrypt file";
        cout << "\n3. Exit\n";
        cin >> ch;

        switch(ch){
	        case 1:{
	            string filename;
	            cout << "Enter the text file name in .txt format: "; 
	            cin >> filename;
	            encryptfromfile(filename);
	            break;
	        }
	        case 2:{
	            string filename;
	            cout << "Enter the text file name in .txt format: "; 
	            cin >> filename;
	            decryptfromfile(filename);
	            break;
	        }
	        case 3:
	            exit(0);
	        default:{
	            cout << "Invalid choice";
	            break;
	        }
        }
    }	
	return 0;
}