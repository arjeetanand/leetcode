class Solution {
public:
    string robotWithString(string s) {
        int n = s.length();
        vector<char> minchartoright(n);
        minchartoright[n-1] = s[n-1];
        for(int i = n-2;i>=0;i--){
            minchartoright[i] = min(s[i], minchartoright[i+1]);
        }
        string t = "";
        string paper = "";
        int i =0;
        while(i<n){
            t.push_back(s[i]);

            char minchar = (i+1 < n) ? minchartoright[i+1] : s[i];

            while(!t.empty()  && t.back() <= minchar){
                paper += t.back();
                t.pop_back();
            }
            i++;
        }

        while(!t.empty()){
            paper+= t.back();
            t.pop_back();
        }
        return paper;
    }
};