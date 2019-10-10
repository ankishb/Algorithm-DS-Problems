
/* Clever trick(efficient)
1. tranverse over all charactrer in string
2. Do following at each step
	1. If found character(not space), count len
	2. If found spaces, increment itr.
*/
int Solution::lengthOfLastWord(const string s) {
    int n = s.length(), len = 0, i = 0;
    while(i < n){
        len = 0;
        while(i < n && s[i] != ' '){
            len++; i++;
        }
        while(i < n && s[i] == ' ') i++;
    }
    return len;
}




void inefficient_length_of_last_word(string A){
	int index = 0;
	int count = 0;
	int prev_count = 0;
	int i;
	for(int i=0; i<A.length(); i++){
		if(A[i] != ' '){
			count++;
			cout<<count<<" ";
			// index = i;
		}
		else if(A[i]==' ' && A[i-1]!=' '){
			prev_count = count;
			count = 0;
		}
		else{
			count = 0;
		}
	}
	if(A[A.length()-1] != ' '){
		// count is not zero and was not stored in prev_count
		cout<<endl<<count<<endl;
	}
	else{
		cout<<endl<<prev_count<<endl;
	}
}

void length_of_last_word(string A){
	int count = 0;
	int prev_count = 0;
	for(int i=A.length()-1; i>=0; i--){
		if(A[i+1] != ' ' && A[i] == ' ' && i<A.length()-1){
			break;
		}
		if(A[i] == ' '){
			count = 0;
		}

		else if(A[i] != ' '){
			count++;
			cout<<count<<" ";
			// index = i;
		}
	}
	cout<<count<<endl;
}