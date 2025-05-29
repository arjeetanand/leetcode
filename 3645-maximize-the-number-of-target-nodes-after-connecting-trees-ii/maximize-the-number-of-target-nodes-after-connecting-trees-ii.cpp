class Solution {
public:
    vector<bool> polarity;
    pair<int,int> bfs(vector<vector<int>>& tree,int n,int x,bool k){
        int odd=0,even=0;
        bool pole=true;
        vector<bool> vis(n+1);
        queue<int> q;
        q.push(x);
        vis[x]=true;
        while(!q.empty()&&k>=0){
            int len=q.size();
            for(int i=0;i<len;i++){
                int node=q.front();
                q.pop();
                if(k) polarity[node]=pole;
                if(pole) odd++;
                else even++;
                for(int it:tree[node]){
                    if(!vis[it]){
                        q.push(it);
                        vis[it]=true;
                    }
                }
            }
            pole=!pole;
        }
        return make_pair(odd,even);
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size(),m=edges2.size();
        vector<vector<int>> tree1(n+1,vector<int>());
        vector<vector<int>> tree2(m+1,vector<int>());
        polarity.assign(n+1,false);
        for(vector<int> edge:edges1){
            int u=edge[0],v=edge[1];
            tree1[u].push_back(v);
            tree1[v].push_back(u);
        }
        for(vector<int> edge:edges2){
            int u=edge[0],v=edge[1];
            tree2[u].push_back(v);
            tree2[v].push_back(u);
        }
        pair<int,int> pr=bfs(tree2,m,0,false);
        int mx=max(pr.first,pr.second);
        pr=bfs(tree1,n,0,true);
        vector<int> ans(n+1,mx);
        for(int i=0;i<=n;i++){
            if(polarity[i]) ans[i]+=pr.first;
            else ans[i]+=pr.second;
        }
        return ans;
    }
};