#include<iostream>
#include<string>
#include<vector>
using namespace std;



  typedef struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 

  class Solution {
  public:
      int countNodes(TreeNode* root) {
          int n = 0;
          if (root != nullptr) {
              n = 0;
              n=nodeNum(root, n);
          }
          else {
              return 0;
          }
          return n;
      }

      int nodeNum(TreeNode* nodee, int n) {
          if (nodee == nullptr) {
              return 0;
          }
          if (nodee->right == nullptr && nodee->left == nullptr) {
              return 1;
          }
          n = n + nodeNum(nodee->left, n)+ nodeNum(nodee->right, n);
        
          return n+1;
      }

  };



int main4() {
   /* TreeNode t6(6);*/
    TreeNode t1(1);
    TreeNode t2(2);
    TreeNode t3(3);
    TreeNode t4(4);
    TreeNode t5(5);
    TreeNode t6(6);
    t1.left = &t2;
    t1.right = &t3;

    t2.left = &t4;
    t2.right = &t5;

    t3.left = &t6;
    t3.right = nullptr;

    cout<<Solution().countNodes(&t1);
    
    
    return 1;
}
