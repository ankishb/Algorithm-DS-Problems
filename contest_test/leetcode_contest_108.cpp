
/*
Every email consists of a local name and a domain name, separated by the @ sign.

For example, in alice@leetcode.com, alice is the local name, and leetcode.com is the domain name.

Besides lowercase letters, these emails may contain '.'s or '+'s.

If you add periods ('.') between some characters in the local name part of an email address, mail sent there will be forwarded to the same address without dots in the local name.  For example, "alice.z@leetcode.com" and "alicez@leetcode.com" forward to the same email address.  (Note that this rule does not apply for domain names.)

If you add a plus ('+') in the local name, everything after the first plus sign will be ignored. This allows certain emails to be filtered, for example m.y+name@email.com will be forwarded to my@email.com.  (Again, this rule does not apply for domain names.)
*/
class Solution {
public:
    int numUniqueEmails(vector<string>& emails) {
        set<string> store;
        int n = emails.size();
        string s;
        int j, jj;
        string temp;
        for(int i=0; i<n; i++){
            s = "";
            temp = emails[i];
            for(j=0; j<temp.length(); j++){
                if(temp[j] == '@') break;
                else if(temp[j] == '.') continue;
                else if(temp[j] == '+') break;
                else s += temp[j];
            }
            while(j<temp.length() && temp[j] != '@') j++;
            for(jj=j; jj<temp.length(); jj++){
                s += temp[jj];
            }
            store.insert(s);
        }
        return store.size();
    }
};







class Solution {
public:
    void getMinSum(vector<vector<int> > T, int row, int col, int cur_sum, int &min_sum){
        cout<<row<<" "<<col<<" "<<T[row][col]<<" "<<cur_sum<<endl;
        // if(cur_sum > min_sum) return ;
        if(row >= T.size() || col >= T.size()) return;
        if(row == T.size()-1){
            if(min_sum > cur_sum){
                min_sum = cur_sum;
            }
            return ;
        }

        if(row <= T.size()-1 && col-1 >= 0){
            getMinSum(T, row+1, col-1, cur_sum+T[row+1][col-1], min_sum);
        }
        if(row <= T.size()-1) getMinSum(T, row+1, col, cur_sum+T[row+1][col], min_sum);
        if(row <= T.size()-1 && col+1 <= T.size()){
            getMinSum(T, row+1, col+1, cur_sum+T[row+1][col+1], min_sum);
        }
    }

    int minFallingPathSum(vector<vector<int>>& A) {
        if(A.size() == 0) return 0;
        if(A.size() == 1) return A[0][0];
        
        int min_sum=0, cur_sum=0;
        int n = A.size();
        for(int i=0; i<n; i++){
            min_sum += A[i][0];
        }
        int row = 0;
        for(int col=0; col<n; col++){
            getMinSum(A, row, col, cur_sum+A[row][col], min_sum);
        }
        return min_sum;
    }
};


class Solution {
public:
    int naive(vector<int> A, int S){
        int count = 0;
        int n = A.size();
        int cur_sum;
        for(int i=0; i<n; i++){
            cur_sum = 0;
            for(int j=i; j<n; j++){
                cur_sum += A[j];
                if(cur_sum == S){
                    count++;
                    while(j+1<n && A[j+1] == 0){
                        count++;
                        j++;
                    }
                    break;
                }
            }
        }
        return count;
    }

    int efficient(vector<int> A, int S){
        int count=0, cur_sum=0;
        int n = A.size();
        int i=0, j=0;
        
        while(i<n || j<n){
            if(i>=n-1 && j>=n-1) break;
            cout<<i<<" "<<j<<" "<<cur_sum<<endl;
            if(j<n && cur_sum < S){
                cur_sum += A[j];
                j++;
            }
            else if(cur_sum == S){
                count++;
                while(j<n && A[j] == 0){
                    count++;
                    j++;
                }
                if(j<n) cur_sum += A[j];
            }
            else{
                cur_sum -= A[i];
                if(cur_sum == S) count++;
                i++;
                while(i<j && i<n && A[i] == 0){
                    count++;
                    i++;
                }
            }
        }
        return count;
    }

    int numSubarraysWithSum(vector<int>& A, int S) {
        // return naive(A, S);
        return efficient(A, S);
    }
};