// https://www.interviewbit.com/problems/grid-unique-paths/

#include <bits/stdc++.h>
using namespace std;
#define loop(i, start, end) for(int i=start; i<end; i++)

// int Solution::uniquePaths(int A, int B) {
//     int path[A][B] = {0};
//     for(int i=0; i<A; i++){
//         for(int j=0; j<B; j++){
//             if(i==0 || j==0){
//                 path[i][j] = 1;
//             }
//             else{
//                 path[i][j] = path[i-1][j] + path[i][j-1];
//             }
//         }
//     }
//     return path[A-1][B-1];
// }


void count_unique_path(int A, int B){
	int path[A][B] = {0};
	loop(i, 0, A){
		loop(j, 0, B){
			if(i==0 || j==0){
				path[i][j] = 1;
			}
			else{
				path[i][j] = path[i-1][j] + path[i][j-1];
			}
		}
	}
	loop(i, 0, A){
		loop(j, 0, B){
			cout<<path[i][j]<<" ";
		}
		cout<<endl;
	}
}

void optimal_sol(int *path, int row, int col){
	if(row==1 ||col==1){
		*((path+row*col)+col) = 1;
	}
	else{
		int a, b;
		// if(*((path+(row-1)*col)+col) != 0){
		// 	a = *((path+(row-1)*col)+col);
		// }
		// else{
		if(*((path+(row-1)*col)+col) != 0){
			// *((path+(row-1)*col)+col) = optimal_sol(path, row-1, col);
			optimal_sol(path, row-1, col);
		}
		
		// if(*((path+row*(col-1))+(col-1)) != 0){
		// 	b = *((path+row*(col-1))+(col-1));
		// }
		// else{
		if(*((path+row*(col-1))+(col-1)) != 0){
			// *((path+row*(col-1))+(col-1)) = optimal_sol(path, row, col-1);
			optimal_sol(path, row, col-1);
		}

		*((path+row*col)+col) = *((path+(row-1)*col)+col) + *((path+row*(col-1))+(col-1));
	}
}

int main()
{
	int test;
	cin>>test;
	while(test--){
		int A, B;
		cin>>A>>B;
		// count_unique_path(A, B);
		int path_matrix[A][B];
		memset(path_matrix, 0, sizeof(path_matrix));
		optimal_sol(path_matrix, A, B);

		loop(i, 0, A){
			loop(j, 0, B){
				cout<<path_matrix[i][j]<<" ";
			}
			cout<<endl;
		}
		cout<<path_matrix[A-1][B-1]<<endl;
	}
	return 0;
}