#include <iostream>
#include <string>
using namespace std;
int main()
{
    string str;
    cout << "Enter string: ";
    getline(cin, str);
    if (str.empty())
    {
        cout << "Empty string" << endl;
        return 1;
    }
    int Len = str.length();
    long long out = 0;
    bool isSign = false, isNegative = false, started = false, isNumb = false;
    for(int i = 0; i < Len ; i++)
    {
        if(str[i] != ' ')
            started = true;
        if(started)
        {
            if(isSign==false && (str[i] == '+' || str[i] == '-'))
            {
                isSign = true;
                if(str[i] == '-')
                    isNegative = true;
            }
            else if(str[i] >= '0' && str[i] <= '9')
            {
                isSign = true;
                out = out * 10 + (str[i] - '0');
                isNumb = true;
            }
            else
                break;
        }
    }
    if(isNumb)
    {
        if(isNegative)
            out = -out;
        if(out < -2147483648)
            out = -2147483648;
        else if(out > 2147483647)
            out = 2147483647;
        cout << "Output: " << out << endl;
    }
    else
    {
        cout << "No valid integer found" << endl;
        return 1;
    }
    return 0;
}