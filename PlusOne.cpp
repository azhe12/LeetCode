#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> digits_new;
        int digit;
        int extra = 1;

        for (int i = digits.size() - 1; i >= 0; i--) {
            digit = digits[i] + extra;
            extra = digit / 10;
            digits_new.push_back(digit % 10);
            //cout<<"digit: " << digit % 10<<endl;
        }
        if (extra != 0)
            digits_new.push_back(extra);

        for (int i = 0; i < digits_new.size() / 2; i++) {
            int t;
            t = digits_new[i];
            digits_new[i] = digits_new[digits_new.size() - i - 1];
            digits_new[digits_new.size() - i - 1] = t;
        }

        return digits_new;
    }
};

int main()
{
    vector<int> a(3,1);
    vector<int> b;
    class Solution so;
    b = so.plusOne(a);
    for (int i = 0; i < b.size(); i++)
        cout<<b[i]<<endl;
}
