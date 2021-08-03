/*

Write a function that returns a copy of this sentence 
where all the words:
	-start with a capital letter
	-the rest of the letters are lower case
*/

#include<bits/stdc++.h>
using namespace std;



string normalize(const string &sentence) {
    string copy = sentence;
    //Make the changes in copy, and return it
    
    string temp = "";
    int new_word = 1;
    for(int i=0;i<sentence.length();){
    	while(copy[i]==' ')
    		i++;
    	if(new_word){
    		copy[i] = toupper(copy[i]);
    		i++;
    	}
    	while(copy[i] !=' ' and i<copy.length()){
    		copy[i] = tolower(copy[i]);
    		i++;
    	}
    	i++;
    }

    return copy;
}


int main(){

	string input = " this is SO  MUCH FUN! at";
	//output = "This is So Much Fun! at"

	auto output = normalize(input);
	cout<<output;
	return 0;
}