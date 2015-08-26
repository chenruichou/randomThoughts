#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
	vector<int> out;
	//unordered_map practice: begin/end
	unordered_map<string,string> mymap;
  	mymap = {{"Australia","Canberra"},{"U.S.","Washington"},{"France","Paris"}};
	for (auto it = mymap.begin(); it != mymap.end(); it++){
		cout << it->first << ": " << it->second << endl;
	}
	
	// main
	unordered_map<int,int> map; // map value to index
	for (auto it = nums.begin(); it != nums.end(); it++){
		map[*it]=it - nums.begin()+1;
	}
	// test the map built
	for (auto it = map.begin(); it != map.end(); it++){
		cout << it->first << ": " << it->second << endl;
	}
	cout << "test out-of-bound access: map[101] = " <<map[101] << endl;
	
	// find pairs
	for (auto it = nums.begin(); it!=nums.end(); it++){
		if(map[target-*it]!=0 && *it<=target/2){
			cout << "("<<*it<<", "<<target-*it<<") at index(" \
			<<it-nums.begin()<<", "<<map[target-*it]-1<<")"<<endl;
		}
	}
	

	return out;        
    }
};


int main(){
	int nums[] = {2,3,4,5,6,7,8};
	vector<int> nums_v;
	nums_v.assign(nums,nums+6);
	Solution s;	
	int tar=10;
	vector <int> out = s.twoSum(nums_v,tar);
	return 0;
}
