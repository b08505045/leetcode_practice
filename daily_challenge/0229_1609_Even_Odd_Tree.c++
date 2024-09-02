#include <iostream>
#include <vector>
#include <queue>
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
    bool isEvenOddTree(TreeNode* root) {
        if (!root) {
            return true;
        }
        
        queue<TreeNode*> Q;
        int level = 0;

        Q.push(root);

        while(!Q.empty()) {
            int size = Q.size();
            int temp = !(level % 2) ? std::numeric_limits<int>::min() : std::numeric_limits<int>::max();

            for(int i = 0; i < size; i++) {
                TreeNode* node = Q.front();
                Q.pop();

                if(!(level % 2)) {
                    if(!(node -> val) || node -> val <= temp) return false;
                } else {
                    if((node -> val) || node -> val >= temp) return false;
                }

                temp = node -> val;

                if(node -> left) Q.push(node -> left);
                if(node -> right) Q.push(node -> right);
            }

            level++;
        }

        return true;
    }
};

int main () {
    Solution S;
    string s = "]";
    TreeNode* q = NULL;
    return 0;
}