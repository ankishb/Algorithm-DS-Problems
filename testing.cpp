// https://www.interviewbit.com/problems/reverse-the-string/

// - A sequence of non-space characters constitutes a word.
// - Your reversed string should not contain leading or trailing spaces, even if it is present in the input string.
// - If there are multiple spaces between words, reduce them to a single space in the reversed string

#include <bits/stdc++.h>
using namespace std;

void reverse_string(string &A){
    int count=0;

    for(int i=A.length()-1; i>=0; i--){
    	cout<<"-- entering loop --"<<endl;
        if(A[i] == ' ' && count != 0){
            cout<<A.substr(i+1, count)<<" ";
            count = 0;
            // idx = 
        }
        else{
            count++;
        }
        // count++;
    }
    cout<<A.substr(0, count);
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		string A;
		getline(cin, A);
		cout<<A<<endl;
		reverse_string(A);
	}
	return 0;
}




// C++ program for illustration 
// of multimap::find() function 
#include <bits/stdc++.h> 
using namespace std; 
  
int main() 
{ 
  
    // initialize container 
    multimap<int, int> mp; 
  
    // insert elements in random order 
    mp.insert({ 2, 30 }); 
    mp.insert({ 1, 40 }); 
    mp.insert({ 2, 60 }); 
    mp.insert({ 3, 20 }); 
    mp.insert({ 1, 50 }); 
    mp.insert({ 4, 50 }); 
  
    cout << "The elements from position 3 in multimap are : \n"; 
    cout << "KEY\tELEMENT\n"; 
  
    // // find() function finds the position at which 3 is 
    // for (auto itr = mp.find(1); itr != mp.end(); itr++){
    //  if(itr != mp.end()){
    //      cout << itr->first << '\t' << itr->second << '\n'; 
    //  }
    // }
    multimap<int, int>::iterator itr;
    itr = mp.find(1);
    if(itr != mp.end()){
        cout<<itr->first<<" : "<<itr->second<<endl;
    }
  
    return 0; 
}