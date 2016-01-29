#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
        void merge(vector<int> &num1, int m, vector<int> &num2, int n){
            int c1=0;
            int c2=0;
            while(1){
                while(c1-c2<m && num1[c1]<=num2[c2]){    
                    c1++;
                }
                if(c1-c2==m){
                    for(int i=0;i<n-c2;i++)
                        num1[c1+i] = num2[c2+i];
                    break;
                }

                // num1[c1]>num2[c2]
                int c2_0 = c2;
                while(c2<n && num2[c2]<=num1[c1]){
                    c2++;        
                }
                if(c2==n)
                    break;
                // num2[c2]>num1[c1]
                // copy num1[c1:c1+c2-c2_0]
                for(int i=m+c2-c2_0;i>=c1;i--)
                    num1[i] = num1[i-c2+c2_0];
                //copy num2[c2_0:c2-1] to num1[c1:c1+c2-c2_0-1]
                for(int i=0;i<c2-c2_0;i++)
                    num1[c1+i] = num2[c2_0+i];
                c1+=(c2-c2_0);
            }
            return;
        }

};

int main(){
    Solution sol;
    vector<int> num1 = {1,2,3,4,5,0,0,0,0,0};
    vector<int> num2 = {2,3,7,8,9};
    sol.merge(num1, 5, num2, 5);
    for(int i=0;i<num1.size();i++){
        cout << num1[i] << " ";
    }
    cout << endl;
    return 1;
}
