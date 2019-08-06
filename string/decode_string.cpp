
class Solution {
public:
    string decodeString(string str) {
        stack<string> chars;
        int n = str.length();
        stack<int> nums;
        string res;
        int no = 0;
        for(int i=0; i<n; i++){
            if(isdigit(str[i])){
                no = no*10 + (str[i] - '0');
            }
            else if(isalpha(str[i])){
                res.push_back(str[i]);
            }
            else if(str[i] == '['){
                chars.push(res);
                nums.push(no);
                // reset them
                res = "";
                no = 0;
            }
            else if(str[i] == ']'){
                // first augment 
                string temp = "";
                for(int j=0; j<nums.top(); j++){
                    temp += res;
                }
                res = chars.top() + temp;
                chars.pop();
                nums.pop();
            }
        }
        return res;
    }
};