#include<iostream>
#include<vector>
#include<cmath>
#include<climits>
#include<algorithm>
using namespace std;



pair<int,int> minDifference(vector<int> a,vector<int> b){
    //Complete this method
    int len1 = a.size(), len2 = b.size();
    int ans = INT_MAX;
    pair<int, int> res;
    for (int i = 0; i < len1; ++i)
    {
       for (int j=0; j< len2; ++j)
       {
        if( abs(a[i]-b[j]) < ans) {
                ans = abs(a[i]-b[j]);
                res.first = a[i];
                res.second = b[j];
        }
       }
    }

    return res;
}


//another method using sorting

pair<int,int> minDifferenceM2(vector<int> a,vector<int> b){
    //Complete this method
    int len1 = a.size(), len2 = b.size();
    int ans = INT_MAX;
    pair<int, int> res;
    
    //sorting array
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int i=0,j=0;
    while(i<len1 && j<len2)
    {
        if(abs(a[i] - b[j]) < ans) {
            ans = abs(a[i] - b[j]);
            res.first = a[i];
            res.second = b[j];
        }

        if (a[i]< b[j])
            i++;
        else j++;
    }

    return res;
}


int main() {
    vector<int> a = {23, 5, 10, 17, 30};
    vector<int> b = {26, 134, 135, 14, 19};

    auto ans = minDifference(a,b);
    cout<<ans.first<<","<<ans.second;
    return 0;
}