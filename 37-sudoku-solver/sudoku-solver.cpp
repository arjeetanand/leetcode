class Solution {
public:
    int row[9][9]={false};
    int col[9][9]={false};
    int box[9][9]={false};
    bool solve(vector<vector<char>>& board,int n){
        int i=n/9;
        int j=n%9;
        int n_box=(i/3)*3+j/3;
        if(i>=9||j>=9) return true;
        if(board[i][j]!='.'){
            if(solve(board,n+1)) return true;
            else return false;
        }else{
            for(char k='1';k<='9';k++){
                int num=k-'1';
                if(!row[i][num]&&!col[j][num]&&!box[n_box][num]){
                    row[i][num]=col[j][num]=box[n_box][num]=true;
                    board[i][j]=k;
                    if(solve(board,n+1)) return true;
                    else{
                        row[i][num]=col[j][num]=box[n_box][num]=false;
                        board[i][j]='.';
                    }
                }
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int n_box=(i/3)*3+j/3;
                if(board[i][j]!='.')
                {
                    int num=board[i][j]-'1';
                    row[i][num]=col[j][num]=box[n_box][num]=true;
                }
            }
        }
        solve(board,0);
    }
};