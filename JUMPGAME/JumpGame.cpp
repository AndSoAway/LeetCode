#include<cstdlib>
#include<stack>
#include<vector>
using std::vector;
using std::stack;

class Solution {
public:
	bool canJump(vector<int>& nums) {
		if(nums.empty() || nums.size() == 1)
			return true;
		int n = nums.size();
		bool canReach = false;
		stack<int> aStack;
		aStack.push(n-1);
		while(!aStack.empty() && aStack.top() >= 0) {
			int top = aStack.top();
			if(top == 0) {
				canReach = true;
				break;
			}
			int i = top - 1;
			while(i >= 0) {
				if(nums[i] >= top - i) {
					aStack.push(i);
					break;	
				}
				i --;
			}
		
			if(top == (n-1)) {
				break;
			}
	
			/*不能到达K*/
			if(i == top) {
				aStack.pop();
				aStack.push(top - 1);
			}
		}
		
		return canReach;
	}
};
