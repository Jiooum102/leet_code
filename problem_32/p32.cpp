#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int longestValidParentheses(string s) {
        if(s.length()<2)
            return 0;
        int maxlen=0;
        vector<int> truepos;
        bool* check = new bool[s.length()];
        truepos.push_back(0);
        check[0]=true;
        for(int i=1;i<s.length();i++)
        {
            check[i]=true;
            if(s[i]==')')
            {
                if(!truepos.empty()&&s[truepos.back()]=='(')
                {
                    check[i]=false;
                    check[truepos.back()]=false;
                    truepos.pop_back();
                    if(truepos.empty())
                        maxlen=i+1;
                    else
                        maxlen=max(i-truepos.back(),maxlen);
                }
            }
            if(check[i]==true)
                truepos.push_back(i);
        }
        return maxlen;
        return 0;
    }
};
int main()
{
    Solution sol;
    string s;
    cout << "Enter a string of parentheses: ";
    cin >> s;
    int result = sol.longestValidParentheses(s);
    cout << "Longest valid parentheses substring length: " << result << endl;
    return 0;
}
