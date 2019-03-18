#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <vector>

void rotate(std::vector<int>& nums, int k) {
    int n = nums.size();
    std::reverse(nums.begin(), nums.end());
    std::reverse(nums.begin(), nums.begin() + k % n);
    std::reverse(nums.begin() + k % n, nums.end());
}

int main() {
    int k;
    int i;
    std::vector<int> a;
    std::scanf("%d", &k);
    while (scanf("%d", &i) != EOF) {
        a.push_back(i);
    }
    rotate(a, k);
    for (i = 0; i < a.size(); i++) {
        std::printf("%d", a[i]);
        if (i < a.size() - 1) {
            std::printf(" ");
        } else {
            std::printf("\n");
        }
    }
    return 0;
}
