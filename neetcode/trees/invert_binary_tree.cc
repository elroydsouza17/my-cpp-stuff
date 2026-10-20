#include <iostream>

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
    TreeNode* invertTree(TreeNode* root) {
      if (root == NULL) {
          return root;
      }

      auto temp = root->left;
      root->left = root->right;
      root->right = temp;

      invertTree(root->left);
      invertTree(root->right);

      return root;   
    }
};


int main() {
  Solution solution;
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2);
  root->right = new TreeNode(3);

  std::cout << "left node" << root->left->val << std::endl; 
  std::cout << "right node" << root->right->val << std::endl;

  solution.invertTree(root);

  std::cout << "left node" << root->left->val << std::endl; 
  std::cout << "right node" << root->right->val << std::endl;
}