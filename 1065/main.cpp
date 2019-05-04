#include <vector>
#include <string>
#include <iostream>
#include <cmath>

int lengthOfLongestSubstring(std::string s) {
    std::vector<int> dict(256, -1);
    int maxLen = 0, start = -1;
    for (int i = 0; i != s.length(); i++) {
        if (dict[s[i]] > start) start = dict[s[i]];
        dict[s[i]] = i;
        maxLen = std::max(maxLen, i - start);
    }
    return maxLen;
}

int main() {
    std::string s;
    std::cin >> s;
    std::cout << lengthOfLongestSubstring(s) << "\n";
    return 0;
}
