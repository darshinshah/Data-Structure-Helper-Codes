#include<iostream>

using namespace std;

struct node
{
    int data;
    node* left;
    node* right;
};

node* Deleteroot(node* root);
node* FindMin(node* root);
node* Deletenode(node* root,int value);

void noofnodes(node* root,int *value)
{
    if(root!=NULL)
    {
        noofnodes(root->left,value);
        noofnodes(root->right,value);
        (*value)=(*value)+1;
    }
}

node* insertbst(node* root,int value)
{
    if(root==NULL)
    {
        node* newnode=new node;
        newnode->left=NULL;
        newnode->data=value;
        newnode->right=NULL;
        root=newnode;
    }
    else if (value<root->data)
    {
        root->left=insertbst(root->left,value);
    }
    else if (value>root->data)
    {
        root->right=insertbst(root->right,value);
    }
    else
    {
        cout<<"Duplicates not Allowed ";
    }
    return root;
}

void preorder(node* root)//NLR
{
    if(root!=NULL)
    {
        cout<<root->data<<"----->";
        preorder(root->left);
        preorder(root->right);
    }
}

void inorder(node* root) //LNR
{
    if(root!=NULL)
    {
        inorder(root->left);
        cout<<root->data<<"----->";
        inorder(root->right);
    }
}

void postorder(node* root) //LRN
{
    if(root!=NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout<<root->data<<"----->";
    }
}

node* Deletenode(node* root,int value)
{
    if(root==NULL)
    {
        cout<<"No node to Delete\n";
    }
    else if(value==root->data)
    {
        root=Deleteroot(root);
    }
    else if (value<root->data)
    {
        root->left=Deletenode(root->left,value);
    }
    else if (value>root->data)
    {
        root->right=Deletenode(root->right,value);
    }
    return root;
}

node* FindMin(node* root)
{
    while(root->left!=NULL)
    {
        root=root->left;
    }
    return root;
}

node* Deleteroot(node* root)
{
    //Case 1: For Leaf Node
    if(root->left==NULL && root->right==NULL)
    {
        delete root;
        return NULL;
    }
    //Case 2:Node Having One Child
    else if(root->left==NULL)
    {
        node* temp=root;
        root=root->right;
        delete temp;
    }
    else if(root->right==NULL)
    {
        node* temp=root;
        root=root->left;
        delete temp;
    }
    //Case 3:Node 2 Childeren
    else
    {
        node* temp=FindMin(root->right);
        root->data=temp->data;
        root->right=Deletenode(root->right,temp->data);
    }
    return root;
}


node* searchelement(node* root,int value)
{
    if(root==NULL)
    {
        cout<<"No node to Search";
    }
    else if(value==root->data)
    {
        cout<<"Element Found";
    }
    else if (value<root->data)
    {
        root->left=searchelement(root->left,value);
    }
    else if (value>root->data)
    {
        root->right=searchelement(root->right,value);
    }
    return root;
}


int main()
{
    node* root=NULL;
    int data;
    int noofelements;
    int deleteelement;
    int searchele;
    cout<<"How Many Elements you Want to add : ";
    cin>>noofelements;
    for(int i=0;i<noofelements;i++)
    {
        cout<<"Enter the Data : ";
        cin>>data;
        root=insertbst(root,data);
    }
    cout<<" ";
    cout<<"\n\n";

    cout<<"No of nodes are  :  ";
    int value=0;
    noofnodes(root,&value);
    cout<<value;
    cout<<"\n";





    cout<<"The Preorder is  : ";
    preorder(root);
    cout<<"END ";
    cout<<"\n\n";
    cout<<"The Inorder is   : ";
    inorder(root);
    cout<<"END ";
cout<<"\n\n";
    cout<<"The Postorder is : ";
    postorder(root);
    cout<<"END ";
cout<<"\n\n";

for(int j=0;j<5;j++)
{
    cout<<"Enter Element You Want to Delete : ";
    cin>>deleteelement;
    root=Deletenode(root,deleteelement);
}




    cout<<"\n\n";
    cout<<"The Preorder is  : ";
    preorder(root);
    cout<<"END ";
cout<<"\n\n";
    cout<<"The Inorder is   : ";
    inorder(root);
    cout<<"END ";
cout<<"\n\n";
    cout<<"The Postorder is : ";
    postorder(root);
    cout<<"END ";

cout<<"\n\n";
cout<<"Enter the Search element : ";
cin>>searchele;
    searchelement(root,searchele);
}
