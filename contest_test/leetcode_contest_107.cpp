
class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        int count_i=0, count_j=0;
        int i=0, j=0;
        int n=name.length(), m=typed.length();
        if(n==0 && m==0) return true;
        else if(n==0 || m==0) return false;
        if(name[i] != typed[j]) return false;
        j++;
        for(i=0; i<n; i++){
        	count_i=1, count_j=1;
        	while(i<n-1 && name[i+1]==name[i]){
        		count_i++; i++;
        	}
        	while(j<m-1 && typed[j+1]==typed[j]){
        		count_j++; j++;
        	}
			if(count_j < count_i) return false;
        }
        return true;
    }
};




class Solution {
public:
    int minFlipsMonoIncr(string S) {
        int n=S.length();
        bool first_1 = false;
        int count_1=0, count_0=0;
        for(int i=0; i<n; i++){
            if(S[i] == '1'){
                count_1++;
                first_1 = true;
            }
            if(S[i]=='0' && first_1==true){
                count_0++;
            }
        }
        return (count_1<count_0) ? count_1 : count_0;
    }
};