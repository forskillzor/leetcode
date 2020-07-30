/*
    https://leetcode.com/problems/median-of-two-sorted-arrays/
    Created by skillzor on 7/29/20.
*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
public:
    int getJ(int i, int len) { return (len-2*i) / 2; }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int i, j;
        vector<int> &v1{ ((nums1.size() < nums2.size() ? nums1 : nums2)) };
        vector<int> &v2{ ((nums1.size() > nums2.size() ? nums1 : nums2)) };
        int totalLength = v1.size() + v2.size();
//        (v1[i] <= v2[j+1] && v1[i+1] >= v2[j])
    }
};

Solution solution;

void test(vector<int> vec1, vector<int> vec2, double out )
{
    static int counter = 1;
    double res;
    cout << "test: " << counter << " "
         << (((res = solution.findMedianSortedArrays(vec1, vec2)) == out)
                                                     ? ("\033[0;42m\033[1;37m" "PASSED" "\033[0m")
                                                     : "\033[0;41m\033[1;37m" "FAILED" "\033[0m") << " "
         << "result: " << static_cast<double>(res) << " "
         << "solution: " << out
         << "\n";
    ++counter;
}

int main() {
    test(vector<int>{ 1, 2 }, vector<int>{ 3, 4 }, 2.5);
    test(vector<int>{ 1, 3 }, vector<int>{ 2 }, 2.0);
    test(vector<int>{ 1, 2, 3, 4, 5, 6 }, vector<int>{ 25, 26, 27 }, 5.0);
    test(vector<int>{ 1, 3, 5, 7, 9 }, vector<int>{ 6, 8, 10 }, 6.5);


    return 0;
}
