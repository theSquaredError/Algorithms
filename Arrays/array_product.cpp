//  Problem: Product of array except itself

#include<iostream>
#include<vector>

using namespace std;

//1st method: Using extra space complexity O(N)
vector<int> productArray(vector<int> arr){
    
    //Create an output Array
    int n = arr.size();
    vector<int> output(n,1);
    
    vector<int> left(n);
    vector<int> right(n);
    
    left[0] = arr[0];
    for(int i=1;i<n;i++)
    	left[i] = left[i-1]*arr[i];

    right[n-1] = arr[n-1];
    for(int i = n-2;i>=0;i--)
    	right[i] = right[i+1]*arr[i];

    output[0] = right[1];
    output[n-1] = left[n-2];

    for(int i=1;i<=n-2;i++)
    	output[i] = left[i-1]*right[i+1];
    
    
    
    return output;
}

//Method 2: without using extra space of O(N)

vector<int> productArray2(vector<int> arr) {
	int n = arr.size();

	vector<int> output(n,1);
	//storing left cumulative product in output
	output[0] = arr[0];
	for(int i =1;i<n;++i) {
		output[i] = output[i-1]*arr[i];
	}

	int product = 1; //for maintaing right cumulative product
	output[n-1] = output[n-2];
	product *= arr[n-1];
	for(int i = n-2;i>0; --i) {
		output[i] = output[i-1]*product;
		product *= arr[i];
	}
	output[0] = product;

	return output;
}

int main() {
	vector<int> arr = {1, 2, 3, 4};
	auto res = productArray(arr);

	for(auto x: res)
		cout<<x<<" ";
	cout<<endl;

	return 0;
}