/*
Taken while following Prateek Narang DSA course
*/

#include<iostream>
#include<unordered_map>
using namespace std;

string unique_substring(string str){

	int i=0,j=0;
	
	int start_window=-1;
	int window_len = 0;
	int max_window_len = 0;
	
	unordered_map<char, int> u_map;
	
	while(j<str.length()){
		
		char ch = str[j];
		
		//if ch is present in hashmap
		if(u_map.count(ch) and i<=u_map[ch]){
			i =  u_map[ch]+1;
			window_len = j-i;
		}
		
		//update the last occ
		u_map[ch] =j;
		window_len++;
		j++;

		//update max_window at every step
		if(window_len > max_window_len){
			max_window_len = window_len;
			start_window = i;
		}

	}

	return str.substr(start_window, max_window_len);
}


int main(){
	string input ;
	cin>>input;

	cout<<unique_substring(input);

	return 0;
}