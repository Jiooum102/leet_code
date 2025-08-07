#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout << "Enter string: ";
    cin >> str;
    int Len = str.length();
    int numRows;
    cout << "Enter number of rows: ";
    cin >> numRows;
    string result = "";
    int div = 2 * numRows - 2;
    for (int i = 0; i < numRows; i++)
    {
        for (int j = i; j < Len; j += div)
        {
            result += str[j];
            if (i > 0 && i < numRows - 1)
            {
                int midIndex = j + div - 2 * i;
                if (midIndex < Len)
                {
                    result += str[midIndex];
                }
            }
        }
    }
    cout << "Converted string: " << result << endl;
    return 0;
}