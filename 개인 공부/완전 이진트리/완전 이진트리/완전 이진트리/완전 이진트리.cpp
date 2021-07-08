#include<cstdio>

int n;

void f(int h, int u, int l) {
    if (h == n) {
        printf("%d ", l);
        return;
    }
    printf("%d ", u);
    f(h + 1, u - (1 << h - 1), l), f(h + 1, u - (1 << h - 1) * 2, l + (1 << h - 1));
}

int main() {
    scanf_s("%d", &n);
    f(1, (1 << n - 1) - 1, (1 << n - 1));
}