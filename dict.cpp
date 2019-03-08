#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

int tot, tot_wa;
struct Word {
	string CH, EN;
}word[100005], WA[100005];

bool cmp(Word a, Word b) {
	return a.EN < b.EN;
}

string Str(int x) {
	string res;
	if(x > 9) res = Str(x/10);
	res.push_back(x%10+'0');
	return res;
}

/*{{{ Save*/
void save_week(int num) {
	string ra, rb, path = "data/week/"+Str(num)+"/wa.swap";
	FILE *fp = freopen(path.data(), "w", stdout);
	cout << tot_wa << endl;
	sort(WA+1, WA+tot_wa+1, cmp);
	for (int i = 1; i <= tot_wa; ++i) {
		cout << WA[i].EN << ' ';
		cout << WA[i].CH << '\n';
	}
	fflush(fp);
	freopen("/dev/tty", "w", stdout);
}
/*}}}*/

/*{{{ 周计划*/
void Week_read(int num, int type) {
	string path = "data/week/", ra, rb;
	path += Str(num);
	if (!type) path += "/words";
	else path += "/wa";
	FILE *fp = freopen(path.data(), "r", stdin);
	cin >> tot;
	for (int i = 1; i <= tot; ++i) {
		cin >> ra >> rb;
		word[i].EN = ra;
		word[i].CH = rb;
	}
	fflush(fp);
	freopen("/dev/tty", "r", stdin);
}

void Week() {
	int num, a[100005], type;
	string ra, rb;
	system("clear");
	tot_wa = 0;
	cout << "请输入周数:"; cin >> num;
	cout << "请输入听写方式:\n";
	cout << "1.按顺序听写\n";
	cout << "2.随机听写\n";
	cout << "3.错题听写\n";
	cout << "->";
	cin >> type;
	tot = 0, Week_read(num, (type == 3));
	for (int i = 1; i <= tot; ++i) a[i] = i;
	if (type == 2) random_shuffle(a+1, a+tot+1);
	system("clear");
	cout << "                Dictation begin！！\n";
	for (int i = 1; i <= tot; ++i) {
		int j = a[i];
		cout << "Chinese：" << word[j].CH << endl;
		cout << "English：";
		cin >> ra;
		if (ra[0] == 'n' && ra.size() == 1) {
			cout << "The answer is " << word[j].EN << endl;
			cout << "是否加入错词库？(y/n)";
			cin >> rb;
			if (rb[0] == 'y') WA[++tot_wa] = word[j], save_week(num);
			continue;
		}
		while (ra != word[j].EN) {
			cout << "WA! Try again or input 1 to see answer\n";
			cin >> ra;
			if (ra[0] == '1') {
				cout << "The answer is " << word[j].EN << endl;
				cout << "是否加入错词库？(y/n)";
				cin >> rb;
				if (rb[0] == 'y') WA[++tot_wa] = word[j], save_week(num);
				break;
			}
		}
		if (ra == word[j].EN) cout << "AC\n";
	}
	cout << "Finish!!!\n";
	ra = "mv data/week/"+Str(num)+"/wa.swap data/week/"+Str(num)+"/wa";
	system(ra.data());
	getchar(), getchar();
	return;
}
/*}}}*/

/*{{{Menu*/
void Menu_main() {
	int choice;
	while (true) {
		system("clear");
		cout << " ________\n";
		cout << " |主菜单|\n";
		cout << " ########\n";
		cout << " 1.周计划\n";
		cout << " 2.退出  \n";
		cout << " ########\n";
		cout << "->your choice:";
		cin >> choice;
		if (choice == 1) Week();
		if (choice == 2) return;
	}
}
/*}}}*/

int main() {
	srand(time(0));
	Menu_main();
	system("clear");
	return 0;
}
