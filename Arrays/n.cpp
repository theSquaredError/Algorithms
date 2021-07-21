#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
using namespace std;

int trap(vector<int>& height) {
        vector<int>left;
        vector<int>right;
        int curr = height[0];
        int ans = 0;
        for(auto x: height){
            curr = max(curr,x);
            left.push_back(curr);
        }
        
        curr = height[height.size()-1];
        for(int i = height.size()-1;i>=0;i--)
        {
            curr = max(curr, height[i]);
            right.push_back(curr);
        }
  
        reverse(right.begin(), right.end());
        for(int i=0;i<height.size()-1; i++)
        {
            ans+= min(left[i],right[i])-height[i];
        }
        
        return ans;
    }



int main(){
	vector<int> arr = {0,1,0,2,1,0,1,3,2,1,2,1};
	for(int x: arr)
		cout<<x<<" ";
	cout<<endl;
	int res = trap(arr);
	cout<<res;
	return 0;
}