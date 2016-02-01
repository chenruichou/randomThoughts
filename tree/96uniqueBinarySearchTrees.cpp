#include<iostream>
#include<vector>
#include <unordered_map>
using namespace std;

class Solution{
	public:
		int numTrees(int n){
			unordered_map<int,int> memorized;
			return numTreesSol(n, memorized);
		}
		int numTreesSol(int n, unordered_map<int,int> &memorized){
			if(n==0)
				return 1;
			else if(n==1)
				return 1;
			else if (n==2)
				return 2;
			else{
				int num=0;
				for(int i=0;i<n;i++){
					int out_i=0;
					if(memorized[i]==0){
						out_i = numTreesSol(i, memorized);
						memorized[i] = out_i;
					}else{
						out_i = memorized[i];
					}

					int out_n_i_1=0;
					if(memorized[n-i-1]==0){
						out_n_i_1 = numTreesSol(n-i-1, memorized);
						memorized[n-i-1] = out_n_i_1;
					}else{
						out_n_i_1 = memorized[n-i-1];
					}
					num+=out_n_i_1*out_i;
				}
				return num;
			}
		}
};

int main(){
	Solution sol;
	int out = sol.numTrees(3);
	cout << out << endl;
	return 1;
}
