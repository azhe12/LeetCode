#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> row;
        if (rowIndex == 0) {
            row.push_back(1);
            return row;
        }

        if (rowIndex == 1) {
            row.push_back(1);
            row.push_back(1);
            return row;
        }

        row.push_back(1);
        row.push_back(1);

        for (int i = 2; i <= rowIndex; i++) {  /*row Index*/
            int prev_j_1 = row[0];
            int prev_j_1_backup;

            //for (int j = 1; j <= rowIndex - 1; j++) {
            for (int j = 1; j <= i - 1; j++) {
                prev_j_1_backup = row[j];       /*保存上一行的j元素*/
                row[j] = prev_j_1 + row[j];
                prev_j_1 = prev_j_1_backup;
            }
            row.push_back(1);
        }
        return row;
    }
};

int main()
{
    Solution so;
    int n;
    while (true) {
    
        cout<<"Enter n: ";
        if (cin>>n) {
            vector<int> row;
            row = so.getRow(n);
            for (vector<int>::iterator it = row.begin(); it != row.end(); it++) {
                cout<<*it<<" ";
            }
            cout<<endl;
        } else {
            break;
        }
    }

}
