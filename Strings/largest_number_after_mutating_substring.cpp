#include<bits/stdc++.h>
using namespace std;


	// string maximumNumber(string num, vector<int>& change) {
 //        bool start = false;
 //        for (int i = 0; i < num.size(); ++i) {
 //            int curr = num[i] - '0';
 //            if (change[curr] > curr) {
 //                if (!start) {
 //                    start = true;
 //                }
 //                num[i] = change[curr] + '0';
 //            } else if (change[curr] < curr && start)
 //                break;
 //        }
 //        return num;
 //    }


string maximumNumber(string num, vector<int>& change) {
        int s_length = num.size();
        bool flag = false;
        //changes to starting of the num will give the maximum number
        // so we need to check that if we can update the starting substring 
        // then we don't need to search for other substring
        int i =0;
        while(i<s_length and change[num[i]-'0']<=num[i]-'0')
        	i++;
        for(;i<s_length and change[num[i]-'0']>=num[i]-'0';++i)
        	num[i] = change[num[i]-'0']+'0';
        return num;
    }

int main(){


	vector<int> a = {9,4,3,5,7,2,1,9,0,6};
	string num ="021";
	auto res = maximumNumber(num, a);
	cout<<res;
	return 0;
}