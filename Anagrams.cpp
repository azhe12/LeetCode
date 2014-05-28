/*  azhe
 *  2014/5/28
 *  https://oj.leetcode.com/problems/anagrams/
 * */
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

using namespace std;

#if 0
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <=1)
            return res;

        /*1. 对单词的字母排序, 并保存为pair.second*/
        /*不能用map， 因为步骤2的sort需要随机访问容器，map不支持随机访问*/
        vector<pair<string, string> > v;
        for (int i = 0; i < strs.size(); i++) {
            string tmp = strs[i];
            sort(tmp.begin(), tmp.end());       /*对每个单词排序*/
            v.push_back(make_pair(strs[i], tmp));
        }

        /*2. 对second排序*/
        sort(v.begin(), v.end(), cmp);
        /*3. 找出临近相同second即为变位词*/
        typedef vector<pair<string, string> >::iterator Iterator;
        Iterator pre = v.end();
        string same;
        for (Iterator it = v.begin(); it != v.end(); it++) {
            if (same != "") {
               if (it->second == same) {
                   res.push_back(it->first);
               } else {    /*由于变位词已经连续*/
                   break;
               }
            } else {
                if (pre != v.end()) {
                    if (it->second == pre->second) {
                        res.push_back(pre->first);
                        res.push_back(it->first);
                        same = it->second;
                    }
                }
            }
            pre = it;
        }

        return res;
    }
private:
#if 1

    /*必须为static, 否则的话 cmp有this指针，多了一个型参，和sort中的compare函数原型不匹配*/
    static bool cmp(const pair<string, string>& a, const pair<string, string>& b)
    {
        return a.second < b.second;
    }
#endif
};
#endif
class Solution {
public:
    vector<string> anagrams(vector<string> &strs) {
        vector<string> res;
        if (strs.size() <= 1) return res;
        map<string, int> anagram;
        for (int i = 0; i < strs.size(); ++i)
        {
            string s = strs[i];
            sort(s.begin(), s.end());
            if (anagram.find(s) == anagram.end()) {
                anagram.insert(make_pair(s, i));
            } else {
                if (anagram[s] >= 0) {
                    res.push_back(strs[anagram[s]]);
                    anagram[s] = -1;
                }
                res.push_back(strs[i]);
            }
        }
        return res;
    }
};
int main()
{
    vector<string> strs;
    strs.push_back("tea");
    strs.push_back("and");
    strs.push_back("ate");
    strs.push_back("eat");
    strs.push_back("den");

    vector<string> res;
    Solution so;
    res = so.anagrams(strs);

    for (int i = 0; i < res.size(); i++) {
        cout<<res[i]<<endl;
    }
    return 0;
}
