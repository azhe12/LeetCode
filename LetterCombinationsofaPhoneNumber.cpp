/*  azhe
 *  2014/5/19
 *  http://oj.leetcode.com/problems/letter-combinations-of-a-phone-number/
 * */
#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

class Solution {
public:
    vector<string> lCRecur(string digits, map<char, string> & phN)
    {
        vector<string> res;
        if (digits.size() == 0) {
            res.push_back("");
            return res;
        }
        if (digits.size() == 1) {   /*只有一个数字*/
            string phNumString = phN[digits[0]];     /*phN如: '2':"abc"*/
            for (int i = 0; i < phNumString.size(); i++) {
                char letter[2];
                letter[0] = phNumString[i];
                letter[1] = '\0';
                res.push_back(letter);     /*如: ["a", "b", "c"]*/
            }
            return res;
        } else {                    /*多个数字*/
            vector<string> letters = lCRecur(string(digits.begin(), digits.begin()+1), phN);
            vector<string> remainLetters = lCRecur(string(digits.begin() + 1, digits.end()), phN);

            for (int i = 0; i < letters.size(); i++) {
                for (int j = 0; j < remainLetters.size(); j++) {
                    string combLetter = letters[i] + remainLetters[j];
                    res.push_back(combLetter);
                }
            }
            return res;
        }
    }
    vector<string> letterCombinations(string digits) {
        map<char, string> phN;
        phN['2'] = "abc";
        phN['3'] = "def";
        phN['4'] = "ghi";
        phN['5'] = "jkl";
        phN['6'] = "mno";
        phN['7'] = "pqrs";
        phN['8'] = "tuv";
        phN['9'] = "wxyz";
        return lCRecur(digits, phN);
    }
};

int main()
{
    string s;
    Solution so;
    cout<<"Enter: ";
    while (cin>>s) {
        vector<string> lc;
        lc = so.letterCombinations(s);
        for (int i = 0; i < lc.size(); i++) {
            cout<<lc[i]<<" ";
        }
        cout<<endl;
        cout<<"Enter: ";
    }
}
