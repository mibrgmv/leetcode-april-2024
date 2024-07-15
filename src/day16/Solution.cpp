class Solution {
public:
    int d, v;

    void travel(TreeNode* node, int currentDepth) {
        if (currentDepth == d-1) {
            auto newL = new TreeNode(v);
            auto newR = new TreeNode(v);
            newL->left = node->left;
            node->left = newL;
            newR->right = node->right;
            node->right = newR;
        } else {
            if (node->left) {
                travel(node->left, currentDepth + 1);
            }
            if (node->right) {
                travel(node->right, currentDepth + 1);
            }
        }
    }

    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            auto* newRoot = new TreeNode(val);
            newRoot->left = root;
            return newRoot;
        } else {
            d = depth;
            v = val;
            travel(root, 1);
            return root;
        }
    }
};