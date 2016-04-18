/*
 * 思路：因为题目的要求必须是O(n)而不是O(n*sizeof(integer)),意味着不能挨个运算每个数字的bit,所以肯定是一个递推公式.
 * 解法如下：给定一个数x，bit 1 count的函数为f(x)
 *          如果x是偶数，那么f(x) = f(x>>1);
 *          如果x是奇数，那么f(x) = f(x>>1) + 1;
 */
#include <vector>
using namespace std;
class Solution {
    public:
        vector<int> countBits(int num) {
            vector<int> ret(num+1);
            ret[0] = 0;
            for(int i = 1; i<=num;i++){
                if (i%2 == 0){
                    ret[i] = ret[i>>1];
                }else{
                    ret[i] = ret[i>>1] + 1;
                }
            } 
            return ret;
        }
};
