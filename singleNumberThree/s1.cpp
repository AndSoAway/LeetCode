#include<cstdio>
#include<vector>
#include<functional>
#include<algorithm>

using namespace std;
struct Solution {
    vector<int> singleNumber(vector<int>& nums) {
        int a = 0, b = 0, s = accumulate(nums.begin(), nums.end(), 0, bit_xor<int>());
        printf("%d \n", s);
        printf("s & -s : %d\n", s & -s);
        for(auto n : nums)
             n & s & -s ? a ^= n : b ^= n;
        return vector<int>{a, b};
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 2, 1, 5};
    Solution s;
    vector<int> res = s.singleNumber(nums);
    for(vector<int>::iterator it = res.begin(); it != res.end(); it++) {
       printf("%d ", *it);
    }
    printf("\n");
}
