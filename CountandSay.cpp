/*  azhe_liu
 *  2014/5/4
 *
 * */
/*The count-and-say sequence is the sequence of integers beginning as follows:
1, 11, 21, 1211, 111221, ...

1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.
Given an integer n, generate the nth sequence.

Note: The sequence of integers will be represented as a string.
* */
#include <iostream>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s = new String();
        string s_new = new String();
        int j = 0;
        int j_prev = 0;
        int j_len = 0;
        if (n == 0)
            return string("");
        if (n == 1)
            return string("1");

        s = "1";
        for (int i = 2; i <= n; i++) {
            j = 1;
            j_prev = j - 1;
            j_len = j - j_prev;
            while (j < s.size()) {
                while (s[j] == s[j-1]) {
                    j++;
                    if (j >= s.size())
                        break;
                }

                j_len = j - j_prev;
                
                char buf1[2];
                char buf2[2];
                snprintf(buf1, sizeof(buf1), "%d", j_len);
                snprintf(buf2, sizeof(buf2), "%c", s[j_prev]);
                s_new += string(buf1) + string(buf2);
                j_prev = j;
                j++;
                j_len = j - j_prev;
            }
            if (j_prev < s.size()) {
                char buf1[2];
                char buf2[2];
                snprintf(buf1, sizeof(buf1), "%d", j_len);
                snprintf(buf2, sizeof(buf2), "%c", s[j_prev]);
                s_new += string(buf1) + string(buf2);
            }
            s = s_new;
            &s_new = NULL;
            delete &s_new;
            string& s_new = new string();
            s_new = "";
        }
        return s;
    }
};


int main()
{
    Solution so;
    int n;
#if 1
    cout<<"Enter n: "<<endl;
    while (cin>>n) {
        cout<<so.countAndSay(n)<<endl;
        cout<<"Enter n: "<<endl;
    }
#endif
    //cout<<so.countAndSay(5)<<endl;
    return 0;
}
