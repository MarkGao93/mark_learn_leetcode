#include "dynamic_programming.h"
#include "common.h"

using std::vector;
using std::min;
using std::max;

void leetcode_509();
void leetcode_70();
void leetcode_746();
void leetcode_62();
void leetcode_63();
void leetcode_343();
void leetcode_96();


int dynamic_programming_main() {
    cout << endl << "dynamic_programming_main" << endl;    

    // 基础题目
    leetcode_509();
    leetcode_70();
    leetcode_746();
    leetcode_62();
    leetcode_63();
    leetcode_343();
    leetcode_96();
}


///////////////////////////////////////////////////////////////////////////////
// 斐波那契数, simple, 
///////////////////////////////////////////////////////////////////////////////
void leetcode_509() {
    cout << endl << "leetcode_509" << endl;    
    // 斐波那契数 （通常用 F(n) 表示）形成的序列称为 斐波那契数列 。
    // 该数列由 0 和 1 开始，后面的每一项数字都是前面两项数字的和。也就是：
    // F(0) = 0，F(1) = 1
    // F(n) = F(n - 1) + F(n - 2)，其中 n > 1
    // 给定 n ，请计算 F(n) 。
    // 输入：n = 4
    // 输出：3
    // 解释：F(4) = F(3) + F(2) = 2 + 1 = 3
    // 提示：0 <= n <= 30
    // Carl: https://www.programmercarl.com/0509.%E6%96%90%E6%B3%A2%E9%82%A3%E5%A5%91%E6%95%B0.html
    // leetcode: https://leetcode.cn/problems/fibonacci-number/description/

    class Solution {
    public:
        // 方法一：递归法
        int fib_1(int n) {
            if (n <= 1) return n;
            return fib_1(n - 1) + fib_1(n - 2);
        }
        // 时间复杂度：O(2^n)
        // 空间复杂度：O(n)，算上了编程语言中实现递归的系统栈所占空间

        // 方法二：动态规划法
        int fib_2(int n) {
            // 动规五部曲：
            // 这里我们要用一个一维dp数组来保存递归的结果
            // 1. 确定dp数组以及下标的含义
            // dp[i]的定义为：第i个数的斐波那契数值是dp[i]
            // 2. 确定递推公式
            // 题目已经把递推公式直接给我们了：状态转移方程 dp[i] = dp[i - 1] + dp[i - 2];
            // 3. dp数组如何初始化
            // 题目中把如何初始化也直接给我们了
            // dp[0] = 0;
            // dp[1] = 1;
            // 4. 确定遍历顺序
            // 从递归公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，
            // dp[i]是依赖 dp[i - 1] 和 dp[i - 2]，那么遍历的顺序一定是从前到后遍历的
            // 5. 举例推导dp数组
            // 按照这个递推公式dp[i] = dp[i - 1] + dp[i - 2]，我们来推导一下，
            // 当N为10的时候，dp数组应该是如下的数列： 0 1 1 2 3 5 8 13 21 34 55

            if (n <= 1) return n;
            vector<int> dp(n + 1);
            dp[0] = 0;
            dp[1] = 1;
            for (int i = 2; i <= n; ++i) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
        // 时间复杂度：O(n)
        // 空间复杂度：O(n), 可以用dp[0]和dp[1]迭代更新dp[1]和前缀和，实现空间复杂度O(1)
    };

    int target = 19;
    Solution var509;
    int ret = var509.fib_2(target);
    cout << "leetcode_509 expected result is 4181 !" << endl;
    cout << "ret = " << ret << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 爬楼梯, simple, Hot100
///////////////////////////////////////////////////////////////////////////////
void leetcode_70() {
    cout << endl << "leetcode_70" << endl;    
    // 假设你正在爬楼梯。需要 n 阶你才能到达楼顶。
    // 每次你可以爬 1 或 2 个台阶。你有多少种不同的方法可以爬到楼顶呢？
    // 输入：n = 3
    // 输出：3
    // 解释：有三种方法可以爬到楼顶。1 阶 + 1 阶 + 1 阶，1 阶 + 2 阶，2 阶 + 1 阶
    // 提示：1 <= n <= 45
    // Carl: https://www.programmercarl.com/0070.%E7%88%AC%E6%A5%BC%E6%A2%AF.html
    // leetcode: https://leetcode.cn/problems/climbing-stairs/description/

    class Solution {
    public:
        // 方法一：动态规划法
        int climbStairs(int n) {
            // 本题大家如果没有接触过的话，会感觉比较难，多举几个例子，就可以发现其规律。
            // 爬到第一层楼梯有一种方法，爬到二层楼梯有两种方法。
            // 那么第一层楼梯再跨两步就到第三层 ，第二层楼梯再跨一步就到第三层。
            // 所以到第三层楼梯的状态可以由第二层楼梯 和 到第一层楼梯状态推导出来，那么就可以想到动态规划了。
            // 动规五部曲：
            // 定义一个一维数组来记录不同楼层的状态
            // 1. 确定dp数组以及下标的含义
            // dp[i]的定义为：到达第i阶有dp[i]种方法
            // 2. 确定递推公式
            // 从dp[i]的定义可以看出，dp[i] 可以有两个方向推出来。
            // 首先是dp[i - 1]，上i-1层楼梯，有dp[i - 1]种方法，那么再一步跳一个台阶不就是dp[i]了么。
            // 还有就是dp[i - 2]，上i-2层楼梯，有dp[i - 2]种方法，那么再一步跳两个台阶不就是dp[i]了么。
            // 那么dp[i]就是 dp[i - 1]与dp[i - 2]之和！
            // 状态转移方程 dp[i] = dp[i - 1] + dp[i - 2];
            // 3. dp数组如何初始化
            // dp[1] = 1;
            // dp[2] = 2;
            // 4. 确定遍历顺序
            // 从递归公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，
            // dp[i]是依赖 dp[i - 1] 和 dp[i - 2]，那么遍历的顺序一定是从前到后遍历的
            // 5. 举例推导dp数组
            // 按照这个递推公式dp[i] = dp[i - 1] + dp[i - 2]，我们来推导一下，
            // 当N为5的时候，dp数组应该是如下的数列：1 2 3 5 8

            if (n <= 2) return n;
            vector<int> dp(n + 1);
            dp[1] = 1;
            dp[2] = 2;
            for (int i = 3; i <= n; ++i) {
                dp[i] = dp[i - 1] + dp[i - 2];
            }
            return dp[n];
        }
        // 时间复杂度：O(n)
        // 空间复杂度：O(n), 可以用dp[1]和dp[2]迭代更新dp[2]和前缀和，实现空间复杂度O(1)
    };

    int target = 19;
    Solution var70;
    int ret = var70.climbStairs(target);
    cout << "leetcode_70 expected result is 6765 !" << endl;
    cout << "ret = " << ret << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 使用最小花费爬楼梯, simple, 
///////////////////////////////////////////////////////////////////////////////
void leetcode_746() {
    cout << endl << "leetcode_746" << endl;    
    // 给你一个整数数组 cost ，其中 cost[i] 是从楼梯第 i 个台阶向上爬需要支付的费用。
    // 一旦你支付此费用，即可选择向上爬一个或者两个台阶。
    // 你可以选择从下标为 0 或下标为 1 的台阶开始爬楼梯。
    // 请你计算并返回达到楼梯顶部的最低花费。
    // 输入：cost = [10,15,20]
    // 输出：15
    // 解释：你将从下标为 1 的台阶开始。- 支付 15 ，向上爬两个台阶，到达楼梯顶部。总花费为 15 。
    // 提示：2 <= cost.length <= 1000，0 <= cost[i] <= 999
    // Carl: https://www.programmercarl.com/0746.%E4%BD%BF%E7%94%A8%E6%9C%80%E5%B0%8F%E8%8A%B1%E8%B4%B9%E7%88%AC%E6%A5%BC%E6%A2%AF.html
    // leetcode: https://leetcode.cn/problems/min-cost-climbing-stairs/description/

    class Solution {
    public:
        // 方法一：动态规划法
        int minCostClimbingStairs(vector<int>& cost) {
            // 动规五部曲：
            // 1. 确定dp数组以及下标的含义
            // dp[i]的定义为：到达第i台阶所花费的最少体力为dp[i]
            // 2. 确定递推公式
            // 可以有两个途径得到dp[i]，一个是dp[i-1] 一个是dp[i-2]。
            // dp[i - 1] 跳到 dp[i] 需要花费 dp[i - 1] + cost[i - 1]。
            // dp[i - 2] 跳到 dp[i] 需要花费 dp[i - 2] + cost[i - 2]。
            // 那么究竟是选从dp[i - 1]跳还是从dp[i - 2]跳呢？
            // 一定是选最小的，所以dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            // 3. dp数组如何初始化
            // 看一下递归公式，dp[i]由dp[i - 1]，dp[i - 2]推出，既然初始化所有的dp[i]是不可能的，
            // 那么只初始化dp[0]和dp[1]就够了，其他的最终都是dp[0]dp[1]推出。
            // dp[0] = 0;
            // dp[1] = 0;
            // 4. 确定遍历顺序
            // 从递归公式dp[i] = dp[i - 1] + dp[i - 2];中可以看出，
            // dp[i]是依赖 dp[i - 1] 和 dp[i - 2]，那么遍历的顺序一定是从前到后遍历的
            // 5. 举例推导dp数组
            // 拿示例2：cost = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1] ，来模拟一下dp数组的状态变化，如下：
            // cost：  1, 100, 1, 1, 1, 100, 1, 1, 100, 1
            // dp数组：0,  0,  1, 2, 2,   3, 3, 4,   4, 5, 6

            vector<int> dp(cost.size() + 1);
            dp[0] = 0;
            dp[1] = 0;
            for (int i = 2; i <= cost.size(); ++i) {
                dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
            }
            return dp[cost.size()];
        }
        // 时间复杂度：O(n)
        // 空间复杂度：O(n), 可以用dp[0]和dp[1]迭代更新dp[1]和前缀和，实现空间复杂度O(1)
    };

    vector<int> cost = {1,100,1,1,1,100,1,1,100,1};
    Solution var749;
    int ret = var749.minCostClimbingStairs(cost);
    cout << "leetcode_749 expected result is 6 !" << endl;
    cout << "ret = " << ret << endl;

    cost = {1,100,1,100,1,100,1,100,100,1};
    ret = var749.minCostClimbingStairs(cost);
    cout << "leetcode_749 expected result is 104 !" << endl;
    cout << "ret = " << ret << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 不同路径, medium, Hot100
///////////////////////////////////////////////////////////////////////////////
void leetcode_62() {
    cout << endl << "leetcode_62" << endl;    
    // 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
    // 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
    // 问总共有多少条不同的路径？
    // 输入：m = 3, n = 7
    // 输出：28
    // 提示：1 <= m, n <= 100，题目数据保证答案小于等于 2 * 109
    // Carl: https://www.programmercarl.com/0062.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84.html
    // leetcode: https://leetcode.cn/problems/unique-paths/description/

    class Solution {
    public:
        // 方法一：动态规划法
        int uniquePaths_1(int m, int n) {
            // 动规五部曲：
            // 1. 确定dp数组以及下标的含义
            // dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径。
            // 2. 确定递推公式
            // 想要求dp[i][j]，只能有两个方向来推导出来，即dp[i - 1][j] 和 dp[i][j - 1]。
            // 此时在回顾一下 dp[i - 1][j] 表示啥，是从(0, 0)的位置到(i - 1, j)有几条路径，dp[i][j - 1]同理。
            // 那么很自然，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]，因为dp[i][j]只有这两个方向过来。
            // 3. dp数组如何初始化
            // 首先dp[i][0]一定都是1，因为从(0, 0)的位置到(i, 0)的路径只有一条，那么dp[0][j]也同理。
            // 4. 确定遍历顺序
            // dp[i][j]都是从其上方和左方推导而来，那么从左到右一层一层遍历就可以了。
            // 这样就可以保证推导dp[i][j]的时候，dp[i - 1][j] 和 dp[i][j - 1]一定是有数值的。
            // 5. 举例推导dp数组

            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; i < m; ++i) dp[i][0] = 1;
            for (int j = 0; j < n; ++j) dp[0][j] = 1;
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                }
            }
            return dp[m - 1][n - 1];
        }
        // 时间复杂度：O(m*n)
        // 空间复杂度：O(m*n), 可以用一维数组（也可以理解是滚动数组）实现空间复杂度O(n)

        // 方法二：深度搜索
        int dfs(int i, int j, int m, int n) {
            if (i > m || j > n) return 0; // 越界了
            if (i == m && j == n) return 1; // 找到一种方法，相当于找到了叶子节点
            return dfs(i + 1, j, m, n) + dfs(i, j + 1, m, n);
        }
        int uniquePaths_2(int m, int n) {
            // 注意题目中说机器人每次只能向下或者向右移动一步，
            // 那么其实机器人走过的路径可以抽象为一棵二叉树，而叶子节点就是终点！
            return dfs(1, 1, m, n);
        }
        // 时间复杂度：O(2^(m + n - 1) - 1)
        // 空间复杂度：O(m+n)

        // 方法三：数论方法
        int uniquePaths_3(int m, int n) {
            // 在这个图中，可以看出一共m，n的话，无论怎么走，走到终点都需要 m + n - 2 步。
            // 在这m + n - 2 步中，一定有 m - 1 步是要向下走的，不用管什么时候向下走。
            // 那么有几种走法呢？ 可以转化为，给你m + n - 2个不同的数，随便取m - 1个数，有几种取法。
            // 那么这就是一个组合问题了。C （m + n - 2， m - 1）
            // 求组合的时候，要防止两个int相乘溢出！ 所以不能把算式的分子都算出来，分母都算出来再做除法。
            long long numerator = 1; // 分子
            int denominator = m - 1; // 分母
            int count = m - 1;
            int t = m + n - 2;
            while (count--) {
                numerator *= (t--);
                while (denominator != 0 && numerator % denominator == 0) {
                    numerator /= denominator;
                    denominator--;
                }
            }
            return numerator;
        }
        // 时间复杂度：O(m)
        // 空间复杂度：O(1)
    };

    int m = 3, n = 7;
    Solution var62;
    int ret = var62.uniquePaths_1(m, n);
    cout << "leetcode_62 expected result is 28 !" << endl;
    cout << "ret = " << ret << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 不同路径II, medium
///////////////////////////////////////////////////////////////////////////////
void leetcode_63() {
    cout << endl << "leetcode_63" << endl;    
    // 一个机器人位于一个 m x n 网格的左上角 （起始点在下图中标记为 “Start” ）。
    // 机器人每次只能向下或者向右移动一步。机器人试图达到网格的右下角（在下图中标记为 “Finish” ）。
    // 现在考虑网格中有障碍物。那么从左上角到右下角将会有多少条不同的路径？
    // 网格中的障碍物和空位置分别用 1 和 0 来表示。
    // 输入：obstacleGrid = [[0,0,0],[0,1,0],[0,0,0]]
    // 输出：2
    // 提示：1 <= m, n <= 100
    // Carl: https://www.programmercarl.com/0063.%E4%B8%8D%E5%90%8C%E8%B7%AF%E5%BE%84II.html
    // leetcode: https://leetcode.cn/problems/unique-paths-ii/description/

    class Solution {
    public:
        // 方法一：动态规划法
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            // 动规五部曲：
            // 1. 确定dp数组以及下标的含义
            // dp[i][j] ：表示从（0 ，0）出发，到(i, j) 有dp[i][j]条不同的路径。
            // 2. 确定递推公式
            // 递推公式和62.不同路径一样，dp[i][j] = dp[i - 1][j] + dp[i][j - 1]。
            // 但这里需要注意一点，因为有了障碍，(i, j)如果就是障碍的话应该就保持初始状态（初始状态为0）。
            // 3. dp数组如何初始化
            // 首先dp[i][0]一定都是1，因为从(0, 0)的位置到(i, 0)的路径只有一条，那么dp[0][j]也同理。
            // 但如果(i, 0) 这条边有了障碍之后，障碍之后（包括障碍）都是走不到的位置了，所以障碍之后的dp[i][0]应该还是初始值0。
            // 4. 确定遍历顺序
            // dp[i][j]都是从其上方和左方推导而来，那么从左到右一层一层遍历就可以了。
            // 这样就可以保证推导dp[i][j]的时候，dp[i - 1][j] 和 dp[i][j - 1]一定是有数值的。
            // 5. 举例推导dp数组

            int m = obstacleGrid.size(), n = obstacleGrid[0].size();
            if (obstacleGrid[0][0] == 1 || obstacleGrid[m - 1][n - 1] == 1) return 0;
            vector<vector<int>> dp(m, vector<int>(n, 0));
            for (int i = 0; (i < m) && (obstacleGrid[i][0] == 0); ++i) dp[i][0] = 1;
            for (int j = 0; (j < n) && (obstacleGrid[0][j] == 0); ++j) dp[0][j] = 1;
            for (int i = 1; i < m; ++i) {
                for (int j = 1; j < n; ++j) {
                    if (obstacleGrid[i][j] == 0) {                    
                        dp[i][j] = dp[i][j - 1] + dp[i - 1][j];
                    }
                }
            }
            return dp[m - 1][n - 1];
        }
        // 时间复杂度：O(m*n)
        // 空间复杂度：O(m*n), 可以用一维数组（也可以理解是滚动数组）实现空间复杂度O(n)
    };

    // int m = 3, n = 7;
    // Solution var62;
    // int ret = var62.uniquePaths_1(m, n);
    // cout << "leetcode_62 expected result is 28 !" << endl;
    // cout << "ret = " << ret << endl;
    cout << "please test the function in leetcode" << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 整数拆分, medium
///////////////////////////////////////////////////////////////////////////////
void leetcode_343() {
    cout << endl << "leetcode_343" << endl;    
    // 给定一个正整数 n ，将其拆分为 k 个 正整数 的和（ k >= 2 ），并使这些整数的乘积最大化。
    // 返回 你可以获得的最大乘积 。
    // 输入：n = 10
    // 输出：36
    // 解释: 10 = 3 + 3 + 4, 3 × 3 × 4 = 36。
    // 提示：2 <= n <= 58
    // Carl: https://www.programmercarl.com/0343.%E6%95%B4%E6%95%B0%E6%8B%86%E5%88%86.html
    // leetcode: https://leetcode.cn/problems/integer-break/description/

    class Solution {
    public:
        // 方法一：动态规划法
        int integerBreak_1(int n) {
            // 动规五部曲：
            // 1. 确定dp数组以及下标的含义
            // dp[i]：分拆数字i，可以得到的最大乘积为dp[i]。
            // dp[i]的定义将贯彻整个解题过程，下面哪一步想不懂了，就想想dp[i]究竟表示的是啥！
            // 2. 确定递推公式
            // 可以想 dp[i]最大乘积是怎么得到的呢？其实可以从1遍历j，然后有两种渠道得到dp[i].
            // 一个是j * (i - j) 直接相乘。
            // 一个是j * dp[i - j]，相当于是拆分(i - j)，对这个拆分不理解的话，可以回想dp数组的定义。
            // 递推公式：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            // j * (i - j) 是单纯的把整数拆分为两个数相乘，而j * dp[i - j]是拆分成两个以及两个以上的个数相乘。
            // 3. dp数组如何初始化
            // 严格从dp[i]的定义来说，dp[0] dp[1] 就不应该初始化，也就是没有意义的数值。
            // 这里我只初始化dp[2] = 1，从dp[i]的定义来说，拆分数字2，得到的最大乘积是1，这个没有任何异议！
            // 4. 确定遍历顺序
            // 确定遍历顺序，先来看看递归公式：dp[i] = max(dp[i], max((i - j) * j, dp[i - j] * j));
            // dp[i] 是依靠 dp[i - j]的状态，所以遍历i一定是从前向后遍历，先有dp[i - j]再有dp[i]。
            // 5. 举例推导dp数组

            vector<int> dp(n + 1);
            dp[2] = 1;
            for (int i = 3; i <= n; ++i) {
                for (int j = 1; j <= i / 2; ++j) {  // j < i 优化为 j < i / 2
                    dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
                }
            }
            return dp[n];
        }
        // 时间复杂度：O(n^2)
        // 空间复杂度：O(n)

        // 方法二：贪心
        int integerBreak_2(int n) {
            // 本题也可以用贪心，每次拆成n个3，如果剩下是4，则保留4，然后相乘，
            // 但是这个结论需要数学证明其合理性！
            if (n == 2) return 1;
            if (n == 3) return 2;
            if (n == 4) return 4;
            int result = 1;
            while (n > 4) {
                result *= 3;
                n -= 3;
            }
            result *= n;
            return result;
        }
        // 时间复杂度：O(n)
        // 空间复杂度：O(1)
    };

    // time_t now = time(0);
    // char* currentTime = ctime(&now);
    // cout << "currentTime = " << currentTime << endl;
    struct timeval tv;
    gettimeofday(&tv, NULL);
    time_t now = tv.tv_usec;
    // char* currentTime = ctime(&now);
    // cout << "currentTime tv_usec = " << tv.tv_usec << endl;
    // cout << "currentTime = " << currentTime << endl;
    // sleep(1);
    int n = 10;
    Solution var343;
    int ret = var343.integerBreak_1(n);
    cout << "leetcode_343 expected result is 36 !" << endl;
    cout << "ret = " << ret << endl;

    gettimeofday(&tv, NULL);
    time_t now2 = tv.tv_usec;
    // char* currentTime2 = ctime(&now);
    // cout << "currentTime = " << currentTime2 << endl;
    cout << "time diff = " << now2 - now << endl;
    // cout << "please test the function in leetcode" << endl;

    int ret2 = var343.integerBreak_2(n);
    cout << "leetcode_343 expected result is 36 !" << endl;
    cout << "ret2 = " << ret2 << endl;
    gettimeofday(&tv, NULL);
    time_t now3 = tv.tv_usec;
    cout << "time diff = " << now3 - now2 << endl;
}


///////////////////////////////////////////////////////////////////////////////
// 不同的二叉搜索树, medium
///////////////////////////////////////////////////////////////////////////////
void leetcode_96() {
    cout << endl << "leetcode_96" << endl;    
    // 给你一个整数 n ，求恰由 n 个节点组成且节点值从 1 到 n 互不相同的 
    // 二叉搜索树 有多少种？返回满足题意的二叉搜索树的种数。
    // 输入：n = 3
    // 输出：5
    // 提示：1 <= n <= 19
    // Carl: https://www.programmercarl.com/0096.%E4%B8%8D%E5%90%8C%E7%9A%84%E4%BA%8C%E5%8F%89%E6%90%9C%E7%B4%A2%E6%A0%91.html
    // leetcode: https://leetcode.cn/problems/unique-binary-search-trees/description/

    class Solution {
    public:
        // 方法一：动态规划法
        int numTrees(int n) {
            // n为1的时候有一棵树，n为2有两棵树，这个是很直观的。
            // 来看看n为3的时候，有哪几种情况。
            // 当1为头结点的时候，其右子树有两个节点，看这两个节点的布局，是不是和 n 为2的时候两棵树的布局是一样的啊！
            // 当3为头结点的时候，其左子树有两个节点，看这两个节点的布局，是不是和n为2的时候两棵树的布局也是一样的啊！
            // 当2为头结点的时候，其左右子树都只有一个节点，布局是不是和n为1的时候只有一棵树的布局也是一样的啊！
            // 发现到这里，其实我们就找到了重叠子问题了，其实也就是发现可以通过dp[1] 和 dp[2] 来推导出来dp[3]的某种方式。
            // 动规五部曲：
            // 1. 确定dp数组以及下标的含义
            // dp[i] ： 1到i为节点组成的二叉搜索树的个数为dp[i]。
            // 也可以理解是i个不同元素节点组成的二叉搜索树的个数为dp[i] ，都是一样的。
            // 2. 确定递推公式
            // 在上面的分析中，其实已经看出其递推关系， dp[i] += dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量]
            // j相当于是头结点的元素，从1遍历到i为止。
            // 所以递推公式：dp[i] += dp[j - 1] * dp[i - j]; ，j-1 为j为头结点左子树节点数量，i-j 为以j为头结点右子树节点数量
            // 3. dp数组如何初始化
            // 初始化，只需要初始化dp[0]就可以了，推导的基础，都是dp[0]。
            // 从定义上来讲，空节点也是一棵二叉树，也是一棵二叉搜索树，这是可以说得通的。
            // 从递归公式上来讲，dp[以j为头结点左子树节点数量] * dp[以j为头结点右子树节点数量] 
            // 中以j为头结点左子树节点数量为0，也需要dp[以j为头结点左子树节点数量] = 1， 否则乘法的结果就都变成0了。
            // 所以初始化dp[0] = 1
            // 4. 确定遍历顺序
            // 首先一定是遍历节点数，从递归公式：dp[i] += dp[j - 1] * dp[i - j]可以看出，节点数为i的状态是依靠 i之前节点数的状态。
            // 那么遍历i里面每一个数作为头结点的状态，用j来遍历。
            // 5. 举例推导dp数组

            vector<int> dp(n + 1);
            dp[0] = 1;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= i; ++j) {
                    dp[i] += dp[j - 1] * dp[i - j];
                }
            }
            return dp[n];
        }
        // 时间复杂度：O(n^2)
        // 空间复杂度：O(n)
    };

    // time_t now = time(0);
    // char* currentTime = ctime(&now);
    // cout << "currentTime = " << currentTime << endl;
    // struct timeval tv;
    // gettimeofday(&tv, NULL);
    // time_t now = tv.tv_usec;
    // char* currentTime = ctime(&now);
    // cout << "currentTime tv_usec = " << tv.tv_usec << endl;
    // cout << "currentTime = " << currentTime << endl;
    // sleep(1);
    int n = 5;
    Solution var96;
    int ret = var96.numTrees(n);
    cout << "leetcode_96 expected result is 42 !" << endl;
    cout << "ret = " << ret << endl;

    // gettimeofday(&tv, NULL);
    // time_t now2 = tv.tv_usec;
    // // char* currentTime2 = ctime(&now);
    // // cout << "currentTime = " << currentTime2 << endl;
    // cout << "time diff = " << now2 - now << endl;
    // // cout << "please test the function in leetcode" << endl;

    // int ret2 = var343.integerBreak_2(n);
    // cout << "leetcode_343 expected result is 36 !" << endl;
    // cout << "ret2 = " << ret2 << endl;
    // gettimeofday(&tv, NULL);
    // time_t now3 = tv.tv_usec;
    // cout << "time diff = " << now3 - now2 << endl;
}



