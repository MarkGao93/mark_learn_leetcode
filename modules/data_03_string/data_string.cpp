#include "common.h"
#include "data_string.h"
#include <string>
// #include <assert.h>
#include <algorithm>
#include <queue>
// #include <unordered_set>
#include <unordered_map>
using std::vector;
using std::string;
// using std::unordered_set;
using std::unordered_map;
using std::pair;
// using std::sort;
using std::swap;
// using std::reverse;


void leetcode_344();
void leetcode_541();
void leetcode_151();

void leetcode_438();

void leetcode_349();
void leetcode_350();

void leetcode_202();

void leetcode_1();

void leetcode_454();
void leetcode_383();

void leetcode_15();

void leetcode_18();


int data_string_main() {
    cout << endl << "data_string_main" << endl << endl;;

    // Carl Lessons
    leetcode_344();  // simple
    leetcode_541();  // simple
    leetcode_151();  // simple
    leetcode_1();  // simple
    leetcode_454();  // medium
    leetcode_15();  // medium
    leetcode_18();  // medium

    leetcode_383();  // simple
    
    // leetcode_438();  // medium
    // leetcode_350();  // simple

    // LeetCode hot 100
    
    

    return 0;
}


void leetcode_344() {
    cout << endl << "leetcode_344" << endl;
    // 反转字符串
    // type: simple
    // 编写一个函数，其作用是将输入的字符串反转过来。输入字符串以字符数组 s 的形式给出。
    // 不要给另外的数组分配额外的空间，你必须原地修改输入数组、使用 O(1) 的额外空间解决这一问题。
    // 输入: s = ["h","e","l","l","o"]
    // 输出: ["o","l","l","e","h"]
    // url: https://www.programmercarl.com/0344.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        void reverseString(vector<char>& s) {
            for (int i = 0, j = s.size() - 1; i < s.size() / 2; i++, j--) {
                swap(s[i], s[j]);
            }
        }
        // 时间复杂度: O(n)
        // 空间复杂度: O(1)
    };
}


void leetcode_541() {
    cout << endl << "leetcode_541" << endl;
    // 反转字符串II
    // type: simple
    // 给定一个字符串 s 和一个整数 k，从字符串开头算起，每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符。
    // 如果剩余字符少于 k 个，则将剩余字符全部反转。
    // 如果剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符，其余字符保持原样。
    // 输入: s = "abcdefg", k = 2
    // 输出: "bacdfeg"
    // url: https://www.programmercarl.com/0541.%E5%8F%8D%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2II.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        string reverseStr(string s, int k) {
            for (int i = 0; i < s.size(); i += (2 * k)) {
                // 1. 每隔 2k 个字符的前 k 个字符进行反转
                // 2. 剩余字符小于 2k 但大于或等于 k 个，则反转前 k 个字符
                if (i + k <= s.size()) {
                    reverse(s.begin() + i, s.begin() + i + k);
                } else {
                    reverse(s.begin() + i, s.end());
                }
            }
            return s;
        }
        // 时间复杂度: O(n)
        // 空间复杂度: O(1)
    };
}


void leetcode_151() {
    cout << endl << "leetcode_151" << endl;
    // 翻转字符串里的单词
    // type: medium
    // 给你一个字符串 s ，请你反转字符串中 单词 的顺序。
    // 单词 是由非空格字符组成的字符串。s 中使用至少一个空格将字符串中的 单词 分隔开。
    // 返回 单词 顺序颠倒且 单词 之间用单个空格连接的结果字符串。
    // 注意：输入字符串 s中可能会存在前导空格、尾随空格或者单词间的多个空格。
    // 返回的结果字符串中，单词间应当仅用单个空格分隔，且不包含任何额外的空格。
    // 输入: s = "the sky is blue"
    // 输出: "blue is sky the"
    // url: https://www.programmercarl.com/0151.%E7%BF%BB%E8%BD%AC%E5%AD%97%E7%AC%A6%E4%B8%B2%E9%87%8C%E7%9A%84%E5%8D%95%E8%AF%8D.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        string reverseWords(string s) {
            
        }
    };

    
    // int target = 19;
    // Solution var202;
    // bool ret = var202.isHappy(target);
    // cout << "leetcode_202 expected result is 1 !" << endl;
    // cout << "ret = " << ret << endl;

    // ret = var202.isHappy(16);
    // cout << "leetcode_202 expected result is 0 !" << endl;
    // cout << "ret = " << ret << endl;
}


