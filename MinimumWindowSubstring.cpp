//azhe 2014/6/24
//Note:two pointer
#include <string>
#include <iostream>
#include <climits>
using namespace std;
class Solution {
public:
    //a小于等于b, a的每个元素都小于等于b, 才为true
    bool equalLess(int * a, int * b, int n)
    {
        for (int i = 0; i < n; i++) {
            if (a[i] > b[i])
                return false;
        }
        return true;
    }
    string minWindow(string S, string T) {
        int pattern[128] = {0};     //T
        int comb[128] = {0};        //存储[S[start],S[end]]
        for (int i = 0; i < T.size(); i++) {
            pattern[T[i]]++;
        }

        int start = 0;
        int end = 0;
        int minStart = -1;
        int minEnd = INT_MAX;
        int minLen = INT_MAX;

        if (S.size() == 0 || T.size() == 0)
            return string("");
        comb[S[end]]++;     //先将首字母添加
        while (start < S.size() && end < S.size()) {
            if (equalLess(pattern, comb, 128)) {    //1. 找到一个符合的window, 向后移动start, 并且判断是否是len最小
                if (end - start + 1 < minLen) {
                    minLen = end - start + 1;
                    minStart = start;
                    minEnd = end;
                }
                if (start >= end) { //若start==end, 那么end也需要向后移动
                    end++;
                    if (end < S.size())
                        comb[S[end]]++;
                }
                comb[S[start]]--; //start向后移动
                start++;
            } else {                                //2. 未找到window, 向后移动end
                end++;
                if (end < S.size())
                    comb[S[end]]++;
            }
        }
        if (minStart == -1)
            return string("");
        else
            return S.substr(minStart, minLen);
    }
};

int main()
{
            //0123456789
    string s("ADOBECODEBANC");
    string t("ABC");
    
    cout<<Solution().minWindow(s, t)<<endl;
}
