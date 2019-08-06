
#include <bits/stdc++.h>
using namespace std;

void postfix_evaluation(){
	string exp;
	getline(cin, exp);
	stack<string> s;
	// start from left to right, operands and operators are separated with spaces
	int i=0;
	string temp="";
	int a, b;
	char op;
	while(i<=exp.length()){
		cout<<exp[i]<<" ";
		// i++;
		// either there is a space or it reach at end+1
		if(exp[i]==' ' || i==exp.length()){
			if(temp=="+"||temp=="-"||temp=="*"||temp=="/"){
				// cout<<temp<<"--"<<endl;
				a = stoi(s.top());
				s.pop();
				b = stoi(s.top());
				s.pop();

				// cout<<a<<" "<<b<<endl;
				if(temp == "+") s.push(to_string(int(a+b)));
				else if(temp == "-") s.push(to_string(int(a-b)));
				else if(temp == "/") s.push(to_string(int(a/b)));
				else if(temp == "*") s.push(to_string(int(a*b)));
				else cout<<"invalid operation \n";
				// op = '+';//temp[0];
				// swich(op){
				// 	case '*': s.push(a*b);
				// 	case '/': s.push(a/b);
				// 	case '+': s.push(a+b);
				// 	case '-': s.push(a-b);
				// 	default: cout<<"invalid operation"<<endl;
				// }
			}
			else{
				s.push(temp);
			}
			temp = "";
			i++;
		}
		else{
			temp = temp+exp[i];
			i++;
		}
	}

	while(!s.empty()){
		cout<<s.top()<<endl;
		s.pop();
	}

}

void evaluate(){
	postfix_evaluation();
	// string operation;
	// getline(operation);
	// if(operation == "postfix"){
	// 	postfix_evaluation();
	// }
	// else{
	// 	postfix_evaluation();
	// }
}

int main()
{
	int test;
	cin>>test;
	cin.ignore(1);
	while(test--){
		evaluate();
	}
	return 0;
}