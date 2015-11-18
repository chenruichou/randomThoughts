#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public: 
        vector<vector<int>> generateMatrix(int n){
            vector<vector<int>> out(n,vector<int> (n,0));
            fillMatrix(n, 0, 1, out);           
            return out;        
        }
        void fillMatrix(int n, int indx, int val, vector<vector<int>> &out){
            if(indx>n/2) return ;

            for(int i=indx; i<n-indx; i++){
                out[indx][i] = val++;
            }
            for(int i=indx+1;i<n-indx;i++){
                out[i][n-indx-1] = val++;
            }
            for(int i=n-indx-2;i>=indx;i--){
                out[n-indx-1][i] = val++;
            }
            for(int i=n-indx-2;i>indx;i--){
                out[i][indx] = val++;
            }
            fillMatrix(n, indx+1, val, out);
            return;
        }
};

int main(){
    Solution sol;
    vector<vector<int>> out = sol.generateMatrix(3);
    for(int i=0;i<out.size();i++){
        for(int j=0; j<out[i].size();j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }

    return 1;
}
