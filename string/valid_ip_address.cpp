/*
My solution:
    At each iteration, we partition the string, of length [1,2,3]
and check if further partiton of remaining string gives valid ans

Another approach:
    As we need only four substring, to check valid string , which 
    should be of length [4-12]. So we can run 3 loop(Note: As 3 
    loops can partition a string in 4 substrings)
*/
class ip_add{
public:
    vector<vector<string>> st;
    vector<string> cur;
    
    bool is_valid_ip(string c){
        int ci = stoi(c);
        if(to_string(ci) == c && ci >= 0 && ci <= 255){
            return true;
        }
        return false;
    }
    
    void partition(string s, int idx, int len){
        int n = s.length();
        if(idx+len<=n){
            string c = s.substr(idx, len);
            if(is_valid_ip(c)){
                cur.push_back(c);
                helper(s, idx+len);
                cur.pop_back();
            }
        }
    }
        
    void helper(string s, int idx){
        int n = s.length();
        if(idx == n && cur.size() == 4){
            st.push_back(cur);
            return;
        }
        
        partition(s, idx, 1);
        partition(s, idx, 2);
        partition(s, idx, 3);
    }
    
    vector<string> prepare_output(){
        vector<string> ans;
        string out;
        for(auto v : st){
            out = v[0];
            for(int i=1; i<v.size(); i++){
                out = out + "." + v[i];
            }
            ans.push_back(out);
        }
        return ans;
    }
};

vector<string> Solution::restoreIpAddresses(string s) {
    ip_add ip;
    ip.helper(s, 0);
    return ip.prepare_output();
}










// editorial solution


bool isValid(string s) {
    if (s.size() > 1 && s[0]  ==  '0')
        return false;
    if (stoi(s) <= 255 && stoi(s) >= 0)
        return true;
    else
        return false;
}
vector<string> Solution::restoreIpAddresses(string s) {
    vector<string> ans;
    if (s.size() > 12 || s.size() < 4)
        return ans;

    for (int i = 1; i < 4; i++) {
        string first  =  s.substr(0, i);
        if (!isValid(first))
            continue;
        for (int j = 1; i + j < s.size() && j < 4; j++) {
            string second  =  s.substr(i, j);
            if (!isValid(second))
                continue;
            for (int k = 1; i + j + k < s.size() && k < 4; k++) {
                string third = s.substr(i + j, k);
                string fourth = s.substr(i + j + k);
                if (isValid(third) && isValid(fourth)) {
                    string current  =  first + "." + second + "." + third + "." + fourth;
                    ans.push_back(current);
                }
            }
        }
    }

    return ans;
}

