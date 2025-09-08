#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int len=s.length();
        if(len<1||s[0]=='0')
            return 0;
        vector <int> storage(len+1);
        storage[len]=1;
        storage[len-1]=(s[len-1]=='0')?0:1;
        for(int i=len-2;i>=0;i--)
        {
            if(s[i]!='0')
            {
                storage[i]=storage[i+1];
                if(stoi(s.substr(i,2))<27)
                    storage[i]+=storage[i+2];
            }
        }
        return storage[0];
    }
};

int main() {
    Solution sol;
    string s;
    cout << "Enter the encoded string: ";
    cin >> s;
    int result = sol.numDecodings(s);
    cout << "Number of ways to decode: " << result << endl;
    return 0;
}