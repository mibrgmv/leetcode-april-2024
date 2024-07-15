class Solution {
public:
    int ans;

    int sumNumbers(TreeNode* node, int sum=0) {
        sum = sum * 10 + node->val;
        if (node->left != nullptr) {
            sumNumbers(node->left, sum);
        }
        if (node->right != nullptr) {
            sumNumbers(node->right, sum);
        }
        if (node->left == nullptr && node->right == nullptr) {
            ans += sum;
        }
        return ans;
    }
};