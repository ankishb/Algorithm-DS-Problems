
// Input: A = 4.
// Output:

// 4 4 4 4 4 4 4 
// 4 3 3 3 3 3 4 
// 4 3 2 2 2 3 4 
// 4 3 2 1 2 3 4 
// 4 3 2 2 2 3 4 
// 4 3 3 3 3 3 4 
// 4 4 4 4 4 4 4 

// Example 2:

// Input: A = 3.
// Output:

// 3 3 3 3 3 
// 3 2 2 2 3 
// 3 2 1 2 3 
// 3 2 2 2 3 
// 3 3 3 3 3 


#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<=end; i++)

void spiral_fill(vector<vector<int> > &vect, int min, int max, int no){
	cout<<"\n starting at: min: "<<min<<" max: "<<max<<" no: "<<no<<endl;
	if(min == max){
		vect[min][max] = no;
	}
	int i, j;
	// top row
	cout<<"\n top row \n";
	i = min;
	loop(j, min+1, max){
		cout<<"("<<i<<", "<<j<<")\n";
		vect[i][j] = no;
	}
	// right column
	cout<<"\n right column \n";
	j = max;
	loop(i, min+1, max){
		cout<<"("<<i<<", "<<j<<")\n";
		vect[i][j] = no;
	}
	// bottom row
	cout<<"\n bottom row \n";
	i = max;
	loop(j, min, max-1){
		cout<<"("<<i<<", "<<j<<")\n";
		vect[i][j] = no;
	}
	// left column
	cout<<"\n left column \n";
	j = min;
	loop(i, min, max-1){
		cout<<"("<<i<<", "<<j<<")\n";
		vect[i][j] = no;
	}
}

void print_matrix(vector<vector<int> > &vect, int size){
	cout<<"\n------ printing matrix ------\n";
	loop(i, 0, size){
		loop(j, 0, size){
			cout<<vect[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<"\n------ printing matrix ------\n";
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int n;
		cin>>n;
		vector<vector<int> > vect(2*n-1, vector<int>(2*n-1, 0));
		int min=0, max=2*n-2;
		for(int i=n; i>=1; i--){
			spiral_fill(vect, min, max, i);
			min++;
			max--;
		}

		print_matrix(vect, 2*n-2);
	}
	return  0;
}



/*
#define loop(i, start, end) for(int i=start; i<=end; i++)

void spiral_fill(vector<vector<int> > &vect, int min, int max, int no){
    if(min == max){
        vect[min][max] = no;
    }
    int i, j;
    i = min;
    loop(j, min+1, max){
        vect[i][j] = no;
    }
    j = max;
    loop(i, min+1, max){
        vect[i][j] = no;
    }
    i = max;
    loop(j, min, max-1){
        vect[i][j] = no;
    }
    j = min;
    loop(i, min, max-1){
        vect[i][j] = no;
    }
}

vector<vector<int> > Solution::prettyPrint(int A) {
    int n = A;
    vector<vector<int> > vect(2*n-1, vector<int>(2*n-1, 0));
    int min=0, max=2*n-2;
    for(int i=n; i>=1; i--){
        spiral_fill(vect, min, max, i);
        min++;
        max--;
    }
    return vect;
}

*/