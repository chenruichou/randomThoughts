#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        string minWindow(string s, string t) {
            if(s=="") return "";
            if(t=="") return "";

            unordered_map<char, int> m;
            unordered_map<char, int> n;

            // scan for the target set
            for(int i=0;i<t.size();i++){
                m[t[i]]=1; // build hashtable
            }

            // scan for the source set
            int left=0;
            int right=0;
            int matched=0;
            int left_min=0;
            int right_min=0;
            int len_min=s.size()+10;
            while(right < s.size() && left <s.size()){
                //start from left
                if(m[s[left]]==0){ // not matched
                    left++; 
                }else{ // left matched
                    if(left>right)
                        right = left;
                    while(matched<t.size() && right < s.size()){ // right scan to the right
                        if(m[s[right]]==1){
                            if(n[s[right]]==0){ // if it's a newly covered number
                                matched++; 
                            }
                            n[s[right]]++;
                        }
                        right++;
                    }
                    if(matched==t.size()){
                        if(right-left+1 < len_min){ // found a shorter match, update!
                            left_min = left;
                            right_min = right;
                            len_min =right-left+1;
                        }
                    }

                    // left move on
                    n[s[left]]--;
                    if(n[s[left]]==0) // if deleted the last number
                        matched--;
                    left++; // move on;
                }
            }
            if(left_min==0 && right_min==0)
                return "";
            else{
                return s.substr(left_min, len_min);
            }
        }
};


int main(){
    Solution sol;
    string s="ADOBECODEBANC";
    string t="ABC";
    string out = sol.minWindow(s,t);
    cout << out << endl;
    return 1;
}
