#include <iostream>
#include <unordered_map> 
#include <vector>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.empty()) return 0;
        int n = s.size(), left = 0, right = 0;
        string curIndex = "", curMax = "";
        map<char, int> mp;
        map<char, int>::iterator iter;
        

        for(right = 0; right < n; right++){
            cout << right << ", "; 
            if(mp.find(s[right]) == mp.end()){
                curIndex += s[right];
                cout << "not exist, ";
            }
            else{
                curIndex = s.substr(mp[s[right]] + 1, right - mp[s[right]]);
                while(left != mp[s[right]]){
                    iter = mp.find(s[left]);
                    mp.erase(iter);
                    left++;
                }
            }
            mp[s[right]] = right;
            curMax = curIndex.size() > curMax.size() ? curIndex : curMax;
            cout << curMax << endl;
        }
        cout << curMax << endl;
        return curMax.size();
    }
};

int main () {
    Solution S;
    string s;
    cin >> s;
    cout << S.lengthOfLongestSubstring(s);
    return 0;
}