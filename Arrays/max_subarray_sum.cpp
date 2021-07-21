#include<iostream>
#include<vector>
#include<climits>
using namespace std;


int maxSubarraySum(vector<int> arr){
    //Complete this function, your function should return the maximum subarray sum
    int n = arr.size();
    int max_so_far = INT_MIN, max_ending_here = 0;

    for(int x: arr) {
        max_ending_here+=x;
        if(max_ending_here < x) 
            max_ending_here = x;
        
        if(max_so_far < max_ending_here)
            max_so_far = max_ending_here;
    }

    return max_so_far>0?max_so_far:0;
    
    
    
}


int main(){
    vector<int> arr = {-2,-1,-3};
    int ans = maxSubarraySum(arr);
    cout<<ans<<endl;
    return 0;
}