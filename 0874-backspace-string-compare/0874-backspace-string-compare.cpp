// class Solution {
// public:
//     bool backspaceCompare(string s, string t) {
//         stack<char> mp1, mp2;
//         for(auto x:s){
//             if(x=='#' && !mp1.empty()) mp1.pop();
//             else if(x=='#' && mp1.empty()) continue;
//             else mp1.push(x);
//         }
//         for(auto x:t){
//             if(x=='#' && !mp2.empty()) mp2.pop();
//             else if(x=='#' && mp2.empty()) continue;
//             else mp2.push(x);
//         }
//         if(mp1 == mp2) return true;
//         return false;
//     }
// };

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int x=0, y=0;
        
        // for string s
        for(int i=0; i<s.size(); i++){
            if(s[i] == '#'){
                x--;
                x = max(0, x);
            }
            else{
                s[x] = s[i];
                x++;
            }
        }
        // for string t
        for(int i=0; i<t.size(); i++){
            if(t[i] == '#'){
                y--;
                y = max(0, y);
            }
            else{
                t[y] = t[i];
                y++;
            }
        }
        
        if(x != y) return false;
        else{
            for(int i=0; i<x; i++){
                if(s[i] != t[i]) return false;
            }
            return true;
        }
    }
};