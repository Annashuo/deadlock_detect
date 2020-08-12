
#include <iostream>
#include <unordered_map>
#include <string>

using namespace std;

#define MAXOWNER 100
#define MAXRESOURCE 100


int visited[MAXOWNER] = {0};
char map[MAXOWNER][MAXOWNER] = {0};
int path[MAXOWNER] = {0};
string str[MAXOWNER] = {""};
int n = 0;
int maxreq = 0;

void dfs(int k) {
	int i, j;
	visited[k] = true;
	path[n++] = k;
	for (i = 1; i <= maxreq; i++) {
		if (k != i && map[k][i] != 0) {
			str[n - 1] = to_string(k) + " -> " + to_string(i) 
							 + " for " + string(1, map[k][i]);
			if (visited[i] == 0) {
				dfs(i);
			}
			if (visited[i] == 1) {
				cout << "get cycle: ";
				for (j = n - 1;; j--) {
					// cout << path[j] << ' ';
					cout << str[j] << "   ";
					if (path[j] == i) 
						break;
				}
				for (j = j - 1; j >= 0; j--) {
					cout << str[j] << "   ";
					if (path[j] == i) 
						break;
				}
				cout << endl;
			}

			if (visited[i] == -1)
				continue;
		}

	}
	visited[k] = -1;
	n--;
}

int main() {
	unordered_map<char, int> own;
	int rows;
	int i;
	int req;
	char res;

	cin >> rows;
	for (i = 0; i < rows; i++) {
		cin >> req >> res;
		if (req > maxreq)
			maxreq = req;
		if (own.find(res) != own.end())
			map[req][own[res]] = res;
		else 
			own[res] = req;
	}

	for (i = 1; i <= maxreq; i++)
	{
		if (visited[i] != -1)
			dfs(i);
	}

	return 0;
}

