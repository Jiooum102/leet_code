#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution
{
public:
    vector<string> letterCombinations(string digits)
    {
        vector<string> result;
        if (digits.empty())
            return result;
        GenerateAllCombinations(digits, "", 0, result);
        return result;
    }
    void getLettersForDigit(char digit, string &letters)
    {
        switch (digit)
        {
        case '2':
            letters = "abc";
            break;
        case '3':
            letters = "def";
            break;
        case '4':
            letters = "ghi";
            break;
        case '5':
            letters = "jkl";
            break;
        case '6':
            letters = "mno";
            break;
        case '7':
            letters = "pqrs";
            break;
        case '8':
            letters = "tuv";
            break;
        case '9':
            letters = "wxyz";
            break;
        default:
            letters = "";
            break;
        }
    }
    void GenerateAllCombinations(const string &digits, string current, int index, vector<string> &result)
    {
        if (index == digits.size())
        {
            result.push_back(current);
            return;
        }
        string letters;
        getLettersForDigit(digits[index], letters);
        for (char letter : letters)
        {
            GenerateAllCombinations(digits, current + letter, index + 1, result);
        }
    }
};
int main()
{
    string str;
    cout << "Enter digits: ";
    cin >> str;
    Solution sol;
    vector<string> combinations = sol.letterCombinations(str);
    cout << "Letter combinations are: " << endl;
    for (const string &combo : combinations)
    {
        cout << combo << endl;
    }
}