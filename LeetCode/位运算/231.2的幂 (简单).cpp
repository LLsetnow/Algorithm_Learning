/*
给你一个整数 n，请你判断该整数是否是 2 的幂次方。如果是，返回 true ；否则，返回 false 。

如果存在一个整数 x 使得 n == 2x ，则认为 n 是 2 的幂次方。

 

示例 1：

输入：n = 1
输出：true
解释：20 = 1

示例 2：

输入：n = 16
输出：true
解释：24 = 16

示例 3：

输入：n = 3
输出：false

思路：
    将 n % 2 看余数是否为0，如果为0则继续除2，直到n为1或出现非0余数
*/
class Solution {
    public:
        bool isPowerOfTwo(int n) {
            if(n <= 0) return false;
            while(n){
                if(n % 2 == 1 && n != 1) return false;
                n >>= 1;
            }      
            return true;
        }
    };
