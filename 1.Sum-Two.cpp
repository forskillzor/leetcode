//
// Created by skillzor on 7/21/20.
//
/*
 *      https://leetcode.com/problems/two-sum/
 */


#include<iostream>
#include<vector>
#include<map>
using namespace std;

class Solution {
public:
    static vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> table;
        vector<int> result;
        int i = 0, t = 0;
        while (i < nums.size()) {
            t = target - nums[i];
            if (auto found = table.find(t); found != table.end()) {
                result.push_back(found->second);
                result.push_back(i);
                return result;
            }
            table.insert({nums[i], i});
            ++i;
        }
        return result;
    }
};

void test(vector<int> input, int target, vector<int> solution)
{
    static int count = 1;
    enum {failed, passed};
    bool state = failed;

    vector<int> result = Solution::twoSum(input, target);

    if (result == solution)
        state = passed;

    cout << "TEST n: " << count << "  " << (state? "PASSED" : "FAILED") << "\n";

    ++count;
}

int main ()
{
    test({3, 2, 3}, 6, {0, 2});
    test({2, 7, 11, 15}, 9, {0, 1});
    test({3, 3}, 6, {0, 1});
    test({3, 2, 4}, 6, {1, 2});
    test({-10, -1, -18, -19}, -19, {1, 2});
    test({-100, 99, 2, 0, 22, -1001, 500}, -100, {0, 3});
    test({0, 4, 3, 0}, 0, {0, 3});
    test({2, 1, 9, 4, 4, 56, 90, 3}, 8, {3, 4});
    return 0;

}
