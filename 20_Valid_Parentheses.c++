#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        std::stack<char> stk;
        int n = s.size();

        for(int i = 0; i < n; i++){
            if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
                stk.push(s[i]);
            } else {
                if(stk.empty()) return false;
                std::string str;
                str += stk.top();
                str += s[i];
                if(!str.compare("()") || !str.compare("[]") || !str.compare("{}")) {
                    stk.pop();
                } else {
                    return false;
                }
            }
        }

        if(stk.empty()) {
            cout << "true\n";
            return true;
        } else {
            cout << "false\n";
            return false;
        }
    }
};

int main () {
    Solution S;
    string s = "]";
    cout << S.isValid(s) << '\n';
    return 0;
}