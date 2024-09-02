#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p && q) return false;
        if(!q && p) return false;
        if(!p && !q) return true;
        if(p -> val != q -> val) return false;
        if(!isSameTree(p -> left, q -> left)) {
            return false;
        } else {
            retrun isSameTree(p -> right, q -> right);
        }
    }
};

int main () {
    Solution S;
    string s = "]";
    TreeNode* q = NULL;
    return 0;
}