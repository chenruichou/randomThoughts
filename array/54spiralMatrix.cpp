#include <iostream>
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> out;
            findSpiral(matrix, 0, 0, out);
            return out;
        }
        void findSpiral(vector<vector<int>> & matrix, int i, int j, vector<int> &out){
            if(i>matrix.size()/2 || j>matrix[0].size()/2) return;

            // add an outer layer
            for(int q=j; q< matrix[0].size()-j;q++){
                out.push_back(matrix[i][q]);
            }
            for(int p=i+1; p< matrix.size()-i;p++){
                out.push_back(matrix[p][matrix[0].size()-j-1]);
            }
            for(int q=matrix[0].size()-j-2; q>=j; q--){
                out.push_back(matrix[matrix.size()-i-1][q]);
            }
            for(int p=matrix.size()-i-2;p>=i+1;p--){
                out.push_back(matrix[p][j]);
            }
            findSpiral(matrix, i+1, j+1, out);
            return;
        }
};

int main(){
    vector<vector<int>> matrix(4,vector<int>(4,0));
    int tmp = 0;
    for(int i=0; i<matrix.size(); i++)
        for(int j=0; j<matrix[i].size(); j++)
            matrix[i][j] += tmp++;
    Solution sol;
    vector<int> out = sol.spiralOrder(matrix);
    for(int i=0;i<out.size();i++) cout << out[i] << endl;
}
