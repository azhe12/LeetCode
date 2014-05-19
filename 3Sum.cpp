/*  azhe
 *  2014/5/16
 *  http://oj.leetcode.com/problems/3sum/
 * */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void twoSum(vector<int> & num, int begin, int end, int target, vector<vector<int> > &res)
    {
        int i = begin;
        int j = end;

        while (i < j) {
            int sum = num[i] + num[j];
            if (sum == target) {
                vector<int> triple;
                triple.push_back(num[i]);
                triple.push_back(num[j]);
                triple.push_back(num[end+1]);
                res.push_back(triple);

                //cout<<num[i]<<" "<<num[j]<<" "<<num[end+1]<<endl;
                i++;
                if (i < j && (num[i] == num[i-1]))      /*去除重复的num[i]*/
                    i++;

                j--;
                if (i < j && (num[j] == num[j+1]))      /*去除重复的num[i]*/
                    j--;
            } else if (sum < target) {
                i++;
            } else
                j--;

        }
    }
    vector<vector<int> > threeSum(vector<int> &num) {
        vector<vector<int> > res;

        if (num.size() == 0)
            return res;

        sort(num.begin(), num.end());

        for (int i = num.size() - 1; i >= 2; i--) {
            if (i > 2 && (num[i] == num[i - 1])) continue;
            twoSum(num, 0, i - 1, 0 - num[i], res);     /*将3sum分解为2sum*/
        }
        return res;
    }
};

int main()
{
    Solution so;
    vector<int> num;
    num.push_back(-1);
    num.push_back(-1);
    num.push_back(0);
    num.push_back(0);
    num.push_back(1);
    num.push_back(1);
    num.push_back(2);
    num.push_back(2);
    num.push_back(-1);
    num.push_back(-4);
    num.push_back(-4);
    
    vector<vector<int> > res;
    res = so.threeSum(num);
#if 1
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
#endif
    return 0;
}
