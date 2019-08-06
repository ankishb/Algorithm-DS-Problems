// Given N students sitting in a circle You have to distribute M candies to these students also , ith student takes i candies. if ith student didn't get required candies then he will not take it. you have to distribute the candies starting from 1st student and moving along the circle of students till you cannot distribute to a student. you need to output the left out candies.



#include <bits/stdc++.h>
using namespace std;

void candies_distribution(){
	// int n_students, m_candies;
	int n, m;
	cin>>n>>m;

	int i=0;
	// find if candies are less than the current student index, which are sit in a circular fashion, if true, then distribute the candies of that index to student and move on, else break the loop and print the lest out amount.

	while((i%n)+1 <= m){
		m = m-((i%n)+1);
		cout<<(i%n + 1)<<"--"<<m<<endl;
		i++;
	}
	cout<<endl<<m<<endl;
}


int main()
{
	int test;
	cin>>test;
	while(test--){
		candies_distribution();
	}
}