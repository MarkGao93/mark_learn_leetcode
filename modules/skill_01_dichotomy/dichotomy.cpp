#include "common.h"
#include <assert.h>
using std::vector;


void leetcode_704();
void leetcode_35();
void leetcode_34();
void leetcode_69();
void leetcode_367();
void leetcode_74();
void leetcode_33();
void leetcode_153();
void leetcode_4();


int dichotomy_main() {
    cout << endl << "dichotomy_main" << endl << endl;;

    // LeetCode hot 100
    leetcode_704();  // simple
    leetcode_35();  // simple
    leetcode_34();  // medium
    leetcode_74();  // medium
    // need optimization
    leetcode_33();  // medium
    leetcode_153();  // medium
    leetcode_4();  // hard

    // Carl suggested dichotomy questions
    leetcode_69();  // simple
    leetcode_367();  // simple

    return 0;
}







void leetcode_704() {
    cout << endl << "leetcode_704" << endl;
    // type: simple
    // 给定一个 n 个元素有序的（升序）整型数组 nums 和一个目标值 target  ，
    // 写一个函数搜索 nums 中的 target，如果目标值存在返回下标，否则返回 -1。
    // 输入: nums = [-1,0,3,5,9,12], target = 9
    // 输出: 4
    // 解释: 9 出现在 nums 中并且下标为 4
    // leetcode url: https://leetcode.cn/problems/binary-search/description/
    // url: https://www.programmercarl.com/0704.%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.html
    
    class Solution {
    public:
        // 左闭右闭写法
        // 时间复杂度：O(log n)
        // 空间复杂度：O(1)
        int search(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
            while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
                int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
                if (nums[middle] > target) {
                    right = middle - 1; // target 在左区间，所以[left, middle - 1]
                } else if (nums[middle] < target) {
                    left = middle + 1; // target 在右区间，所以[middle + 1, right]
                } else { // nums[middle] == target
                    return middle; // 数组中找到目标值，直接返回下标
                }
            }
            // 未找到目标值
            return -1;
        }
    };

    vector<int> nums = {-1,0,3,5,9,12};
    int target = 9;

    Solution var704;
    int ret = var704.search(nums, target);
    cout << "leetcode_704 expected result is 4 !" << endl;
    cout << "ret = " << ret << endl;

}


void leetcode_35() {
    cout << endl << "leetcode_35" << endl;
    // type: simple
    // 给定一个排序数组和一个目标值，在数组中找到目标值，并返回其索引。
    // 如果目标值不存在于数组中，返回它将会被按顺序插入的位置。
    // nums 为 无重复元素 的 升序 排列数组
    // 请必须使用时间复杂度为 O(log n) 的算法。
    // 示例
    // 输入: nums = [1,3,5,6], target = 5
    // 输出: 2
    // url: https://programmercarl.com/0035.%E6%90%9C%E7%B4%A2%E6%8F%92%E5%85%A5%E4%BD%8D%E7%BD%AE.html



    class Solution {
    public:
        int searchInsert(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1; // 定义target在左闭右闭的区间里，[left, right]
            while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
                int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
                if (nums[middle] > target) {
                    right = middle - 1; // target 在左区间，所以[left, middle - 1]
                } else if (nums[middle] < target) {
                    left = middle + 1; // target 在右区间，所以[middle + 1, right]
                } else { // nums[middle] == target
                    return middle; // 数组中找到目标值，直接返回下标
                }
            }
            // 最终插入位置为left所在位置
            return left;

            // 分别处理如下四种情况
            // 目标值在数组所有元素之前  [0, -1]
            // 目标值等于数组中某一个元素  return middle;
            // 目标值插入数组中的位置 [left, right]，return  right + 1
            // 目标值在数组所有元素之后的情况 [left, right]， 因为是右闭区间，所以 return right + 1
            // return right + 1;

            // return left or right + 1 is the same
        }
    };

    vector<int> nums = {1,3,5,6};
    int target = 2;

    Solution var35;
    int ret = var35.searchInsert(nums, target);
    cout << "leetcode_35 expected result is 1 !" << endl;
    cout << "ret = " << ret << endl;
    assert(ret == 1);

    target = 7;
    ret = var35.searchInsert(nums, target);
    cout << "leetcode_35 expected result is 4 !" << endl;
    cout << "ret = " << ret << endl;

    target = 0;
    ret = var35.searchInsert(nums, target);
    cout << "leetcode_35 expected result is 0 !" << endl;
    cout << "ret = " << ret << endl;

}


