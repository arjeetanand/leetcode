class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        string ans="";int j;int i;
        for(i=0,j=0;i<word1.size() && j<word2.size();i++,j++){
            ans=ans+word1[i];
            ans=ans+word2[j];
           
        }
        if(i!=word1.length()){
            ans+=word1.substr(i,word1.size()-i);
        }
         if(j!=word2.length()){
            ans+=word2.substr(j,word2.size()-j);
        }
        return ans;
    }
};