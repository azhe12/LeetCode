/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/19
 *
 * */
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;

class Solution {
public:
#if 0
    /*  1. 使用递归, 分段解决
     *  2. 如果size()为零则直接返回
     *  3. 如果此段是最后一位，则直接相加
     *  4. 计算重复, 如果此段只有重复数字则直接相加
     *  5. 判断大小，如果下一位大于上一位则，减去上一位.
     *  6. 如果下一位小于上一位，此时情况比较复杂。注意XIV(14), MCMXCVI(1996)
     *      XIV:10+(5-1), MCMXCVI:1000+(100-100)+(100-10)+(5+1)
     *      计算重复，重复结束后，比较i+1与i位，如果i+1位不小于begin, 那么先计算begin~i+1这一段。
     *
     * */
    int romanToIntRecurse(string s, int start, int sum, map<char, int>& m) {
        int i;
        if (start >= s.size())  /*end*//*2*/
            return sum;

        if (start == (s.size() - 1))    /*the last one*//*3*/
            return sum + m[s[start]];

        for (i = start + 1; i < s.size(); i++) {    /*4*/
            if (s[i] != s[i-1])
                break;
        }
        if (i == s.size()) {    /*end*/ /*4*/
            return sum + (s.size() - start) * m[s[start]];
        }

        if (m[s[i]] > m[s[i-1]]) {
            sum += m[s[i]] - (i - start) * m[s[i-1]];   /*5*/
        } else {    /*m[s[i]]<m[s[i-1]]*/
            sum += m[s[i-1]] * (i-start);
            int begin = i;

            while (i+1 < s.size()) {
                if (s[i+1] != s[i])
                    break;
                i++;
            }

            if (i+1 < s.size()) {
                if ((m[s[i+1]] > m[s[i]]) && 
                        (m[s[i+1]] <= m[s[begin - 1]])) {    /*如XIV*/
                    sum += m[s[i+1]] - m[s[i]] * (i-begin+1);
                    return romanToIntRecurse(s, i+2, sum, m);
                }
            }

            sum += m[s[i]] * (i - begin + 1);
        }
        return romanToIntRecurse(s, i+1, sum, m);
    }

    int romanToInt(string s) {
        map<char, int> m;
        m.insert(pair<char, int>('I', 1));
        m.insert(pair<char, int>('V', 5));
        m.insert(pair<char, int>('X', 10));
        m.insert(pair<char, int>('L', 50));
        m.insert(pair<char, int>('C', 100));
        m.insert(pair<char, int>('D', 500));
        m.insert(pair<char, int>('M', 1000));
        return romanToIntRecurse(s, 0, 0, m);
    }
#endif
    /*  从右向左结合
     *  左边小就减去，左边大就相加
     * */
    int romanToInt(string s) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int length = s.length();
        if(length <1) return 0;
        map<char,int> m;
        m['I'] = 1;
        m['V'] = 5;
        m['X'] = 10;
        m['L'] = 50;
        m['C'] = 100;
        m['D'] = 500;
        m['M'] = 1000;
        int i = length-1;
        int sum = m[s[i--]];
        while(i>=0)
            if(m[s[i+1]] > m[s[i]])
                sum -= m[s[i--]];
            else
                sum += m[s[i--]];
        return sum;
    }
};


int main()
{
    class Solution so;
    cout<<so.romanToInt(string("XIV"))<<endl;
    cout<<so.romanToInt(string("MCMXCVI"))<<endl;
}
