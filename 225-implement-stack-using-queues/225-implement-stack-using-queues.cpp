class MyStack 
{
    public:
    queue<int> stk1, stk2;
    MyStack() 
    {
        
    }
    
    void push(int x) 
    {
        if(stk1.size() == stk2.size() && stk1.empty())
        {
            stk1.push(x);
        }
        else
        {
            if(stk1.empty())
            {
                stk1.push(x);
                while(!stk2.empty())
                {
                    stk1.push(stk2.front());
                    stk2.pop();
                }
            }
            else if(stk2.empty())
            {
                stk2.push(x);
                while(!stk1.empty())
                {
                    stk2.push(stk1.front());
                    stk1.pop();
                }
            }
        }
    }
    
    int pop() 
    {
        if(!stk1.empty())
        {
            int t = stk1.front();
            stk1.pop();
            return t;
        }
        
        if(!stk2.empty())
        {
            int t = stk2.front();
            stk2.pop();
            return t;           
        }
        return 0;
    }
    
    int top() 
    {
        if(!stk1.empty())
        {
            return stk1.front();
        }
        else if(!stk2.empty())
        {
            return stk2.front();           
        }   
        
        return 0;
    }
    
    bool empty() 
    {
        if(stk1.size() == 0 && stk2.size() == 0)
            return 1;
        else
            return 0;
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */