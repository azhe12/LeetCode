/*  azhe_liu
 *  liuyuanzhe123@126.com
 *  2014/4/20
 *
 * */
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        string comStr;
        int comLen;
        int j;

        if (strs.size() == 0)
            return string("");

        comStr = strs[0];
        comLen = strs[0].size();

        for (int i = 0; i < strs.size(); i++) {
            for (j = 0; j <comLen; j++) {
                if (comStr[j] != strs[i][j])
                    break;
            }
            comLen = j;
        }
        
        return comStr.assign(strs[0], 0, comLen);
    }
};

int main()
{
    class Solution so;
    vector<string> strs;
    strs.push_back("abcdazhe");
    strs.push_back("abcapple");
    strs.push_back("abcdpear");
    cout<<so.longestCommonPrefix(strs)<<endl;
}
