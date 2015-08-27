#include <vector>
#include <iostream>
using namespace std;
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
    }
};


int main(){
	Solution s;
	int array_num1 [] ={3,6,9,11};
	int array_num2 [] ={4,8,12};
	vector<int> num1,num2;
	num1.assign(array_num1,array_num1+4);
	num2.assign(array_num2,array_num2+3);
	int median = s.findMedianSortedArrays(num1,num2);

	return 1;
}
