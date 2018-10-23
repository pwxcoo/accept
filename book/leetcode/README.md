# Introduction

Leetcode problems(Top 100 Liked Questions).


## leetcode1. Two Sum

一个无序数组，找出数组中两个元素等于给定值

**用哈希表保存出现过的元素及其对应的下标，然后每次遍历查询哈希表中是否有 target - nums[i]，没有就更新哈希表**

## leetcode2. Add Two Numbers

链表相加

## leetcode3. Longest Substring Without Repeating Characters

找出字符串中最长的没有重复字符的子串

**类似滑动窗口的方法，用哈希表保存出现过字符的下标，并维护一个 start 变量和哈希表，出现重复就更新 start。**

## ?leetcode4. Median of Two Sorted Arrays

得到两个有序数组的中位数，要求复杂度 $$O(log(m+n))$$，m 和 n 分别是两个数组的长度。

## leetcode5. Longest Palindromic Substring

求字符串中最长的回文

- **left, right 指针向两边展开**
- **menacher 算法**

## leetcode10. Regular Expression Matching

正则匹配。

- `'.'` 匹配任意一个
- `'*'` 匹配前一个字符 0 次或任意次

**动态规划**

## leetcode11. Container With Most Water

一个数组表示高度，能得到的最大矩阵（用这个矩阵盛水）。

**左右两个指针向中间收敛**

## leetcode15. 3Sum

数组中三个数之和为目标值。

**排序后，遍历的时候然后用两个指针收敛查找**

## leetcode17. Letter Combinations of a Phone Number

字母组合。

## leetcode19. Remove Nth Node From End of List

删除链表倒数第几个结点。

**一个 fast 指针**

## leetcode20. Valid Parentheses

判断括号是否有效。

**用栈保存**

## leetcode21. Merge Two Sorted Lists

合并链表。

**归并排序**

## leetcode22. Generate Parentheses

求出 n 个括号所有的组合。

**回溯**

## leetcode23. Merge k Sorted Lists

合并链表。

**归并排序**

## leetcode32. Longest Valid Parentheses

找出括号字符串中最长的有效字符串。

**动态规划，用一个数组保存当前 `')'` 构成的最长的有效字符串最左边的 `'('`**

## leetcode33. Search in Rotated Sorted Array

在 rotated 的数组里找到指定值。

**二分**

## leetcode34. Find First and Last Position of Element in Sorted Array

找到一个数字在有序数组中第一次出现的下标和最后一次出现的下标

**二分**

## leetcode35. Search Insert Position

lower_bound

**二分**

## leetcode39. Combination Sum

从一个无重复元素数组中挑出任意个元素（可以一直元素使用多次）之和为目标值。

**回溯**

## leetcode42. Trapping Rain Water
一个数组代表高度，求能得到多少积水。

**两个指针向中间移动**

## leetcode46. Permutations

全排序。

**回溯**

## leetcode48. Rotate Image

90度旋转图片。

**上下颠倒，然后对角线对称就变成 90 度旋转了**

## leetcode49. Group Anagrams

分类字符串，字符内容一样就是一样（不管字符顺序）

- **给字符排序，然后放到哈希表里**
- **还有一种方法就是用质数，每个字母对应一个质数，用质数积表示字符，这样哈希表存的的就是整数（但是要考虑溢出）**

## leetcode53. Maximum Subarray

最大字串和。

**动态规划**

## leetcode55. Jump Game

一个数组代表最大跳跃距离，判断是否到终点。

**贪心**

## leetcode56. Merge Intervals

合并区间。

**排序，合并区间**

## leetcode62. Unique Paths

机器人行走路径数。

**动态规划**

## leetcode64. Minimum Path Sum

左上角走到右下角最小的行走路径。（每个点有权重）

**动态规划**

## leetcode70. Climbing Stairs

爬楼梯。

**动态规划**

## leetcode72. Edit Distance

计算两个单词之间的距离。

**动态规划**。

## leetcode75. Sort Colors

颜色排序。

**三个指针**

## leetcode76. Minimum Window Substring

求最短的字串中包含给定字符串。

**用哈希表保存给定字符，用一个 count 记录，求出 count 后，移动 left 指针，更新窗口**

## leetcode78. Subsets

求集合的所有子集。

**回溯**

## leetcode79. Word Search

一个 board，每个 board 一个字母，是否通过走位组成给定单词。

**DFS**

## leetcode84. Largest Rectangle in Histogram

求一个柱状图能构成的最大的矩形。

**对每个柱，找出左边第一个小于它的，找出右边第一个小于它的，然后求面积。模拟一个单调栈。**

