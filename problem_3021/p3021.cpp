#include <iostream>

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {
        long long out = 0;
        int even, odd;
        even = n / 2;
        odd = m / 2 + ((m % 2 == 1) ? 1 : 0);
        out =  (long long)even * (long long)odd;
        even = m / 2;
        odd = (n / 2) + ((n % 2 == 1) ? 1 : 0);
        out += (long long) even * (long long) odd;
        return out;
    }
};

int main()
{
    Solution sol;
    int n, m;
    cout << "The maximum number of flowers in the first line is: ";
    cin >> n;
    cout << "The maximum number of flowers in the second line is: ";
    cin >> m;
    long long result = sol.flowerGame(n, m);
    cout << "Number of possible pairs is: " << result << endl;
    return 0;
}