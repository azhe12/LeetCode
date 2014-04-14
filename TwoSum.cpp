/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/13
 *
 * */
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
    int val;
    int index;
    //Node(){}
    Node(int v, int i):val(v), index(i){}
};


bool compare(const Node &l, const Node &r) {
    return l.val < r.val;
}

class Solution {
public:
    /*  1. 先排序
     *  2. 从头和尾分别缩减范围求和
     * */
    vector<int> twoSum(vector<int> &numbers, int target) {
        vector<int> result(2,0);

        vector<Node> t;

        for (int i = 0; i < numbers.size(); i++) {
            t.push_back(Node(numbers[i], i));
        }

        sort(t.begin(), t.end(), compare);
        int i = 0;
        int j = numbers.size() - 1;
        int sum = 0;

        while (i != j) {
            sum = t[i].val + t[j].val;
            if (sum == target) {
                int minIndex = min(t[i].index, t[j].index);
                int maxIndex = max(t[i].index, t[j].index);
                result[0] = minIndex + 1;
                result[1] = maxIndex + 1;
                //break;
                return result;
            } else if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
    }
};


int main()
{
    class Solution so;
    //int a[4] = {2,7,11,15};
    int a[] = {4,3,  2};
    vector<int> t(a, a+3);
    vector<int> res(2);

    res = so.twoSum(t, 6);
    cout<<res[0]<<" "<<res[1]<<endl;
}
