#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        GnrPrth(n, n, "", result);
        return result;
    }
private:
    void GnrPrth(int left, int right, string current, vector<string>& result) {
        if (left == 0 && right == 0) {
            result.push_back(current);
            return;
        }
        if (left > 0) {
            GnrPrth(left - 1, right, current + "(", result);
        }
        if (right > left) {
            GnrPrth(left, right - 1, current + ")", result);
        }
    }
};
int main() {
    Solution sol;
    int n;
    cout << "Enter the number of pairs of parentheses: ";
    cin >> n;
    vector<string> result = sol.generateParenthesis(n);
    cout << "Generated parentheses combinations are: " << endl;
    for (const string& str : result) {
        cout << str << endl;
    }
    return 0;
}