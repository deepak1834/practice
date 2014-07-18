#include<stdio.h>
#include<stdlib.h>
#define null 0
struct tree
{
	int num;
	struct tree *l;
	struct tree *r;
	struct tree *p;
};
typedef struct tree node;
node *rt;
node * (min)(node *P);
node* (max)(node *p);
void display(node *p);
node* (success)(node *p, int);
void insert(node *p)
	{
		node *m,*x,*y;
		int n,q=1;
		do
		{	
		printf("enter the num u want to insert \n");
		scanf("%d",&n);
		m=(node *)malloc(sizeof(node));
		m->num=n;
		m->r=null;
		m->l=null;
		m->p=null;
		if(rt==null)
		{
			m->p=null;
			m->r=m->l=null;
			rt=m;
		}
		else
		{
			y=null;
			x=rt;
			while(x!=null)
			{
				y=x;
				if(n>(x->num))
				x=x->r;
				else
				x=x->l;
			}
			m->p=y;
			if(y==null)
			m->p=rt;
		   if((y->num)>=n)
			y->l=m;
			else
			y->r=m;
		}
		printf("press 1 if u want to insert more else press 0\n");
		scanf("%d",&q);
	  	}while(q==1);
	  	printf("ur new list is\n");
	  	display(rt);
	}
	void display(node *d)
	{
		if(rt==null)
		{
			printf("tree empty");
		}
		else
		{
		if(d!=null)
		{
			display(d->l);
		printf("%d\n",d->num);
		display(d->r);
		}
	    }
	}
node * (max)(node *p)
	{
		node *x=p,*y=null;
		while(x!=null)
		{
			y=x;
			x=x->r;
		}
		return y;
	}
node * (min)(node *p)
	{
		node *x,*y=null;
		x=p;
		while(x!=null)
		{
			y=x;
			x=x->l;
		}
		return y;
	}
node * (success)(node *p, int n)
{
		node *x,*y,*z;
		x =p;
		while(x!=null && x->num!=n)
		{
			if((x->num)>=n)
			x=x->l;
			else
			x=x->r;
		}
	   if(x==null)
	    {
		return x;
	    }
	    else if(x->r!=null)
	    return min(x->r);
		else
	{
		z=x->p;
		while(z!=null && x==z->r)
        {
			x=z;
			z=z->p;
		}
		return z;
	}
}
node * (delete)(node *p)
{
		int n;
		node *x,*y=p,*z=p,*d=p;
		printf("enter the element u want to delete\n");
		scanf("%d",&n);
		while(d!=null && (d->num)!=n)
		{
			if((d->num)>=n)
			d=d->l;
			else
			d=d->r;
			z=d;
		}
		if(d==null)
        return d;
		else
		{
			if(z->l==null || z->r==null)
			y=z;
			else
			y=success(z,z->num);
			if((y->l)!=null)
			x=y->l;
			else
			x=y->r;
			if(x!=null)
			x->p=y->p;
			if(y->p==null)
			rt=x;
			else if(y==y->p->l)
			y->p->l=x;
			else
			y->p->r=x;
			if(y!=z)
			{
				z->num=y->num;
				z=y;
			}
			free(y);
			return y;
			
		}
				
		
}

	main()
	{
    int d=1,s,ch,q;
    node *t,*e,*f,*g;
    do
    {
	printf("press 1 to insert \n");
	printf("press 2 to find max \n");
	printf("press 3 to find min\n");
	printf("press 4 to find the successor\n");
	printf("press 5 to delete\n");
	printf("enter the choice\n");
	scanf("%d",&ch);
	switch(ch)
			{
				case 1:
					insert(rt);
					break;
				case 2:
					e=max(rt);
					if(e!=null)
					printf("\nmax of tree is %d\n",e->num);
					else
					printf("max does not exist\n");
					break;
				case 3:
					f=min(rt);
					if(f!=null)
					printf("min of ur tree is % d \n",f->num);
					else
					printf("min does not exist\n");
					break;
				case 4:
					printf("enter the num whose successor u want to know\n");
					scanf("%d",&q);
					g=success(rt,q);
					if(g!=null)
					printf("\nsucccessor of %d is %d\n",q,g->num);
					else
					printf("\nsuccessor does not exit\n");
					break;
				case 5:
					t=delete(rt);
					if(t!=null)
					display(rt);
					else
					printf("element cannot be deleted\n");
					break;
			}
		printf("press 1 if u want to continue else press 0\n");
		scanf("%d",&d);
	}while(d==1);
}
