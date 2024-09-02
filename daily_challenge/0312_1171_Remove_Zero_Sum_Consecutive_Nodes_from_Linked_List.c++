#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* removeZeroSumSublists(ListNode* head) {
        if(!head) return NULL;

        std::unordered_map<int, int> umap;
        std::stack<ListNode*> stk;
        ListNode* node = head;
        int curSum = 0, index = 0;

        umap[0] = head -> val;

        while(node) {
            curSum += node -> val;
            if(umap.count(curSum)) {
                int a = node -> val;
                for(int i = index; i >= umap[curSum]; i--) {
                    stk.pop();
                }
            } else {
                umap[curSum] = index;
                stk.push(node);
            }

            node = node -> next;
            index++;
        }

        if(stk.empty()) return NULL;

        ListNode* res = stk.top();
        res -> next = NULL;
        stk.pop();

        ListNode* temp;
        
        while(!stk.empty()) {
            temp = res;
            res = stk.top();
            res -> next = temp;
            stk.pop();
        }
        return res;
    }
};

int main () {
    Solution S;
    string s = "]";
    TreeNode* q = NULL;
    return 0;
}