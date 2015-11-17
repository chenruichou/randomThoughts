#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
        int numTrees(int n){
            if(n==0)
                return 1;
            else if(n==1)
                return 1;
            else if (n==2)
                return 2;
            else{
                int num=0;
                for(int i=0;i<n;i++){
                    num+=numTrees(n-i-1)*numTrees(i);
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
