#include<iostream>
#include<string>
#include<vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string dict [] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv" };
    	vector<string> lettComb;
	string comb(digits.size(),'\0');
	findLetterCombination(digits,0,dict,comb,lettComb);
	return lettComb;
    }
    void findLetterCombination(string digits, int indx, string dict [], string &comb, vector<string> &lettComb){
    	if(indx==digits.size()){
		lettComb.push_back(comb);
		return;
	}
        string str = dict[digits[indx]-'0'];
	for (auto it=str.begin();it!=str.end();it++){
		comb[indx]=*it;
		findLetterCombination(digits,indx+1,dict,comb,lettComb);	
	}
    }
};

int main(){
	Solution sol;
	vector<string> out;
	out = sol.letterCombinations("23");
	for(auto it=out.begin();it!=out.end();it++){
		cout<<*it<<endl;
	}
	return 1;
}
