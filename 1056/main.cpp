#include <cmath>
#include <iostream>
#include <cstdio>
#include <cctype>
#include <limits.h>
#include <vector>
using std::cout;
using std::max;
using std::min;

int main() {
    std::vector<int> nums1{0, 0};
    std::vector<int> nums2{0, 0};

    scanf("%d", &nums1[0]);
    scanf("%d", &nums1[1]);
    scanf("%d", &nums2[0]);
    scanf("%d", &nums2[1]);

    double ret = 0;
    size_t s1 = nums1.size();
    size_t s2 = nums2.size();
    size_t half = (s1 + s2) / 2;
    size_t curr = 0, curr1 = 0, curr2 = 0;
    int v1 = 0, v2 = 0;
    int median[2]{0};
    while (curr < half + 1) {
        if (curr1 >= s1)
            goto c2;
        else if (curr2 >= s2)
            goto c1;
        else if (nums1[curr1] < nums2[curr2])
            goto c1;
        else
            goto c2;
    c1:
        v1 = nums1[curr1];
        v2 = INT_MAX;
        ++curr;
        ++curr1;
        goto next;
    c2:
        v2 = nums2[curr2];
        v1 = INT_MAX;
        ++curr;
        ++curr2;
    next:
        median[0] = median[1];
        median[1] = min(v1, v2);
    }
    if ((s1 + s2) % 2)
        ret = median[1];
    else
        ret = (double)(median[0] + median[1]) / 2.0;

    cout << ret << "\n";
    return 0;
}

