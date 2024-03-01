#include "common.h"
#include "hash_table.h"
#include <assert.h>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using std::vector;
using std::string;
using std::unordered_set;
using std::unordered_map;
using std::pair;
// using std::sort;

void leetcode_242();
void leetcode_383();
void leetcode_49();
void leetcode_438();

void leetcode_349();
void leetcode_350();

void leetcode_202();

void leetcode_1();

void leetcode_454();

void leetcode_15();

void leetcode_18();


int hash_table_main() {
    cout << endl << "hash_table_main" << endl << endl;;

    // Carl Lessons
    leetcode_242();  // simple
    leetcode_349();  // simple
    leetcode_202();  // simple
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


void leetcode_242() {
    cout << endl << "leetcode_242" << endl;
    // 有效的字母异位词
    // type: simple
    // 给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的字母异位词。
    // 注意：若 s 和 t 中每个字符出现的次数都相同，则称 s 和 t 互为字母异位词。
    // s 和 t 仅包含小写字母
    // 输入: s = "anagram", t = "nagaram"
    // 输出: true
    // url: https://www.programmercarl.com/0242.%E6%9C%89%E6%95%88%E7%9A%84%E5%AD%97%E6%AF%8D%E5%BC%82%E4%BD%8D%E8%AF%8D.html

    class Solution {
    public:
        bool isAnagram(string s, string t) {
            // 方法一，暴力法

            // 方法二，哈希法
            // 定义一个数组叫做record用来上记录字符串s里字符出现的次数。
            // 需要把字符映射到数组也就是哈希表的索引下标上，因为字符a到字符z的ASCII是26个连续的数值，所以字符a映射为下标0，相应的字符z映射为下标25。
            // 再遍历 字符串s的时候，只需要将 s[i] - ‘a’ 所在的元素做+1 操作即可，并不需要记住字符a的ASCII，只要求出一个相对数值就可以了。 
            // 这样就将字符串s中字符出现的次数，统计出来了。
            // 那看一下如何检查字符串t中是否出现了这些字符，同样在遍历字符串t的时候，对t中出现的字符映射哈希表索引上的数值再做-1的操作。
            // 那么最后检查一下，record数组如果有的元素不为零0，说明字符串s和t一定是谁多了字符或者谁少了字符，return false。
            // 最后如果record数组所有元素都为零0，说明字符串s和t是字母异位词，return true。
            // 时间复杂度为O(n)，空间上因为定义是的一个常量大小的辅助数组，所以空间复杂度为O(1)。
            int record[26] = {0};
            for (int i = 0; i < s.size(); i++) {
                // 并不需要记住字符a的ASCII，只要求出一个相对数值就可以了
                record[s[i] - 'a']++;
            }
            for (int j = 0; j < t.size(); j++) {
                record[t[j] - 'a']--;
            }
            for (int k = 0; k < 26; k++) {
                // record数组如果有的元素不为零0，说明字符串s和t 一定是谁多了字符或者谁少了字符。
                if (record[k] != 0) {
                    return false;
                }
            }
            // record数组所有元素都为零0，说明字符串s和t是字母异位词
            return true;
        }
    };
}


void leetcode_349() {
    cout << endl << "leetcode_349" << endl;
    // 两个数组的交集
    // type: simple
    // 给定两个数组 nums1 和 nums2 ，返回 它们的交集 。输出结果中的每个元素一定是 唯一 的。我们可以 不考虑输出结果的顺序 。
    // 输入: nums1 = [1,2,2,1], nums2 = [2,2]
    // 输出: [2]
    // url: https://www.programmercarl.com/0349.%E4%B8%A4%E4%B8%AA%E6%95%B0%E7%BB%84%E7%9A%84%E4%BA%A4%E9%9B%86.html#%E7%AE%97%E6%B3%95%E5%85%AC%E5%BC%80%E8%AF%BE

    class Solution {
    public:
        vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
            // 这道题目，主要要学会使用一种哈希数据结构：unordered_set，这个数据结构可以解决很多类似的问题。
            // 注意题目特意说明：输出结果中的每个元素一定是唯一的，也就是说输出的结果的去重的， 同时可以不考虑输出结果的顺序
            // 时间复杂度: O(n + m) m 是最后要把 set转成vector
            // 空间复杂度: O(n)
            unordered_set<int> result_set;  // 存放结果，之所以用set是为了给结果集去重
            unordered_set<int> nums_set(nums1.begin(), nums1.end());
            for (int num : nums2) {
                // 发现nums2的元素 在nums_set里又出现过
                // find返回的是迭代器的指针，如果没有找到，则返回尾指针，即end()
                if (nums_set.find(num) != nums_set.end()) {
                    result_set.insert(num);
                }
            }
            return vector<int>(result_set.begin(), result_set.end());
        }

        vector<int> intersection_with_list(vector<int>& nums1, vector<int>& nums2) {
            // 本题后面 力扣改了 题目描述 和 后台测试数据，增添了 数值范围：
            // 1 <= nums1.length, nums2.length <= 1000
            // 0 <= nums1[i], nums2[i] <= 1000
            // 所以就可以 使用数组来做哈希表了， 因为数组都是 1000以内的。
            // 时间复杂度: O(n + m) m 是最后要把 set转成vector
            // 空间复杂度: O(n)
            unordered_set<int> result_set;  // 存放结果，之所以用set是为了给结果集去重
            int hash[1005] = {0}; // 默认数值为0
            for (int num : nums1) {  // nums1中出现的字母在hash数组中做记录
                hash[num] = 1;
            }
            for (int num : nums2) { // nums2中出现话，result记录
                if (hash[num] == 1) {
                    result_set.insert(num);
                }
            }
            return vector<int>(result_set.begin(), result_set.end());
        }
    };
}


void leetcode_202() {
    cout << endl << "leetcode_202" << endl;
    // 快乐数
    // type: simple
    // 编写一个算法来判断一个数 n 是不是快乐数。
    // 「快乐数」 定义为：
    // 对于一个正整数，每一次将该数替换为它每个位置上的数字的平方和。
    // 然后重复这个过程直到这个数变为 1，也可能是 无限循环 但始终变不到 1。
    // 如果这个过程 结果为 1，那么这个数就是快乐数。
    // 如果 n 是 快乐数 就返回 true ；不是，则返回 false 。
    // 输入: n = 19
    // 输出: true
    // url: https://www.programmercarl.com/0202.%E5%BF%AB%E4%B9%90%E6%95%B0.html#%E6%80%9D%E8%B7%AF

    class Solution {
    public:
        bool isHappy(int n) {
            // 时间复杂度: O(logn)
            // 空间复杂度: O(logn)
            unordered_set<int> result_set;
            while (1) {
                int sum = getSum(n);
                if (sum == 1) {return true;}
                // 如果这个sum曾经出现过，说明已经陷入了无限循环了，立刻return false
                if (result_set.find(sum) != result_set.end()) {
                    return false;
                } else {
                    result_set.insert(sum);
                }
                n = sum;
            }

        }
    private:
        // 取数值各个位上的单数之和
        int getSum(int n) {
            int sum = 0;
            while (n) {
                sum += (n % 10) * (n % 10);
                n /= 10;
            }
            return sum;
        }
    };

    
    int target = 19;
    Solution var202;
    bool ret = var202.isHappy(target);
    cout << "leetcode_202 expected result is 1 !" << endl;
    cout << "ret = " << ret << endl;

    ret = var202.isHappy(16);
    cout << "leetcode_202 expected result is 0 !" << endl;
    cout << "ret = " << ret << endl;
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



