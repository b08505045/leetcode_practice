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
    int findBottomLeftValue(TreeNode* root) {
        int level = 0;
        return find(root, level).first;
    }

    pair<int, int> find(TreeNode* node, int level) {
        if(!node) return std::make_pair(0,0);
        if(!(node -> left) && !(node -> right)) {
            return std::make_pair(node -> val, level);
        }
        if(!(node -> left) && !(node -> right)) return find(node -> left, ++level);
        if(!(node -> left) && !(node -> right)) return find(node -> right, ++level);
        pair<int, int> left = find(node -> left, ++level);
        pair<int, int> right = find(node -> right, ++level);
        cout << "left level : " << left.second << ", right level : " << right.second << '\n';
        if(left.second >= right.second) {
            return left;
        } else {
            return right;
        }
    }
};

int main () {
    Solution S;
    string s = "]";
    TreeNode* q = NULL;
    return 0;
}