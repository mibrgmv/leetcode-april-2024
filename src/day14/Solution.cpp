class Solution {
public:
    int ans = 0;

    void traverseLeft(TreeNode* node, bool isLeft) {
        if (isLeft && node->right == nullptr && node->left == nullptr) {
            ans += node->val;
        } else {
            sumOfLeftLeaves(node);
        }
    }

    int sumOfLeftLeaves(TreeNode* root) {
        if (root->left != nullptr) {
            traverseLeft(root->left, true);
        }
        if (root->right != nullptr) {
            traverseLeft(root->right, false);
        }
        return ans;
    }
};