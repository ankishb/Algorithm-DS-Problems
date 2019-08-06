
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int n = nums.size();
        int i, j=n-2, max_id, max_no;
        bool found = false;
        while(j >= 0){
            pq.push(nums[j+1]);
            if(nums[j] < nums[j+1]){
                found = true;
                break;
            }
            j--;
        }
        if(!found){
            pq.push(nums[j+1]);
            i = 0;
            while(!pq.empty()){
                nums[i] = pq.top();
                i++; pq.pop();
            }
        }
        else{
            found = false;
            i = j+1;
            while(!pq.empty()){
                cout<<pq.top()<<" ";
                if(!found && pq.top() > nums[j]){
                    nums[i] = nums[j];
                    nums[j] = pq.top();
                    found = true;
                }
                else{
                    nums[i] = pq.top();
                }
                pq.pop();
                i++;
            }
        }
    }
    void nextPermutation2(vector<int>& nums) {
        int n = nums.size();
        int j=n-2, max_id, max_no;
        bool found = false;
        while(j >= 0){
            if(nums[j] < nums[j+1]){
                found = true;
                break;
            }
            j--;
        }
        if(!found){
            sort(nums.begin(), nums.end());
        }
        else{
            max_no = nums[j+1];
            max_id = j+1;
            for(int i=j+1; i<n; i++){
                if(max_no > nums[i] && nums[i] > nums[j]){
                    cout<<i<<" ";
                    max_no = nums[i];
                    max_id = i;
                }
            }
            cout<<max_id;
            swap(nums[j], nums[max_id]);
            sort(nums.begin()+j+1, nums.end());
        }
    }
};

// https://www.interviewbit.com/problems/next-permutation/

#include <bits/stdc++.h>
using namespace std;

void Solution::nextPermutation(vector<int> &A) {
    vector<int>::iterator it;
    bool break_loop = false;
    int el;

    for(int i=A.size()-2; i>=0; i--){
        if(A[i] < A[i+1]){
            cout<<"\n enetered here";
            el = A[i];
            sort(A.begin()+i, A.end());

            it = find(A.begin()+i, A.end(), el);
            int pos = it-A.begin();
            // cout<<endl<<el<<" "<<*it<<" "<<pos<<" "<<A[pos]<<endl;
            // swapping with next biggest element;
            pos++;
            for(int j=pos; j>=i+1; j--){
                swap(A[j], A[j-1]);
            }
            break_loop = true;
            break;
        }
    }
    if(break_loop == false){
        sort(A.begin(), A.end());
    }
}

void next_permutation(vector<int> &A){
	vector<int>::iterator it;
	bool break_loop = false;
	int el;

	for(int i=A.size()-2; i>=0; i--){
		if(A[i] < A[i+1]){
			cout<<"\n enetered here";
			el = A[i];
			sort(A.begin()+i, A.end());

			it = find(A.begin()+i, A.end(), el);
			int pos = it-A.begin();
			// cout<<endl<<el<<" "<<*it<<" "<<pos<<" "<<A[pos]<<endl;
			// swapping with next biggest element;
			pos++;
			for(int j=pos; j>=i+1; j--){
				swap(A[j], A[j-1]);
			}
			break_loop = true;
			break;
		}
	}
	if(break_loop == false){
		sort(A.begin(), A.end());
	}

	for(it=A.begin(); it!=A.end(); ++it){
		cout<<*it<<" ";
	}
	cout<<endl;
}

// A : [ 444, 994, 508, 72, 125, 299, 181, 238, 354, 223, 691, 249, 838, 890, 758, 675, 424, 199, 201, 788, 609, 582, 979, 259, 901, 371, 766, 759, 983, 728, 220, 16, 158, 822, 515, 488, 846, 321, 908, 469, 84, 460, 961, 285, 417, 142, 952, 626, 916, 247, 116, 975, 202, 734, 128, 312, 499, 274, 213, 208, 472, 265, 315, 335, 205, 784, 708, 681, 160, 448, 365, 165, 190, 693, 606, 226, 351, 241, 526, 311, 164, 98, 422, 363, 103, 747, 507, 669, 153, 856, 701, 319, 695, 52 ]

//  A: [ 444 994 508 72 125 299 181 238 354 223 691 249 838 890 758 675 424 199 201 788 609 582 979 259 901 371 766 759 983 728 220 16 158 822 515 488 846 321 908 469 84 460 961 285 417 142 952 626 916 247 116 975 202 734 128 312 499 274 213 208 472 265 315 335 205 784 708 681 160 448 365 165 190 693 606 226 351 241 526 311 164 98 422 363 103 747 507 669 153 856 701 695 52 319 ]

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		int el;
		vector<int> vect;
		while(n--){
			cin>>el;
			vect.push_back(el);
		}
		next_permutation(vect);
	}
	return 0;
}