void leetcode_1() {
    cout << endl << "leetcode_1" << endl;
    // 两数之和
    // type: simple
    // 给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 
    // 和为目标值 target  的那 两个 整数，并返回它们的数组下标。
    // 你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
    // 你可以按任意顺序返回答案。
    // 输入: nums = [2,7,11,15], target = 9
    // 输出: [0,1]
    // url: https://www.programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        vector<int> twoSum(vector<int>& nums, int target) {
            unordered_map<int, int> result_map;
            for (int i = 0; i < nums.size(); i++) {
                // 遍历当前元素，并在map中寻找是否有匹配的key
                auto iter = result_map.find(target - nums[i]);
                if (iter != result_map.end()) {
                    return {iter->second, i};
                }

                // 如果没找到匹配对，就把访问过的元素和下标加入到map中
                result_map.insert(pair<int, int>(nums[i], i));
            }
            return {};
        }
        // 时间复杂度: O(n)
        // 空间复杂度: O(n)
        // 本题其实有四个重点：
        // 为什么会想到用哈希表
        // 哈希表为什么用map
        // 本题map是用来存什么的
        // map中的key和value用来存什么的
    };

    
    // int target = 19;
    // Solution var202;
    // bool ret = var202.isHappy(target);
    // cout << "leetcode_202 expected result is 1 !" << endl;
    // cout << "ret = " << ret << endl;

    // ret = var202.isHappy(16);
    // cout << "leetcode_202 expected result is 0 !" << endl;
    // cout << "ret = " << ret << endl;
}


void leetcode_454() {
    cout << endl << "leetcode_454" << endl;
    // 四数之和II
    // type: medium
    // 给你四个整数数组 nums1、nums2、nums3 和 nums4 ，数组长度都是 n ，请你计算有多少个元组 (i, j, k, l) 能满足：
    // 0 <= i, j, k, l < n
    // nums1[i] + nums2[j] + nums3[k] + nums4[l] == 0
    // 输入: nums1 = [1,2], nums2 = [-2,-1], nums3 = [-1,2], nums4 = [0,2]
    // 输出: 2
    // url: https://www.programmercarl.com/0001.%E4%B8%A4%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
            // 本题解题步骤：
            // 首先定义 一个unordered_map，key放a和b两数之和，value 放a和b两数之和出现的次数。
            // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中。
            // 定义int变量count，用来统计 a+b+c+d = 0 出现的次数。
            // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就用count把map中key对应的value也就是出现次数统计出来。
            // 最后返回统计值 count 就可以了
            // 时间复杂度: O(n^2)
            // 空间复杂度: O(n^2)，最坏情况下A和B的值各不相同，相加产生的数字个数为 n^2

            unordered_map<int, int> sumAB_map;  //key:a+b的数值，value:a+b数值出现的次数
            int count_num = 0;  // 统计a+b+c+d = 0 出现的次数
            // 遍历大A和大B数组，统计两个数组元素之和，和出现的次数，放到map中
            for (int a : nums1) {
                for (int b : nums2) {
                    sumAB_map[a + b]++;
                }
            }
            // 在遍历大C和大D数组，找到如果 0-(c+d) 在map中出现过的话，就把map中key对应的value也就是出现次数统计出来。
            for (int c : nums3) {
                for (int d : nums4) {
                    if (sumAB_map.find(0 - (c + d)) != sumAB_map.end()) {
                        count_num += sumAB_map[0 - (c + d)];
                    }                    
                }
            }
            return count_num;
        }
    };

    
    // int target = 19;
    // Solution var202;
    // bool ret = var202.isHappy(target);
    // cout << "leetcode_202 expected result is 1 !" << endl;
    // cout << "ret = " << ret << endl;

    // ret = var202.isHappy(16);
    // cout << "leetcode_202 expected result is 0 !" << endl;
    // cout << "ret = " << ret << endl;
}


