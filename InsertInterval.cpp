//azhe
//2014/6/22
/**
 * Definition for an interval.
 */
#include <iostream>
#include <vector>
using namespace std;

 struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };
 
class Solution {
public:
    vector<Interval> insert(vector<Interval> &intervals, Interval newInterval) {
        bool insertFlag = false;
        vector<Interval>::iterator it;
        vector<Interval> res;
        for (it = intervals.begin(); it != intervals.end(); it++) {
            if (!insertFlag) {  //未插入
                if (it->start > newInterval.end) {  //new在it左边, 直接插入new和*it
                    insertFlag = true;  //插入
                    res.push_back(newInterval);
                    res.push_back(*it);
                } else if (newInterval.start > it->end) {   //new在it右边, 不断插入*it
                    res.push_back(*it);
                } else {    //new和it有重合的地方, 重新计算new的start和end
                    newInterval.start = min(it->start, newInterval.start);
                    newInterval.end = max(it->end, newInterval.end);
                }
            } else {    //new已插入，接着在末尾插入余下it
                res.push_back(*it);
            }
        }
        if (!insertFlag)  //new始终未插入，那么最终放置到末尾
            res.push_back(newInterval);

        return res;
    }
};

int main()
{
    vector<Interval> v;
#if 0
    Interval in1(1,3);
    Interval in2(6,9);
    Interval newIn(2,5);
    v.push_back(in1);
    v.push_back(in2);
#endif
    Interval in1(1,2);
    Interval in2(3,5);
    Interval in3(6,7);
    Interval in4(8,10);
    Interval in5(12,16);

    //Interval newIn(4,9);
    Interval newIn(0,1);
    v.push_back(in1);
    v.push_back(in2);
    v.push_back(in3);
    v.push_back(in4);
    v.push_back(in5);


    vector<Interval> res;
    Solution so;
    res = so.insert(v, newIn);
    for (int i = 0; i < res.size(); i++)
        cout<<res[i].start<<" "<<res[i].end<<endl;
}
