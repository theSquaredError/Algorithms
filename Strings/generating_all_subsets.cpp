/*
Using recursion method
*/


#include<iostream>
#include <vector>
using namespace std;


//recursive solution
/*
vector<vector<int>> find_subsets(vector<int> set, int idx, vector<vector<int>> &result){
	if(set.empty())
		return {{}};
	if(idx == set.size()-1) {  //if we are at last element of the set
		result.push_back({});
		result.push_back({set[idx]});
	}
	else{  //else we will solve recursively
		find_subsets(set, idx+1, result); //first we will find the all possible subsets for set starting from next element to last element 
		int n = result.size();
		for(int i=0;i<n;++i){
			vector<int> r = result[i];
			r.push_back(set[idx]);
			result.push_back(r);
		}

	}

return result;
}

*/
//implemented iterative solution in the main
int main(){
	vector<int> set = {1,2,3};
	vector<vector<int>> subsets = {{}};
	//subsets = find_subsets(set,0,subsets);
	for(auto x:set){
		int n = subsets.size();
		for(int i=0;i<n;i++){
			vector<int>r = subsets[i];
			r.push_back(x);
			subsets.push_back(r);
		}

	}
	for(auto v: subsets){
		for(auto x:v)
			cout<<x<<" ";
		cout<<endl;
	}
	return 0;

}

//3. There is one other method which uses bit masking