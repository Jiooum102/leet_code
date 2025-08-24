#include <iostream>
#include <vector>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    string getPermutation(int n, int k)
    {
        if (n < 2)
            return "1";
        string out = "";
        vector<int> nums;
        int getNum = 1;
        for (int i = 1; i < n; i++)
        {
            nums.push_back(i);
            getNum *= i;
        }
        nums.push_back(n);
        int index = (k - 1) % (getNum * n);
        do
        {
            int nextNum = index / getNum;
            out = out + char(nums[nextNum] + '0');
            nums.erase(nums.begin() + nextNum);
            if (nums.size() < 1)
                break;
            index %= getNum;
            getNum /= nums.size();
        } while (nums.size() > 0);
        return out;
    }
};

int main()
{
    Solution sol;
    int n, k;
    cout << "Enter length of permutations (n): ";
    cin >> n;
    cout << "Enter the k-th permutation to find (k): ";
    cin >> k;
    string result = sol.getPermutation(n, k);
    cout << "The " << k << "-th permutation of numbers 1 to " << n << " is: " << result << endl;
    return 0;
}