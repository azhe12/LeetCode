//azhe liuyuanzhe123@126.com
//https://oj.leetcode.com/problems/gray-code/
//note: dfs
//1. 新增的0和1在高位
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void dfs(int dep, int maxDep, vector<int> & code)
    {
        if (dep > maxDep)
            return;
        //for (int i = 0; i < code.size(); i++)
            //code[i] = 2 * code[i];

        for (int i = code.size()-1; i >= 0; i--)
            code.push_back((1<<(dep-1)) + code[i]); //注意<<符号优先级大于+，所以要加括号
        
        dfs(dep+1, maxDep, code);
    }
    vector<int> grayCode(int n) {
        vector<int> code;

        code.push_back(0);
        dfs(1, n, code);
        return code;
    }
};

int main()
{
    int n; 
    //cin>>n;
    Solution so;
    vector<int> code;
    n = 2;
    code = so.grayCode(n);
    for (int i = 0; i < code.size(); i++)
        cout<<code[i]<<" ";
    cout<<endl;
}
