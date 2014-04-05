#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(const char *s) {
        int n = strlen(s);
        int i, j;
        
        for (i = n -1; i >= 0; i--) {
            if (*(s+i) != ' ')
                break;
        }
        if (i < 0)
            return 0;
        j = i;
        for (; i >= 0; i--) {
            if (*(s+i) == ' ') {
                break;
            }
        }
        return j - i;
    }
};

int main() {
    class Solution so;
    //const char * s = "Hello World";
    const char * s = "asdf  adasdf";
    printf("%d\n", so.lengthOfLastWord(s));
    //printf("len=%lu\n", strlen(s));
}
