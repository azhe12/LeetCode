//azhe
//2014/6/21
/**
 * Definition for an interval.
 */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

bool comp(const Interval & lhs, const Interval & rhs)
{
    return lhs.start < rhs.start;
}
class Solution {
public:
    vector<Interval> merge(vector<Interval> &intervals) {
        vector<Interval> res;
        //if (intervals.size() == 0) return res;
        sort(intervals.begin(), intervals.end(), comp);
        for (int i = 0; i < intervals.size(); i++) {
            int last = res.size() - 1;
            if (i == 0)
                res.push_back(intervals[i]);
            else if (intervals[i].start <= res[last].end) {
                res[last].end = max(intervals[i].end, res[last].end);
            } else {
                res.push_back(intervals[i]);
            }
        }
        return res;
    }
};

int main()
{
    Interval in1(1, 3);
    Interval in2(2, 6);
    Interval in3(8, 10);
    Interval in4(15, 18);
    vector<Interval> inters;
    inters.push_back(in1);
    inters.push_back(in2);
    inters.push_back(in3);
    inters.push_back(in4);
    vector<Interval> res;
    Solution so;
    res = so.merge(inters);
    for (int i = 0; i < res.size(); i++) {
        cout<<res[i].start<<" "<<res[i].end<<endl;
    }
}
