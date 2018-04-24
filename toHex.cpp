#include <stdio.h>
#include <stdlib.h>
#include <string>
using namespace std;
class Solution {
    const char *hex = "0123456789abcdef";
    public:
    string toHex(int num) {
        if (num == 0)
            return "0";
        string result;
        int current = num;
        int filter;
        bool begin_count = false;
        for (int i = 28; i >= 0; i -= 4) {
            filter = 0xf << i;
            current = num & filter;
            current >>= i;
            int value = current & 0xf;
            if (value != 0)
                begin_count = true;
            if (begin_count)
                result += hex[value];
        }
        return result;

    }

};

int main(int argc, char *argv[])
{
    int num = atoi(argv[1]);
   Solution s;
   printf("num:%d, hex:%s\n", num, s.toHex(num).c_str());
}
