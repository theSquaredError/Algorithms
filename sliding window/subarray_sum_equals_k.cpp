#include <iostream>
#include<vector>

using namespace std;

//works for positive numbers only.
void subarray_sum(int *nums, int n, int k){
	int i=0,j=0;
	int cs=0;
	while(j<n){
		cs+=nums[j];
		j++;

		while(i<j and cs>k){
			cs-=nums[i];
			i++;
		}

		if(cs == k){
			cout<<i<<"-"<<j-1<<endl;
		}
	}
}

//handling the case for the array containing negative numbers also
void subarray_modified(){
	
}

int main(){
	int v[] = {1,3,2,1,4,1,3,2,1,1};
	int n = sizeof(v)/sizeof(int);
	int k=8;
	subarray_sum(v,n,k);
	return 0;
}
