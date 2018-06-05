#include <iostream>
#include <stdbool.h>
#include <limits.h>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
	int data ;
	vector<Node *>child;
};

int height(struct Node *root)
{
	if(root == NULL)
		return 0;
	queue<Node *> q;

	q.push(root);
	int height = 0;

	while(1)
	{
		int nodeCount = q.size();
		
		if(nodeCount == 0)
			return height;

		height++;

		while(nodeCount>0)
		{
			Node *node = q.front();
			q.pop();

			while(!(node->child).empty())
				{
					q.push((node->child).back());
					(node->child).pop_back();
				}
			nodeCount--;
		}
	}
}

int main()
{
	int n , i ,read ,root;
	cin >> n;
	int heighttree=0;
	if(n!=0); 
	struct Node *node = new Node[n];

	for(i=0;i<n;i++)
		{
			node[i].data = i;
		}

	for(i=0 ; i<n ; i++)
	{
		cin>>read;
		if(read == -1)
			root = i;
		else
			(node[read].child).push_back(&node[i]);
	}
	if(n !=0 )
		heighttree = height(&node[root]);
	cout<<heighttree<<"\n";

}
