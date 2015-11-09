#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> allSol;
	vector<int> sol;
	if(candidates.size()==0) return allSol;
	sort(candidates.begin(),candidates.end());
	findSum(candidates, 0, target, sol, allSol);
	return allSol;
     }

     void findSum(vector<int> &candidates, int start, int target, vector<int> &sol, vector<vector<int>> &allSol){
     	if(target==0){
		allSol.push_back(sol);
		return;
	}
	for(int i=start; i<candidates.size();i++){
		// NOTE!!! get unique solution EASY TO MAKE MISTAKE
		if(i>start && candidates[i]==candidates[i-1]) continue;

		if(candidates[i]<=target){
			sol.push_back(candidates[i]);
			findSum(candidates, i+1, target-candidates[i], sol, allSol);
			sol.pop_back();
		}
	}
     }
};


int main(){
	
	vector<int> candidates = {2,3,6,7};
	int target = 7;
	Solution sol;
	vector<vector<int>> in = sol.combinationSum2(candidates, target);
	for(int i=0;i<in.size();i++){
		for(int j=0;j<in[i].size();j++)
			cout << in[i][j] << " ";
		cout << endl;
	}
	
	return 1;
}
