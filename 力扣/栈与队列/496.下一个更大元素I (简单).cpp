/*
nums1 中数字 x 的 下一个更大元素 是指 x 在 nums2 中对应位置 右侧 的 第一个 比 x 大的元素。

给你两个 没有重复元素 的数组 nums1 和 nums2 ，下标从 0 开始计数，其中nums1 是 nums2 的子集。

对于每个 0 <= i < nums1.length ，找出满足 nums1[i] == nums2[j] 的下标 j ，并且在 nums2 确定 nums2[j] 的 下一个更大元素 。如果不存在下一个更大元素，那么本次查询的答案是 -1 。

返回一个长度为 nums1.length 的数组 ans 作为答案，满足 ans[i] 是如上所述的 下一个更大元素 。

 

示例 1：

输入：nums1 = [4,1,2], nums2 = [1,3,4,2].
输出：[-1,3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 4 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。
- 1 ，用加粗斜体标识，nums2 = [1,3,4,2]。下一个更大元素是 3 。
- 2 ，用加粗斜体标识，nums2 = [1,3,4,2]。不存在下一个更大元素，所以答案是 -1 。

示例 2：

输入：nums1 = [2,4], nums2 = [1,2,3,4].
输出：[3,-1]
解释：nums1 中每个值的下一个更大元素如下所述：
- 2 ，用加粗斜体标识，nums2 = [1,2,3,4]。下一个更大元素是 3 。
- 4 ，用加粗斜体标识，nums2 = [1,2,3,4]。不存在下一个更大元素，所以答案是 -1 。

 

提示：

    1 <= nums1.length <= nums2.length <= 1000
    0 <= nums1[i], nums2[i] <= 104
    nums1和nums2中所有整数 互不相同
    nums1 中的所有整数同样出现在 nums2 中

 

进阶：你可以设计一个时间复杂度为 O(nums1.length + nums2.length) 的解决方案吗？


*/
#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;
class Solution {
public:
    // 暴力解
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;                    
        for(auto& num : nums1){
            static int count = 0;
            // cout << count++ <<"for循环开始" << endl;
            // 在nums2 中找到num
            int i;
            for(i = 0; i < (int)nums2.size(); i++){
                if(nums2[i] == num)
                    break;
            }
            int findFlag = 0;
            for(int j = i + 1; j < (int)nums2.size(); j++){
                cout << "j = " << j << endl;
                if(nums2[j] > num){
                    // cout << "找到下一个更大元素为" << nums2[j] << endl;
                    res.push_back(nums2[j]);
                    findFlag = 1;
                    break;
                }
            }
            if(!findFlag){
                // cout << "未找到" << endl;
                res.push_back(-1);

            }
        }
        return res;
    }

    vector<int> nextGreaterElement2(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int> hashmap;
        stack<int> st;
        // 从后往前遍历nums2，找到nums2[i]的下一个更大元素
        // nums2 = {2,5,3,6,8,4,7,1};
        // st = {2,5,6,8};
        // hashmap = {1:-1, 7:-1, 4:7, 8:-1, 6:8, 3:6, 5:6, 2:5}
        for (int i = nums2.size() - 1; i >= 0; --i) {
            int num = nums2[i];
            while (!st.empty() && num >= st.top()) {
                st.pop();
            }
            hashmap[num] = st.empty() ? -1 : st.top();
            // cout << num << ":" << hashmap[num] << ", ";
            st.push(num);
        }
        vector<int> res(nums1.size());
        // nums1 直接从hashmap中找到结果
        for (int i = 0; i < (int)nums1.size(); ++i) {
            res[i] = hashmap[nums1[i]];
        }
        return res;
    }
};



int main(){
    system("chcp 65001>nul");
    Solution s;
    vector<int> nums1 = {4,1,2};
    vector<int> nums2 = {2,5,3,6,8,4,7,1};
    vector<int> res = s.nextGreaterElement2(nums1, nums2);
    for(auto& num : res){
        cout << num << " ";
    }
    cout << endl;

}