/*
Leetcode
Problem 392: Given two strings s and t, return true if s is a subsequence of t, or false otherwise.

A subsequence of a string is a new string that is formed from the original string by 
deleting some (can be none) of the characters without disturbing the relative positions of the remaining 
characters. (i.e., "ace" is a subsequence of "abcde" while "aec" is not).

Example 1:

Input: s = "abc", t = "ahbgdc"
Output: true


Example 2:

Input: s = "axc", t = "ahbgdc"
Output: false
*/

/*
Solving using two pointer technique
*/

#include<iostream>

using namespace std;

bool isSequence(string s, string t) {

	if(s.length()>t.length())
		return false;
	int i=0; //pointer for s
	int j=0; //pointer for t

	while(i<s.length() and j<t.length()){
		if(s[i]==t[j]){
			i++;
			j++;
		}
		else {
			j++;
		}
	}

	if(i==s.length())
		return true;
	return false;
}

int main() {
	string s = "abxc";
	string t = "ahbgdc";

	auto res = isSequence(s, t);
	cout<<res;
	return 0;
}