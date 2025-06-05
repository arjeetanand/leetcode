class Solution {
    public:
        string smallestEquivalentString(string s1, string s2, string baseStr) {
                map<char,set<char>>mp;

                        int n = s1.size();
                                for(int i = 0; i < n; i++){
                                            char a = s1[i];
                                                        char b = s2[i];

                                                                    set<char>transitivity;
                                                                                if(mp.find(a) != mp.end()) transitivity.insert(mp[a].begin(), mp[a].end());
                                                                                            transitivity.insert(a);

                                                                                                        if(mp.find(b)!= mp.end()) transitivity.insert(mp[b].begin(), mp[b].end());
                                                                                                                    transitivity.insert(b);

                                                                                                                                for (char c : transitivity) {
                                                                                                                                                mp[c] = transitivity;
                                                                                                                                                            }
                                                                                                                                                                    }

                                                                                                                                                                            string ans = "";
                                                                                                                                                                                    for (char ch : baseStr) {
                                                                                                                                                                                                if (mp.find(ch)!=mp.end()) {
                                                                                                                                                                                                                ans += *mp[ch].begin();
                                                                                                                                                                                                                            } else {
                                                                                                                                                                                                                                            ans += ch;
                                                                                                                                                                                                                                                        }
                                                                                                                                                                                                                                                                }

                                                                                                                                                                                                                                                                        return ans;
                                                                                                                                                                                                                                                                            }
                                                                                                                                                                                                                                                                            };
