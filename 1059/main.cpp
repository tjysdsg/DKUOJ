#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <numeric>
#include <string>
#include <vector>

int main() {
    char *line = nullptr;
    size_t sz;
    getline(&line, &sz, stdin);
    sz = strlen(line);
    std::vector<int> nums{};
    int start = 0, end = 0;
    for (int i = 0; i < sz; ++i) {
        if (line[i] == ' ' || i == sz - 1) {
            end = i;
            std::string n_str(&line[start], end - start + 1);
            nums.push_back(std::stoi(n_str));
            start = ++end;
        }
    }
    int minNum = *std::min_element(nums.begin(), nums.end());
    int n = nums.size();
    int sum = std::accumulate(nums.begin(), nums.end(), 0);
    printf("%d\n", sum - minNum * n);
    return 0;
}

