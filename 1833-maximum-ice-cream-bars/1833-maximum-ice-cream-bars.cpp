class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int x = *max_element(costs.begin(), costs.end());
        vector<long long> freq(x);
        for(int i=0; i<costs.size(); i++){
            freq[costs[i]-1]++;
        }
        int ans = 0;
        for(int i=0; i<freq.size(); i++){
            if(freq[i] * (i + 1) <= coins){
                ans += freq[i];
                coins -= (freq[i] * (i + 1));
            }
            else{
                while(coins >= i+1){
                    ans++;
                    coins -= (i+1);
                }
                
            }
        }
        return ans;
    }
};