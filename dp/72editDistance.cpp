#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
        int minDistance(string word1, string word2) {
            int n1 = word1.size();
            int n2 = word2.size();
            int out = solMinDistance(word1, word2, 0, 0, n1, n2);
        }
        int solMinDistance(string word1, string word2, int i, int j, int n1, int n2){
            if(i==n1-1 && j==n2-1){
                return 1;
            }else{
                // not matched => Edit!
                
            
            }
        
        }
};

int main(){
    Solution sol;
    string w1 = "hellobabe";
    string w2 = "hallowbeyourname";
    int out = sol.minDistance(w1,w2);
    cout << out << endl;
    return 1;
}
