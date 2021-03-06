// Prime Factors
// Created by zhang on 2020/8/23.
//
#include <cmath>
#include <cstdio>

const int maxn = 100010;
int prime[maxn], pNum = 0;

bool isPrime(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= (int) sqrt(n); ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

void findPrime() {
    for (int i = 0; i < maxn; ++i) {
        if (isPrime(i)) prime[pNum++] = i;
    }
}

struct factor {
    int x, cnt; //����,����
} fac[10];

int main() {
    findPrime();
    int n, num = 0;
    scanf("%d", &n);
    if (n == 1)printf("1=1");
    else {
        printf("%d=", n);
        int sqr = (int) sqrt(n);
        for (int i = 0; i < pNum && prime[i] <= sqr; ++i) {
            if (n % prime[i] == 0) {
                fac[num].x = prime[i];
                fac[num].cnt = 0;
                while (n % prime[i] == 0) {
                    fac[num].cnt++;
                    n /= prime[i];
                }
                num++;
            }
            if (n == 1) break;
        }
        if (n != 1) {
            fac[num].x = n;
            fac[num++].cnt = 1;
        }
        for (int i = 0; i < num; ++i) {
            if (i > 0) printf("*");
            printf("%d", fac[i].x);
            if (fac[i].cnt > 1) printf("^%d", fac[i].cnt);
        }
    }
    return 0;
}