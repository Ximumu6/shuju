#include "F:/f/shujujiegou/stack/stack.cpp"
#include"F:/f/shujujiegou/queue/Queue.cpp"
#include<iostream>
#include <cstdio>
#include<stdlib.h>
#include<time.h>
//尽力了老师，真的不会了。。。 
using namespace std;
int n;
long long l[100010]= {0};
long long r[100010]= {0};
long long a[100010];
long long st[100010];  //区分相同元素 所以存储下标  数组模拟栈
void getRight()  //得到每一个右边元素比自己小的元素下标
{//模拟单调栈的规则
	int t=0;
	for(int i=n-1; i>=0; i--)
	{
		while(t>0&&a[i]<=a[st[t-1]])
		{
			t--;
		}
		if(t==0)   //说明有边界为栈底 可以延展到最后
			r[i]=n; 
		else
			r[i]=st[t-1];
		st[t++]=i;
	}
}
void getLeft()   //得到每一个左边元素比自己小的元素下标
{
	int t=0;
	for(int i=0; i<n; i++)
	{
		while(t>0&&a[i]<=a[st[t-1]])
		{
			t--;
		}
		if(t==0)
			l[i]=0;   //说明有边界为栈顶 可以延展到最开始
		else
			l[i]=st[t-1]+1; 
		st[t++]=i;
	}
}
int main()
{
	srand(time(0));
    int s1[10];//创建数组储存每个柱型的高度，此处定为10个柱型
    for (int i = 0; i < 10; i++) {
        cout << "每个柱型高度：";
        for (int j = 0; j < 10; j++) {
            s1[j] = rand() % 100;//为每个柱型赋随机值
            cout << s1[j] << " ";
        }
         cout << endl;
       	getLeft();
		getRight();
		long long ans;
		vector<int> heights = { s1[0],s1[1],s1[2],s1[3],s1[4],s1[5],s1[6],s1[7],s1[8],s1[9] };
		for (int i = 0; i <10; i++)
		{
			ans=max(ans,(r[i] - l[i] ) * s1[i]);		
		}
		cout<<"最大矩形的面积为："<<ans<<endl;
    }
	cout<<"请输入每个矩形的高度：";
	while(1)
	{
		scanf("%d",&n);
		if(n==0) break;
		for(int i=0; i<n; i++)
		{
			scanf("%lld",&a[i]);
		}
		getLeft();
		getRight();
		long long ans = 0;
		for (int i = 0; i <n; i++)
		{
			ans=2*max(ans,(r[i] - l[i] ) * a[i]);		
		}
		cout<<"最大矩形的面积为："<<ans<<endl;
	}

	return 0;
}


