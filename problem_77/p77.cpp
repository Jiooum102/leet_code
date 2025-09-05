#include <iostream>
#include <vector>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combine(int n, int k)
    {
        vector<vector<int>> out;
        vector<int> combination(k);
        for (int i = 0; i < k; i++)
        {
            combination[i] = i + 1;
        }
        while (true)
        {
            out.push_back(combination);
            int index = k - 1;
            while (index >= 0 && combination[index] == n + index + 1 - k)
            {
                index--;
            }
            if (index < 0)
                break;
            combination[index]++;
            for (int j = index + 1; j < k; j++)
                combination[j] = combination[j - 1] + 1;
        }
        return out;
    }
};

int main()
{
    Solution sol;
    int n, k;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter k: ";
    cin >> k;
    vector<vector<int>> result = sol.combine(n, k);
    cout << "Combinations of " << n << " choose " << k << ":\n";
    for (const auto &comb : result)
    {
        for (int num : comb)
        {
            cout << num << " ";
        }
        cout << endl;
    }
    return 0;
}