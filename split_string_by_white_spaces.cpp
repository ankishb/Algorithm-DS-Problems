/*
Input:
3
Hello         world
My name          is                       Ankish
Bansal.               I stand here by the purpose of coding

Output:
Hello	world	
Hello	world
My	name	is	Ankish	
My	name	is	Ankish
Bansal.	I	stand	here	by	the	purpose	of	coding	
Bansal.	I	stand	here	by	the	purpose	of	coding

*/
// new try
#include <bits/stdc++.h>
using namespace std;

void split1(string s){
    istringstream ss(s);
    string word;
    while(ss >> word){
        cout<<word<<"\t";
    }
    cout<<endl;
}

void split2(string s){
    string word;
    int n = s.length(), i = 0;
    while(i < n){
        if(s[i] == ' '){
            cout<<word<<"\t";
            word = "";
            while(i < n && s[i] == ' ') i++;
            i--;
        }
        else word += s[i];
        i++;
    }
    cout<<word<<endl;
}

int main()
{
    int test;
    cin>>test;
    cin.ignore(1);
    while(test--){
        string s;
        getline(cin, s);
        // cout<<"---------- String Stream ---------------\n";
        split1(s);
        // cout<<"------------ Own logic -----------------\n";
        split2(s);
    }
    return 0;
}






// old one
#include <bits/stdc++.h>
using namespace std;

void split1(string s){
	string word = "";
	int n = s.length();
	for(int i=0; i<n; i++){
		if(s[i]==' ' && word.length()==0) continue;

		if(s[i] == ' '){
			cout<<word<<endl;
			word = "";
		}
		else{
			word += s[i];
		}
	}
	cout<<word<<endl;
}

void split2(string str){
	istringstream ss(str);
	do{
		string word;
		ss>>word;
		cout<<word<<endl;
	}
	while(ss);
}



int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string str;
		getline(cin, str);
		cout<<"------splitting by simple method-----\n";
		split1(str);
		cout<<"------splitting by string_stream-----\n";
		split2(str);
		// cout<<"splitting by using strtok\n";
		// split3(str);
	}
	return 0;
}