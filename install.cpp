#include <bits/stdc++.h>

using namespace std;

int main() {
	system("cp -rf data /tmp/.dictation_data");
	system("g++ -o .exe dict.cpp -g");
	system("sudo cp .exe /usr/bin/dictation");
	return 0;
}
