//Leetcode- 901

class StockSpanner {
    stack<pair<int, int>> s;
    int index;
public:
    StockSpanner()
    {
        index = 0;    
    }
    int next(int price) {
            
        while(!s.empty() && s.top().first <= price)
            s.pop();
        int ans = s.empty()? (index + 1) : (index - s.top().second) ;
        
        s.push(make_pair(price, index));
        index++;
        
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */