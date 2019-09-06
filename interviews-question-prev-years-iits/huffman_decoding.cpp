
/*
1
5
a 01
b 110
c 101
d 0010
e  1111
1100010110111101
Output: bdbea
*/

string huffmanDecode(vector<string> codes, string encoded) {
    int n = codes.size();
    unordered_map<string,char> ids;
    for (int i = 0; i < n; i++) {
        char key = codes[i][0];
        string val = codes[i].substr(2);
        ids[val] = key;
    }
    string decoded = "", cur = "";
    for (char c : encoded) {
        cur += c;
        if (ids.find(cur) != ids.end()) {
            decoded += ids[cur];
            cur = "";
        }
    }
    if (cur != "") {
        decoded += ids[cur];
    }
    return decoded;
}

int main() {
    // Driver Program to test above function
    assert(huffmanDecode(
        {"a\t01", "b\t110", "c\t101", "d\t0010", "\n\t1111"},
        "1100010110111101") == "bdb\na");
    return 0;
}






#include <bits/stdc++.h>
using namespace std;

string huffmanDecode(vector<string> str, string decode){
    unordered_map<string,char> my_map;
    // for(auto s : str) cout<<s[0]<<" "<<s.substr(2)<<" \n";
    for(auto s : str) my_map[s.substr(2)] = s[0];
    set<int> len;
    for(auto itr : my_map) len.insert(itr.first.length());
    string substr, ans;
    int i=0, j, n = decode.length();
    while(i <= n-1){
        for(auto l : len){
            substr = decode.substr(i, l);
            if(my_map.find(substr) != my_map.end()){
                ans += my_map[substr];
                i += l;
                break;
            }
        }
    }
    
    return ans;
}

int main()
{
    string ans = huffmanDecode(
        {"a\t01", "b\t110", "c\t101", "d\t0010", "e\t1111"},
        "1100010110111101");
    assert(ans == "bdbea");
    cout<<"passed test case\n";
    return 0;
}






#include <bits/stdc++.h>
using namespace std;

string huffmanDecode(unordered_map<string,string> my_map, string decode){
    set<int> len;
    for(auto itr : my_map){
        len.insert(itr.first.length());
    }
    string substr, ans;
    int i=0, j, n = decode.length();
    while(i <= n-1){
        for(auto l : len){
            substr = decode.substr(i, l);
            cout<<substr<<" ";
            if(my_map.find(substr) != my_map.end()){
                ans += my_map[substr];
                i += l;
                break;
            }
        }
        cout<<i<<" :: ";
    }
    
    return ans;
}

int main()
{
    int test; cin>>test;
    while(test--){
        int n; cin>>n;
        unordered_map<string, string> my_map;
        string a, b;
        for(int i=0; i<n; i++){
            cin>>a>>b;
            my_map[b] = a;
        }
        string decode;
        cin>>decode;
        cout<<huffmanDecode(my_map, decode)<<endl;
    }
    return 0;
}



    // // Driver Program to test above function
    // assert(huffmanDecode(
    //     {"a\t01", "b\t110", "c\t101", "d\t0010", "\n\t1111"},
    //     "1100010110111101") == "bdb\na");