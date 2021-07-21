#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector< vector<int> > triplets(vector<int> arr, int targetSum){

	vector<vector<int> > result;
	int n = arr.size();
	sort(arr.begin(), arr.end());

	for(int i =0; i<= n-3 ; i++){

		

		//doing Pair sum
		int j=i+1, k = n-1;
		
		while(j<k)
		{
			int currentSum = arr[i];
			currentSum += arr[j];
			currentSum += arr[k];
			if (currentSum == targetSum)
			{
				result.push_back({arr[i], arr[j], arr[k]});
				j+=1;
				k-=1;
			}
			else if (currentSum<targetSum)
				j+=1;
			else
				k-=1;
		}
	}

	return result;
}

int main()
{
	vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 15};
	int S = 18;

	auto result = triplets(arr, S);

	for(auto v: result)
	{
		for(auto ans: v)
			cout<<ans<<",";
		cout<<endl;
	}
	return 0;
}