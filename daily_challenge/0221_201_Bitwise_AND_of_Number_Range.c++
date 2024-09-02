#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int diff = right - left;
        int num_bit_diff = this->decimalToBinary(diff).size();
        vector<int> bin_left = this->decimalToBinary(left);
        vector<int> bin_right = this->decimalToBinary(right);
        vector<int> AND;
        vector<int> AND_reverse;
        for(int i = num_bit_diff + 1; i < bin_left.size(); i++){
            AND_reverse.push_back(bin_left & bin_right);
        }
        cout << "difference : " << bit_diff;
        return 0;
    }

    // Function to convert decimal to binary
    vector<int> decimalToBinary(int decimal) {
        std::vector<int> binary;
        std::vector<int> reverse_bin;

        // Handle the case when the decimal number is 0
        if (decimal == 0)
            reverse_bin.push_back(0);

        // Convert decimal to binary
        while (decimal > 0) {
            int remainder = decimal % 2;
            reverse_bin.push_back(remainder);
            decimal /= 2;
        }

        for(int i = reverse_bin.size() - 1; i >= 0; i--){
            binary.push_back(reverse_bin[i]);
        }

        return binary;
    }
};

int main () {
    Solution S;
    int a = 13;
    vector<int> vec = S.decimalToBinary(a);
    for(int i = 0; i < vec.size(); i++){
        cout << vec[i];
    }
    cout << '\n';
    S.rangeBitwiseAnd(5, 10);

    return 0;
}