#include<vector>
#include<iostream>
#include<stdlib.h>
using namespace std;

class Solution {
    public:
        int climbStairs(int n) {
            vector<int> w(n+1,-1); //memorization 
            int out = climbStairsAll(n,0,w);
            return out;
        }
        int climbStairsAll(int n, int curr, vector<int> &w){
            if(curr==n){
                return 1;
            }else{
                //curr < n
                int n1=0;
                int n2=0;
                if(curr+1<=n){
                    if(w[curr+1]==-1){
                        n1 = climbStairsAll(n,curr+1,w);
                        w[curr+1]=n1;
                    }else{
                        n1=w[curr+1];
                    }
                }else{
                    n1=0;
                }

                if(curr+2<=n){
                    if(w[curr+2]==-1){
                        n2 = climbStairsAll(n,curr+2,w);
                        w[curr+2]=n2;
                    }else{
                        n2=w[curr+2];
                    }
                }else{
                    n2=0;
                }
                return n1+n2;
            }

        }
};

int main(int argc, char *argv[]){
    Solution sol;
    int n=atoi(argv[1]);
    int out = sol.climbStairs(n);
    cout << out << endl;
    return 1;
}