void leetcode_34() {
    cout << endl << "leetcode_34" << endl;
    // type: medium
    // 给你一个按照非递减顺序排列的整数数组 nums，和一个目标值 target。
    // 请你找出给定目标值在数组中的开始位置和结束位置。
    // 如果数组中不存在目标值 target，返回 [-1, -1]。
    // 你必须设计并实现时间复杂度为 O(log n) 的算法解决此问题。
    // 示例
    // 输入: nums = [5,7,7,8,8,10], target = 8
    // 输出: [3,4]
    // url: https://programmercarl.com/0034.%E5%9C%A8%E6%8E%92%E5%BA%8F%E6%95%B0%E7%BB%84%E4%B8%AD%E6%9F%A5%E6%89%BE%E5%85%83%E7%B4%A0%E7%9A%84%E7%AC%AC%E4%B8%80%E4%B8%AA%E5%92%8C%E6%9C%80%E5%90%8E%E4%B8%80%E4%B8%AA%E4%BD%8D%E7%BD%AE.html


    // 寻找target在数组里的左右边界，有如下三种情况：

    // 情况一：target 在数组范围的右边或者左边，例如数组{3, 4, 5}，target为2或者数组{3, 4, 5},target为6，此时应该返回{-1, -1}
    // 情况二：target 在数组范围中，且数组中不存在target，例如数组{3,6,7},target为5，此时应该返回{-1, -1}
    // 情况三：target 在数组范围中，且数组中存在target，例如数组{3,6,7},target为6，此时应该返回{1, 1}
    class Solution {
    public:
        vector<int> searchRange(vector<int>& nums, int target) {
            int leftBorder = getLeftBorder(nums, target);
            int rightBorder = getRightBorder(nums, target);
            // 情况一
            if (leftBorder == -2 || rightBorder == -2) return {-1, -1};
            // 情况三
            if (rightBorder - leftBorder > 1) return {leftBorder + 1, rightBorder - 1};
            // 情况二
            return {-1, -1};
        }    
    private:
        // 二分查找，寻找target的右边界（不包括target）
        // 如果rightBorder为没有被赋值（即target在数组范围的左边，例如数组[3,3]，target为2），为了处理情况一
        int getRightBorder(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;  // 定义target在左闭右闭的区间里，[left, right]
            int rightBorder = -2;  // 记录一下rightBorder没有被赋值的情况
            while (left <= right) {  // 当left==right，区间[left, right]依然有效
                int middle = left + ((right - left) / 2);  // 防止溢出 等同于(left + right)/2
                if (nums[middle] > target) {
                    right = middle - 1;  // target 在左区间，所以[left, middle - 1]
                } else { // 当nums[middle] == target的时候，更新left，这样才能得到target的右边界
                    left = middle + 1;
                    rightBorder = left;
                }
            }
            return rightBorder;
        }
        // 二分查找，寻找target的左边界leftBorder（不包括target）
        // 如果leftBorder没有被赋值（即target在数组范围的右边，例如数组[3,3],target为4），为了处理情况一
        int getLeftBorder(vector<int>& nums, int target) {
            int left = 0;
            int right = nums.size() - 1;
            int leftBorder = -2; // 记录一下leftBorder没有被赋值的情况
            while (left <= right) {
                int middle = left + ((right - left) / 2);
                if (nums[middle] >= target) { // 寻找左边界，nums[middle] == target的时候更新right
                    right = middle - 1;
                    leftBorder = right;
                } else {
                    left = middle + 1;
                }
            }
            return leftBorder;
        }
    };
    // 这份代码在简洁性很有大的优化空间，例如把寻找左右区间函数合并一起。
    // 但拆开更清晰一些，而且把三种情况以及对应的处理逻辑完整的展现出来了。

    vector<int> nums = {5,7,7,8,8,10};
    int target = 8;

    Solution var34;
    vector<int> ret = var34.searchRange(nums, target);
    cout << "leetcode_34 expected result is [3,4] !" << endl;
    cout << "ret = ";
    for (int i = 0; i < ret.size(); i++) {
        cout << ret[i] << " ";
    }
    cout << endl;
    // cout << "ret = " << ret << endl;
    // assert(ret == 1);

    // target = 7;
    // ret = var35.searchInsert(nums, target);
    // cout << "leetcode_35 expected result is 4 !" << endl;
    // cout << "ret = " << ret << endl;

    // target = 0;
    // ret = var35.searchInsert(nums, target);
    // cout << "leetcode_35 expected result is 0 !" << endl;
    // cout << "ret = " << ret << endl;

}


