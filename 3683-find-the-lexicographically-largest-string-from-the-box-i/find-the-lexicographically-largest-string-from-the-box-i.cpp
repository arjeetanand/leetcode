class Solution {
public:
    string helper(string word, int numFriends, int index) {
        if (numFriends == word.size()) 
            return string(1, word[index]);

        int need = (numFriends - 1) - index;
        string res = word.substr(index, word.size() - index - need);
        return res;
    }

    string answerString(string word, int numFriends) {
        if (numFriends == 1) 
            return word;

        vector<int> indices;
        char maxChar = '\0';

        // Find the maximum character
        for (char c : word) {
            if (c > maxChar) {
                maxChar = c;
            }
        }

        // Collect all indices of the max character
        for (int i = 0; i < word.size(); ++i) {
            if (word[i] == maxChar) {
                indices.push_back(i);
            }
        }

        string res = string(1, word[0]);

        for (int i = 0; i < indices.size(); ++i) {
            res = max(res, helper(word, numFriends, indices[i]));
        }

        return res;
    }
};