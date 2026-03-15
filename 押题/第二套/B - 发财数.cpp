#include <stdio.h>

int main() {
    int t;
    scanf("%d", &t);
    int s[10000];
    int k = 0;

    // 从2开始找到1e4个 发财数
    for (int num = 2; k < 10000; num++) {
        int n = num;
        int factors = 0;    // 因子个数
		
        // 提取所有 2因子
        while (n % 2 == 0) {	
            factors++;
            n /= 2;
        }
		
        // 提取其他因子（不用担心因子不是质数）
        for (int j = 3; j * j <= n; j += 2) {	
            while (n % j == 0) {
                factors++;                     
                n /= j;
            }
        }
		
        // 剩下最后一个因子
        if (n > 1) {
            factors++;
        }
		
        // 符合发财数条件 记录
        if (factors >= 8) {
            s[k++] = num;
        }
    }

    while (t--) {
        int n;
        scanf("%d", &n);
        printf("%d\n", s[n - 1]);
    }
    
    return 0;
}