void leetcode_74() {
    cout << endl << "leetcode_74" << endl;
    // 搜索二维矩阵
    // type: medium
    // 给你一个满足下述两条属性的 m x n 整数矩阵：
    // 每行中的整数从左到右按非严格递增顺序排列。
    // 每行的第一个整数大于前一行的最后一个整数。
    // 给你一个整数 target ，如果 target 在矩阵中，返回 true ；否则，返回 false 。
    // 示例
    // 输入: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
    // 输出: true
    // url: https://leetcode.cn/problems/search-a-2d-matrix/description/?envType=study-plan-v2&envId=top-100-liked

    // 思路1：两次二分查找
    // 时间复杂度：O(log⁡m+log⁡n)=O(log⁡mn)，其中 m 和 n 分别是矩阵的行数和列数
    // 空间复杂度：O(1)。
    class Solution {
    public:
        bool searchMatrix(vector<vector<int>>& matrix, int target) {
            int m = matrix.size();
            int n = matrix[0].size();
            // cout << "m = " << m << endl;
            // cout << "n = " << n << endl;
            if (m == 1 && n == 1) {
                return target == matrix[0][0];
            }

            int rowIndex = 0;
            if (m != 1) {
                vector<int> firstInRow;
                // cout << "firstInRow = ";
                for (int i = 0; i < m; i++) {
                    firstInRow.push_back(matrix[i][0]);
                    // cout << matrix[i][0] << ", ";
                }
                // cout << endl;
                
                int left = 0;
                int right = m - 1; // 定义target在左闭右闭的区间里，[left, right]
                while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
                    int middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2
                    if (firstInRow[middle] > target) {
                        right = middle - 1; // target 在左区间，所以[left, middle - 1]
                    } else if (firstInRow[middle] < target) {
                        left = middle + 1; // target 在右区间，所以[middle + 1, right]
                    } else { // firstInRow[middle] == target
                        rowIndex = middle; // 数组中找到目标值，直接返回下标
                        break;
                    }
                    // 最终插入位置为left所在位置
                    rowIndex = right;   
                }
                // cout << "rowIndex = " << rowIndex << endl;
                // cout << "right = " << right << endl;
                if (rowIndex == -1) {
                    return false;
                }
            }

            if (n == 1) {
                return target == matrix[rowIndex][0];
            } else {
                // vector<int> rowData = matrix[rowIndex][:];        
                int leftInRow = 0;
                int rightInRow = n - 1; // 定义target在左闭右闭的区间里，[left, right]
                while (leftInRow <= rightInRow) { // 当left==right，区间[left, right]依然有效，所以用 <=
                    int middle = leftInRow + ((rightInRow - leftInRow) / 2);// 防止溢出 等同于(left + right)/2
                    if (matrix[rowIndex][middle] > target) {
                        rightInRow = middle - 1; // target 在左区间，所以[left, middle - 1]
                    } else if (matrix[rowIndex][middle] < target) {
                        leftInRow = middle + 1; // target 在右区间，所以[middle + 1, right]
                    } else { // firstInRow[middle] == target
                        // rowIndex = middle; // 数组中找到目标值，直接返回下标
                        return true;
                    }
                }
                // 最终插入位置为left所在位置
                return false;
            }
        }
    };

    vector<vector<int>> matrix = {{1,3,5,7},{10,11,16,20},{23,30,34,60}};
    int target = 11;

    Solution var74;
    bool ret = var74.searchMatrix(matrix, target);
    cout << "leetcode_74 expected result is true !" << endl;
    cout << "ret = " << ret << endl;

    matrix = {{1, 1}};
    target = 0;
    ret = var74.searchMatrix(matrix, target);
    cout << "leetcode_74 expected result is false !" << endl;
    cout << "ret = " << ret << endl;

    matrix = {{1, 1}};
    target = 1;
    ret = var74.searchMatrix(matrix, target);
    cout << "leetcode_74 expected result is true !" << endl;
    cout << "ret = " << ret << endl;

    matrix = {{1}, {3}};
    target = 1;
    ret = var74.searchMatrix(matrix, target);
    cout << "leetcode_74 expected result is true !" << endl;
    cout << "ret = " << ret << endl;

    // 思路2：一次二分查找
    // 若将矩阵每一行拼接在上一行的末尾，则会得到一个升序数组，我们可以在该数组上二分找到目标元素。
    // 代码实现时，可以二分升序数组的下标，将其映射到原矩阵的行和列上。

}


