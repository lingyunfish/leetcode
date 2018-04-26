#include <string>
#include <map>
#include <vector>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        map<char, vector<int> > alpha_index;
        for (size_t i = 0; i < s.length(); ++i) {
            alpha_index[s[i]].push_back(i);

        }
        int max_length = 0;
        string result;
        for (size_t i = 0; i < d.size(); ++i)
        {
            if (d[i].length() < result.length())
                continue;
            int current_max_index = 0;
            size_t j = 0;
            map<char, vector<int> > tmp_alpha_index = alpha_index;
            for (; j < d[i].length(); ++j)
            {
                if (tmp_alpha_index.find(d[i][j]) == tmp_alpha_index.end())
                    break;
                vector<int>& index = tmp_alpha_index[d[i][j]];
                int min_index = find_min_index(index, current_max_index);
                if (min_index == -1)
                    break;
                current_max_index = min_index;

            }
            if (j == d[i].length())
            {
                if (d[i].length() == result.length())
                {
                    if (d[i] < result)
                        result = d[i];

                }
                else
                {
                    result = d[i];

                }

            }

        }
        return result;

    }

    int find_min_index(vector<int>& index, const int max_index)
    {
        size_t i = 0;
        for (; i < index.size(); ++i)
        {
            if (index[i] >= max_index)
                break;
        }
        if (i == index.size())
            return -1; //not find
        int result = index[i];
        index[i] = -1;
        return result;
    }
};

int main()
{
    string s = "abpcplea";
    vector<string> d;
    d.push_back("ale");
    d.push_back("apple");
    d.push_back("monkey");
    d.push_back("plea");

    Solution solu;
    printf("result:%s\n", solu.findLongestWord(s, d).c_str());
    return 0;
}
