#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            string out = "";
            findPerm(n, 1, k, 1, out);
            return out;
        }
        string findPerm(int n, int indx, int k, int k_indx, string out){
            if(indx>n) return;

            for(int i=1;i<=n;i++){
                out.push_back('0'+i);

            }

        }

};

int main(){
    Solution sol;
    string out = sol.getPermutation(3,5);
    cout << out << endl;
    return 1;
}
