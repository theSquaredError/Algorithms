/*
Problem: You are building a logic for a clock that requires you to convert
absolute time in minutes into a format supported by a digital clock.

Examples:-
----------

125 minutes can be displayed as 2:05
155 minutes can be displayed as 2:35


(Assume the maximum value of minutes will be less than 24x60)

*/

#include <iostream>
#include<string>

using namespace std;

string convert_to_digital_time(int minutes){

	string ans ="";
	int hrs = minutes/60;
	ans+=to_string(hrs)+":";

	int min = minutes%60;
	if(min<10){
		ans+="0"+to_string(min);
	}
	else{
		ans+=to_string(min);
	}

	return ans;

}

int main(){
	
	int minutes=155;
	//cin>>minutes
	string time = convert_to_digital_time(minutes);
	cout<<time;

	return 0;

}