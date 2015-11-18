#include<iostream>
#include<vector>
using namespace std;
class Solution{
    public:
        int lengthOfLastWord(string s){
            int c = 0;
            for(int i=0; i<s.size();i++){
                if(s[i]==' '){
                    c=0;
                }else{
                    c++;
                }
            }
            return c;
        }
};

int main(){
    Solution sol;
    string s = "Hello World";
    int out = sol.lengthOfLastWord(s);
    cout << out << endl;
    return 1;
}
