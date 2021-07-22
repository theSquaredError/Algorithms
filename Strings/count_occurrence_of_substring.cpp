#include<bits/stdc++.h>
using namespace std;

vector<int> stringSearch(string big,string small){
    //store the occurrences in the result vector
    vector<int> result = {};
    int index = 0;
    while(1) {
        index = big.find(small, index);
        if(index==-1)
            break;
        if(index!=-1) {
            result.push_back(index);
            index +=1;
        }

        
    }

    return result;
}


int main() {
    string bigString = "I liked the movie, acting in movie was great!";
    string smallString = "movie";
    vector<int> res = stringSearch(bigString, smallString);

    for(int x: res)
        cout<<x<<" ";

    return 0;
}