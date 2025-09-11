class Solution {
public:
    string sortVowels(string s) {
        auto is_vowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        string collected_vowels;
        for (char c : s) {
            if (is_vowel(c)) {
                collected_vowels.push_back(c);
            }
        }

        sort(collected_vowels.begin(), collected_vowels.end());

        int v = 0;
        for (int i = 0; i < s.length(); ++i) {
            if (is_vowel(s[i])) {
                s[i] = collected_vowels[v];
                v++;
            }
        }

        return s;
    }
};