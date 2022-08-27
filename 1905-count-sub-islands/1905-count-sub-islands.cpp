class Solution {
public:

void saglyakadejunn(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int i,int j,int& bound){

    if(i < 0 || j < 0 || i >=grid2.size() || j >= grid2[0].size() || grid2[i][j] == 0) {
       return;
   }
   
   if(grid2[i][j]==1){
      if(grid1[i][j]==0){
         bound=0;
        return;  
      } 
       grid2[i][j]=0;
   }
   
  //call to four direction
   
   saglyakadejunn(grid1 , grid2 , i+1 , j , bound);
   saglyakadejunn(grid1 , grid2 , i-1 , j , bound);
   saglyakadejunn(grid1 , grid2 , i , j+1 , bound);
   saglyakadejunn(grid1 , grid2 , i , j-1 , bound);

}
int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
   
    int ans=0;
  
    for(int i=0;i<grid2.size();i++){
        for(int j=0;j<grid2[i].size();j++){
            int bound = 1;
            if(grid2[i][j]==1)
            {   
               saglyakadejunn(grid1,grid2,i,j,bound);
               if(bound==1) ans++;
            }
        }
    }
    return ans;
}
};