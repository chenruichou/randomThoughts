#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
	int b = 10;
	int r = x / b;
	int d = 1;
	if (r==0)
		return true;
	else{
		// determine the #digits
		while (r>0){
			d++;
			b*=10;
			r=x/b;
		}
		// then scan to determine if it's a palindrome
		int c=0;
		if(d % 2 == 0){
			c=1;	
		}
		for(int i=1;i<=d/2;i++){
			int v1 = (int)((int)x/(int)pow(10,i-1)) % 10;
			int v2 = (int)((int)x/(int)pow(10,d-i)) % 10;
			if(v1 != v2)
				return false;
		}
		return true;
	}
	
    }
};

int main(){
	Solution sol;
	bool out = sol.isPalindrome(12321);
	cout << out << endl;
	return 1;
}