void leetcode_383() {
    cout << endl << "leetcode_383" << endl;
    // 赎金信
    // type: simple
    // 给你两个字符串：ransomNote 和 magazine ，判断 ransomNote 能不能由 magazine 里面的字符构成。
    // 如果可以，返回 true ；否则返回 false 。
    // magazine 中的每个字符只能在 ransomNote 中使用一次。
    // 输入: ransomNote = "a", magazine = "b"
    // 输出: false
    // 输入：ransomNote = "aa", magazine = "aab"
    // 输出：true
    // url: https://www.programmercarl.com/0383.%E8%B5%8E%E9%87%91%E4%BF%A1.html#%E6%80%9D%E8%B7%AF

    class Solution {
    public:
        bool canConstruct(string ransomNote, string magazine) {
            // 思路一，暴力解法
            /*
            for (int i = 0; i < magazine.length(); i++) {
                for (int j = 0; j < ransomNote.length(); j++) {
                    // 在ransomNote中找到和magazine相同的字符
                    if (magazine[i] == ransomNote[j]) {
                        ransomNote.erase(ransomNote.begin() + j); // ransomNote删除这个字符
                        break;
                    }
                }
            }
            // 如果ransomNote为空，则说明magazine的字符可以组成ransomNote
            if (ransomNote.length() == 0) {
                return true;
            }
            return false;
            */
            // 时间复杂度: O(n^2)
            // 空间复杂度: O(1)

            // 思路二，数组哈希法
            // 开辟数组用于存储每个字母的出现次数
            int record[26] = {0};
            // 情况一：如果magazine的字符少，不可能满足要求
            if (ransomNote.size() > magazine.size()) {
                return false;
            }
            for (int i = 0; i < magazine.length(); i++) {
                // 通过record数据记录 magazine里各个字符出现次数
                record[magazine[i]-'a'] ++;
            }
            for (int j = 0; j < ransomNote.length(); j++) {
                // 遍历ransomNote，在record里对应的字符个数做--操作
                record[ransomNote[j]-'a']--;
                // 如果小于零说明ransomNote里出现的字符，magazine没有
                if(record[ransomNote[j]-'a'] < 0) {
                    return false;
                }
            }
            return true;
            // 时间复杂度: O(n)
            // 空间复杂度: O(1)

            // 在C++中，std::string类有两个成员函数可以用于获取字符串的长度：size()和length()。
            // 这两个函数的功能是相同的，它们都返回字符串中字符的数量（不包括结尾的null字符）。
            // 这两个函数的区别只是名称不同，其功能是相同的，都用于返回字符串中字符的数量。
            // 在实际使用中，size()和length()可以互换使用。但更倾向于使用size()，因为它在STL容器中被广泛使用，并且也被一些其他的STL容器和算法使用。
        }
    };

    
    // int target = 19;
    // Solution var202;
    // bool ret = var202.isHappy(target);
    // cout << "leetcode_202 expected result is 1 !" << endl;
    // cout << "ret = " << ret << endl;

    // ret = var202.isHappy(16);
    // cout << "leetcode_202 expected result is 0 !" << endl;
    // cout << "ret = " << ret << endl;
}


void leetcode_15() {
    cout << endl << "leetcode_15" << endl;
    // 三数之和
    // type: medium
    // 给你一个整数数组 nums ，判断是否存在三元组 [nums[i], nums[j], nums[k]] 满足 i != j、i != k 且 j != k ，
    // 同时还满足 nums[i] + nums[j] + nums[k] == 0 。请
    // 你返回所有和为 0 且不重复的三元组。
    // 输入: nums = [-1,0,1,2,-1,-4]
    // 输出: [[-1,-1,2],[-1,0,1]]
    // url: https://www.programmercarl.com/0015.%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            // 思路一：哈希set法，不建议
            /*
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            // 找出a + b + c = 0
            // a = nums[i], b = nums[j], c = -(a + b)
            for (int i = 0; i < nums.size(); i++) {
                // 排序之后如果第一个元素已经大于零，那么不可能凑成三元组
                if (nums[i] > 0) {
                    break;
                }
                if (i > 0 && nums[i] == nums[i - 1]) { //三元组元素a去重
                    continue;
                }
                unordered_set<int> set;
                for (int j = i + 1; j < nums.size(); j++) {
                    if (j > i + 2
                            && nums[j] == nums[j-1]
                            && nums[j-1] == nums[j-2]) { // 三元组元素b去重
                        continue;
                    }
                    int c = 0 - (nums[i] + nums[j]);
                    if (set.find(c) != set.end()) {
                        result.push_back({nums[i], nums[j], c});
                        set.erase(c);// 三元组元素c去重
                    } else {
                        set.insert(nums[j]);
                    }
                }
            }
            return result;
            */
            // 时间复杂度: O(n^2)
            // 空间复杂度: O(n)，额外的 set 开销

            // 思路二：双指针法
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            // 找出a + b + c = 0
            // a = nums[i], b = nums[left], c = nums[right]
            for (int i = 0; i < nums.size(); i++) {
                // 排序之后如果第一个元素已经大于零，那么无论如何组合都不可能凑成三元组，直接返回结果就可以了
                if (nums[i] > 0) {
                    return result;
                }
                // 错误去重a方法，将会漏掉-1,-1,2 这种情况
                /*
                if (nums[i] == nums[i + 1]) {
                    continue;
                }
                */
                // 正确去重a方法
                if (i > 0 && nums[i] == nums[i - 1]) {
                    continue;
                }
                int left = i + 1;
                int right = nums.size() - 1;
                while (right > left) {
                    // 去重复逻辑如果放在这里，0，0，0 的情况，可能直接导致 right<=left 了，从而漏掉了 0,0,0 这种三元组
                    /*
                    while (right > left && nums[right] == nums[right - 1]) right--;
                    while (right > left && nums[left] == nums[left + 1]) left++;
                    */
                    if (nums[i] + nums[left] + nums[right] > 0) right--;
                    else if (nums[i] + nums[left] + nums[right] < 0) left++;
                    else {
                        result.push_back(vector<int>{nums[i], nums[left], nums[right]});
                        // 去重逻辑应该放在找到一个三元组之后，对b 和 c去重
                        while (right > left && nums[right] == nums[right - 1]) right--;
                        while (right > left && nums[left] == nums[left + 1]) left++;

                        // 找到答案时，双指针同时收缩
                        right--;
                        left++;
                    }
                }

            }
            return result;
            // 时间复杂度: O(n^2)
            // 空间复杂度: O(1)
        }
    };

    
    // int target = 19;
    // Solution var202;
    // bool ret = var202.isHappy(target);
    // cout << "leetcode_202 expected result is 1 !" << endl;
    // cout << "ret = " << ret << endl;

    // ret = var202.isHappy(16);
    // cout << "leetcode_202 expected result is 0 !" << endl;
    // cout << "ret = " << ret << endl;
}


