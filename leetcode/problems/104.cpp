#include <bits/stdc++.h>
using namespace std;

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
    
    int f(TreeNode* root, int depth){
        ll x = depth, y = depth;
        if(root->left != NULL){
            x = f(root->left, depth + 1);
        }
        if(root->right != NULL){
            y = f(root->right, depth + 1);
        }
        return max(x, y);
    }
    
    int maxDepth(TreeNode* root) {
        return f(root, 0);
    }
};

int main() {

}