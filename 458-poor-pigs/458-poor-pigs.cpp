class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int T = minutesToTest/minutesToDie;           
        return (int)ceil(log(buckets)/log(T+1));
    }
};