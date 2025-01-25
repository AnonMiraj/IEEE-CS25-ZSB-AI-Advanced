#include <stdio.h>
#include <string.h>

int p[1010][1010], sum, ma, n, m;
int fx[4] = {1, -1, 0, 0};
int fy[4] = {0, 0, 1, -1};

void dfs(int x, int y) {
    int *p_base = &p[0][0];
    long long offset = x * 1010 + y;

    __asm__ __volatile__ (
        "movl (%[base], %[off], 4), %%eax\n\t" 
        "addl %%eax, %[sum]\n\t"             
        "movl $0, (%[base], %[off], 4)\n\t" 
        : [sum] "+m" (sum)
        : [base] "r" (p_base), [off] "r" (offset)
        : "eax", "memory"
    );

    for (int ii = 0; ii < 4; ++ii) {
        int newx = x + fx[ii];
        int newy = y + fy[ii];

        if (newx >= 0 && newx < n && newy >= 0 && newy < m && p[newx][newy] != 0) {
            dfs(newx, newy);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; i++) {
        scanf("%d%d", &n, &m);
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                scanf("%d", &p[j][k]);
            }
        }
        sum = 0;
        ma = 0;
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                if (p[j][k] != 0) {
                    dfs(j, k);
                    if (sum > ma)
                        ma = sum;
                    sum = 0;
                }
            }
        }
        printf("%d\n", ma);
    }
    return 0;
}
