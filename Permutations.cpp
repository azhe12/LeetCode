/*  azhe
 *  2014/5/27
 *  https://oj.leetcode.com/problems/permutations/
 *  Note: 利用递归，选出一个数然后对余下的数进行排列
 * */
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    
    void getRes(vector<int> &num, vector<int> & p, vector<vector<int> > & res)
    {
        if (num.size() == 0) {
            res.push_back(p);
            return;
        }

        if (num.size() == 1) {  /*只有一个元素*/
            p.push_back(num[0]);
            res.push_back(p);
            p.pop_back();       /*由于p是引用，所以需要pop, 避免影响实参*/
            return;
        }

        /*利用递归，选出一个数然后对余下的数进行排列*/
        for (int i = 0; i < num.size(); i++) {
            vector<int> tmp = num;
            int e = tmp[i];
            tmp.erase(tmp.begin()+i);
            p.push_back(e);
            getRes(tmp, p, res);
            p.pop_back();       /*由于p是引用，所以需要pop, 避免影响实参*/
        }
    }
    vector<vector<int> > permute(vector<int> &num) {
            vector<vector<int> > res;
            vector<int> p;
            getRes(num, p, res);
            return res;
    }
};

int main()
{
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.push_back(3);

    vector<vector<int> > res;
    Solution so;
    res = so.permute(v);

    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}
