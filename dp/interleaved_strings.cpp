
/* Backtracking
1. first we check, if all the string have reached at end,
	if yes, we get ans
2. if final string have reached at end, it would be impossible to do then
3. now check, if first character match with any of other's first charater
	we check over all possible cases and final get our result
*/
unordered_map<string, bool> my_map;

bool backtrack_with_mem(string s1, string s2, string s) {
    if(s1.length()==0 && s2.length()==0 && s.length()==0){
        return true;
    }
    else if(s.length()==0){
        return false;
    }

    string s_ = s1 + "|" + s2 + "|" + s;
    if(my_map.find(s_) != my_map.end()){
        return my_map[s_];
    }
    
    bool first = false, second = false;
    if(s1.length()>0 && s1[0] == s[0]){
        first = backtrack_with_mem(s1.substr(1), s2, s.substr(1));
    }
    if(s2.length()>0 && s2[0] == s[0]){
        second = backtrack_with_mem(s1, s2.substr(1), s.substr(1));
    }
    my_map[s_] = (first || second);
    return my_map[s_];
}


bool backtrack(string s1, string s2, string s) {
    if(s1.length()==0 && s2.length()==0 && s.length()==0){
        return true;
    }
    else if(s.length()==0) return false;
    
    // cout<<s1<<" "<<s2<<" "<<s<<endl;
    bool first = false, second = false;
    if(s1.length()>0 && s1[0] == s[0]){
        first = backtrack(s1.substr(1), s2, s.substr(1));
    }
    if(s2.length()>0 && s2[0] == s[0]){
        second = backtrack(s1, s2.substr(1), s.substr(1));
    }
    return (first || second);
}


bool isInterleave(string s1, string s2, string s) {
    // return backtrack(s1, s2, s);
    return backtrack_with_mem(s1, s2, s);
}