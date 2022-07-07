class Solution {
public:

bool isInterleave(string s1, string s2, string s3) 
{
   int n =s1.size();
   int m = s2.size();
   if(n+m !=s3.size()) 
      return false;

    int arr[n+1][m+1];
    for(int i =0;i<n+1;i++){
        for(int j=0;j<m+1;j++){
            if(i==0 && j==0){
                arr[i][j] = true;
            }else if(i==0){
                arr[i][j] = (arr[i][j-1] && s2[j-1]==s3[i+j-1]);
            }else if(j==0){
                arr[i][j] = (arr[i-1][j] && s1[i-1]==s3[i+j-1]);
            }else{
                arr[i][j] = (arr[i-1][j] && s1[i-1]==s3[i+j-1])||(arr[i][j-1] && s2[j-1]==s3[i+j-1]);
            }
        }
    }
    return arr[n][m];
}
};