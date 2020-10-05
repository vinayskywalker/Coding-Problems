/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* helper(vector<int>& v,int st,int end){
        if(st>end) return NULL;
        int mid=(st+end)/2;
        TreeNode* root=new TreeNode(v[mid]);
        root->left=helper(v,st,mid-1);
        root->right=helper(v,mid+1,end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        TreeNode* root=NULL;
        if(nums.size()==0){
            return root;
        }
        return helper(nums,0,nums.size()-1);
    }
};