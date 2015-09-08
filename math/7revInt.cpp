#include<iostream>
#include<queue>
using namespace std;

class Solution{
  public:
	int reverse(int x){
		bool isNeg=0;
		if(x<0){
			isNeg=1;
			x = 0-x;
		}
		queue<int> q;
		int t = 1;
		int d = x/t %10;
		while(d>0){
			q.push(d);
			t*=10;
			d = x/t%10;	
		}
		int out=0;
		while(!q.empty()){
			out *= 10;
			out += q.front();
			q.pop();
		}
		if(isNeg==1)
			out = 0-out;
		return out;
	}
};

int main(){
	Solution sol;
	int out = sol.reverse(-394321);
	cout << out << endl;
	return 1;
}
