/*  azhe
 *  2014/5/20
 *  http://oj.leetcode.com/problems/4sum/
 * */
#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std;
class Solution {
private:
public:
    vector<vector<int> > fourSum(vector<int> &num, int target) {
        vector<vector<int> > ret;
        sort(num.begin(), num.end());
        
        ret.clear();
        
        for(int i = 0; i < num.size(); i++)
        {
            if (i > 0 && num[i] == num[i-1])        /*去重复*/
                continue;
                
            for(int j = i + 1; j < num.size(); j++)
            {
                if (j > i + 1 && num[j] == num[j-1])    /*去重复*/
                    continue;
                    
                int k = j + 1;
                int t = num.size() - 1;
                
                while(k < t)        /*求twoSum*/
                {
                    if (k > j + 1 && num[k] == num[k-1])    /*去重复*/
                    {
                        k++;
                        continue;
                    }
                    
                    if (t < num.size() - 1 && num[t] == num[t+1])   /*去重*/
                    {
                        t--;
                        continue;
                    }
                    
                    int sum = num[i] + num[j] + num[k] + num[t];
                    
                    if (sum == target)
                    {
                        vector<int> a;
                        a.push_back(num[i]);
                        a.push_back(num[j]);
                        a.push_back(num[k]);
                        a.push_back(num[t]);
                        ret.push_back(a);
                        k++;
                    }
                    else if (sum < target)
                        k++;
                    else
                        t--;                        
                }
            }
        }
        
        return ret;
    }
};
int main()
{
#if 0
    istream_iterator<int> in_iter(cin);
    //cout<<"first"<<endl;
    istream_iterator<int> eof;
    vector<int> v(in_iter, eof);
#if 0
    for (int i = 0; i < v.size(); i++) {
        cout<<v[i]<<endl;
    }
    //cout<<"sec"<<endl;
#endif

    //vector<vector<int> > res = so.twoSum(v, 9);
    
#endif
    int n;
    vector<int> v;
    cout<<"Enter: ";
    while (cin>>n) {
        v.push_back(n);
    }
    Solution so;
    vector<vector<int> > res = so.fourSum(v, 0);
    cout<<"Result:"<<endl;
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++) {
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
