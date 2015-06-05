#include<vector>
#include<cstring>
using std::vector;
bool canJump(vector<int>& nums) {

        int length = nums.size();

        int* canReachable = new int[length];

        memset(canReachable, 0, sizeof(int) * length);

        canReachable[0] = 1;

        for(int i = 0; i < length - 1; i++) {

            if(canReachable[i] == 0)

                continue;

            for(int j = 1; j <= nums[i]; j++) {

                (i + j < length) ? canReachable[i + j] = 1 : 0;

            }

        }

        bool ret =  (canReachable[length - 1] == 1);

	delete[]  canReachable;

        return (ret);

    }
