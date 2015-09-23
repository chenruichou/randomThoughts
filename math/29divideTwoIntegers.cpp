#include<iostream>
#include<vector>
#include<climits>
using namespace std;

class Solution {
	public:
	int divide(int dividend, int divisor) {
		if(divisor==0) return dividend > 0 ? INT_MAX : INT_MIN;			
		//if(dividend==0 || dividend<divisor) return 0;
		int isNeg = (dividend > 0 && divisor < 0) || \
 			    (dividend < 0 && divisor > 0) ? 1: 0;
		int dividend_abs = dividend<0 ? 0-dividend : dividend;
		int divisor_abs = divisor<0 ? 0-divisor : divisor;
		if(dividend==0 || dividend_abs < divisor_abs) return 0;
		int out = 0;
		while(dividend_abs > divisor_abs){
			dividend_abs -= divisor_abs;
			out++;	
		}
		out = isNeg==1 ? 0-out : out;
		return out;
	}
};

int main(){
	Solution sol;
	int out = sol.divide(-5,2);
	cout << out << endl;
	return 1;
}
