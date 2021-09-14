#include <iostream>
#include <vector>

using namespace std;



bool check(vector<vector<bool>>& board, int row, int col) {
	
	int n = board.size();
	for(int i =0;i<=row;i++){
		if(board[i][col]) return false; //checking if any queen already placed on same column previously

		//checking if all the diagonals are safe -
		if(row-i >=0 and col-i>=0 and board[row-i][col-i]) return false;
		if(row-i >=0 and col+i<n and board[row-i][col+i]) return false;

	}
	return true;
}  
int solve(vector<vector<bool>>& board, int row){
	// Base case: if all the rows are completed
	if( row == board.size())
		return 1;
	int count = 0;
	// now we try every columns of that row
	for(int col =0; col< board.size();col++){
		if(check(board, row, col)){ // if we can place Q at row,col
			board[row][col] = true; //place the queen at (row,col)
			count+= solve(board, row+1); //explore for the next row. the function will return 1 if all N queens get placed for the current combination
			board[row][col] = false; //backtrack - remove previously placed queen and try for different columns

		}
	}

	return count;

}
int totalNQueens(int n){
	vector<vector<bool>> board(n, vector<bool>(n,false));
	return solve(board, 0);
}

int main(){
	int count = totalNQueens(4);
	cout<<count;
	return 0;
}