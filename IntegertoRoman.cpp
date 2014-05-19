/*  azhe
 *  2014/5/16
 *  http://oj.leetcode.com/problems/integer-to-roman/
 * */
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        if (num == 0)
            return roman;

        /*  M    CM  D   CD  C   XC L  XL X  IX V IV I
         *  1000 900 500 400 100 90 50 40 10 9  5 4  1 
         * */
        // 阿拉伯数字转罗马数字：  
    // 把所有小数字在前的组合也作为基本数字，再做一个对应的数值表就可以解决问题了。  
    // I、V、X、   L、   C、     D、     M  
    // 1．5、10、50、100、500、1000  
        map<int, pair<int, string> > rTab;
        rTab[0] = make_pair(1000, "M");
        rTab[1] = make_pair(900, "CM");
        rTab[2] = make_pair(500, "D");
        rTab[3] = make_pair(400, "CD");
        rTab[4] = make_pair(100, "C");
        rTab[5] = make_pair(90, "XC");
        rTab[6] = make_pair(50, "L");
        rTab[7] = make_pair(40, "XL");
        rTab[8] = make_pair(10, "X");
        rTab[9] = make_pair(9, "IX");
        rTab[10] = make_pair(5, "V");
        rTab[11] = make_pair(4, "IV");
        rTab[12] = make_pair(1, "I");

        for (int i = 0; i < rTab.size(); i++) {
            while (num >= rTab[i].first) {
                num -= rTab[i].first;
                roman += rTab[i].second;
            }
        }
        return roman;
    }
};

int main()
{
    Solution so;
    while (true) {
        int num;
        cout<<"Enter num: ";
        cin>>num;
        cout<<so.intToRoman(num)<<endl;
    }
    return 0;
}
