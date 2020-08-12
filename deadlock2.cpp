
#include <iostream>
#include <map>
#include <string>

using namespace std;

#define MAXOWNER 100
#define MAXRESOURCE 100


map<char, int> visited;
map<char, map<char, char> > dep;
char path[MAXOWNER];
string str[MAXOWNER] = {""};
int n = 0;

void dfs(char k) {
	visited[k] = 1;
	path[n++] = k;
	map<char, char>::iterator it;
	for (it = dep[k].begin(); it != dep[k].end(); it++) {
		if (k != it->first) {
			str[n - 1] = string(1, k) + " -> " + string(1, it->first) 
							 + " for " + string(1, it->second);
			if (visited[it->first] == 0) {
				dfs(it->first);
			}
			if (visited[it->first] == 1) {
				int j;
				cout << "get cycle: ";
				for (j = n - 1; ; j--) {
					cout << str[j] << "   ";
					if (path[j] == it->first) 
						break;
				}
				for (j = j - 1; j >= 0; j--) {
					cout << str[j] << "   ";
					if (path[j] == it->first) 
						break;
				}
				cout << endl;
			}
			if (visited[it->first] == -1)
				continue;
		}
	}

	visited[k] = -1;
	n--;
}

int main() {
	map<char, int> own;
	int rows;
	int i;
	char req;
	char res;
	map<char, map<char, char> >::iterator it;

	cin >> rows;
	for (i = 0; i < rows; i++) {
		cin >> req >> res;
		if (own.find(res) != own.end())
			dep[req][own[res]] = res;
		else 
			own[res] = req;
	}
	for (it = dep.begin(); it != dep.end(); it++) {
		if (visited[it->first] != -1)
			dfs(it->first);
	}

	return 0;
}

