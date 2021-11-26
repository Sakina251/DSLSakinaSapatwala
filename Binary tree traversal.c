/**************************************************************
Implementation of Binary Tree Traversal
**************************************************************/

#include &lt;stdio.h&gt;
#include &lt;conio.h&gt;
#include &lt;stdlib.h&gt;
#include &lt;malloc.h&gt;

struct node
{
int data;
struct node *left;
struct node *right;
};
struct node *tree;
void create(struct node *);
struct node *insert(struct node *, int);
void inorder(struct node *);
void preorder(struct node *);
void postorder(struct node *);

void main()
{
printf(&quot;\n --- WELCOME TO IMPLEMENTATION OF BINARY TREE TRAVERSALS --- \n&quot;);
int choice, x;
struct node *ptr;

create(tree);
do
{
printf(&quot;\n *** --- opertaions available --- *** &quot;);
printf(&quot;\n 1. Insert a Node&quot;);
printf(&quot;\n 2. Display Inorder Traversal&quot;);
printf(&quot;\n 3. Display Preorder Traversal&quot;);
printf(&quot;\n 4. Display Postorder Traversal&quot;);
printf(&quot;\n 5. Exit \n&quot;);
printf(&quot; Please enter your choice : &quot;);
scanf(&quot;%d&quot;, &amp;choice);
switch (choice)
{
case 1:
printf(&quot;\n Enter the data to be inserted : &quot;);
scanf(&quot;%d&quot;, &amp;x);
tree = insert(tree, x);
break;
case 2:
printf(&quot;\n Elements in the inorder traversala are : &quot;);
inorder(tree);
printf(&quot;\n&quot;);
break;
case 3:
printf(&quot;\n Elements in the preorder traversala are : &quot;);
preorder(tree);
printf(&quot;\n&quot;);
break;
case 4:
printf(&quot;\n Elements in the postorder traversala are : &quot;);
postorder(tree);

printf(&quot;\n&quot;);
break;
default:
printf(&quot;\n Please enter a valid option 1, 2, 3, 4.&quot;);
break;
}
} while (choice != 5);
}

void create(struct node *tree)
{
tree = NULL;
}

// Function for inserting a new node
struct node *insert(struct node *tree, int x)
{
struct node *p, *temp, *root;
p = (struct node *)malloc(sizeof(struct node));
p-&gt;data = x;
p-&gt;left = NULL;
p-&gt;right = NULL;
if (tree == NULL)
{
tree = p;
tree-&gt;left = NULL;
tree-&gt;right = NULL;
}
else
{
root = NULL;

temp = tree;
while (temp != NULL)
{
root = temp;
if (x &lt; temp-&gt;data)
temp = temp-&gt;left;
else
temp = temp-&gt;right;
}
if (x &lt; root-&gt;data)
root-&gt;left = p;
else
root-&gt;right = p;
}
return tree;
}

// Function for Inorder Traversals
void inorder(struct node *tree)
{
if (tree != NULL)
{
inorder(tree-&gt;left);
printf(&quot; %d \t&quot;, tree-&gt;data);
inorder(tree-&gt;right);
}
}

// Function for Preorder Traversals
void preorder(struct node *tree)
{

if (tree != NULL)
{
printf(&quot; %d \t&quot;, tree-&gt;data);
preorder(tree-&gt;left);
preorder(tree-&gt;right);
}
}

// Function for Postorder Traversals
void postorder(struct node *tree)
{
if (tree != NULL)
{
postorder(tree-&gt;left);
postorder(tree-&gt;right);
printf(&quot; %d \t&quot;, tree-&gt;data);
}
}