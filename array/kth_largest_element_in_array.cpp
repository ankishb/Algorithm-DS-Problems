
struct custom_pq{
    bool operator()(const int &a, const int &b){
        return (a > b);
    }
};

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // priority_queue<int, vector<int>, greater<int>> pq;
        priority_queue<int, vector<int>, custom_pq> pq;
        for(auto a : nums){
            if(pq.size() == k && pq.top() < a){
                pq.pop();
                pq.push(a);
            }
            if(pq.size() < k) pq.push(a);
        }
        return pq.top();
    }
};


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        // create min heap
        priority_queue<int, vector<int>, greater<int>> pq;
        for(auto itr : nums){
            if(pq.size() <k){
                pq.push(itr);
            }
            else{
                if(itr > pq.top()){
                    pq.pop();
                    pq.push(itr);
                }
            }
        }
        return pq.top();
    }
};


    
public class Solution {
  
  public int findKthLargest(int[] a, int k) {
    int n = a.length;
    int p = quickSelect(a, 0, n - 1, n - k + 1);
    return a[p];
  }
  
  // return the index of the kth smallest number
  int quickSelect(int[] a, int lo, int hi, int k) {
    // use quick sort's idea
    // put nums that are <= pivot to the left
    // put nums that are  > pivot to the right
    int i = lo, j = hi, pivot = a[hi];
    while (i < j) {
      if (a[i++] > pivot) swap(a, --i, --j);
    }
    swap(a, i, hi);
    
    // count the nums that are <= pivot from lo
    int m = i - lo + 1;
    
    // pivot is the one!
    if (m == k)     return i;
    // pivot is too big, so it must be on the left
    else if (m > k) return quickSelect(a, lo, i - 1, k);
    // pivot is too small, so it must be on the right
    else            return quickSelect(a, i + 1, hi, k - m);
  }
  
  void swap(int[] a, int i, int j) {
    int tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
  }

}


    public int findKthLargest(int[] A, int k) {
        k = A.length - k; // convert to index of k largest
        int l = 0, r = A.length - 1;
        while (l <= r) {
            int i = l; // partition [l,r] by A[l]: [l,i]<A[l], [i+1,j)>=A[l]
            for (int j = l + 1; j <= r; j++)
                if (A[j] < A[l]) swap(A, j, ++i);
            swap(A, l, i);

            if (k < i) r = i - 1;
            else if (k > i) l = i + 1;
            else return A[i];
        }
        return -1; // k is invalid
    }