## leetcode85. Maximal Rectangle

最大 01 矩阵。

**可以化解成上一题的柱状图问题**

## leetcode94. Binary Tree Inorder Traversal

中序遍历。

**非递归**

## leetcode96. Unique Binary Search Trees

给定结点个数，多少种构造 BST 的方式

**动态规划**

## leetcode98. Validate Binary Search Tree

判断是否有效的 BST

- **递归**
- **中序遍历**

## leetcode100. Same Tree

判断两颗树是否一样。

**递归**

## leetcode101. Symmetric Tree

判断树是否是对称的

**写一个 helper 函数来递归**

## leetcode102. Binary Tree Level Order Traversal

层次遍历

**用队列来模拟**

## leetcode104. Maximum Depth of Binary Tree

求树的深度。

**递归**

## leetcode105. Construct Binary Tree from Preorder and Inorder Traversal

先序遍历 + 中序遍历构造二叉树。

## leetcode114. Flatten Binary Tree to Linked List

flatten 二叉树。

**非递归方式修改指针**

## leetcode121. Best Time to Buy and Sell Stock

股票问题，一次交易。

**维护一个前面最小值的变量**

## leetcode124. Binary Tree Maximum Path Sum

二叉树的最大路径和。

**开一个全局的变量维护，然后递归**

## leetcode128. Longest Consecutive Sequence

求出无序数组里，连续的序列个数。（时间复杂度要求 $$O(n)$$）

**哈希表保存当前数字，边界的数组会记录此序列的大小**

## leetcode136. Single Number

一个序列，每个元素出现两次（除了一个元素），找出那个元素

**异或运算**

## leetcode139. Word Break

给定一个字符串和一个字符串数组，判断该字符串是否能被数组内字符串组成。

**用一个哈希表来保存**

## leetcode141. Linked List Cycle

判断链表是否有环。

**fast 和 slow 指针**

## leetcode142. Linked List Cycle II

判断链表环的起点。

**一个从相交点开始，一个从头开始，相遇的点就是环的起点**

## leetcode146. LRU Cache

LRU Cache

**哈希表 + 链表模拟**

## ?leetcode148. Sort List

链表排序。要求时间 $$O(nlogn)$$, 空间 $$O(1)$$

**Bottom-to-Up 的归并排序**

## leetcode152. Maximum Product Subarray

求最大积的字串的最大积。

**维护两个变量，一个是之前的最大值，一个是之前的最小值，如果当前是负数，两者就交换**

## leetcode155. Min Stack

最小栈。

**多开一个栈，保存当前的栈内最小值**

## leetcode160. Intersection of Two Linked Lists

找到两条链表相交的点。

**两个指针跑，跑完了的话就跑到对方的头指针去**

## leetcode169. Majority Element

求出数组中大于等于 n / 2 的元素（major element）

- **用一个 count 做计数**
- **开数组记录，位运算**

## leetcode198. House Robber

抢劫，强相邻的会报警，求最多强多少。

**维护两个变量，抢这家的最大值，不强这家的最大值**

## leetcode200. Number of Islands

求岛的数量。

**BFS，DFS 都可以**

## leetcode206. Reverse Linked List

反转链表

**递归，非递归都可以。就是改指针**

## leetcode207. Course Schedule

课程安排，拓扑排序。

**相当于判断图是否存在环。DFS，BFS 都可以，BFS 用队列维护入度为 0 的结点**

## leetcode208. Implement Trie (Prefix Tree)

实现一个前缀树（字典树）

**根结点为空，维护一个字典树**

## leetcode215. Kth Largest Element in an Array

数组中第 K 大的元素。

- **直接用 sort**
- **堆排序**
- **快速排序**

## leetcode218. The Skyline Problem

给楼的坐标和高度，描绘 Skyline。

**一个楼分成两个 line，用正负号标记这个 line 是起点还是终点，排序，维护一个 cur 高度，变化就加入结果集**


## leetcode221. Maximal Square

求 01 矩阵中最大的正方形。

**动态规划，$$dp[i][j] = min(dp[i - 1][j - 1], dp[i - 1][j], dp[i][j - 1]) + 1$$，空间可以优化成线性的**

## leetcode226. Invert Binary Tree

反转二叉树。

**递归，或者用栈模拟递归**

## leetcode234. Palindrome Linked List

判断链表是否回文。

**找到中点，反转链表**

## leetcode236. Lowest Common Ancestor of a Binary Tree

最低的公共祖先

**递归查找**

## leetcode238. Product of Array Except Self

不用除法算出数组中某个数的 product of array except self。

