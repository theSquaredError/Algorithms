/*
Problem: 
--------
Write a function to perform basic string compression using the counts of repeated
characters, also known as Run Length Encoding.

If the "compressed" string would not be smaller tha the original string, your function
should return the input string. 

Input:-
------
bbbaaaadexxxxxx
abc

Output:-
-------
b3a4d1e1x6
abc
*/

#include<iostream>
#include<string>

using namespace std;

// string compressString(const string &str){

// 	string res="";
// 	int count;
// 	for(int i =0;i<str.length()-1; ){
// 		char ch = str[i];
// 		count=1;
// 		while(str[i]==str[i+1]){
// 			count++;
// 			i++;
// 		}
// 		i++;
// 		res+= ch+to_string(count);
// 	}
// 	if(str[str.length()-1] != str[str.length()-2]){
// 		res+=str[str.length()-1]+ to_string(1);
// 	}
// 	if(res.length()<str.length())
// 		return res;
// 	else
// 		return str;
// }

string compressString(const string &str){   
    //complete the function to return output string
    stringstream result;
 
    result<<str[0];
    int count=1;
    for(int i=1; i<str.size(); i++, count++){
        if(str[i] != str[i-1]){
            result<<to_string(count);
            result<<str[i];
            count=0;
        }
    }
    result<<to_string(count);
    
    return result.str().size()<str.size()? result.str():str;
}


int main(){

	string s = "accc";
	auto res = compressString(s);
	cout<<res;
	return 0;
}