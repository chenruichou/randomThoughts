#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution{
    public:
    vector<vector<int>> palindromPairs(vector<string> &in){
        vector<vector<int>> out;
        vector<int> cand;
        for(int i=0;i<in.size();i++){
            for(int j=0;j<in.size();j++){
                if(i!=j){
                    int len = in[i].size()+in[j].size();
                    int offset = 0;
                    while(offset < len/2){
                        char left, right;
                        //get left
                        if(offset < in[i].size()){
                            left = in[i][offset];
                        }else{
                            left = in[j][offset-in[i].size()];
                        }
                        // get right
                        if(offset < in[j].size()){
                            right = in[j][in[j].size()-1-offset];
                        }else{
                            right = in[i][in[i].size()-1-(offset-in[j].size())];
                        }
                        if(left!=right)
                            break;
                        offset++;
                    }
                    if(offset==len/2){
                        cand.clear();
                        cand.push_back(i);
                        cand.push_back(j);
                        out.push_back(cand);
                    }
                }
            }
        }
        return out;
    }
};

int main(){
    Solution sol;
    vector<string> s = {"s","sslll","sabba","sx","xs"};
    vector<vector<int>> out = sol.palindromPairs(s);
    for(int i=0;i<out.size();i++){
        for(int j=0;j<out[i].size();j++){
            cout << out[i][j] << " ";
        }
        cout << endl;
    }
    return 1;
}
