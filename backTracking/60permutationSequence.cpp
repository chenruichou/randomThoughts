#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        string getPermutation(int n, int k) {
            string *out = new string[n];
            vector<bool> is_used(n+1, false);
	    bool is_found= findPerm(n, 0, k, 0, is_used, out);
            if(is_found) return *out;
	    else return "not_found";
        }
        bool findPerm(int n, int n_indx, int k, int k_indx, vector<bool> &is_used, string *out){
            if(n_indx==n) {
	    	k_indx++;
	    	if(k_indx==k) return 1;
		else return false;
	    }

            for(int i=1;i<=n;i++){
		    if(is_used[i]==false){
		    	(*out).push_back('0'+i);
		    	is_used[i]=true;
			n_indx++;
			n_indx = n_indx%3;
			if(n_indx==0) n_indx=3;	
		    	bool is_found = findPerm(n, n_indx, k, k_indx, is_used, out);
			if(is_found==true) return true; // found, return
			(*out).pop_back(); //elsewise
			is_used[i]=false;
		    }
            }
	    return false;
        }

};

int main(){
    Solution sol;
    string out = sol.getPermutation(3,1);
    cout << out << endl;
    return 1;
}
