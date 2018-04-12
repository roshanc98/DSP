//This program creates binary trees and checks the equivalence of the created binary trees

#include <iostream>
#include <string.h>
using namespace std;

//Class includes declaration of functions used to create, display and check for the equivalance of the binary tress.
class node
{
	public:
	int info;
	node *lcl;
	node *rcl;
	node *create_bt(node *root);
	void display(node *root, int level);
	void equivalance(node *root,node *root1);
	int count(node *root);
};

//The function inputs data of the binary tree
node *node::create_bt( node *p)
{
	int x,count=0;
	cout<<"Enter info(-1 for null): ";
	cin>>x;
	count++;
	if(x==-1)
	{
		return NULL;
	}
	p=new node();
	p->info=x;
	cout<<"Enter left child of "<<x;
	p->lcl=create_bt(p);
	cout<<"Enter right child of "<<x;
	p->rcl=create_bt(p);
	return p;
}

//The function uses recursion to display contents of the binary tree
void node::display(node *root, int level)
{
	int i;
	if(root==NULL)
	{
		return;
	}
	display(root->lcl,level+1);
	for(i=0;i<level;i++)
	{
		cout<<"    ";
		cout<<root->info<<endl;
		display(root->rcl,level+1);
	}
}

//The function determines the equivalence of 2 binary trees
void node::equivalance(node *root,node *root1)
{
	node*cur;
	node *cur1;
	node *s[20], *s1[20];
	int top=-1,top1=-1;
	int flag=0;
	//Check whether the binary tree is empty or not
	if(root==NULL || root1==NULL)
	{
		cout<<"empty tree!";
	}
	else
	{
		cur=root;
		cur1=root1;
		for(;;)
		{
			while(cur!=NULL || cur1!=NULL)
			{
				s[++top]=cur;//Stores value in the stack
				s1[++top1]=cur1;//Stores value in the stack
				cur=cur->lcl;
				cur1=cur1->lcl;
			}
			//Compares the value of two different tress until the stack is not empty
			if(top!=-1 || top1!=-1)
			{
				cur=s[top--];
				cur1=s1[top1--];
				if(cur->info != cur1->info)
				{
					flag=1;//if the values are not equal, the if loop will break(end)
					break;
				}
				cur=cur->rcl;
				cur1=cur1->rcl;
			}
			else
			{
				break;
			}
		}
	}
	if(flag==1)
	{
		cout<<"The trees are not Equivalent"<<endl;
	}
	else
	{
		cout<<"The trees are Equivalent"<<endl;
	}
}

int node::count(node* root)
{
	int cnt=0;
	node*cur;
	node *s[20];
	int top=-1;
	if(root==NULL)
	{
		return cnt;
	}
	else
	{
		cur=root;
		for(;;)
		{
			while(cur!=NULL)
			{
				s[++top]=cur;
				cur=cur->lcl;
			}
			if(top!=-1)
			{
				cur=s[top--];
				cnt++;
				cur=cur->rcl;
			}
			else
			{	
				return cnt;
			}
		}
	}

}

int main()
{
	node *root = new node();
	node *root1 = new node();
	node ob;
	int c1,c2;
	cout<<"Enter the Elements of tree 1"<<endl;
	root=ob.create_bt(root);
	cout<<endl<<"Enter the elements of tree 2"<<endl;
	root1=ob.create_bt(root1);
	cout<<"The tree 1 structure"<<endl;
	ob.display(root,1);
	cout<<"The tree 2 structure"<<endl;
	ob.display(root1,1);
	if(ob.count(root)!=ob.count(root1))
	{
		cout<<"The Binary trees are not equivalent";
		return 0;
	}
	ob.equivalance(root,root1);
	return 0;
}

