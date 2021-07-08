#include <cstdio>
#include <utility>
using namespace std;
typedef pair<int, int> BTREE;
BTREE btree[1 << 15];
int N;
void insert(int root, int idx, int key) {
	if (idx == 1) {
		btree[root].first = key;
		return;
	}
	if (idx == 2) {
		btree[root].second = key;
		return;
	}
	if (idx % 2 == 1) insert(btree[root].first, idx / 2, key);
	else insert(btree[root].second, (idx - 1) / 2, key);
}
void pre(int idx) {
	if (idx == 0) return;
	printf("%d ", idx);
	pre(btree[idx].first);
	pre(btree[idx].second);
}
int main() {
	scanf_s("%d", &N);
	if (N == 1) return puts("1");
	if (N == 2) return puts("1 3 2");
	if (N == 3) return puts("3 1 7 5 6 2 4");
	int root = (1 << (N - 1)) - 1;
	btree[root].first = 1;
	btree[root].second = root - 1;
	for (int i = 1; i < root / 2; i++) {
		insert(btree[root].first, i, i * 2 + 1);
		insert(btree[root].second, i, i * 2);
	}
	for (int i = 0; i < 1 << (N - 2); i++) {
		insert(btree[root].first, i + root / 2, (1 << N) - i * 2 - 1);
		insert(btree[root].second, i + root / 2, (1 << N) - i * 2 - 2);
	}
	pre(root);
}