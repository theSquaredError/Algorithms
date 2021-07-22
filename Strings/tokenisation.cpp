// Tokenising a string denotes splitting a string with respect to some delimeter(s).

/*
Input 
"today is a sunny day"

Output 
"today","is","a","a","sunny","day"

*/

/*
String tokenisation in c++

1. Using stringstream class
2. Using strok function class
*/

//Creating our own tokeniser

#include<iostream>
#include<cstring>
using namespace std;

char *mystrtok(char *str, char delim) {

	static char *input = NULL;
	if(str!=NULL) {
		input = str;
	}

	if(input == NULL)
		return NULL;

	char *token = new char[strlen(input)+1];
	int i =0;
	for( ; input[i]!='\0'; i++) {
		if(input[i]!=delim){
			token[i] = input[i];
		}
		else {
			token[i] = '\0';
			input = input+i+1;
			return token;
		}
	}

	token[i] = '\0';
	input == NULL;
	return 0;
}


int main() {
	char s[1000];
	cin.getline(s, 1000);

	//strtok
	char *token = mystrtok(s, ' ');

	while(token!=NULL) {
		cout<<token<<endl;
		token = mystrtok(NULL,' ');
	}
}