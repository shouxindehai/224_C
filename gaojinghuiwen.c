#include <stdio.h> 
#include<stdbool.h>
#include<string.h>

int n, q[1000001], l, w[1000001], ans;
char s[999];
void init() 
{
	int j = 0;
	for(int i = strlen(s) - 1; i >= 0 ; i--) 
	{
		if(s[i] >= '0' && s[i] <= '9') 
		{
			q[++j] = s[i] - '0';
		}
		else 
		{
			q[++j] = s[i] - 'A' + 10;
		} 
	}
}
void add(int a[], int b[]) 
{
	for(int i = 1; i <= l; i++)
	{
		a[i] += b[i];
		a[i + 1] += a[i] / n; 
		a[i] %= n;
	}
	if(a[l + 1] > 0) 
	{
		l++; 
	}
}
bool f(int a[]) 
{
	int ln = l;
	int i = 1;
	int j = l;
	while(ln--)
	{
		if(ln < l / 2) 
		{
			break;
		}
		if(a[i] != a[j])
		{
			return false; 
		}
		i++;
		j--;
	}
	return true;
}
void turn(int a[]) 
{
	int j = 0;
	for(int i = l; i >= 1; i--) 
	{
		w[++j] = a[i]; 
	}
}
int main()
{
	scanf("%d",&n);
	scanf("%s",s);
	init(); 
	l =strlen(s);
	while(!f(q)) 
	{
		turn(q);
		add(q, w); 
		ans++;
		if(ans > 30) 
		{
			break;
		}
	}
	if(ans > 30)
	{
		printf("Impossible!"); 
	}
	else
	{
		printf("STEP=%d", ans);
	}
	return 0;
}