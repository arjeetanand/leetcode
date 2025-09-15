class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {

        unordered_set<char>s(brokenLetters.begin(),brokenLetters.end());

        int count=0;

        bool f=true;

        int sp=0;

        for(int i=0;i<text.size();i++){

            if(text[i]==' '){
                sp++;
                f=true;
            }

            else if( s.count(text[i]) && f){
                count++;
                f=false;
                
            }

        }

        return sp+1-count;
        
    }
};