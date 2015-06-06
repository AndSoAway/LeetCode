#include <string>
#include <cstdio>

using namespace std;

class Solution{
public:
	int minDistance(string word1, string word2) {
		int len1 = word1.size();
		int len2 = word2.size();
		int** dis = new int*[len1 + 1];
		for(int i = 0; i < len1 + 1; i++) {
			dis[i] = new int[len2 + 1];
		}
		for(int i = 0; i < len2; i++) {
			dis[0][i] = len1;
		}
		for(int i = 0; i < len1; i++) {
			dis[i][0] = len2;
		}
		dis[0][0] = 0;
		for(int i = 1; i <= len1; i++) {
			for(int j = 1; j <= len2; j++) {
				int diff = word1[i] != word2[j];
				dis[i][j] = min(min(1 + dis[i - 1][j], 1 + dis[i][j - 1]), diff + dis[i - 1][j - 1]);
			}
		}
		for(int i = 0; i <= len1; i++) {
			delete[] dis[i];
		}
		delete dis;
		int res = dis[len1][len2];
		return dis[len1][len2];
	} 

private:
	int min(int a, int b) {
		return a > b ? b : a;
	}
};

int main() {
	string word1("sunny");
	string word2("snowy");
	Solution solution;
	printf("EditDistance: %d\n", solution.minDistance(word1, word2));
	return 0;
}
