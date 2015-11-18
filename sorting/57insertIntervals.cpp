#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;
struct Interval{
    int start;
    int end;
    Interval(): start(0), end(0){}
    Interval(int s, int e): start(s), end(e) {}
};

bool compareInterval(Interval &a, Interval &b) {
    return a.start<b.start;
}

class Solution{
    public:
        vector<Interval> insert(vector<Interval> & intervals, Interval newInterval){
            if(intervals.size()==0){
                vector<Interval> out;
                return out;  
            } 
            vector<Interval> out;
            // ***sort by start: need to define a structure 
            sort(intervals.begin(), intervals.end(), compareInterval);
            Interval p = Interval();
            int start_indx;
            bool is_inserted = false;
            if(newInterval.start>=intervals[0].start){
                p.start = intervals[0].start;
                p.end = intervals[0].end;
                start_indx = 1;
            }else{
                p.start = newInterval.start;
                p.end = newInterval.end;
                start_indx = 0;
                is_inserted = true;
            }

            for(int i=start_indx; i<intervals.size();i++){
                if(is_inserted==false && newInterval.start < intervals[i].start){
                    // process inserted item first
                    if(newInterval.start > p.end){
                        out.push_back(p);
                        p.start = newInterval.start;
                        p.end = newInterval.end;
                    }else if (newInterval.end > p.end){
                        p.end = newInterval.end;
                    }
                }


                if(intervals[i].start > p.end){
                    out.push_back(p);
                    p.start = intervals[i].start;
                    p.end = intervals[i].end;
                }else if (intervals[i].end > p.end){
                    p.end = intervals[i].end;
                }
            }
            out.push_back(p);
            return out;
        }

};

int main(){
    Solution sol;
    vector<Interval> intervals;

    Interval p = Interval(1,3);
    intervals.push_back(p);
    p = Interval(2,6);
    intervals.push_back(p);
    p = Interval(8,10);
    intervals.push_back(p);
    p = Interval(15,18);
    intervals.push_back(p);
    Interval newInterval = Interval(6,7);
    vector<Interval> out = sol.insert(intervals, newInterval);

    for(int i=0;i<out.size();i++){
        cout << "["<< out[i].start << "," << out[i].end << "]" << ",";
    }
    cout << endl;
    return 1;
}
