#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        double out=1;
	if(n==0) return 1;
	if(n>0){
		for(int i=0;i<n;i++){
			out *= x;
		}
	}else{
		// binary search to find the root
		int d = 0-n; // degree
		double left, right;
		if(x>=1){
			// search between 1 and x
			left = 1;
			right = x;
		}else if(x>0 && x<1){
			// search between 0 and 1
			left = 0;
			right = 1;
		}else if(x<0 && x>-1){
			// search between -1 and 0
			left = -1;
			right = 0;
		}else{
			// search between x and -1
			left = x;
			right = -1;
		
		}
		double mid;
		while(right-left>0.01){
			mid = (double) (left+right)/2;
			cout << mid << " ";
			double est = 1;
			for(int i=0;i<d;i++)
				est *=mid;
			if(est-x<0.01 && est-x>-0.01){
				out = mid;
				break;
			}else if(est<x){
				left = mid;
			}else{
				right = mid;
			}
		}
		out = mid;
		
		
	}
	return out;
    }
};

int main(){
	// I upgrade the problem to root finding
	Solution sol;
	double out = sol.myPow(2.2,-2);
	cout <<out<<endl;
	return 1;
}
