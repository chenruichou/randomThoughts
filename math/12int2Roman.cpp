#include<iostream>
#include<string>
using namespace std;
class Solution{
	public:
	string int2Roman(int x){
		string roman [] = {"M","CM","D","CD","C","XC","L","XL","X","IX","V","IV","I"};
		int roman_int [] = {1000,900,500,400,100,90,50,40,10,9,5,4,1};
		string out= "";
		int d=0;
		while(x>0){
			int c = x/roman_int[d];
			x = x % roman_int[d];
			for(int i=0;i<c;i++){
				out.append(roman[d]);
			}
			d++;
		}
		return out;
	}
};

int main(){
	Solution sol;
	string out = sol.int2Roman(1199);
	cout << out << endl;
	return 1;
}
