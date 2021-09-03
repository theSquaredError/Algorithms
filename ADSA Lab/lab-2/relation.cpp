/*
Problem :- Design a data-structure relation R and support the following
			operations using classes.

			a. R.init(n); //The relation R is established on the set{1,...,n}
			b. R.add(1,2); // The pair(1,2) is added to R.
			c. R.add(3,4); //The pair(3,4) is added to R.
			d. R.isReflexive(); // return true iff R is reflexive
			e. R.isSymmetric(); //returns true iff R is symmetric
*/


#include <iostream>
#include <vector>
using namespace std;


class Relation
{	
	vector<vector<int>> M;
	int n; //no. of rows or columns

public: 
	void add(int a, int b);
	void init(int n);
	bool isReflexive();
	bool isSymmetric();
	void displayMatrix();
	
};

void Relation::init(int s){
	n = s;
	vector<int> r(n,0);
	for(int i=1;i<=n;i++){
		M.push_back(r);
	}
}

void Relation:: add(int a, int b){
	if(a<=n and b<=n)
		M[a-1][b-1]=1;
}

bool Relation:: isSymmetric(){
	for(int i=0;i<n;i++){
		for(int j=0;j<i;j++)
			if(M[i][j]!=M[j][i])
				return false;
	}

	return true;
}

bool Relation::isReflexive(){
	for(int i=0;i<n;i++)
		if(M[i][i]!=1)
			return false;

	return true;
}

void Relation:: displayMatrix(){
	for(int i=0; i<=n-1; i++)
	    {
	        for(int j=0; j<=n-1; j++)
	        {
	            cout<<M[i][j]<<" ";
	        }
	        cout<<endl;
	    }
}
int main(){

	Relation R;
	R.init(4);
	R.add(4,1);
	R.add(1,4);
	R.add(1,1);
	R.add(2,2);
	R.add(3,3);
	R.add(4,4);

	R.displayMatrix();
	cout<<R.isReflexive();
	cout<<R.isSymmetric();

	return 0;
}