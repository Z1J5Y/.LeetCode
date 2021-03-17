/*
 * @lc app=leetcode.cn id=2 lang=c
 *
 * [2] 两数相加
 *
 * https://leetcode-cn.com/problems/add-two-numbers/description/
 *
 * algorithms
 * Medium (39.31%)
 * Likes:    5521
 * Dislikes: 0
 * Total Accepted:    684.2K
 * Total Submissions: 1.7M
 * Testcase Example:  '[2,4,3]\n[5,6,4]'
 *
 * 给你两个 非空 的链表，表示两个非负的整数。它们每位数字都是按照 逆序 的方式存储的，并且每个节点只能存储 一位 数字。
 * 
 * 请你将两个数相加，并以相同形式返回一个表示和的链表。
 * 
 * 你可以假设除了数字 0 之外，这两个数都不会以 0 开头。
 * 
 * 
 * 
 * 示例 1：
 * 
 * 
 * 输入：l1 = [2,4,3], l2 = [5,6,4]
 * 输出：[7,0,8]
 * 解释：342 + 465 = 807.
 * 
 * 
 * 示例 2：
 * 
 * 
 * 输入：l1 = [0], l2 = [0]
 * 输出：[0]
 * 
 * 
 * 示例 3：
 * 
 * 
 * 输入：l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
 * 输出：[8,9,9,9,0,0,0,1]
 * 
 * 
 * 
 * 
 * 提示：
 * 
 * 
 * 每个链表中的节点数在范围 [1, 100] 内
 * 0 <= Node.val <= 9
 * 题目数据保证列表表示的数字不含前导零
 * 
 * 
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2)
{
    
    struct ListNode *ret=calloc(1,sizeof(struct ListNode)),*temp=NULL,*L=NULL;
    long long la=0,lb=0,lc;
    L=ret;
    temp=l1;
    for(long long i=1;temp!=NULL;i*=10,temp=temp->next)
    {
        la+=temp->val*i;
        
    }
    
    temp=l2;
    for(long long i=1;temp!=NULL;i*=10,temp=temp->next)
    {
        lb+=temp->val*i;
        
    }
    lc=la+lb;
    if(!lc)
    {
        ret->val=0;
        ret->next=NULL;
        return ret;
    }
    for(;lc;)
    {
        temp=(struct ListNode *)calloc(1,sizeof(struct ListNode));
        temp->val=lc%10;
        L->next=temp;
        L=temp;
        lc/=10;
    }
    L->next=NULL;
    return ret->next;
}
// @lc code=end

