#include "F:/f/shujujiegou/stack/stack.cpp"
#include"F:/f/shujujiegou/queue/Queue.cpp"
#include<iostream>
#include <cstdio>
#include<stdlib.h>
#include<time.h>
//��������ʦ����Ĳ����ˡ����� 
using namespace std;
int n;
long long l[100010]= {0};
long long r[100010]= {0};
long long a[100010];
long long st[100010];  //������ͬԪ�� ���Դ洢�±�  ����ģ��ջ
void getRight()  //�õ�ÿһ���ұ�Ԫ�ر��Լ�С��Ԫ���±�
{//ģ�ⵥ��ջ�Ĺ���
	int t=0;
	for(int i=n-1; i>=0; i--)
	{
		while(t>0&&a[i]<=a[st[t-1]])
		{
			t--;
		}
		if(t==0)   //˵���б߽�Ϊջ�� ������չ�����
			r[i]=n; 
		else
			r[i]=st[t-1];
		st[t++]=i;
	}
}
void getLeft()   //�õ�ÿһ�����Ԫ�ر��Լ�С��Ԫ���±�
{
	int t=0;
	for(int i=0; i<n; i++)
	{
		while(t>0&&a[i]<=a[st[t-1]])
		{
			t--;
		}
		if(t==0)
			l[i]=0;   //˵���б߽�Ϊջ�� ������չ���ʼ
		else
			l[i]=st[t-1]+1; 
		st[t++]=i;
	}
}
int main()
{
	srand(time(0));
    int s1[10];//�������鴢��ÿ�����͵ĸ߶ȣ��˴���Ϊ10������
    for (int i = 0; i < 10; i++) {
        cout << "ÿ�����͸߶ȣ�";
        for (int j = 0; j < 10; j++) {
            s1[j] = rand() % 100;//Ϊÿ�����͸����ֵ
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
		cout<<"�����ε����Ϊ��"<<ans<<endl;
    }
	cout<<"������ÿ�����εĸ߶ȣ�";
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
		cout<<"�����ε����Ϊ��"<<ans<<endl;
	}

	return 0;
}


