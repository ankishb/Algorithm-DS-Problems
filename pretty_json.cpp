// Given a string and number of rows ‘n’. Print the string formed by concatenating n rows when input string is written in row-wise Zig-Zag fashion.

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

void string_tab(string &s, int tab_count){
	for(int i=0; i<tab_count; i++){
		s = s+'\t';
	}
}

void pretty_json(string s){
	vector<string> vect;
	string temp = "";
	int tab_count = 0;
	for(int i=0; i<s.length(); i++){
		if(s[i] == ' '){

		}
		else if(s[i] == '{' || s[i]=='['){
			if(temp != "" && s[i-1]!=' ' && i>0){
				vect.push_back(temp);
			}
			temp = "";
			string_tab(temp, tab_count);
			temp = temp+s[i];
			tab_count++;
			vect.push_back(temp);
			temp = "";
		}
		else if((s[i-1]=='{' || s[i-1]=='[')&&(i>0)&&(s[i]!='{' || s[i]!='[')){
			if(s[i] != ','){
				temp = "";
				string_tab(temp, tab_count);
				temp = temp+s[i];
			}
			else{
				if(temp !=""){
					vect.push_back(temp);
					temp = "";
					string_tab(temp, tab_count);
				}
			}
			
		}
		else if((s[i]=='}' || s[i]==']')&&(i>0)){
			if(temp != "" && s[i-1]!=' '){
				vect.push_back(temp);
			}
			tab_count--;
			temp = "";
			string_tab(temp, tab_count);
			vect.push_back(temp+s[i]);
		}
		else if((s[i-1]=='}' || s[i-1]==']')&&(i>0)&&(s[i]!='}' || s[i]!=']')){
			if(s[i] != ','){
				temp = "";
				string_tab(temp, tab_count);
				temp = temp+s[i];
			}
			else{
				// temp = "";
				temp = ',';
				vect.push_back(temp);
				temp = "";
				string_tab(temp, tab_count);
			}
		}

		else if((i==s.length()-1)&&(s[i]!='{' || s[i]!='[')&&(s[i]!='}' || s[i]!=']')){
			temp = temp+s[i];
			vect.push_back(temp);
		}
		else{
			if(s[i] != ','){
				temp += s[i];
			}
			else{
				temp += s[i];
				vect.push_back(temp);
				temp = "";
				string_tab(temp, tab_count);
			}
			
		}
	}
	for(int i=0; i<vect.size(); i++){
		cout<<vect[i]<<endl;
	}
}

int main()
 {
	int test;
	cin>>test;
	while(test--){
		string s;
		getline(cin, s);
		pretty_json(s);
	}
	return 0;
}










////////////////////////
Keep in mind these things -

1) ‘{‘, ‘[’ have the same effect on the printing

2) ‘}’, ‘]’ have the same effect as well

3) ‘:’ and ‘,’ are the only other 2 characters that matter.

Then after taking care of corner cases code will be  -

vector<string> ChangeInput(string str)
{
    vector<string> result;
    if (str.length() == 0) 
        return result;

    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    string indent = "";
    string curr = "";
    int i = 0, len = str.length();
    
    while (i < len)
    {
        curr.push_back(str[i]);
        switch(str[i])
        {
            case ',':
                result.push_back(curr);
                curr = indent;
                i++;
                break;

            case ':':
                i++;
                if (str[i] == '{' || str[i] == '[')
                {
                    result.push_back(curr);
                    curr = indent;
                }
                break;

            case '{':
            case '[':

                i++;
                result.push_back(curr);
                if (i < len && (str[i] != '}' || str[i] != ']'))
                {
                    indent.push_back('\t');
                }
                curr = indent;
                break;

            case '}':
            case ']':
                i++;
                if (i < len && str[i] == ',') break;
                result.push_back(curr);
                if (i < len && (str[i] == '}' || str[i] == ']'))
                {
                    if (!indent.empty()) indent.pop_back();
                }
                curr = indent;
                break;

            default : 
                i++;
                if (i < len && (str[i] == '}' || str[i] == ']'))
                {
                    result.push_back(curr);
                    if (!indent.empty()) indent.pop_back();
                    curr = indent;
                }
        }
    }
    return result;
}