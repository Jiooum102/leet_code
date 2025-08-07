#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    long long x, s;
    cout << "Enter integer: ";
    cin >> x;
    if (x < 0)
        s = -x;
    else
        s = x;
    long long rx = 0;
    while (s > 0)
    {
        rx = rx * 10 + s % 10;
        s /= 10;
    }
    if (x < 0)
        rx = -rx;
    if(rx < -pow(2, 31) || rx >= pow(2, 31))
    {
        cout << 0 << endl;
        return 1;
    }
    cout << "Reversed integer: " << rx << endl;
    return 0;
}