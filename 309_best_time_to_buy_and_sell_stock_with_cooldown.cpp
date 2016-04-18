#include <vector>

using namespace std;
enum TRANS {
    buy,
    cooldown,
    cooldown_duration
};


class Solution {
    public:
        int maxProfit(vector<int>& prices) {
            int profit = 0;
            TRANS state = cooldown;
            int in_hand_price = 0;
            for(int i = 0; i < prices.size(); i++){
                if (state == cooldown_duration){
                    state = cooldown;
                }
                else if (state == cooldown){
                    if (i < prices.size()-1 && prices[i+1] > prices[i]){
                        state = buy;
                        in_hand_price = prices[i];
                    }
                }else if (state == buy){
                    //check whether to sell
                    if (i == prices.size()-1 ||
                            (prices[i+1] < prices[i] &&
                            (i == prices.size()-2 || prices[i+2] < prices[i]))){
                        state = cooldown_duration; 
                        profit += prices[i] - in_hand_price;
                    }
                }
            }

            return profit;
        }
};
