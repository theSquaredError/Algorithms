#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

int largestBand(vector<int> arr){

		int n = arr.size();
		unordered_set<int> S;

		for(auto x: arr)
			S.insert(x);

		int largestLen = 1;
		//traversing arr

		for(auto element: arr)
		{
			int parent = element-1;
			//  find returns end iterator if key is not found,
    		//  else it returns iterator to that key
			
			//if parent is not in the arr
			if(S.find(parent) == S.end())
			{
				int next = element+1;
				int cnt = 1;

				//while next consecutive is present in the array
				while(S.find(next)!=S.end()){
					next++;
					cnt++;
				}
				if(cnt>largestLen){
					largestLen = cnt;
				}
			}
		}

		return largestLen;
}



int main(){
	vector<int> arr = {100, 4, 200, 1, 2};
	int ans = largestBand(arr);
	cout<<ans;
	return 0;
}