#include<vector>
#include<iostream>
#include<unordered_map>
using namespace std;

class Solution{
    public:
        vector<vector<int>> subsetsWithDup(vector<int> &nums){
            vector<vector<int>> out;
            vector<int> cand;
            unordered_map<int,bool> m;
            subsetsWithDupSol(out,nums,cand,0,m);
            return out;
        }
        void subsetsWithDupSol(vector<vector<int>> &out, vector<int> &nums, vector<int> &cand, int i, unordered_map<int, bool> &m){
            if(i==nums.size()){
                if(cand.size()==1){
                    //check if duplicate
                    if(m[cand[0]]==false){
                        out.push_back(cand);
                        m[cand[0]]=true;
                    }
                }else{
                    out.push_back(cand);
                }
                return;
            }
            // recursion
            cand.push_back(nums[i]);
            subsetsWithDupSol(out, nums, cand, i+1,m);
            cand.pop_back();
            subsetsWithDupSol(out, nums, cand, i+1,m);
            return;
        }

};

int main(){
    Solution sol;
    vector<int> nums = {1,2,2};
    vector<vector<int>> out = sol.subsetsWithDup(nums);
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}
