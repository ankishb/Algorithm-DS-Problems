
// O(n^2)
int Solution::lis(const vector<int> &A) {
    int n = A.size();
    int arr[n];
    memset(arr, 0, sizeof(arr));
    
    for(int i=1; i<n; i++){
        for(int j=0; j<i; j++){
            if(A[i] > A[j]){
                arr[i] = max(arr[j]+1, arr[i]);
            }
        }
    }
    int ans = INT_MIN;
    for(int i=0; i<n; i++){
        ans = max(ans, arr[i]);
    }
    return ans+1;
}






public class Solution {

public int lis(final List<Integer> A) {
    List<Integer> piles = new ArrayList<Integer>();
    int toInsert;
    
    for (int i = 0 ; i < A.size() ; i++) {
        toInsert = Solution.binarySearchPile(piles, 0, piles.size() - 1, A.get(i));
        if (toInsert >= 0) {
            piles.set(toInsert, A.get(i));
        } else {
            piles.add(A.get(i));
        }
    }
    
    return piles.size();
}

public static int binarySearchPile(List<Integer> piles, int l, int r, int x) {

    if (piles.size() == 0 || l > r) {
        return -1;
    }
    
    
    if (l == r) {
        if (piles.get(l) < x) {
            return -1;
        }
        return l;
    }
    
    int middle = (r - l) / 2 + l;
    
    if (piles.get(middle) == x) {
        return middle;
    }
    
    if (piles.get(middle) < x) {
        return Solution.binarySearchPile(piles, middle + 1, r, x);
    }
    
    if (middle - 1 < 0 || piles.get(middle - 1) < x) {
        return middle;
    }
    
    return Solution.binarySearchPile(piles, l, middle - 1, x);
}

}