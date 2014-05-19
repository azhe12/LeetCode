/*  azhe
 *  2014/5/19
 *  http://oj.leetcode.com/problems/3sum-closest/
 * */
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twoSum(vector<int> & num, int begin, int end, int target)
    {
        int i = begin;
        int j = end;
        int sum = num[i] + num[j];
        int closest = sum;

        while (i < j) {
            //cout<<num[i]<<num[j]<<endl;
            sum = num[i] + num[j];
            closest = (abs(sum - target) < abs(closest - target)) ? sum:closest;

            if (sum == target) {
                return sum;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return closest;
    }

    int threeSumClosest(vector<int> &num, int target) {
        if (num.size() < 3)
            return 0;
        sort(num.begin(), num.end());

        int closest = num[0] + num[num.size() - 1] + num[num.size() - 2];
        for (int i = 0; i < num.size() - 2; i++) {
            int new_target = target - num[i];
            int sum = num[i] + twoSum(num, i + 1, num.size() - 1, new_target);
            closest = (abs(sum - target) < abs(closest - target)) ? sum:closest;
        }
        return closest;
    }
};

int main()
{
    vector<int> v;
    int n;
#if 1
    while (true) {
        cout<<"Enter: ";
        if (!(cin>>n))
            break;
        v.push_back(n);
    }
#endif
#if 0
        cout<<"Enter: ";
    if (!(cin>>n))
        cout<<"ENd"<<endl;
#endif
    Solution so;

    cout<<"Closest: "<<so.threeSumClosest(v, 5)<<endl;
    return 0;
}
