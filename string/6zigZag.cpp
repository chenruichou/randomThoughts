#include<iostream>
#include<vector>
#include<string>
using namespace std;
class Solution{
    public:
	string convert(string s, int numRows) {
        	string s_out="";
		int n = s.length();
		int sp = numRows*2-2;
		for (int i=0; i<numRows; i++){
			for (int j=i; j<n; j+=sp){
				char c = s[j];
				s_out.insert(s_out.end(),c);
				if( j%sp!=0 && j%sp!=sp/2){
					// fill in letters in the gap
					int indx_ladder = j+(sp-j%sp)-j%sp;
					c = s[indx_ladder];
					if(indx_ladder < n)
						s_out.insert(s_out.end(),c);
				}
			}				
		}
		cout <<s_out<<endl;	
		return s_out;	
    	}
};
int main(){
	Solution sol;
	string s = "convertme";
	int numRows = 3;
	string s_out = sol.convert(s,numRows);
	cout << s << " -> " << s_out << endl;
	return 1;
}
