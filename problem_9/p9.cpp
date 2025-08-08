#include <iostream>
#include <cmath>
using namespace std;
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        if(x==0||x==1)
            return true;
        if(x%10==0)
            return false;
        int* arr = new int[(int)log10(x)+5];
        int tmp=x,pos=0;
        while(tmp>0)
        {
            arr[pos]=tmp%10;
            pos++;
            tmp/=10;
        }
        int i=0,j=pos-1;
        while(i<j)
        {
            if(arr[i]!=arr[j])
                return false;
            i++;
            j--;
        }
        return true;
    }
};
int main()
{
    Solution sol;
    int x;
    cout << "Enter integer: ";
    cin >> x;
    if(sol.isPalindrome(x))
        cout << "The integer is a palindrome." << endl;
    else
        cout << "The integer is not a palindrome." << endl;
    return 0;
}