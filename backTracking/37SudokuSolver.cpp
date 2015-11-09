#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	void solveSudoku(vector<vector<char>> &board){
		//filter out the invalid sizes
		if(board.size()!=9 || board[0].size()!=9)
			return;
		else
			bool findSolSudoku = solSudoku(board,0,0);
	}
	bool solSudoku(vector<vector<char>> &board, int row, int col){
		// return if reached the end
		if(row==9) return 1;
		
		int col_nex,row_nex;
		// compute the next index locations
		if(col==8){
			col_nex = 0;
			row_nex = row+1;	
		}else{
			col_nex = col+1;
			row_nex = row;
		}

		if(board[row][col]!='.'){
			if(!isValid(board,row,col)) return false;
			return solSudoku(board, row_nex, col_nex);
		}

		// if not '.', try out a valid number
		for(int i=0;i<9;i++){
			board[row][col] = '0'+i;
			if(isValid(board,row,col) && solSudoku(board,row_nex,col_nex))
				return true;
		}
		
		// not found any solution
		// Reset the grid !!!!! NOTE!!! EASY mistake
        	board[row][col] = '.'; // reset the failing grid
		return false;
		
	}
	bool isValid(vector<vector<char>> &board, int row, int col){
		// check size
		if(board.size()!=9 && board[0].size()!=9) return false;
		
		// check self range
		if(board[row][col]<'0' || board[row][col] > '9') return false;

		// check row & col sum, if any repetitive
		for(int i=0; i<9; i++){
			if(i!= col && board[row][col]==board[row][i]) return false;
			if(i!= row && board[row][col]==board[i][col]) return false;
		}

		// check subbox
		int indx_row_start = row/3*3;
		int indx_col_start = col/3*3;
		for(int i=indx_row_start;i<indx_row_start+3;i++){
			for(int j=indx_col_start;j<indx_col_start+3;j++){
				if((i!=row && j!=col) && board[row][col]==board[i][j])
					return false;
			}
		}
		return true;	
	}
};

int main(){
	return 1;
}
