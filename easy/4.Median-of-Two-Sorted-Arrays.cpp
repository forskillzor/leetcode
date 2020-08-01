/*
    https://leetcode.com/problems/median-of-two-sorted-arrays/
    Created by skillzor on 7/29/20.
*/
#include<vector>
#include<iostream>
using namespace std;

class Solution {
    int maxLeft(vector<int> v1, vector<int> v2, unsigned long i, unsigned long j) {
        --i, --j;
        if (i >= 0 && j >=0 && i < v1.size() && j < v2.size()) {
            return v1[i] > v2[j] ? v1[i] : v2[j];
        }
        else if (i >= 0 && i < v1.size()) {
            return v1[i];
        }
        else if (j >= 0 && j < v2.size()) {
            return v2[j];
        }
        else
            return 0;
    }
    int minRight(vector<int> v1, vector<int> v2, unsigned long i, unsigned long j) {
        ++i, ++j;
        if (i >= 0 && j >=0 && i < v1.size() && j < v2.size()) {
            return v1[i] < v2[j] ? v1[i] : v2[j];
        }
        else if (i >= 0 && i < v1.size()) {
            return v1[i];
        }
        else if (j >= 0 && j < v2.size()) {
            return v2[j];
        }
        else
            return 0;
    }
    int getJ(int i, int len) { return ((len-2*i) / 2) - 1; }
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> &v1{ ((nums1.size() >= nums2.size() ? nums1 : nums2)) };
        vector<int> &v2{ ((nums1.size() < nums2.size() ? nums1 : nums2)) };
        unsigned long totalLength = v1.size() + v2.size();
        unsigned long i = 0, j = 0;
        unsigned long imin, imax, imid;
        int maxL, minR;
        int bigger;

        if (!(totalLength % 2)) {
            imin = (v1.size() - v2.size() ) / 2;
            imax = totalLength / 2 - 1;
        }
        else {
            imin = (v1.size() - v2.size() ) / 2;
            imax = totalLength / 2;
        }
        while (imin <= imax) {

            imid = (imin + imax) / 2;
            i = imid;
            j = getJ(i, totalLength);

            if (i >= 0 && j >=0) {
                bigger = v1[i] > v2[j] ? v1[i] : v2[j];
            }
            else if (i >= 0)
                bigger = v1[i];
            else if (j >= 0)
                bigger = v2[j];

            if (totalLength % 2) {
                if ((maxL = maxLeft(v1 , v2, i, j)) <= (minR = minRight(v1, v2, i, j))) {
                    if (maxL <= bigger && bigger <= minR)
                        return bigger;
                }
            }
            else {
                if ((maxL = maxLeft(v1 , v2, i, j)) <= (minR = minRight(v1, v2, i, j))
                        && (maxL <= v1[i] && v1[i] <= minR)
                        && (maxL <= v2[j] && v2[j] <= minR) )
                            return (v1[i] + v2[j]) / 2.0;
            }
            if (bigger < minR ) {
                if (bigger == v1[i])
                    imax = imid - 1;
                else
                    imin = imid + 1;
                continue;
            }
            else if (bigger > maxL) {
                if (bigger == v2[j])
                    imin = imid + 1;
                else
                    imax = imid - 1;
                continue;
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
    test(vector<int>{ 1, 2, 3, 4, 5, 6 }, vector<int>{ 25, 26, 27 }, 5.0);
    test(vector<int>{ 4, 20, 32, 50, 55, 61 }, vector<int>{ 1, 15, 22, 30, 70 }, 30.0);
    test(vector<int>{ 1, 3 }, vector<int>{ 2 }, 2.0);
    test(vector<int>{ 1, 2 }, vector<int>{ 3, 4 }, 2.5);
    test(vector<int>{ 1, 3, 5 }, vector<int>{ 2, 4, 6 }, 3.5);
    test(vector<int>{ 1, 3, 5, 7, 9 }, vector<int>{ 4, 6, 8 }, 5.5);
    test(vector<int>{ 1, 3, 5, 7, 9 }, vector<int>{ 6, 8, 10 }, 6.5);


    return 0;
}
