/*
两个整数之间的 汉明距离 指的是这两个数字对应二进制位不同的位置的数目。

给你两个整数 x 和 y，计算并返回它们之间的汉明距离。

 
示例 1：

输入：x = 1, y = 4
输出：2
解释：
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
上面的箭头指出了对应二进制位不同的位置。

示例 2：

输入：x = 3, y = 1
输出：1

 

提示：

    0 <= x, y <= 231 - 1
思路：
    对两个数对2取余，如果余数不同，则汉明距离+1， 然后将两个数右移一位， 直到其中一个数为0
    对于还未归零的数字，对2取余,若余数为1 汉明距离+1,否则不变。右移一次，直到为0
*/
#include <D:\github\Algorithm_Learning\LeetCode\headfile\stdc++.h>
using namespace std;

class Solution {
    public:
        int hammingDistance(int x, int y){
            int res = 0;
            while(x != 0 && y != 0){
                if((x & 1) != (y & 1)) res++;
                x >>= 1;
                y >>= 1;
            }

            int tmp = max(x, y);
            while(tmp != 0){
                if(tmp & 1) res++;
                tmp >>= 1;
            }
            return res;
        }
};

int main(){
    Solution s;
    cout << s.hammingDistance(93, 73) << endl;
}