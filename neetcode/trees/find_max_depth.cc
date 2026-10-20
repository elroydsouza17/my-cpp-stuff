#include <iostream>
#include <algorithm>

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
    int maxDepth(TreeNode* root) {
      if (root == NULL) {
        return 0;
      } 

      return 1 + std::max(maxDepth(root->left), maxDepth(root->right));
    }
};

int main() {

  Solution solution;
  TreeNode* node5 = new TreeNode(5);
  TreeNode* node4 = new TreeNode(4, NULL, node5);
  TreeNode* node1 = new TreeNode(3, node4, NULL);
  TreeNode* node2 = new TreeNode(2);
  TreeNode* node3 = new TreeNode(1, node1, node2);

  int res = solution.maxDepth(node3);
  std::cout << res << "\n";
}