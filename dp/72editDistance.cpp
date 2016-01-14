#include<vector>
#include<iostream>
using namespace std;

class Solution {
	public:
		int minDistance(string word1, string word2) {
			int out = solMinDistance(word1, word2, 0, 0);
			return out;
		}
		int solMinDistance(string word1, string word2, int i, int j){
			if(i==word1.size()-1){
				return word2.size()-j-1;
			}
			if(j==word2.size()-1){
				return word1.size()-i-1;
			}
			
			int addDist = solMinDistance(word1,word2,i,j+1)+1;
			int remvDist = solMinDistance(word1,word2,i+1,j)+1;
			int chgDist = solMinDistance(word1,word2,i+1,j+1) + (word1[i]==word2[j] ? 0 : 1);

			return min(min(addDist,remvDist),chgDist);
		}
};

int main(){
	Solution sol;
	string w1 = "hello";
	string w2 = "hallowbeyourname";
	int out = sol.minDistance(w1,w2);
	cout << out << endl;
	return 1;
}
