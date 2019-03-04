/*******************************
Author:galaxy yr
LANG:C++
Created Time:2019年01月03日 星期四 13时59分47秒
*******************************/
#include<iostream>
#include<cstdio>
#include<map>
#include<fstream>
#include<ctime>
#include<cstdlib>
using namespace std;
const string file="word.txt";
ifstream test(file);
const int maxn=1000;
string word[maxn],mean[maxn];
int cnt;
void add(ofstream & k)
{
        cout<<"请先输入英文再输入中文。（输入@退出）\n";
        while(true)
        {
                string a,b;
                cin>>a;
                if(a=="@")return;
                cin>>b;
                word[++cnt]=a;mean[cnt]=b;
                k<<a<<' '<<b<<endl;
        }
}
int main()
{
        {
                string s,t;
                while(test) { test>>s>>t; word[++cnt]=s;mean[cnt]=t;}
        }
        test.close();
        ofstream f(file,ios::app);
        cout<<"是否添加新单词？ y/n ";
        char ch=cin.get();
        if(ch=='y') { add(f); }
        srand(time(0));
        cout<<"请输入抽查次数:";
        {
                int t;
                cin>>t;
                while(t--)
                {
                        int k=rand()%cnt+1;
                        cout<<mean[k]<<' ';
                        string n;
                        cin>>n;
                        if(n==word[k])cout<<"答对了  "<<word[k]<<endl;
                        else cout<<"答错了  "<<word[k]<<endl;
                }
        }
        return 0;
}