**pre sum 数组的思想，左边一个，右边一个**

## leetcode240. Search a 2D Matrix II

在 2D 矩阵中搜索某个数。

**从左下角开始查找**

## leetcode279. Perfect Squares

一个完美平方数是由多少个最少的平方数的和组成的

- **动态规划**
- **四平方和定理**

## leetcode283. Move Zeroes

把数组中所有的零移动到数组末尾。

**遍历的时候 in-place 替换**

## leetcode287. Find the Duplicate Number

一个 n + 1 长度的数组，包含 1 ~ n 的数，有一个数字是重复，找出这个数。要求时间小于 $$O(n^2)$$，空间为常数。

- **二分，找出一个数，然后找出小于等于这个数的，查看结果是否为这个数**
- **想象成链表环的问题，找到入口结点**

## leetcode297. Serialize and Deserialize Binary Tree

序列化和反序列化二叉树。

**用 `','` 来分割结点，用 `'x'` 来表示空结点**

## leetcode300. Longest Increasing Subsequence

最长上升子序列。

**用 lower_bound 更新序列**

## leetcode301. Remove Invalid Parentheses

删除最少的字符，使得给定的括号字符串合法。

**BFS**

## leetcode309. Best Time to Buy and Sell Stock with Cooldown

购买股票有冻结期，求最大利润。

**动态规划，维护三个变量，一个变量表示最后一步为卖出的最大利润，一个为最后一步为冻结的最大利润，一个为最后一步为买入的最大利润**

## leetcode312. Burst Balloons

一组气球，气球爆炸的话，就会得到 arr[i] * arr[i - 1] * arr[i + 1] 的值，求最大的值。

**动态规划，$$dp[i][j] = max(dp[i][u - 1] + dp[u + 1][j] + num[u] * num[u - 1] * num[u + 1]$$**

## leetcode322. Coin Change

花最少数量的币组成给定的 amount。

**动态规划**

## leetcode337. House Robber III

抢劫问题。不过这次是树，不是数组。

**一个 helper 函数，每个函数应该返回两个值，一个抢劫这个结点的最大值，一个不抢劫这个结点的最大值**

## leetcode338. Counting Bits

得到小于等于 n 的数字的 1 的个数。

**位运算，动态规划**

## leetcode347. Top K Frequent Elements

第 k 个出现最频繁的数。

**桶排序**

## leetcode394. Decode String

解码字符串。比如 s = "3[a]2[bc]", 返回 "aaabcbc".

**递归**

## leetcode406. Queue Reconstruction by Height

排序一个队列，元素的第二个值表示前面有多少个元素大于或等于它。

**从大到小，然后从小到大。然后插入排序更新**

## leetcode416. Partition Equal Subset Sum

判断一个数组元素能否分成两半。

**维护一个 dp[half] 的数组**

## leetcode437. Path Sum III

判断二叉树中是否有一段之和等于给定值。

**DFS,然后维护一个哈希表，用 pre sum 数组来存储数据**

## leetcode438. Find All Anagrams in a String

判断给定字符串 s 中有多少个字符串 p 的 anagrams。

**滑动窗口，维护一个哈希表**

## leetcode448. Find All Numbers Disappeared in an Array

求出数组中 disappeared 的元素。

**in place 替换字符串**

## leetcode461. Hamming Distance

求两个数字的 hamming distance。

**异或运算**

## leetcode494. Target Sum

求给定数组中，通过加减，得到给定值。

**$$sum(P) = (target + sum(nums)) / 2$$，然后 01 背包问题**

## leetcode538. Convert BST to Greater Tree

BST 中每个结点加上比它大的所有结点和。

**右 - 根 - 左遍历**

## leetcode543. Diameter of Binary Tree

求二叉树的直径（不一定经过根结点）

**递归，维护一个全局变量**

## leetcode560. Subarray Sum Equals K

求子数组和为 K。

**pre sum 数据 + 哈希表保存之前的结果集**

## leetcode572. Subtree of Another Tree

求树是否是子树。

**写一个 same 函数，递归**

## leetcode581. Shortest Unsorted Continuous Subarray

最短的连续子数组，排序后可以让整个数组有序。

**left 向左移动和 right 指针向右移动，一旦乱序就可以得到值，left 表示当前的值比右边的最小值还要小，right 反之**

## leetcode617. Merge Two Binary Trees

合并两个二叉树。

**递归**

## leetcode621. Task Scheduler

求任务完成时间，相同任务有冷却期。

**划分周期，每个周期内必须放置不同的任务，可以直接用公式求得**

## leetcode647. Palindromic Substrings

**回文的 manacher 算法**