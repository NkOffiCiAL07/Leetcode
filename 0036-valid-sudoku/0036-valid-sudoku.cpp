class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        for(int i=0; i<n; i++){
            set<int> s1, s2;
            for(int j=0; j<n; j++){
                if(board[i][j] != '.'){
                    if(!s1.count(board[i][j]-'0')){
                        s1.insert(board[i][j]-'0');
                    }
                    else
                        return false;
                }
                
                if(board[j][i] != '.'){
                    if(!s2.count(board[j][i]-'0')){
                        s2.insert(board[j][i]-'0');
                    }
                    else
                        return false;
                }
            }
            
            
            for(int i=0; i<n; i+=3){
                for(int j=0; j<n; j+=3){
                    set<int> s3, s4;
                    for(int k=0; k<=2; k++){
                        for(int l=0; l<=2; l++){
                           if(board[i+k][j+l] != '.'){
                            if(!s3.count(board[i+k][j+l]-'0')){
                                s3.insert(board[i+k][j+l]-'0');
                            }
                            else
                                return false;
                           }                         
                        }
                    } 
                }
            }
        }
        
        return true;
    }
};