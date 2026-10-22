class Solution {
public:
    string reverseWords(string s) {
    stringstream ss(s);
    string word, result;

    while (ss >> word) {
        reverse(word.begin(), word.end());

        if (!result.empty())
            result += " ";

        result += word;
    }

    return result;
}
};