#include <vector>
#include <cstdio>
using namespace std;

bool canJump(vector<int>& nums);

int main() {
	int  numData[] = {3, 2, 1, 0, 4};
	vector<int> nums(numData, numData + sizeof(numData) / sizeof(int));
	printf(canJump(nums) ? "Yes\n" : "No\n");
	return 0;
}
