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




