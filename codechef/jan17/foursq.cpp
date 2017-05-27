//Problem URL : https://www.codechef.com/JAN17/problems/FOURSQ

//This solution will pass two subtasks
*************************************************************************************************************************************

#include <iostream>
#include <cstdio>
#include <cmath>
 
using namespace std;
 
int a[100010],ans[4],n;
long long int p;
struct node
{
	long long int pro;
}tree[400010];
 
void merge(node &l,node &r,node &c)
{
	c.pro=(l.pro*r.pro)%p;
}
 
void build(int i,int s,int e)
{
	if(s==e)
	{
		tree[i].pro=a[s];
		return ;
	}
	int lc,rc,m;
	m=(s+e)>>1;
	lc=i<<1;
	rc=lc+1;
	build(lc,s,m);
	build(rc,m+1,e);
	merge(tree[lc],tree[rc],tree[i]);
}
 
void upd(int i,int s,int e,int ind)
{
	if(s==e&&s==ind)
	{
		tree[i].pro=a[s];
		return;
	}
	if(s==e&&s!=ind)
	 return;
	int lc,rc,m;
	lc=i<<1;
	rc=lc+1;
	m=(s+e)>>1;
	if(m>=ind)
	 upd(lc,s,m,ind);
	else if(m<ind)
	 upd(rc,m+1,e,ind);
	merge(tree[lc],tree[rc],tree[i]);
}
 
long long int query(int i,int s,int e,int qs,int qe)
{
	if(s>e||s>qe||e<qs)
	 return 1;
	if(s==qs&&e==qe)
	 return tree[i].pro;
	int lc,rc,m;
	long long int x,y;
	lc=i<<1;
	rc=lc+1;
	m=(s+e)>>1;
	if(qe<=m)
	 return query(lc,s,m,qs,qe);
	else if(qs>m)
	 return query(rc,m+1,e,qs,qe);
	else
	{
		x=query(lc,s,m,qs,m);
		y=query(rc,m+1,e,m+1,qe);
		return (x*y)%p;
	}
	return 1;
}
 
int bs(int e,int s)
{
	int l=0,h=s,m,x;
	while(l<=h)
	{
		m=(l+h)/2;
		x=(m*m)%p;
		if(x==e)
		 return m;
		else if(x<e)
		{
			l=m+1;
		}
		else if(x>e)
		{
			h=m-1;
		}
	}
	return -1;
}
 
int solve(long long int v,int s)
{
	int i,j,k,e,x,y,z,r,u1,u2,u3;
	for(i=s;i>=0;i--)
	{
		x=(i*i)%p;
		if(x>v)
		break;
		u1=sqrt(v-x);
		for(j=u1;j>=0;j--)
		{
			y=(j*j)%p;
			if(y>v)
			 break;
			u2=sqrt(v-x-y);
			for(k=u2;k>=0;k--)
			{
				z=(k*k)%p;
				if(z>v)
				 break;
				e=v-x-y-z;
				if(e<0)
				 break;
				u3=sqrt(v-x-y-z);
				r=bs(e,u3);
				if(r!=-1)
				{
					ans[0]=i;
					ans[1]=j;
					ans[2]=k;
					ans[3]=r;
					return 0;
				}
			}
		}
	}
	return -1;
}
 
int main() {
	int t,q,i,v,id,l,r,x,cnt;
	long long int val,v1;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%lld",&n,&q,&p);
		for(i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			a[i]=a[i]%p;
		}
		build(1,1,n);
		while(q--)
		{
			cin>>id>>l>>r;
			if(id==1)
			{
				a[l]=r%p;
				upd(1,1,n,l);
			}
			else if(id==2)
			{
				val=query(1,1,n,l,r);
				cnt=0;
				if(val==0)
				{
					ans[0]=ans[1]=ans[2]=ans[3]=0;
					x=0;
				}
				else
				{
					while(val%4==0)
					{
						val/=4;
						cnt++;
					}
					v=sqrt(val);
				    x=solve(val,v);
				}
				if(x==-1)
				 printf("-1\n");
				else
				{
					//v1=((long long int)pow(2,cnt))%p;
					v1=(1<<cnt)%p;
					for(i=0;i<4;i++)
					 printf("%d ",(ans[i]*v1)%p);
					printf("\n");
				}
			}
		}
	}
	return 0;
}   
