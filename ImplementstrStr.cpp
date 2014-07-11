/*  azhe
 *  2014/6/15
 *  https://oj.leetcode.com/problems/implement-strstr/
 * */
#include <iostream>
#include <string.h>
using namespace std;

class Solution {
public:
    char *strStr(char *haystack, char *needle) {
        bool find = false;
        if (!haystack || !needle)
            return NULL;

        if (*needle == '\0')
            return haystack;
        char * h_start = haystack;
        char * n_start = needle;
        while (*h_start != '\0') {
            char *p = h_start;
            while (*p != '\0' && 
                    *n_start != '\0' &&
                    *p == *n_start){
                p++;
                n_start++;
            }
            if (*n_start == '\0') { /*find!*/
                find = true;
                break;
            }
            h_start++;
            n_start = needle;
        }
        if (find)
            return h_start;
        else
            return NULL;
    }

    char *strStr2(char *haystack, char *needle) {
        char * s1 = haystack;
        char * s2 = needle;
        const char *p=s1;
        const size_t len = strlen(s2);
        for (;(p=strchr(p,*s2)) != 0;p++)
        {
            if(strncmp(p,s2,len)==0)
                return (char*)p;
        }
        return (0);
    }

};

int main()
{
    Solution so;
    char * name = "azhe";
    char * s = "h";
    //cout<<so.strStr(name, s)<<endl;
    cout<<so.strStr2(name, s)<<endl;
    return 0;
}
