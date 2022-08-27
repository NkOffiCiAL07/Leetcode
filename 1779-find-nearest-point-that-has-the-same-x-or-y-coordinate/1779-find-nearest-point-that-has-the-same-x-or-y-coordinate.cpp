class Solution {
public:
    
    double cal(int x,int y,long a,long b)
    {
        a=(a-x)*(a-x);
        b=(b-y)*(b-y);
        return sqrt(a+b);
    }
    
    int nearestValidPoint(int x, int y, vector<vector<int>>& points) 
    {
   
        int md=1e5,t=-1,dist;
        
        for(int i=0;i<points.size();i++)
        {
            if(x==points[i][0]||y==points[i][1])
            {
               dist=cal(x,y,points[i][0],points[i][1]);
                if(dist<md)
                {
                    md=dist;
                    t=i;
                }
            }
        }
        
        
        return t;
    }
};