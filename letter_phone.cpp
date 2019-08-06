

#include <bits/stdc++.h>
using namespace std;


void get_comb(string a, string b, map<string, string> my_map, 
              vector<string> &ans){
    
    string a_val = my_map[a];
    string b_val = my_map[b];
    
    for(int i=0; i<a_val.length(); i++){
        string temp = "";
        for(int j=0; j<b_val.length(); j++){
            temp = temp + a_val[i] + b_val[j];
            // cout<<temp<<endl;
            ans.push_back(temp);
            temp = "";
        }
    }
}

vector<string> phone_letter_comb(string s){
    vector<string> ans;
    map<string, string> my_map;
    my_map["0"] = "0";
    my_map["1"] = "1";
    my_map["2"] = "abc";
    my_map["3"] = "def";
    my_map["4"] = "ghi";
    my_map["5"] = "jkl";
    my_map["6"] = "mno";
    my_map["7"] = "pqrs";
    my_map["8"] = "tuv";
    my_map["9"] = "wxyz";

    if(s.length() == 1){
        string a_val = my_map[s[0]];
        for(int i=0; i<a_val.length(); i++){
            string temp = "";
            temp = temp + a_val[i];
            ans.push_back(temp);
        }
        
        return ans;
    }

    vector<string> A;
    for(int i=0; i<s.length(); i++){
    	A.push_back(my_map[s[i]]);
    }

    for(int i=0; i<s.length()-1; i++){
        for(int j=i+1; j<s.length(); j++){
            if((s[i]=="0" || s[i]=="1") && 
               (s[j]=="0" || s[j]=="1")){
                string temp = "";
                temp = temp + s[i] + s[j];
            }
            else{
                get_comb(s[i], s[j], my_map, ans);
            }
        }
    }

    return ans;
    
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		string s;
		cin>>s;

		vector<string> ans;
		ans = phone_letter_comb(s);

		vector<string>::iterator itr;
		cout<<"\n letter combinations \n";
		for(itr=ans.begin(); itr!=ans.end(); ++itr){
			cout<<*itr<<" ";
		}
		cout<<endl;
	}
	return 0;
}



// correct solution

// 1. Recursive
string checkMapping(int A){
    if(A == '0'){
        return "0";
    }
    else if(A == '1'){
        return "1";
    }
    else if(A == '2'){
        return "abc";
    }
    else if(A == '3'){
        return "def";
    }
    else if(A == '4'){
        return "ghi";
    }
    else if(A == '5'){
        return "jkl";
    }
    else if(A == '6'){
        return "mno";
    }
    else if(A == '7'){
        return "pqrs";
    }
    else if(A == '8'){
        return "tuv";
    }
    else if(A == '9'){
        return "wxyz";
    }
    return "";
}

void rec(vector<string> values, vector<string>& sol, string s, int i, int j){
    int size = values.size();
    if(i == values.size()){
        sol.push_back(s);
        return;
    }
    s = s + "1";
    for(; j < values[i].size(); j++){
        s[s.size()-1] = values[i][j];
        rec(values, sol, s, i+1, 0);
    }
}

vector<string> Solution::letterCombinations(string A) {
    vector<string> sol;
    vector<string> values;
    
    for(int i = 0; i < A.size(); i++){
        values.push_back(checkMapping(A[i]));
    }
    rec(values, sol, "", 0, 0);
    
    return sol;
    
}



// 2. Iterative
#include <bits/stdc++.h> 
using namespace std; 

// Function to return a vector that contains 
// all the generated letter combinations 
vector<string> letterCombinationsUtil(const int number[], 
									int n, 
									const string table[]) 
{ 
	// To store the generated letter combinations 
	vector<string> list; 

	queue<string> q; 
	q.push(""); 

	while (!q.empty()) { 
		string s = q.front(); 
		q.pop(); 

		// If complete word is generated 
		// push it in the list 
		if (s.length() == n) 
			list.push_back(s); 
		else

			// Try all possible letters for current digit 
			// in number[] 
			for (auto letter : table[number[s.length()]]) 
				q.push(s + letter); 
	} 

	// Return the generated list 
	return list; 
} 

// Function that creates the mapping and 
// calls letterCombinationsUtil 
void letterCombinations(const int number[], int n) 
{ 

	// table[i] stores all characters that 
	// corresponds to ith digit in phone 
	string table[10] 
		= { "0", "1", "abc", "def", "ghi", "jkl", 
			"mno", "pqrs", "tuv", "wxyz" }; 

	vector<string> list 
		= letterCombinationsUtil(number, n, table); 

	// Print the contents of the vector 
	for (auto word : list) 
		cout << word << " "; 

	return; 
} 

// Driver program 
int main() 
{ 
	int number[] = { 2, 0, 3, 1}; 
	int n = sizeof(number) / sizeof(number[0]); 

	letterCombinations(number, n); 

	return 0; 
} 










class Solution {
public:
    void generate_comb(string s1, string s2, vector<string> &ans){
        int n1 = s1.length();
        int n2 = s2.length();
        string s;
        for(int i=0; i<n1; i++){
            for(int j=0; j<n2; j++){
                cout<<s1[i]<<s2[j]<<" ";
                s = s1[i] + s2[j];
                ans.push_back(s);
            }
        }
    }
    void generate_comb2(vector<string> &temp, string s2){
        vector<string> ans;
        int n1 = temp.size();
        int n2 = s2.length();
        string s1;
        for(int i=0; i<n1; i++){
            s1 = temp[i];
            generate_comb(s1, s2, ans);
        }
        // return ans;
        for(auto itr : ans) cout<<itr<<" ";
        temp = ans;
    }
    
    vector<string> letterCombinations(string digits) {
        unordered_map<char, string> mapping;
        mapping.insert({'0',"0"});
        mapping.insert({'1',"1"});
        mapping.insert({'2',"abc"});
        mapping.insert({'3',"def"});
        mapping.insert({'4',"ghi"});
        mapping.insert({'5',"jkl"});
        mapping.insert({'6',"mno"});
        mapping.insert({'7',"pqrs"});
        mapping.insert({'8',"tuv"});
        mapping.insert({'9',"wxyz"});
        
        int n = digits.length();
        vector<string> ans, temp;
        if(n == 0) return ans;
        string s = mapping[digits[0]];
        string tp;
        for(int i=0; i<s.length(); i++){
            tp = "";
            tp = tp + s[i];
            ans.push_back(tp);
        }
        if(n == 1){
            return ans;
        }
        for(int i=1; i<n; i++){
            // char tp = digits[i];
            cout<<digits[i]<<" "<<mapping[digits[i]]<<endl;
            generate_comb2(ans, mapping[digits[i]]);
        }

        return ans;
    }
};