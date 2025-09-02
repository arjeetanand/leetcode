class Solution {
public:
    int numberOfPairs(vector<vector<int>>& points) {
        int n = points.size();
        int ans = 0;

        for(int i = 0 ; i<n ; i++){
            for(int j = 0 ; j<n ; j++){
                if(i == j)continue;
                //checking the condition of upper left points i.e point j is upper left of point i.
                if(points[j][0] <= points[i][0] && points[j][1] >= points[i][1]){
                    int cnt = 0;
                    //checking if some other point is voilating the condition for points i and J.
                    for(int k = 0 ; k<n ; k++){
                        if(k == i || k == j) continue;
                        if((points[k][0] >= points[j][0] && points[k][0] <= points[i][0]) && 
                           (points[k][1] <= points[j][1] && points[k][1] >= points[i][1])){
                                cnt++;
                            }
                    }
                    if(cnt == 0) ans++;
                }
            }
        }
        return ans;
    }
};