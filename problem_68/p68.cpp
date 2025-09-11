#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> out;
        int head = 0;
        int index = 0;
        while (index < words.size()) {
            int tmpWid=words[index++].length();
            while (index < words.size() && tmpWid + 1 + words[index].size() <= maxWidth)
            {
                tmpWid+=words[index++].length()+1;
            }
            int numWords=index-head;
            string line = words[head];
            if (numWords < 2 || index == words.size()) {
                for (head = head + 1; head < index; head++)
                    line += " " + words[head];
                while (line.length() < maxWidth) {
                    line += " ";
                }
            } else {
                head++;
                int tmp = maxWidth - tmpWid;
                int division = tmp / (index - head);
                int add = tmp % (index - head);
                while (head < index) {
                    for (int i = 0; i <= division; i++)
                        line += " ";
                    if ((add--)>0)
                        line +=" ";
                    line += words[head];
                    head++;
                }
            }
                out.emplace_back(line);
                line.clear();
        }
        return out;
    }
};

int main()
{
    Solution sol;
    vector<string> words;
    int maxWidth;
    int n;
    cout << "Enter the number of words: ";
    cin >> n;
    cout << "Enter the words: ";
    for (int i = 0; i < n; i++) {
        string word;
        cin >> word;
        words.push_back(word);
    }
    cout << "Enter the maximum width: ";
    cin >> maxWidth;

    vector<string> result = sol.fullJustify(words, maxWidth);
    for (auto line : result) {
        cout << line << endl;
    }
    return 0;
}