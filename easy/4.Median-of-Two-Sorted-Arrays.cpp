/*
    https://leetcode.com/problems/median-of-two-sorted-arrays/
    Created by skillzor on 7/29/20.
*/
#include<vector>
#include<iostream>
#include<cmath>
#include<limits>
#include<climits>

using namespace std;

/*
 *  1. Дожно быть два массива.
 */
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v1, v2;
        vector<int> *bigger = nullptr, *smaller = nullptr;

        bigger = (nums1.size() >= nums2.size()) ? &nums1 : &nums2;
        smaller = (nums1.size() < nums2.size()) ? &nums1 : &nums2;

        if ((*smaller).size() == 0) {
            int half = ((*bigger).size() + 1) / 2;
            v1.insert(v1.end(), (*bigger).begin(), (*bigger).begin() + half);
            v2.insert(v2.end(), (*bigger).begin() + half, (*bigger).end());
        }
        else {
            v1 = *bigger;
            v2 = *smaller;
        }
        int size1 = v1.size();
        int size2 = v2.size();
        int imax = size1;
        int half = (size1 + size2 + 1) / 2;
        int imin = half - size2;


        while (imin <= imax) {
            int i = (imin + imax) / 2;
            int j = half - i;

            if (i < imax && v2[j-1] > v1[i]) {
                imin = i + 1;
            }
            else if (i > imin && v1[i-1] > v2[j]) {
                imax = i - 1;
            }
            else {
                int maxLeft = 0;
                if (i == 0) { maxLeft = v2[j-1]; }
                else if (j == 0) { maxLeft = v1[i-1]; }
                else { maxLeft = max(v1[i-1], v2[j-1]); }
                if ((size1 + size2) % 2) {
                    return maxLeft;
                }

                int minRight = 0;
                if (i == size1) { minRight = v2[j]; }
                else if (j == size2) { minRight = v1[i]; }
                else { minRight = min(v1[i], v2[j]); }
                return 
                    (minRight + maxLeft) / 2.0;
            }
        }

        return 0.0;
    }
};

static Solution solution;

void test(vector<int> vec1, vector<int> vec2, double out )
{
    static int counter = 1;
    double res;
    cout << "test: " ;
    cout.width(4);
    cout << counter << " "
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
    test(vector<int>{ 1 }, vector<int>{ 2, 3, 4 }, 2.5);
    test(vector<int>{ 100001 }, vector<int>{100000}, 100000.5);
    test(vector<int>{ 4, 5, 6, 7, 8, 9}, vector<int>{ 1, 2, 3 }, 5.0);
    test(vector<int>{ }, vector<int>{ 1, 2, 3, 4, 5, 6 }, 3.5);
    test(vector<int>{ }, vector<int>{ 2, 3 }, 2.5);
    test(vector<int>{ 1, 2, 4 }, vector<int>{ 5, 6, 7 }, 4.5);
    test(vector<int>{ 1, 2, 3, 4 }, vector<int>{ 5, 6, 7, 8 }, 4.5);
    test(vector<int>{ 3 }, vector<int>{ 1, 2 }, 2.0);
    test(vector<int>{ -2, -1}, vector<int>{ 3 }, -1.0);
    test(vector<int>{ 1, 2 }, vector<int>{ 3 }, 2.0);
    test(vector<int>{ 1, 2, 3, 4, 5, 6 }, vector<int>{ 25, 26, 27 }, 5.0);
    test(vector<int>{ 4, 20, 32, 50, 55, 61 }, vector<int>{ 1, 15, 22, 30, 70 }, 30.0);
    test(vector<int>{ 2, 3 }, vector<int>{ 1 }, 2.0);
    test(vector<int>{ 1 }, vector<int>{ 2, 3 }, 2.0);
    test(vector<int>{ }, vector<int>{ 1 }, 1.0);
    test(vector<int>{ 1, 2 }, vector<int>{ 3, 4 }, 2.5);
    test(vector<int>{ 1, 3, 5, 7, 9 }, vector<int>{ 6, 8, 10 }, 6.5);
    test(vector<int>{ 1, 3, 5 }, vector<int>{ 2, 4, 6 }, 3.5);
    test(vector<int>{ 1, 3, 5, 7, 9 }, vector<int>{ 4, 6, 8 }, 5.5);
    test(vector<int>{ 1, 2 }, vector<int>{ -1, 3 }, 1.5);
    test(vector<int>{ 1, 3 }, vector<int>{ 2 }, 2.0);
    test(vector<int>{ 2 }, vector<int>{ 1, 3 }, 2.0);


    return 0;
}
