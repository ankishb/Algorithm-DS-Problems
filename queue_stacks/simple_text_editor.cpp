#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, query, k, ith, m;
    string w, cur;
    cin>>n;
    stack<string> s;
    for(int i=0; i<n; i++){
        cin>>query;
        if(query == 1){
            //append
            cin>>w;
            if(s.empty()) s.push(w);
            else s.push(s.top()+w);
        }
        else if(query == 2){
            // delete last k character
            // i assume stack is not empty
            cin>>k;
            if(s.empty()) continue;
            cur = s.top();
            m = cur.length();
            cur = cur.substr(0, m-k);
            // if(m == k) cur = "";
            s.push(cur);
        }
        else if(query == 3){
            cin>>ith;
            if(s.empty()) continue;
            cur = s.top();
            cout<<cur[ith-1]<<endl;
        }
        else{
            s.pop();
        }
    }
    
    return 0;
}







#include<bits/stdc++.h>
using namespace std;


int main() {
    int n, query, k, ith, m;
    string w, cur;
    cin>>n;
    stack<string> s;
    for(int i=0; i<n; i++){
        cin>>query;
        switch(query){
        	case 1: 
	    		//append
	            cin>>w;
	            if(s.empty()) s.push(w);
	            else s.push(s.top()+w);
	    		break;
	    	case 2:
				// delete last k character
				// i assume stack is not empty
				cin>>k;
				if(s.empty()) continue;
				cur = s.top();
				m = cur.length();
				cur = cur.substr(0, m-k);
				// if(m == k) cur = "";
				s.push(cur);
				break;
	        case 3:
	        	cin>>ith;
	            if(s.empty()) continue;
	            cur = s.top();
	            cout<<cur[ith-1]<<endl;
	            break;
	        case 4:
	        	s.pop();
	        // default:
	        // 	cout<<"recheck you input\n";
    	}
    }
    return 0;
}