void leetcode_18() {
    cout << endl << "leetcode_18" << endl;
    // 四数之和
    // type: medium
    // 给你一个由 n 个整数组成的数组 nums ，和一个目标值 target 。
    // 请你找出并返回满足下述全部条件且不重复的四元组 [nums[a], nums[b], nums[c], nums[d]] 
    // （若两个四元组元素一一对应，则认为两个四元组重复）：
    // 0 <= a, b, c, d < n
    // a、b、c 和 d 互不相同
    // nums[a] + nums[b] + nums[c] + nums[d] == target
    // 你可以按 任意顺序 返回答案 。
    // 输入: nums = [1,0,-1,0,-2,2], target = 0
    // 输出: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]
    // url: https://www.programmercarl.com/0018.%E5%9B%9B%E6%95%B0%E4%B9%8B%E5%92%8C.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        vector<vector<int>> fourSum(vector<int>& nums, int target) {
            // 四数之和和15.三数之和是一个思路，都是使用双指针法, 基本解法就是在三数之和的基础上再套一层for循环。
            // 15.三数之和的双指针解法是一层for循环num[i]为确定值，然后循环内有left和right下标作为双指针，
            //   找到nums[i] + nums[left] + nums[right] == 0。
            // 四数之和的双指针解法是两层for循环nums[k] + nums[i]为确定值，依然是循环内有left和right下标作为双指针，
            //   找出nums[k] + nums[i] + nums[left] + nums[right] == target的情况，
            // 三数之和的时间复杂度是O(n^2)，四数之和的时间复杂度是O(n^3) 。
            // 那么一样的道理，五数之和、六数之和等等都采用这种解法。

            // 双指针法
            vector<vector<int>> result;
            sort(nums.begin(), nums.end());
            for (int k = 0; k < nums.size(); k++) {
                // 剪枝处理
                if (nums[k] > target && nums[k] >= 0) {
                    break; // 这里使用break，统一通过最后的return返回
                }
                // 对nums[k]去重
                if (k > 0 && nums[k] == nums[k - 1]) {
                    continue;
                }
                for (int i = k + 1; i < nums.size(); i++) {
                    // 2级剪枝处理
                    if (nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) {
                        break;
                    }

                    // 对nums[i]去重
                    if (i > k + 1 && nums[i] == nums[i - 1]) {
                        continue;
                    }
                    int left = i + 1;
                    int right = nums.size() - 1;
                    while (right > left) {
                        // nums[k] + nums[i] + nums[left] + nums[right] > target 会溢出
                        if ((long) nums[k] + nums[i] + nums[left] + nums[right] > target) {
                            right--;
                        // nums[k] + nums[i] + nums[left] + nums[right] < target 会溢出
                        } else if ((long) nums[k] + nums[i] + nums[left] + nums[right]  < target) {
                            left++;
                        } else {
                            result.push_back(vector<int>{nums[k], nums[i], nums[left], nums[right]});
                            // 对nums[left]和nums[right]去重
                            while (right > left && nums[right] == nums[right - 1]) right--;
                            while (right > left && nums[left] == nums[left + 1]) left++;

                            // 找到答案时，双指针同时收缩
                            right--;
                            left++;
                        }
                    }

                }
            }
            return result;
            // 时间复杂度: O(n^3)
            // 空间复杂度: O(1)
        }
    };

    
    // int target = 19;
    // Solution var202;
    // bool ret = var202.isHappy(target);
    // cout << "leetcode_202 expected result is 1 !" << endl;
    // cout << "ret = " << ret << endl;

    // ret = var202.isHappy(16);
    // cout << "leetcode_202 expected result is 0 !" << endl;
    // cout << "ret = " << ret << endl;
}



