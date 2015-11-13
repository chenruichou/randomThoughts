#include<iostream>
#include<vector>
using namespace std;
class Solution {
	public:
		vector<vector<string>> solveNQueens(int n) {
			vector<vector<string>> out_all;
			vector<string> out(n,string (n,'.'));
			findNQueens(n,0,out,out_all); 
			return out_all;
		}
		void findNQueens(int n, int indx, vector<string> &out, vector<vector<string>> &out_all){
			if(indx==n){
				out_all.push_back(out);
				return;
			}

			for(int i=0;i<n;i++){
				out[indx][i]='Q';
				if(isValidNQueens(out)){
					findNQueens(n,indx+1,out, out_all);
				}
				out[indx][i]='.'; // roll back
			}
			return;
		}
		bool isValidNQueens(vector<string> &out){
			//check row
			for(int i=0; i<out.size(); i++){
				bool set_Q = 0;
				for(int j=0;j<out[i].size();j++){
					if(out[i][j]=='Q'){
						if(set_Q ==0){
							set_Q=1;
						}else{
							return false;
						}
					}	
				}
			}
			// check col
			for(int i=0; i<out.size(); i++){
				bool set_Q = 0;
				for(int j=0;j<out[i].size();j++){
					if(out[j][i]=='Q'){
						if(set_Q ==0){
							set_Q=1;
						}else{
							return false;
						}
					}	
				}
			}
			return true;
		}
};


int main(){
	Solution sol;
	vector<vector<string>>out = sol.solveNQueens(8);
	for(int i=0;i<out.size();i++){
		for(int j=0;j<out[i].size();j++){
			cout << out[i][j] << " ";
		}
		cout << endl;
	}
	cout << out.size()<<endl;
	return 1;
}
