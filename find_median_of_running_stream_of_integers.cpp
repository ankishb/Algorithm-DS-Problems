
#include <bits/stdc++.h>
using namespace std;

void print_heap(priority_queue<int> max_heap, 
	priority_queue<int, vector<int>, greater<int> > min_heap){
	cout<<"\n max heap\n";
	while(!max_heap.empty()){
		cout<<max_heap.top()<<" ";
		max_heap.pop();
	}
	cout<<"\n min heap\n";
	while(!min_heap.empty()){
		cout<<min_heap.top()<<" ";
		min_heap.pop();
	}
	cout<<endl;
}

vector<double> find_running_median(vector<int> A){
	vector<double> ans;
	priority_queue<int> max_heap;
	priority_queue<int, vector<int>, greater<int> > min_heap;
	
	double median = 0.0;
	for(int i=0; i<A.size(); i++){
		if((double)A[i] <= median){
			// case: if size of max_heap + 1 be greater than the min_heap, then pop element from max_heap and insert it into min_heap
			// cout<<min_heap.size()<<" "<<max_heap.size()<<endl;
			max_heap.push(A[i]);
		}
		else{
			// cout<<min_heap.size()<<" "<<max_heap.size()<<endl;
			min_heap.push(A[i]);
		}

		if(max_heap.size() > min_heap.size()+1){
			min_heap.push(max_heap.top());
			max_heap.pop();
		}
		else if(min_heap.size() > max_heap.size()+1){
			max_heap.push(min_heap.top());
			min_heap.pop();
		}
		print_heap(max_heap, min_heap);

		if(max_heap.size() == min_heap.size()){
			median = min_heap.top() + max_heap.top();
			median = median/2.0;
		}
		else if(max_heap.size() > min_heap.size()){
			median = (double)max_heap.top();
		}
		else{
			median = (double)min_heap.top();
		}
		ans.push_back(median);
	}
	return ans;
}



// vector<double> runningMedian(vector<int> a) {
//     vector<double> ans;
//     double ans_;
//     vector<int> temp;
//     for(int i=0; i<a.size(); i++){
//         temp.push_back(a[i]);
//         sort(temp.begin(), temp.end());
//         if(temp.size()%2 == 0){
//             int l_idx = (temp.size()/2)-1;
//             int r_idx = (temp.size()/2);
//             ans_ = temp[l_idx] + temp[r_idx];
//             ans_ = ans_/(2*1.0);
//         }
//         else{
//             int idx = (temp.size()/2);
//             ans_ = temp[idx]*1.0;
//         }
//         ans.push_back(ans_);
//     }
//     return ans;
// }


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

		vector<double> ans;
		ans = find_running_median(vect);
		cout<<"Median of running stream of integers\n";
		for( auto itr : ans){
			cout<<itr<<" ";
		}
		cout<<endl;
	}
	return 0;
}