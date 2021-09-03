/*
Problem :- Given an expression E in the postfix representation, write a program to evaluate the value
of E, using stack data-structure.

*/

#include <stack>
#include <iostream>
#include <string.h>
#include <vector>
#include <cmath>
#include <bits/stdc++.h>
using namespace std;

bool isNumber(const string& str)
{
    for (char const &c : str) {
        if (std::isdigit(c) == 0) return false;
    }
    return true;
}

int postfixEvaluation(string p_expression){
	// Returns first token
	vector<string> v;
	
	stringstream check1(p_expression);
	string intermediate;

	while(getline(check1, intermediate, ' ')){
		v.push_back(intermediate);
	}

	stack<double> S;

	for(int i=0; i<v.size();i++){
		if(isNumber(v[i])){
				S.push((double)stoi(v[i]));
			}
		
		else
		{
			double num1 = S.top();
			S.pop();
			double num2 = S.top();
			S.pop();

			switch(v[i][0]){

				case '+':S.push(num1+num2); break;
				case '-':S.push(num1-num2); break;
				case '*':S.push(num1*num2); break;
				case '/':S.push(num1/num2); break;
				case '^':S.push(pow(num1,num2)); break;

			}
		}

	}
		return S.top();

}

int main(){
	string p_expression = "2 3 +";

	double res = postfixEvaluation(p_expression);
	cout<<res;

	return 0;
}