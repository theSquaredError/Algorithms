#include <iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

int main() {
	vector<int> v={5,4,3,10,6,32,11,45};
	vector<int> max_array;
	vector<int> min_array;

	// when number of element is even
    for(int i=0;i<v.size()-1;i=i+2){
        if(v[i+1]>v[i]){
            max_array.push_back(v[i+1]);
            min_array.push_back(v[i]);
        }else{
            max_array.push_back(v[i]);
            min_array.push_back(v[i+1]);
        }
    }
    int minimum = INT_MAX;
    int maximum = INT_MIN;
    for(int c:max_array)
        maximum = max(c,maximum);
    for(int c: min_array)
        minimum = min(c, minimum);

    cout<<maximum<<" "<<minimum;
	return 0;
}

