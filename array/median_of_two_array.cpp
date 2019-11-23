// double nth_element1(vector<int> A, vector<int> B, int k){
//     int n1 = A.size(), n2 = B.size();
//     int low = min(A[0], B[0]), mid;
//     int high = max(A.back(), B.back());
//     while(low <= high){
//         mid = (low + high) /2 ;
//         auto itr1 = lower_bound(A.begin(), A.end(), mid) - A.begin();
//         auto itr2 = lower_bound(B.begin(), B.end(), mid) - B.begin();
//         int idx = itr1 + itr2;
//         // if(idx == k) return max(A[itr1], B[itr2]);
//         if(idx <= k) low = mid+1;
//         else high = mid-1;
//     }
//     return mid;
// }

/*
double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
    if(A.size()>B.size())return findMedianSortedArrays(B,A);
    
    int x = A.size(), y = B.size();
    int low =0, high = x;
    while(low<=high){
        int partX = (low+high)/2;
        int partY = (x+y+1)/2-partX;
        
        int maxleftX = (partX==0)?INT_MIN:A[partX-1];
        int minrightX = (partX==x)?INT_MAX:A[partX];
        
        int maxleftY = (partY==0)?INT_MIN:B[partY-1];
        int minrightY = (partY==y)?INT_MAX:B[partY];
        
        if(maxleftX<=minrightY && maxleftY<=minrightX){
            if((x+y)%2==0)
                return  (double)(max(maxleftX,maxleftY)+min(minrightX,minrightY))/2;
            else return (double)(max(maxleftX,maxleftY));
        }
        else if(maxleftX>minrightY){
            high = partX-1;
        }
        else if(maxleftY>minrightX){
            low = partX+1;
        }
    }
}
*/

double kth_element(vector<int> A, int l1, int h1, vector<int> B, int l2, int h2, int k){
    if(h1 < 0 && h2 < 0) return 0;
    if(h1 < 0) return B[k];
    if(h2 < 0) return A[k];
    int m1 = l1 + (h1 - l1)/2;
    int m2 = l2 + (h2 - l2)/2;
    
    if((m1 + m2) < k){
        if(A[m1] > B[m2]){
            return kth_element(A, l1, h1, B, m2+1, h2, k-m2-1);
        }
        else{
            return kth_element(A, m1, h1, B, l2, h2, k-m1-1);
        }
    }
    else{
        if(A[m1] > B[m2]){
            return kth_element(A, l1, m1, B, l2, h2, k);
        }
        else{
            return kth_element(A, l1, h1, B, l2, m2, k);
        }
    }
}

double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {

// double find_median(vector<int> A, vector<int> B){
    int n1 = A.size(), n2 = B.size();
    int k = (n1 + n2)/2;
    if((n1+n2)%2 == 1) return kth_element(A, 0, n1-1, B, 0, n2-1, k);
    double kth1 = kth_element(A, 0, n1-1, B, 0, n2-1, k);
    double kth2 = kth_element(A, 0, n1-1, B, 0, n2-1, k-1);
    return (kth1 + kth2)/2;
}

// double nth_element(vector<int> A, vector<int> B, int k){
//     int n1 = A.size(), n2 = B.size();
//     int n = n1 + n2, count = 0;
//     int i = 0, j = 0;
//     while(i < n1 && j < n2){
//         count++;
//         if(count == k) return min(A[i], B[j]);
//         if(A[i] <= B[j]) i++;
//         else j++;
//     }
//     while(i < n1){
//         count++;
//         if(count == k) return A[i];
//         i++;
//     }
//     while(j < n2){
//         count++;
//         if(count == k) return B[j];
//         j++;
//     }
//     return -1;
// }

//     double findMedianSortedArrays22(vector<int> nums1, vector<int> nums2) {
//         int N1 = nums1.size();
//         int N2 = nums2.size();
//         if(N1 > N2) {
//             return findMedianSortedArrays22(nums2, nums1);
//         }
//         int lo = 0, hi = N1;
//         while (lo <= hi) {
//             int mid1 = (lo + hi) / 2;       /*❶*/
//             int mid2 = (N1+N2+1)/2 - mid1;  /*❷*/
            
//             double L1 = (mid1 == 0) ? INT_MIN : nums1[mid1-1];    /*❸*/ 
//             double R1 = (mid1 == N1) ? INT_MAX : nums1[mid1];
//             double L2 = (mid2 == 0) ? INT_MIN : nums2[mid2-1];
//             double R2 = (mid2 == N2) ? INT_MAX : nums2[mid2];
            
//         //     if(L1 > R2) {
//         //         hi = mid1 - 1;             /*❹*/
//         //     } else if(L2 > R1) {
//         //         lo = mid1 + 1;               /*❺*/
//         //     } else {                       /*❻*/
//         //         if((N1+N2)%2 == 0) {
//         //             return (max(L1,L2) + min(R1, R2)) / 2;
//         //         } else {
//         //             return max(L1, L2);
//         //         }
//         //     }
//         // }
        
        
//             if (L1 > R2) lo = mid2 + 1;        // A1's lower half is too big; need to move C1 left (C2 right)
//             else if (L2 > R1) hi = mid2 - 1;    // A2's lower half too big; need to move C2 left.
//             else return (max(L1,L2) + min(R1, R2)) / 2;    // Otherwise, that's the right cut.
//         }
//         return -1;
//     }
  
  
/*
double Solution::findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
// double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    int N1 = nums1.size();
    int N2 = nums2.size();
    if (N1 < N2) return findMedianSortedArrays(nums2, nums1);    // Make sure A2 is the shorter one.
    
    int lo = 0, hi = N2 * 2;
    while (lo <= hi) {
        int mid2 = (lo + hi) / 2;   // Try Cut 2 
        int mid1 = N1 + N2 - mid2;  // Calculate Cut 1 accordingly
        
        double L1 = (mid1 == 0) ? INT_MIN : nums1[(mid1-1)/2];    // Get L1, R1, L2, R2 respectively
        double L2 = (mid2 == 0) ? INT_MIN : nums2[(mid2-1)/2];
        double R1 = (mid1 == N1 * 2) ? INT_MAX : nums1[(mid1)/2];
        double R2 = (mid2 == N2 * 2) ? INT_MAX : nums2[(mid2)/2];
        
        if (L1 > R2) lo = mid2 + 1;        // A1's lower half is too big; need to move C1 left (C2 right)
        else if (L2 > R1) hi = mid2 - 1;    // A2's lower half too big; need to move C2 left.
        else return (max(L1,L2) + min(R1, R2)) / 2;    // Otherwise, that's the right cut.
    }
    return -1;
} 
*/


// double Solution::findMedianSortedArrays(const vector<int> &A, const vector<int> &B) {
//     int n1 = A.size(), n2 = B.size();
//     int n = n1 + n2;
//     if(n1 == 0 && n2 == 0) return 0;
//     if(n1 == 0){
//         if(n2%2 == 1) return B[n2/2];
//         else (B[n2/2 - 1] + B[n2/2])/2;
//     }
//     if(n2 == 0){
//         if(n1%2 == 1) return A[n1/2];
//         else (A[n1/2 - 1] + A[n1/2])/2;
//     }
//     return findMedianSortedArrays22(A, B);
//     // if(n%2 == 1) return nth_element(A, B, n/2 + 1);
//     // return (nth_element(A, B, n/2) + nth_element(A, B, n/2 + 1))/2;
// }
