#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n == 1 && trust.size() == 0) return 1;
        if(n == 0 || trust.size() == 0) return -1;

        int res = -1;
        int len = trust.size();
        unordered_map<int, int> exist;
        unordered_map<int, int> count;

        for(int i = 0; i < len; i++){
            exist[trust[i][0]] = trust[i][0];
            cout << trust[i][0] << " exist. ";
            if(!count.count(trust[i][1])){
                count[trust[i][1]] = 1;
                cout << trust[i][1] << " = 1.\n";
            } else{
                count[trust[i][1]] += 1;
                cout << trust[i][1] << " += 1.\n";
            }
        }

        for(int i = 1; i <= n; i++){
            // trust nobody
            if(exist.count(i) == 0){
                cout << i << " trust nobody.";
                // everybody trust him
                if(count.count(i) && count[i] == n - 1){
                    res = i;
                }
            }
        }
        return res;
    }
};

int main () {
    Solution S;
    int n = 2;
    vector<vector<int>> trust = {{1,2}};
    cout << S.findJudge(n, trust);
    return 0;
}