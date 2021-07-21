#include<iostream>
#include <vector>
#include<algorithm>

using namespace std;

int minSwaps(vector<int> arr){
	int n = arr.size();
	int ans = 0;
	//storing arr with their original positions
	pair<int,int> arrPos[n];
	for(int i=0; i<n; i++) {
		arrPos[i].first = arr[i];
		arrPos[i].second = i;
	}

	//sorting the arrPos to know the correct position of each element
	sort(arrPos, arrPos+n);

	//we need to find the cycles in the arr
	//traversing the arr

	vector<bool> visited (n, false);

	for(int i=0;i<n;i++) {
		//if element is already visited or it is already at correct positon
		//we will skip
		if(visited[i] or i == arrPos[i].second)
			continue;
		//else we will check for the cycles 

		int cycle_size = 0;
		int j = i;
		while(!visited[j]) {
			visited[j] = true;

			j = arrPos[j].second;
			cycle_size +=1;
		}

		if(cycle_size > 0)
			ans += (cycle_size -1);

	}

	return ans;

}

int main(){
	vector <int> arr = {5, 4, 3, 2, 1};

	int ans = minSwaps(arr);
	cout<<ans<<endl;
	return 0;
}