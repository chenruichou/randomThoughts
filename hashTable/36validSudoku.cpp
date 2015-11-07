#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
	public:
		bool isValidSudoku(vector<vector<char>>& board) {
			unordered_map<char,bool> m; //hashmap
			//check row
			for(int i=0; i< board.size();i++){
				m.clear();
				for(int j=0; j< board.size();j++){
					char c = board[i][j];
					if(c != '.'){
						if(c<'1' || c> '9') 
							return false;
						if(m[c]==false)
							m[c]=true;
						else
							return false;
					}
				}	
			}
			//check col
			for(int j=0; j< board.size();j++){
				m.clear();
				for(int i=0; i< board.size();i++){
					char c = board[i][j];
					if(c != '.'){
						if(c<'1' || c> '9') 
							return false;
						if(m[c]==false)
							m[c]=true;
						else
							return false;
					}
				}
			}
			// check for subbox
			for(int p=0;p<3;p++){
				for(int q=0;q<3;q++){
					m.clear();
					for(int i=0;i<3;i++){
						for(int j=0;j<3;j++){
							char c = board[i+p*3][j+q*3];
							if(c!='.'){
								if(c<'1' || c>'9')
									return false;
								if(m[c]==false)
									m[c]=true;
								else
									return false;
							}	
						}
					}
				}
			}
			return 1;

			/* // no need to check for diag
			//check diag
			m.clear();
			for(int i=0;i<board.size();i++){
			char c = board[i][i];
			if(c != '.'){
			if(c<'1' || c> '9')
			return false;
			if(m[c]==false)
			m[c]=true;
			else
			return false;
			}
			}
			m.clear();
			for(int i=0;i<board.size();i++){
			char c = board[i][board.size()-i-1];
			if(c != '.'){
			if(c<'1' || c> '9')
			return false;
			if(m[c]==false)
			m[c]=true;
			else
			return false;
			}
			}
			 */
		}
};


int main(){
	Solution sol;
	vector<vector<char>> board(100,vector<char>(100,'.'));
	cout <<	sol.isValidSudoku(board) << endl;
	return 1;
}
