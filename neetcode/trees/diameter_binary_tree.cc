struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int res;
    int dfs(TreeNode* root) {
        if (root == NULL) {
            return 0;
        }
        
        int left = dfs(root->left);
        int right = dfs(root->right);
        res = std::max(res, left + right);
        return 1 + std::max(left, right);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        res = 0;
        dfs(root);
        return res;
    }
};

int main() {

  Solution solution;
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node4 = new TreeNode(4, NULL, node5);
  TreeNode* node1 = new TreeNode(3, node4, NULL);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(1, node1, node2);

  int res = solution.diameterOfBinaryTree(node3);
  std::cout << res << "\n";
}