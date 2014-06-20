//azhe
//2014/6/20
//
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    //高位在前如"123"表示数字123
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        vector<int> numInt1;
        vector<int> numInt2;
        vector<int> resInt(len1+len2, 0);
        string res;

        for (int i = len1-1; i >= 0; i--) { //将num1,num2转换为低位在前的vector<int>
            numInt1.push_back(num1[i]-'0');
        }
        for (int i = len2-1; i >= 0; i--) {
            numInt2.push_back(num2[i]-'0');
        }

        //1. num1和num2不同十进制位上数字的乘积 表现在进制之和的那个位上, 如
        //个 十 百 千 万
        //0  1  2  3  4
        //十位(1)和百位(2)的乘积 在千(3)位上
        //2. num1和num2乘积的最终结果位数是 len1+len2 - 1或者len1+len2
        for (int i = 0; i < len1; i++) {    
            for (int j = 0; j < len2; j++) {
                resInt[i+j] += numInt1[i]*numInt2[j];
            }
        }

        int c = 0;
        for (int i = 0; i < len1 + len2; i++) { //计算进位
            int tmp = c + resInt[i];
            c = tmp / 10;
            resInt[i] = tmp % 10;
        }

        int i = len1 + len2 - 1;
        while (i >= 0 && resInt[i] == 0) i--;   //去掉高位的0
        for (int j = i; j >= 0; j--) {  //将int数组转换为string, 并且高位在前
            res.push_back(resInt[j] + '0');
        }
        if (res.size() == 0)
            res.push_back('0');
        return res;
    }
};

int main()
{
    Solution so;
    string num1, num2;
    while (true) {
        cout<<"Enter s1 s2: ";
        if (cin>>num1>>num2) {
            cout<<so.multiply(num1, num2)<<endl;
        } else 
            break;
    }
}
