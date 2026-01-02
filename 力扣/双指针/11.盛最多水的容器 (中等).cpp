/*
给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是 (i, 0) 和 (i, height[i]) 。
找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
返回容器可以储存的最大水量。
说明：你不能倾斜容器。
*/


#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    // 暴力解
    int maxArea(vector<int>& height) {
        int max = 0;
        for (int i = 0; i < (int)height.size(); i++) {
            for (int j = i + 1; j < (int)height.size(); j++) {
                int area = (j - i) * min(height[i], height[j]);
                if (area > max) {
                    max = area;
                }
            }
        }
        return max;
    }

    // 双指针
    int maxArea(vector<int>& height) {
        int max = 0;
        // 双指针，i 指向左边，j 指向右边
        for (int i = 0, j = (int)height.size() - 1; i < j;) {
            int area = (j - i) * min(height[i], height[j]);
            if (area > max) {
                max = area;
            }
            // 移动较短的那条边
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max;
    }

    // 双指针 优化
    int maxArea(vector<int>& height) {
        
    }
};

int main() {
    system("chcp 65001>nul");
    vector<int> height = {1,8,6,2,5,4,8,3,7};
    Solution solution;
    int max = solution.maxArea(height);
    cout << "最大面积为：" << max << endl;
    return 0;

}