#include<iostream>
#include<vector>

class Solution{
	public:
		bool isNumber(string s){
			bool out = true;
			for(int i=0; i<s.size();i++){
				if(s[i]==' ') continue;
			}
		}
};

int main(){
	Solution sol;
	cout << sol.isNumber("1 a") << endl;
	cout << sol.isNumber(" 0.1 ") << endl;
	return 1;
}
