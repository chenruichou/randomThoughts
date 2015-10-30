#include<iostream>
#include<vector>
using namespace std;

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
	int left=1;
	int right = n;
	int mid=-1;
        while(left<=right){
		mid = (left+right)/2;
		if(isBadVersion(mid)){
			right = mid - 1;
		}else{
			left = mid + 1;
		}
	}
	return mid;
    }
};


int main(){
	return 1;
}
