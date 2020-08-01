/*
    https://leetcode.com/problems/median-of-two-sorted-arrays/
    Created by skillzor on 7/29/20.
*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    int maxLeft(vector<int> v, unsigned long i, unsigned long j) {
        --i, --j;
        if (i >= 0 && j >=0 && i < v.size() && j < v.size()) {
            return v[i] > v[j] ? v[i] : v[j];
        }
        else if (i >= 0 && i < v.size()) {
            return v[i];
        }
        else if (j >= 0 && j < v.size()) {
            return v[j];
        }
        else
            return -9999999;
    }
    int minRight(vector<int> v, unsigned long i, unsigned long j) {
        ++i, ++j;
        if (i >= 0 && j >=0 && i < v.size() && j < v.size()) {
            return v[i] < v[j] ? v[i] : v[j];
        }
        else if (i >= 0 && i < v.size()) {
            return v[i];
        }
        else if (j >= 0 && j < v.size()) {
            return v[j];
        }
        else
            return 9999999;
    }
public:
    unsigned long len1;
    unsigned long len2;

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    }
};

static Solution solution;

void test(vector<int> vec1, vector<int> vec2, double out )
{
    static int counter = 1;
    double res;
    cout << "test: " << counter << " "
         << (((res = solution.findMedianSortedArrays(vec1, vec2)) == out)
                ? ("\033[0;42m\033[1;37m" "PASSED" "\033[0m")
                : "\033[0;41m\033[1;37m" "FAILED" "\033[0m") << " "
         << "result: ";
    cout.width(4);
    cout << static_cast<double>(res) << " "
         << "solution: ";
    cout.width(4);
    cout << out
         << "\n";
    ++counter;
}

int main() {
    test(vector<int>{ 4, 5, 6, 7, 8, 9}, vector<int>{ 1, 2, 3 }, 5.0);
    test(vector<int>{ 1, 2, 3, 4, 5, 6 }, vector<int>{ 25, 26, 27 }, 5.0);
    test(vector<int>{ 1, 2 }, vector<int>{ -1, 3 }, 1.5);
    test(vector<int>{ 1, 3 }, vector<int>{ 2 }, 2.0);
    test(vector<int>{ 2, 3 }, vector<int>{ 1 }, 2.0);
    test(vector<int>{ 1, 3 }, vector<int>{ 2 }, 2.0);
    test(vector<int>{ 1, 3, 5, 7, 9 }, vector<int>{ 6, 8, 10 }, 6.5);

    test(vector<int>{ 4, 20, 32, 50, 55, 61 }, vector<int>{ 1, 15, 22, 30, 70 }, 30.0);
    test(vector<int>{ 1, 2 }, vector<int>{ 3 }, 2.0);
    test(vector<int>{ -2, -1}, vector<int>{ 3 }, -1.0);
    test(vector<int>{ }, vector<int>{ 1 }, 1.0);
    test(vector<int>{ 1, 2 }, vector<int>{ 3, 4 }, 2.5);
    test(vector<int>{ 1, 3, 5 }, vector<int>{ 2, 4, 6 }, 3.5);
    test(vector<int>{ 1, 3, 5, 7, 9 }, vector<int>{ 4, 6, 8 }, 5.5);


    return 0;
}
