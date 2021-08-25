/*
Problem:- Finding missing number in the given array with range 1 to n
Usin XOR operation
*/

#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> nums = {1,2,4,5,3,7};
	int n = nums.size()+1;
	int res1 = 1;
	for(int i =2;i<=n;i++)
		res1 = res1^i;
	int res2 = nums[0];
	for(int i =1;i<nums.size();i++){
		res2 = res2^nums[i];
	}
	int result = res1^res2;
	cout<<result;

	return 0;
}