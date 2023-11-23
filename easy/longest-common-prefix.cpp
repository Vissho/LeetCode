#include <iostream>
#include <string>
#include <vector>

/* Runtimr: 0 ms, Memory Usage: 9.6 MB */

std::string longestCommonPrefix(std::vector<std::string>& strs)
{
    if (strs.empty())
        return "";
    if (strs.size() == 1)
        return strs[0];

    int i = 0, j = 0, size = strs.size();
    std::string pref;

    while (strs[0][i] != 0 && strs[1][i] != 0) {
        if (strs[0][i] != strs[1][i])
            break;
        pref += strs[0][i];
        i++;
    }

    i = 2;
    while (i < size) {
        if (pref.empty()) {
            return "";
        }

        if (pref[j] == 0) {
            j = 0;
            i++;
        } else if (strs[i][j] == 0 || pref[j] != strs[i][j]) {
            pref[j] == '\0';
            j = 0;
            i++;
        } else {
            j++;
        }
    }

    return pref;
}

int main()
{
    std::vector<std::string> strs = {"baab", "bacb", "b", "cbc"};
    std::cout << longestCommonPrefix(strs) << std::endl;
    return 0;
}