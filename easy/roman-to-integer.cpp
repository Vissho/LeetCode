#include <iostream>
#include <string>

/* Runtimr: 0 ms, Memory Usage: 6.4 MB */

int romanToInt(std::string s)
{
    int result = 0, i = 0, size = s.size();
    while (i < size) {
        if (s[i] == 'I') {
            result += 1;
            if (i + 1 < size) {
                if (s[i + 1] == 'I') {
                    result += 1;
                    i++;
                    if (i + 2 < size && s[i + 2] == 'I') {
                        result += 1;
                        i++;
                    }
                } else if (s[i + 1] == 'V') {
                    result += 3;
                    i++;
                } else if (s[i + 1] == 'X') {
                    result += 8;
                    i++;
                }
            }
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        } else if (s[i] == 'X') {
            result += 10;
            if (i + 1 < size) {
                if (s[i + 1] == 'L') {
                    result += 30;
                    i++;
                } else if (s[i + 1] == 'C') {
                    result += 80;
                    i++;
                }
            }
        } else if (s[i] == 'C') {
            result += 100;
            if (i + 1 < size) {
                if (s[i + 1] == 'D') {
                    result += 300;
                    i++;
                } else if (s[i + 1] == 'M') {
                    result += 800;
                    i++;
                }
            }
        }
        i++;
    }
    return result;
}

int main()
{
    std::cout << romanToInt("MCMXCIV") << std::endl;
    return 0;
}
