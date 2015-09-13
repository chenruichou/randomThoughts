#include<iostream>
#include<string>
#include<unordered_map>

using namespace std;

class Solution {
	public:
	int romanToInt(string s) {
		int out=0;
		unordered_map<char,int> m = \
		{{'M',1000},{'D',500},{'C',100},{'L',50},{'X',10},{'V',5},{'I',1}};
		int curr_max = 0;
		for (auto it = s.end()-1; it != s.begin()-1; it--){
			if(m[*it]>=curr_max){
				out+=m[*it];
				curr_max = m[*it];
			}else{
				out-=m[*it];
			}
						
		}
		return out;
	}
};


int main(){
	Solution sol;
	int out = sol.romanToInt("MCXCIX");
	cout << out << endl;
	return 1;
}
