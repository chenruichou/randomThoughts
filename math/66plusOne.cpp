#include<iostream>
#include<vector>
using namespace std;
class Solution{
public:
	vector<int> plusOne(vector<int> &digits){
		vector<int> out(digits.size(),0);
		bool isOver=true;
		for(int i=digits.size()-1;i>=0;i--){
			if(isOver){
				out[i]=digits[i]+1;
				if(out[i] >=10){
					out[i]-=10;
					isOver=true;
				}else{
					isOver=false;
				}
			}else{
				out[i]=digits[i];
			}
		}
		if(isOver){
			out.insert(out.begin(),1);
		}
		return out;
	}

};

int main(){
	vector<int> digits = {9};
	Solution sol;
	vector<int> out = sol.plusOne(digits);
	for(int i=0;i<out.size();i++){
		cout << out[i] << " ";
	}
	cout << endl;
	return 1;
}
