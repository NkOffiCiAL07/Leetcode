class FoodRatings 
{
    typedef long long ll;
    typedef pair<string, ll> pi;
    class cmp 
    {
        public:
        bool operator()(const pi& a, const pi& b)const 
        {
            return (a.second == b.second ? a.first < b.first : a.second > b.second);
        }
    };
    
    unordered_map<string, pi>foods;
    unordered_map<string, set<pi, cmp>>cus;
    ll n;
    
    public:
    FoodRatings(vector<string>& f, vector<string>& c, vector<int>& r) 
    {
        n = f.size();
        for (ll i = 0;i < n;++i) 
        {
            foods[f[i]] = pi(c[i], r[i]);
            cus[c[i]].insert(pi(f[i], r[i]));
        }
    }

    void changeRating(string food, int newRat) 
    {
        string c = foods[food].first;
        ll oldRat = foods[food].second;
        foods[food].second = newRat;
        cus[c].erase({ food, oldRat });
        cus[c].insert({ food, newRat });
    }

    string highestRated(string c) 
    {
        return cus[c].begin()->first;
    }
};