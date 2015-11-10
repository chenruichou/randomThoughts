#include<iostream>
#include<vector>
using namespace std;
class Solution{
	public:
		int trap(vector<int> &height){
			if(height.size()<3) return 0;
			vector<int> max_left(height.size(),0);
			vector<int> max_right(height.size(),0);
			cout << "test" <<endl;
			int curr_max_left=0;
			int curr_max_right=0;   

			// scan for max left
			for(int i=1;i<height.size();i++){
				max_left[i]=max(curr_max_left,height[i-1]);
				if(curr_max_left < height[i-1]){
					curr_max_left = height[i-1];
				}
			}
			// scan for max right
			for(int i=height.size()-2;i>0;i--){
				max_right[i]=max(curr_max_right,height[i+1]);
				if(curr_max_right <= height[i+1]){
					curr_max_right = height[i+1];
				}
			}
			// compute for the trapped water
			int water = 0;
			for(int i=1;i<height.size()-1;i++){
				int w = min(max_left[i],max_right[i]);
				if(height[i]<w) water+=(w-height[i]);
			}
			return water;
		}
};

int main(){
	Solution sol;
	vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
	cout<<sol.trap(height)<<endl;
	return 1;
}

