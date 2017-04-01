#include "BST.h"

BST::BST() : root(nullptr) {}

//void BST::insert(int insertItem)
//{
//	Node  *newNode = new Node;
//	newNode->data = insertItem;
//	newNode->llink = nullptr;
//	newNode->rlink = nullptr;
//	insert(root, newNode);
//}
//
//void BST::insert( Node* &p, Node *newNode)
//{
//	if (p == nullptr)
//		p = newNode;
//	else if (p->data == newNode->data)
//		cerr << "No duplicates are allowed." << endl;
//	else if (p->data > newNode->data)
//		insert(p->llink, newNode);
//	else
//		insert(p->rlink, newNode);
//}

void BST::inorderTraversal() const
{
	if (root == nullptr)
		cerr << "There is no tree.";
	else
	{
		inorderTraversal(root);
	}
}

void BST::inorderTraversal(const Node *p) const
{
	if (p != nullptr)
	{
		inorderTraversal(p->llink);
		cout << p->data << " ";
		inorderTraversal(p->rlink);
	}
}

void  BST::destroyTree(Node* &p)
{
	if (p != nullptr)
	{
		destroyTree(p->llink);
		destroyTree(p->rlink);
		delete p;
		p = nullptr;
	}
}
	
void  BST::destroyTree()
{
	destroyTree(root);
}

BST::~BST()
{
	destroyTree(root);
}

/***************************************************************

	Implement your functions below this line.

***************************************************************/

// Definition function insert (non-recursive)
void BST::insert(int value)
{
	if (root == nullptr)
	{
		root = new Node();
		root->data = value;
		root->llink = nullptr;
		root->rlink = nullptr;
	}
	else
	{
		Node* temp = root;
		bool isDone = false;

		do
		{
			if (value == temp->data)
			{
				cerr << "The item to insert is already in the list – duplicates are not allowed.The item to insert is already in the list – duplicates are not allowed." << endl;
				isDone = true;
			}
			else if (value < temp->data)
			{
				if (temp->llink == nullptr)
				{
					temp->llink = new Node();
					temp->llink->data = value;
					temp->llink->llink = nullptr;
					temp->llink->rlink = nullptr;
					isDone = true;
				}
				else
				{
					temp = temp->llink;
				}
			}
			else
			{
				if (temp->rlink == nullptr)
				{
					temp->rlink = new Node();
					temp->rlink->data = value;
					temp->rlink->llink = nullptr;
					temp->rlink->rlink = nullptr;
					isDone = true;
				}
				else
				{
					temp = temp->rlink;
				}
			}
		} while (!isDone);
	}
}

// Definition function totalNodes
int BST::totalNodes() const
{
	return (root != nullptr) ? totalNodes(root) : 0;
}

// Definition function totalNodes (recursive)
int BST::totalNodes(const Node* p) const
{
	return (p != nullptr) ? 1 + totalNodes(p->llink) + totalNodes(p->rlink) : 0;
}

// Definition overloaded function preorderTraversal

// Definition overloaded function preorderTraversal (recursive)

// Definition overloaded function postorderTraversal

// Definition overloaded function postorderTraversal (recursive)
