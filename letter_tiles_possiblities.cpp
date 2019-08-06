
void check_cases(string rem, string pre, unordered_map<string, int> &ans){
	if(rem.length() == 0){
		if(pre.length() != 0){
			ans[pre] = 1;
		}
		return ;
	}
	for(int i=0; i<rem.length(); i++){
		char c = rem[i];
		string before = rem.substr(0, i);
		string after = rem.substr(i+1);
		string new_ = before + after;
		check_cases(new_, pre, ans);
		check_cases(new_, pre+c, ans);
	}
}

class Solution {
public:
    int numTilePossibilities(string tiles) {
	unordered_map<string, int> ans;
	check_cases(tiles, "", ans);
	return ans.size();  
    }
};
