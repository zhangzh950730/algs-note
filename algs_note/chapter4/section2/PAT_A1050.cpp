// String Subtraction
// Created by zhang on 2020/8/18.
//
#include <iostream>
#include <cstring>

using namespace std;
const int maxn = 10001;

int main() {
    bool hashTable[128] = {false};
    char str1[maxn], str2[maxn];
    cin.getline(str1, maxn);
    cin.getline(str2, maxn);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for (int i = 0; i < len2; ++i) {
        hashTable[str2[i]] = true;
    }
    for (int i = 0; i < len1; ++i) {
        if (!hashTable[str1[i]]) printf("%c", str1[i]);
    }
    return 0;
}