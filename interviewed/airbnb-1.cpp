#include <iostream>
#include <vector>
using namespace std;

// To execute C++, please define "int main()"

/*
Given:  [[],[1,2,3],[4,5],[],[],[6],[7,8],[],[9],[10],[]]
Print:  1 2 3 4 5 6 7 8 9 10

boolean has_next()
return true or false if there is another element in the set

int next()
return the value of the next element in the array

void remove()
remove the last element returned by the iterator.  That is, remove the element that the previous next() returned
This method can be called only once per call to next(), otherwise, an exception will be thrown. See http://docs.oracle.com/javase/8/docs/api/java/util/Iterator.html#remove() for details.

input = [[],[1,2,3],[4,5],[],[],[6],[7,8],[],[9],[10],[]]
Iterator it = Iterator(input)
it.next()
it.remove()
print input => [[],[2,3],[4,5],[],[],[6],[7,8],[],[9],[10],[]]
while(it.has_next()) print it.next();  => 1 2 3 4 ...
*/ 

class Iterators{
  public:
    
    vector<vector<int>> in;
    int curr_indx_array=0;
    int curr_indx_subarray=0;
    Iterators(vector<vector<int>> &input){
      in = input;
    }
    bool has_next(){
      if(curr_indx_array==in.size()-1 && curr_indx_subarray==in[curr_indx_array].size()-1){
        // last of last
        return false;
      }else{
        return true;
      }
    }
    int next(){
      if(has_next()){
        int out = 0;
        if(in[curr_indx_array].size()==0 || curr_indx_subarray==in[curr_indx_array].size()-1){
            curr_indx_subarray=0;
            curr_indx_array++;
            while(in[curr_indx_array].size()==0){
              curr_indx_array++;
            }
            out = in[curr_indx_array][curr_indx_subarray];
          }else{
            curr_indx_subarray++;
            out = in[curr_indx_array][curr_indx_subarray];
          }
        return out;
      }
    }
    void remove(){
      
    }
};
int main() {
  vector<vector<int>> in = {{},{1,2},{4,5,6},{7},{},{8,9}};
  //fill up
  
  Iterators it(in);
  
  while(it.has_next()){
    cout << it.next() << " ";
  }
  
  return 0;
}

