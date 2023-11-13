class Solution {
public:
    string sortVowels(string s) {
        auto isVowel = [](char c) {
            c = tolower(c);
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };
        
        // Separate vowels and consonants
        string vowels, consonants;
        for (char c : s) {
            if (isVowel(c))
                vowels.push_back(c);
            else
                consonants.push_back(c);
        }
        
        // Sort the vowels
        sort(vowels.begin(), vowels.end());
        
        // Merge the sorted vowels and consonants back to form the result
        int vowelIdx = 0, consonantIdx = 0;
        for (char& c : s) {
            if (isVowel(c))
                c = vowels[vowelIdx++];
            else
                c = consonants[consonantIdx++];
        }
        
        return s;
    }
};