void leetcode_33() {


}


void leetcode_153() {

}


void leetcode_4() {

}


void leetcode_69() {
    cout << endl << "leetcode_69" << endl;
    // x的平方根
    // type: simple
    // 给你一个非负整数 x ，计算并返回 x 的 算术平方根 。
    // 由于返回类型是整数，结果只保留 整数部分 ，小数部分将被 舍去 。
    // 注意：不允许使用任何内置指数函数和算符，例如 pow(x, 0.5) 或者 x ** 0.5 。
    // 输入: x = 8
    // 输出: 2
    // 解释: 8 的算术平方根是 2.82842..., 由于返回类型是整数，小数部分将被舍去。
    // leetcode url: https://leetcode.cn/problems/sqrtx/description/
    
    
    class Solution {
    public:
        // 左闭右闭写法
        // 时间复杂度：O(log n)
        // 空间复杂度：O(1)
        int mySqrt(int x) {
            int left = 0;
            int right = x; // 右界先置为输入值
            while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
                long long middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2, 先置为long long
                if (middle * middle > x) {
                    right = middle - 1; // middle的平方在左区间，所以[left, middle - 1]
                } else if (middle * middle < x) {
                    left = middle + 1; // middle的平方在右区间，所以[middle + 1, right]
                } else { // middle * middle == num
                    return middle; // 找到完全平方数，返回true
                }
            }
            // 未找到平方数
            return right;
        }
    };

    int num = 9;
    Solution var69;
    int ret = var69.mySqrt(num);
    cout << "leetcode_69 expected result is 3 !" << endl;
    cout << "ret = " << ret << endl;

    num = 101;
    ret = var69.mySqrt(num);
    cout << "leetcode_69 expected result is 10 !" << endl;
    cout << "ret = " << ret << endl;
}


void leetcode_367() {
    cout << endl << "leetcode_367" << endl;
    // 有效的完全平方数
    // type: simple
    // 给你一个正整数 num 。如果 num 是一个完全平方数，则返回 true ，否则返回 false 。
    // 完全平方数 是一个可以写成某个整数的平方的整数。换句话说，它可以写成某个整数和自身的乘积。
    // 不能使用任何内置的库函数，如  sqrt 。
    // 输入: num = 16
    // 输出: true
    // 解释: 返回 true ，因为 4 * 4 = 16 且 4 是一个整数。
    // leetcode url: https://leetcode.cn/problems/valid-perfect-square/description/

    class Solution {
    public:
        bool isPerfectSquare(int num) {
            int left = 1;
            int right = num; // 右界先置为输入值
            while (left <= right) { // 当left==right，区间[left, right]依然有效，所以用 <=
                long long middle = left + ((right - left) / 2);// 防止溢出 等同于(left + right)/2, 先置为long long
                if (middle * middle > num) {
                    right = middle - 1; // middle的平方在左区间，所以[left, middle - 1]
                } else if (middle * middle < num) {
                    left = middle + 1; // middle的平方在右区间，所以[middle + 1, right]
                } else { // middle * middle == num
                    return true; // 找到完全平方数，返回true
                }
            }
            // 未找到平方数
            return false;
        }
    };
    // 时间复杂度：O(log⁡n)，其中 n 为正整数 num 的最大值。
    // 空间复杂度：O(1)

    int num = 9;
    Solution var367;
    bool ret = var367.isPerfectSquare(num);
    cout << "leetcode_367 expected result is true !" << endl;
    cout << "ret = " << ret << endl;

    num = 10;
    ret = var367.isPerfectSquare(num);
    cout << "leetcode_367 expected result is false !" << endl;
    cout << "ret = " << ret << endl;
}





