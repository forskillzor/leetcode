//
// Created by skillzor on 7/27/20.
//
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<unordered_map>
#include<unordered_set>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int result = 0;
        string str;
        auto begin = str.begin();

        for (char c : s) {
            if (std::size_t found{str.find(c)}; found != std::string::npos) {
                //str.erase(str.begin(), str.begin() + (found+1));
                //str.begin() += (found + 1);
                str.push_back(c);
            }
            else {
                str.push_back(c);
                if (result < str.length(begin, str.end()))
                    result = str.length();
            }
        }
        return result;
    }
};

Solution solution;
int (*tested)(string s) = &Solution::lengthOfLongestSubstring;

void test(string in, int out)
{
    static int count = 1;
    int res;
    cout << "test: " << count << " "
         << (((res = (*tested)(in)) == out) ? "PASSED" : "FAILED") << " "
         << "result: " << res << " "
         << "solution: " << out
         << "\n";
    ++count;
}

int main() {
    test("abcabcbb", 3);
    test("bbbbb", 1);
    test("pwwkew", 3);

    solution.lengthOfLongestSubstring("abcabcbb");

    return 0;
}
