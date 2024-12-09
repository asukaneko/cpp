#include<bits/stdc++.h>
using namespace std;
int n,m,tot=1;//初始化根节点
int tire[100001][101];//存储的是ascll码,tire[1][2]表示1后面有一个2
int End[1000001];//每个字符串的最后一个字符
string s;
void add()//插入操作
{
	int now=0,num;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		num=s[i]-'a';
		if(!tire[now][num])
		{
			tire[now][num]=++tot;
		}
		now=tire[now][num];
	}
	End[now]++;//表示最后一个字母是结尾
}
int find()//检索操作 
{
	int p=0;
	int ans=0;
	int len=s.length();
	for(int i=0;i<len;i++)
	{
		int num=s[i]-'a';
		p=tire[p][num];
		if(!p)
		{
			return ans;
		} 
		ans+=End[p];
	}
	return ans;//只有找到了才是1，否则是0
}
