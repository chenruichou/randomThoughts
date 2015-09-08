#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution {
	public:
		int myAtoi(string str) {
			int isNeg = 0;
			int out=0;
			for (string::iterator it=str.begin(); it!=str.end(); it++){
				if(*it=='-'){
					isNeg=1;
				}else{
					out += (*it-'0');
					out *=10;
				}
			}        
			out /=10;
			if (isNeg==1){
				out = 0-out;
			}
			return out;
		}
};


int main(){
	Solution sol;
	int out = sol.myAtoi("-321");
	cout << out << endl;
	return 1;
}
