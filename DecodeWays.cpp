/*  azhe
 *  2014/6/4
 *  https://oj.leetcode.com/problems/decode-ways/
 *  Note: DFS+DP
 *  注意特殊情况:
 *  1.  s=""    =>  way=0
 *  2.  s="0"   =>  way=0
 * */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int getRes(string s, int start, vector<int> & way)
    {
        if (start == s.size()) {/*结束*/
            return 1;
        }
        if (s[start] == '0')    /*s="0" =>way=0*/
            return 0;
        if (way[start]) {       /*已保存*/
            return way[start];
        } else {                /*未保存*/
            if (start == s.size() - 1) {
                way[start] = 1;
                return way[start];
            }
            if ((s[start]-'0')*10 + (s[start+1]-'0') <= 26) {   /*前两个数字不大于26*/
                if ((s[start] == '1' && s[start+1] == '0') ||
                        (s[start] == '2' && s[start+1] == '0')) {   /*如果是10或20则只有一种可能*/
                    way[start] = getRes(s, start+2, way);
                    return way[start];
                } else {    /*两种可能*/
                    way[start] = getRes(s, start+1, way) + getRes(s, start+2, way);
                    return way[start];
                }
            } else {        /*前两个数字大于26, 只有一种可能*/
                way[start] = getRes(s, start+1, way);
                return way[start];
            } 
        }
       
    }
    int numDecodings(string s) {
        vector<int> way(s.size());
        if (s.size() == 0)
            return 0;
        return getRes(s, 0, way);
    }
};

int main()
{
    Solution so;
    //string s("395");
    string s("115");
    cout<<so.numDecodings(s)<<endl;
    return 0;
}
