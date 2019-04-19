#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<string>
#include<set>
#include<conio.h>
#include<iomanip>
#include<utility>
#include<map>
#include<stack>
using namespace std;
int main() {
	bool flag = false, flag2 = false,flag3 = false,flag4 = false;
	long long con = 1,max = 10000000,min = -1000000,loop = 0;
	int vertex1, vertix2, weight;
	char choose;
	multiset<pair<pair<int, int>, int>>Table;
	multiset<pair<pair<int, int>, int>>::iterator it;
	map<int, int>vertix_dis;
	map<int, int>::iterator vd;
	map<int, int>path;
	map<int, int>::iterator ph;
	stack<int>route;
	cout << "Entre Vertix 1 and Vertix 2 and Weight between Them  " << endl;
	while (true) {
		flag = false, flag2 = false;
			cout << "\nCity 1 : ";
			cin >> vertex1;
			cout << "\nCity 2 : ";
			cin >> vertix2;
			cout << "\nweight :";
			cin >> weight;
			Table.insert(make_pair(make_pair(vertex1, vertix2), weight));
			cout << "\n****************************************************\n";
			cout << "Do you Want to continue, (Y/N)" << endl;
			choose = _getch();
			while (true) {
				if (choose == 'y' || choose == 'Y' || choose == 'n' || choose == 'N') {
					if (choose == 'y' || choose == 'Y') {
						flag = true;
						break;
					}
					else if (choose == 'n' || choose == 'N') {
						flag2 = true;
						break;
					}
				}
				cout << "Wrong Input" << endl;
				choose = _getch();
			}
			if (flag == true&&flag2 == false)
				continue;
			else if (flag2 == true&& flag == false)
				break;
	}
	for(it = Table.begin(); it != Table.end(); it++) {
		vertix_dis[it->first.first] = max;
		vertix_dis[it->first.second] = max;
		path[it->first.first] = min;
		path[it->first.second] = min;
	}
	int location, distination;
	cout << "Entre your location : ";
	cin >> location;
	cout << "Your distination : ";
	cin >> distination;
	vertix_dis[location] = 0;
	loop = vertix_dis.size();
	while ((loop - 1) > 0) {
		for (it = Table.begin(); it != Table.end(); it++) {
			if ((vertix_dis[it->first.first] + it->second) < vertix_dis[it->first.second]) {
				vertix_dis[it->first.second] = vertix_dis[it->first.first] + it->second;
				path[it->first.second] = it->first.first;
			}
		}
		loop--;
	}
	if (vertix_dis[distination] == 10000000) {
		cout << "Can't reach to this path" << endl;
		flag3 = true;
	}
	else {
		if (location == distination) {
			cout << "Shortest path from : " << location << " To " << distination << " is : " << vertix_dis[distination] << endl;
			cout << "you didn't move from your place" << endl;
			flag3 = true;
		}
		else {
			cout << "Shortest path from : " << location << " To " << distination << " is : " << vertix_dis[distination] << endl;
		}
	}
	if (!flag3) {
		long long count = path.size(), counter = 0;
		route.push(distination);
		while (path[route.top()] != location) {
			long long x = path[route.top()];
			route.push(x);
			if (counter == pow(count, (count - 1))) {
				cout << "can't reach to this path" << endl;
				flag4 = true;
				break;
			}
		}
		if (!flag4) {
			route.push(location);
			int size = route.size();
			cout << "shortest route from location to distination is : ";
			for (int i = 0; i < size; i++) {
				cout << route.top() << " ";
				route.pop();
			}
		}
		cout << endl;
	}
	system("pause");
	return 0;
}