#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        int getNumSentenceFromString(string s, vector<string> &keys){
            // build the key map
            unordered_map<string, bool> m;
            string cand="";
            for(int i=0;i<keys.size();i++){
                m[keys[i]] = 1;
            }
            return solGetNumSentenceFromString(s, 0, m, cand);
        }
        int solGetNumSentenceFromString(string s, int indx, unordered_map<string, bool> &m, string cand){
            if(indx==s.size() && cand.size()==0){
                //visited all the char, add this 
                return 1;
            }
            if(indx>s.size() || (indx==s.size() && cand.size()!=0)){
                // not make the line, reject
                return 0;
            }

            cand.push_back(s[indx]);
            if(m[cand]){
                // not used
                int num = solGetNumSentenceFromString(s, indx+1, m, cand);
                // used
                cand.clear(); 
                int num2 = solGetNumSentenceFromString(s, indx+1, m, cand);
                return num+num2;
            }else{
                return solGetNumSentenceFromString(s, indx+1, m, cand);
            }    
        }
};

int main(){
    Solution sol;
    string s = "applet";
    vector<string> keys = {"apple","applet","t","table","able","app","let"};
    int out = sol.getNumSentenceFromString(s, keys);
    cout << out << endl;
    return 1;
}
