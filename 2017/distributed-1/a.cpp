#include "message.h"
#include "pancakes.h"

#include <bits/stdc++.h>
using namespace std;

#define nl '\n'

const int N = 1e6+1;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);

	int myId = MyNodeId();
	int nodes = NumberOfNodes();

	int stackSize = GetStackSize();
	int diners = GetNumDiners();

	vector<int> stk;
	int start = myId*N;
	int end = (myId+1)*N;
	for (int i=start; i<end && i<stackSize; i++) {
		stk.push_back(GetStackItem(i));
	}

	if (myId+1 < nodes) {
		if (stk.empty()) PutInt(myId+1, -1);
		else PutInt(myId+1, stk.back());
		Send(myId+1);
	}

	int ans = 0;
	int cur = 0;

	if (myId > 0) {
		Receive(myId-1);
		cur = GetInt(myId-1);
	}

	if (!stk.empty()) {
		for (int it : stk) {
			if (it < cur) ans++;
			cur = it;
		}
	}

	if (myId > 0) {
		PutInt(0, ans);
		Send(0);
	} else {
		for (int i=1; i<nodes; i++) {
			Receive(i);
			ans += GetInt(i);
		}
		cout << ans+1 << nl;
	}

	return 0;
}
