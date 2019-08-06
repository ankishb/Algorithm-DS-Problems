
class Solution {
public:
    int kthGrammar(int N, int K) {
        int n=N, k=K;
        vector<int> store;
        while(n != 0){
            store.push_back(k);
            n--;
            k = (k%2 == 0) ? (k/2) : (k/2)+1;
            cout<<k<<" ";
        }
        int sec, first;
        string start = "0";
        for(int i=store.size()-2; i>=0; i--){
            start = (start == "0") ? "01" : "10";
            sec = store[i];
            if(sec%2 == 0) start = start[1];
            else start = start[0];
        }
        return (start=="0") ? 0 : 1;
    }
};