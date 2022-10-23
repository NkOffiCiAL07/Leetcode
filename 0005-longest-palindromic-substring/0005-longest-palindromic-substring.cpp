class Solution {
public:    
    string longestPalindrome(string s) {
        int n = s.size();
        int anslgth = 0;
        int ansl = 0;
        int ansx = 0, ansy = 0;
        
        if(n == 1){
            return s;
        }
        
        for(int i=0; i<n; i++){
            
            // odd
            ansl = 0;
            int x = i-1, y = i+1;
            while(x>=0 && y<n && s[x] == s[y]){
                ansl = (y-x+1);
                x--;
                y++;  
            }
            
            if(anslgth < ansl){
                anslgth = ansl;
                ansx = x+1;
                ansy = y-1;
            }
               
            ansl = 0;
            x = i, y = i+1;
            while(x>=0 && y<n && s[x] == s[y]){
                ansl = (y-x+1);
                x--;
                y++;  
            }
            
            if(anslgth < ansl){
                anslgth = ansl;
                ansx = x+1;
                ansy = y-1;
            }
        }
        
        if(anslgth == 0){
            return s.substr(0, 1);
        }
        
        //cout << anslgth << endl;
        return s.substr(ansx, anslgth);
    }
};