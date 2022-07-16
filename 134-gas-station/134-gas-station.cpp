class Solution 
{
    public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int total = 0, tank = 0, indx = 0;
        for(int i=0; i<gas.size(); i++)
        {
            int tmp = gas[i] - cost[i];
            tank += tmp;
            total += tmp;
            if(tank < 0)
            {
                indx = i + 1;
                tank = 0;
            }
        }
        
        if(total < 0) return -1;
        return indx;
    }
};