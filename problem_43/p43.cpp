#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> StrToNum(string str)
    {
        vector<int> res;
        reverse(str.begin(),str.end());
        for(int i=0;i<str.length();i++)
            res.push_back(int(str[i]-'0'));
        return res;
    }
    string multiply(string num1, string num2) {
        vector<int> N1=StrToNum(num1);
        vector<int> N2=StrToNum(num2);
        vector<int> res;
        int len1=N1.size(),len2=N2.size();
        for(int i=0;i<len1;i++)
        {
            for(int j=0;j<len2;j++)
            {
                if(i<1||len2-j<2)
                    res.push_back(N1[i]*N2[j]);
                else
                    res[i+j]=res[i+j]+N1[i]*N2[j];
            }
        }
        string out="";
        bool Cz=true;
        for(int i=0;i<res.size();i++)
        {
            if(res[i]>9)
            {
                if(res.size()-i<2)
                {
                    res.push_back(res[i]/10);
                    res[i]%=10;
                }
                else
                {
                    res[i+1]+=res[i]/10;
                    res[i]%=10;
                }
            }
            out=char(res[i]+'0')+out;
            if(res[i]>0)
                Cz=false;
        }
        if(Cz)
            return "0";
        return out;
    }
};

int main()
{
    Solution sol;
    string num1, num2;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "The multiplication of " << num1 << " and " << num2 << " is: " << sol.multiply(num1, num2) << endl;
    return 0;
}