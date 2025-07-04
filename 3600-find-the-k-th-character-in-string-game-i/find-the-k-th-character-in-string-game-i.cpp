class Solution {
public:
    char kthCharacter(int k) {
        string str = "a";
        while (str.size() < k) {
            string suffix = "";
            for (char c : str) {
                suffix.push_back(c + 1);
            }
            str += suffix;
        }
        return str[k - 1];
    }
};