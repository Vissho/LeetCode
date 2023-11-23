#include <cmath>
#include <iostream>
#include <vector>

/* Runtimr: 4 ms, Memory Usage: 6.4 - 6.5 MB */

bool isPalindrome(int x)
{
    if (x < 0) {
        return false;
    }

    int digit = -1, temp_x = x;
    do {
        digit++;
        temp_x /= 10;
    } while (temp_x != 0);

    do {
        if (static_cast<int>(x / pow(10, digit)) % 10 != x % 10)
            return false;
        digit -= 2;
        x /= 10;
    } while (digit > 0);

    return true;
}

int main()
{
    std::cout << isPalindrome(1221) << std::endl;
    return 0;
}