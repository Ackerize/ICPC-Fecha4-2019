#include <bits/stdc++.h>
using namespace std;

string tokenize(string s) {
	string r;
	for(int i = 0; i < s.size(); i++) {
		r += s[i];
		if(i < s.size() - 1 && s[i + 1] != ' ')
			r += ' ';
	}
	return r;
}

vector<string> partial;
vector<char> op;
vector<char> oth;

void solve() {
	string ex;
	getline(cin, ex);
	ex = tokenize(ex);
	stringstream ss(ex);
	partial.push_back("");
	char t;
	while(ss >> t) {
		if(t == '(') {
			partial.push_back("");
			continue;
		}
		if(t == '+') {
			op.push_back('+');
			continue;
		}
		if(t == '*') {
			op.push_back('*');
			continue;
		}
		if(t >= 'A' && t <= 'Z') {
			if(partial.back().size())
				partial.back() += op.back();
			partial.back() += t;
			continue;
		}
		char cur = op.back(); op.pop_back();
		auto s = partial.back(); partial.pop_back();
		if(partial.back().size())
			partial.back() += op.back();
		if(op.size() && cur == '+' && op.back() == '*') {
			s += ')';
			partial.back() += '(';
		}
		partial.back() += s;
	}
	cout << partial.back() << endl;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	cin.ignore();
	while(t--)
		solve();
}