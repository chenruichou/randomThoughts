#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
class Solution{
	public:
		string multiply(string num1, string num2){
			// atoi
			int n1 = string2int(num1);
			int n2 = string2int(num2);
			//cout << n1 <<" "<< n2<< endl;
			
			// itoa
			string s = int2string(n1*n2,num1.size()+num2.size());	
			return s;
		}
		int string2int(string s){
			int sign = 1;
			int out = 0;
			for(int i=0;i<s.size();i++){
				if(s[i]=='-'){
					sign=-1;
				}else{
					out = out * 10 + (s[i]-'0');
				}
			}
			return out*sign;	
		}
		string int2string(int n, int m){
			//cout << n <<endl;
			//cout << m << endl;
			string s="";
			// calc max num
			m = pow(10,m);
			// sign bit
			if(n<0){
				s+="-";
				n=0-n;
			}
			while(n>0){
				if(n/m>0){
					s.push_back((char)'0'+n/m);
					n = n - (n/m)*m;	
				}
				m /= 10;
			}
			return s;
		}		
};


int main(){
	string s1 = "722";
	string s2 = "-13";
	Solution sol;
	cout << sol.multiply(s1,s2) << endl;
	return 1;
}
