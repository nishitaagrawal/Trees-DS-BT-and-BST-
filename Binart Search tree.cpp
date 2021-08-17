#include<iostream> //Binary search tree
using namespace std;

class node
{
	public:
		int data;
		node *left;
		node *right;
		node(int n)
		{
			data=n;
			left=NULL;
			right=NULL;
		}
};
class tree
{
	node *root;
	public:
		node *getroot()
		{
			return root;
		}
		tree()
		{
			root=NULL;
		}
		void create();
		int search(node *root,int value);
		int delete_node(int n);
		void inorder(node *root);
};
void tree::create()
{
	node *newnode,*temp;
	int n,ch;
	do
	{
		
		cout<<"Enter the element : ";
		cin>>n;
		newnode=new node(n);
		newnode->data=n;
		newnode->left=NULL;
		newnode->right=NULL;
		if(root==NULL)
		{
			root=newnode;
		}
		else
		{
			temp=root;
			while(1)
			{
				if(n<temp->data)
				{
					if(temp->left==NULL)
					{
						temp->left=newnode;
						break;
					}
					else
					{
						temp=temp->left;
					}
				}
				else
				{
					if(temp->right==NULL)
					{
						temp->right=newnode;
						break;
					}
					else
					{
						temp=temp->right;
					}
				}
			}
			cout<<"Do you want to add mode nodes(1/0) : ";
			cin>>ch;
		}
	}while(ch==1);
}

int tree::search(node *root,int value) 
{
	if(root!=NULL)
	{
		if(root->data==value)
		{
			cout<<"Element found!";
		}
		else if (value<root->data)
		{
			return search(root->left,value);
		}
		else
		{
			return search(root->right,value);
		}
	}
	else
	{
		cout<<"Element not found";
		return 0;
	}	
}

int tree::delete_node(int n)
{
	node *temp, *parent=NULL, *father, *r, *son;
	temp=root;
	while((temp->data!=n) && (temp!=NULL))
	{
		if(n<temp->data)
		{
			parent=temp;
			temp=temp->left;
		}
		else
		{
			parent=temp;
			temp=temp->right;
		}
	}
	if(temp==NULL)
	{
		cout<<"Element not found";
	}
	if(temp->left==NULL)  //single right child only there
	{
		r=temp->right;
	}
	else if(temp->right==NULL)   ///single left child only there
	{
		r=temp->left;
	}
	else   //finds r value leftmost child in right subtree
	{
		father=temp;
		r=temp->right;
		son=r->left;
		while(son!=NULL)
		{
			father=r;
			r=son;
			son=r->left;
		}
		if(father!=temp)
		{
			father->left=r->right;
			r->right=temp->right;
		}
		r->left=temp->left;
	}
	if(parent==NULL)
	{
		root=r;
	}
	else
	{
		if(temp==parent->left)
		{
			parent->left=r;
		}
		else
		{
			parent->right=r;
		}
	}
	delete temp;
}
void tree::inorder(node *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
int main()
{
	tree t;
	node *root;
	int choice,val;
	cout<<"MENU \nPress 1 to insert nodes \nPress 2 to search a node \nPress 3 to delete a node ";
	cout<<"\nPress 4 to display inorder traversal \nPress 5 to exit";
	while(choice!=5)
	{
		cout<<"\n\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case(1):t.create();break;
			case(2):cout<<"Enter the element to be searched : ";
					cin>>val;
					t.search(t.getroot(),val);
					break;
			case(3):cout<<"Enter the value to be deleted : ";
					cin>>val;
					t.delete_node(val);
					break;
			case(4): cout<<"Inorder traversal : ";
					t.inorder(t.getroot());
			case(5):break;
			default:cout<<"Invalid choice";
		}
	}
	
}




