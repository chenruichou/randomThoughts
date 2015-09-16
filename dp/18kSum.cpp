#include<iostream>
#include<string>
#include<vector>
using namespace std;
class Solution{
	public:
		vector<vector<int>> kSum(int k, vector<int> &in, int target){
			sort(in.begin(),in.end());
			vector<vector<int>> all_out;
			vector<int> out;
			findKSum(k,in,0,target,all_out,out);
			return all_out;
		}
		void findKSum(int k, vector<int> &in, int start, int target, vector<vector<int>> &all_out, vector<int> &out){
			if(k==1){
				for(auto it=in.begin()+start;it!=in.end();it++){
					if(it>in.begin() && *it==*(it-1)) continue;
					if(*it==target){
						out.push_back(*it);
						all_out.push_back(out);
						out.pop_back(); // important to release	
					}	
				}
				return;
			}

			if(k==2){
				auto left = in.begin()+start;
				auto right = in.end()-1;
				while(left<right){
					if(left>in.begin() && *left==*(left-1)){
						left++;
						continue;
					};
					int curr_sum = *left+*right;
					if(curr_sum==target){
						out.push_back(*left);
						out.push_back(*right);
						all_out.push_back(out);
						out.pop_back();
						out.pop_back();
						left++; //important
						right--; //important
					}else if(curr_sum<target){
						left++;
					}else
						right--;
				}
				return;
			}
			if(k>=3){
				//for  k >= 3
				for(auto it=in.begin()+start;it!=in.end();it++){
					if(it>in.begin() && *it==*(it-1)) continue;
					out.push_back(*it);
					findKSum(k-1,in,/*important*/it-in.begin()-start+1,target-*it,all_out,out);
					out.pop_back();	
				}
				return;
			}		
		}


};


int main(){
	Solution sol;
	vector<int> in = {1, 0, -1, 0, -2, 2};
	int target = 0;
	vector<vector<int>> all_out = sol.kSum(4,in,target);
	for(auto it=all_out.begin();it!=all_out.end();it++){
		cout <<"( ";
		for(auto it2=(*it).begin();it2!=(*it).end();it2++)
			cout<<  *it2 << ", ";
		cout<<") "<<endl;
	}

	return 1;
}
