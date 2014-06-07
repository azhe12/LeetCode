/*  azhe
 *  2014/6/1
 *  https://oj.leetcode.com/problems/simplify-path/
 * */
#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
public:
    /*从i开始下一段path（以/为结尾）*/
    string nextPath(string& path, int i)
    {
        string slice;
        while (i < path.size() && path[i] != '/') {
            slice.push_back(path[i]);
            i++;
        }
        if (i == path.size())
            return slice;
        slice.push_back('/');
        return slice;
    }
    /*去掉尾部的path, 如/a/b/ 变为/a/ */
    void popToSlash(string path)
    {
        if (path.size() > 1) {
            path.pop_back();     /*如:/a/b/, 先去掉b后的'/'*/
            for (int i = res.size() -2; res[i] != '/'; i--)
                path.pop_back();
        }
    }
    string simplifyPath(string path) {
        strint res;
        if (path.size() == 0)
            return res;
        res.push_back('/');
        int i = 1;
        while (i < path.size()) {
            string nextP = nextPath(path, i);
            if (nextP == "")
                return res;
            i += nextP.size();      /*移动i*/

            if (nextP.size() == 1) {
                if (nextP[0] == '.' || nextP[0] == '/') {       /*'.'或'/'*/
                    continue;
                }
            } else if (nextP.size() == 2) {
                if (nextP[0] == '.' && nextP[1] == '/') {           /* "./" */
                    continue;
                } else if (nextP[0] == '.' && nextP[1] == '.') {    /* ".." */
                    popToSlash(res);
                    continue;
                }
            } else if (nextP.size() == 3) {
                if (nextP[0] == '.' && nextP[1] == '.' && nextP[2] == '/') {    /*"../"*/
                    popToSlash(res);    /*后退*/
                    continue;
                }
            }
            res += nextP;
        }
        if (res.size() > 1 && res[res.size() - 1] == '/')       /* /a/b/ => /a/b */
            res.pop_back();
        return res;
    }   
};

int main()
{
    string path;
    string res;
    Solution so;
    while (true) {
        cout<<"Enter path: ";
        if (cin>>path) {
            cout<<so.simplifyPath(path)<<endl;
        }
    }
}
