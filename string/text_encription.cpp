
#include <bits/stdc++.h>
using namespace std;

// not working (don't know why?)
// Complete the encryption function below.
string encryption(string orig) {
    string s = "";
    for(auto ch : orig){
        if(ch != ' ') s += ch;
    }
    int len = s.length();
    int low  = floor(sqrt((double)len));
    int high = ceil(sqrt((double)len));
    while(low*high < len){
        // as low <= high
        if(low < high) low++;
        else high++;
    }
    // cout<<len<<" "<<low<<" "<<high<<"\n";
    int len_, idx = 0;
    vector<string> v;
    string ss;
    // cout<<v.size()<<" "<<v[0].size()<<endl;
    for(int i=0; i<low; i++){
        idx = i*high;
        len_= (idx + high <= len) ? high : len-idx+1;
        ss = s.substr(idx, len_);
        v.push_back(ss);
    }
    string ans = "";
    for(int i=0; i<high; i++){
        for(int j=0; j<low; j++){
            if(v[j][i] == ' '){
                ans += " ";
                break;
            }
            else ans += v[j][i];
        }
        if(i < high-1) ans += " ";
    }
    return ans;
}

int main()
{
    // ofstream fout(getenv("OUTPUT_PATH"));
    string s;
    getline(cin, s);
    // string result = encryption(s);
    cout<<encryption(s);//<<endl;

    // fout << result << "\n";
    // fout.close();

    return 0;
}





// elegant solution 
int main(){
    string s;
    cin >> s;
    auto n = s.size();
    int row = round(sqrt(n));
    int column;
    if (row >= sqrt(n)) column = row; 
    else column = row + 1;
    for(int j=0;j<column;++j) {
        for(int i=j; i<n; i+=column) cout << s[i];
        cout << ' ';
    }
    return 0;
}