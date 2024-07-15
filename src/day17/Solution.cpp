class Solution {
public:
    vector<string> strings;

    void getStrings(TreeNode* node, string curr="") {
        curr.push_back(97 + node->val);
        if (node->left != nullptr) {
            getStrings(node->left, curr);
        }
        if (node->right != nullptr) {
            getStrings(node->right, curr);
        }
        if (node->left == nullptr && node->right == nullptr) {
            reverse(curr.begin(), curr.end());
            strings.push_back(curr);
        }
    }

    string smallestFromLeaf(TreeNode* root) {
        getStrings(root, "");
        sort(strings.begin(), strings.end());
        return strings.front();
    }
};