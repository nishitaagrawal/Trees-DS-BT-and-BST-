#include<iostream> //binary tree
#include<stack>
using namespace std;
#define max 100
class node 
{
	public:
		int data;
		node *left,*right;
		node(int n)
		{
			data=n;
			left=NULL;
			right=NULL;
		}
		friend class tree;
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
		void preorder(node *root);
		void inorder(node *root);
		void postorder(node *root);
		void nonrec_inorder(node *root);
		void nonrec_preorder(node *root);
		void nonrec_postorder(node *root);
};
void tree::create()
{
	node *temp, *newnode;
    int c, choice;
    char ans;
    do
    {
        cout<<"\nEnter Element : ";
        cin>>c;
        newnode = new node(c);
        if (root == NULL) //treee is empty
        {
        	root = newnode;
		}
        else
        {
            temp = root;
            while(1)
            {
                cout<<"\nLeft or Right (l/r) of "<< temp->data <<" : ";
                cin>>ans;
                if (ans=='l' || ans=='L')
                {
                    if (temp->left == NULL)   //if temp does not have a left child
                    {
                        temp->left = newnode;   //attach node to left of temp
                        break;
                    }
                    else
                    {
                        temp = temp->left;   //move temp to left
                    }
                }
                else 
                {    
                    if (temp->right == NULL)   //if temp does not have a right child
                    {
                        temp->right = newnode;   //attach node to right of temp
                        break;
                    }
                    else
                    {
                        temp = temp->right;   //move temp to right
                    }
                }
            }
        }
        cout<<"\nDo you want to insert more nodes? (1/0) : ";
        cin>>choice;
    } while(choice == 1);
}
void tree::inorder(node *root) //L D R
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		inorder(root->left);
		cout<<root->data<<" ";
		inorder(root->right);
	}
}
void tree::nonrec_inorder(node *root)  
{
	node *temp=root;
	stack<node *> s; //empty stack used to store pointers to node 
	while(temp!=NULL || s.empty()==false)
	{
		while(temp!=NULL)
		{
			s.push(temp);
			temp=temp->left;
		}
		temp=s.top();
		s.pop();
		cout<<temp->data<<" ";
		temp=temp->right;
	}
}
void tree::preorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		cout<<root->data<<" ";
		preorder(root->left);
		preorder(root->right);
	}
}
void tree::nonrec_preorder(node *root)
{
	stack<node *> s;
	node *temp=root;
	if (root==NULL)
	{
		return;
	}
    s.push(root);
    while (!s.empty())
    {
    	temp=s.top();
    	cout<<temp->data<< " ";
    	s.pop();
    	if(temp->right!=NULL) 
		{
            s.push(temp->right);
        }
 	    if(temp->left!=NULL)
		{
            s.push(temp->left);
        }
    }
}
void tree::postorder(node *root)
{
	if(root==NULL)
	{
		return;
	}
	else
	{
		postorder(root->left);
		postorder(root->right);
		cout<<root->data<<" ";
	}
}
void tree::nonrec_postorder(node *root)
{
	stack<node *> s1,s2;
	if (root==NULL)
	{
		return;
	}
    s1.push(root);
    node *temp;
    while (!s1.empty())
    {
    	node *temp=s1.top();
    	s1.pop();
    	s2.push(temp);
    	if(temp->left!=NULL)
		{
            s1.push(temp->left);
        }
    	if(temp->right!=NULL) 
		{
            s1.push(temp->right);
        }   
    }
    while(!s2.empty())
    {
    	temp=s2.top();
    	s2.pop();
    	cout<<temp->data << " ";
	}
}

int main()
{
	tree t;
	node *root;
	int choice;
	cout<<"MENU \nPress 1 to insert nodes \nPress 2 for recurssive Inorder traversal \nPress 3 for recurssive Preorder traversal ";
	cout<<"\nPress 4 for recurssive Postorder traversal \nPress 5 for non recurssive Inorder traversal \nPress 6 for non recurssive Preorder traversal ";
	cout<<"\nPress 7 for non recurssive Postorder traversal \nPress 8 to exit";
	while(choice!=8)
	{
		cout<<"\n\nEnter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case(1):t.create();break;
			case(2):cout<<"\nInorder traversal\n";
					t.inorder(t.getroot());
					break;
			case(3):cout<<"\nPreorder traversal\n";
					t.preorder(t.getroot());
					break;
			case(4):cout<<"\nPostorder traversal\n";
					t.postorder(t.getroot());
					break;
			case(5):cout<<"\nNon recurssive (iterative) Inorder traversal : \n";
					t.nonrec_inorder(t.getroot());
					break;
			case(6):cout<<"\nNon recurssive (iterative) Preorder traversal : \n";
					t.nonrec_preorder(t.getroot());
					break;
			case(7):cout<<"\nNon recurssive (iterative) Postorder traversal : \n";
					t.nonrec_postorder(t.getroot());
					break;
			case(8):break;
			default:cout<"Invalid choice";	
		}
	}
}
