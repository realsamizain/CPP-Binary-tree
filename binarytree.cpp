  
    #include<iostream>
    #include<stdlib.h>   
    #define MIN -65535
    using namespace std;
    struct btree{
    long int id, val;
    struct btree *left, *right;
    };
    typedef struct btree node;
    void myparent(node *tree, long int myid, node **parent){
    if(tree->id==(myid/2))
    *parent = tree;
    if(tree->left)
    myparent(tree->left, myid, parent);
    if(tree->right)
    myparent(tree->right, myid, parent);
    }
    void insert(node **tree, node *item){
    node *parent;
    if(item->id==1)
    *tree=item;
    else{
    myparent(*tree, item->id,&parent);
    if((item->id)%2)
    parent->right=item;
    else
    parent->left=item;
    }
    }
    
    void PrintTree( node* tp, int spaces )
    {
    int i;
    
    if( tp != NULL )
    {
    PrintTree( tp->right, spaces + 3 );
    for( i = 0; i < spaces; i++ ){
    
    }
    cout << tp->val << endl;
    PrintTree( tp->left, spaces + 3 );
    }
    }
    void printout(node *tree);
    
    int countNodes( node *root ) {
    
    if ( root == NULL )
    return 0;  
    else {
    int count = 1;   
    count += countNodes(root->left);  
    
    count += countNodes(root->right); 
    
    return count;  
    }
    }      
    
    int checkLeaf(node* node)
    {
    int count = 0;
    if(node == NULL)       
    return 0;
    if(node->left == NULL && node->right==NULL)      
    return count = count+1;            
    else
    return checkLeaf(node->left)+
    checkLeaf(node->right);      
    }
    
    int interior(node *r)
    {
    
    
    if(r==NULL || (r->left == NULL && r->right == NULL) )
    {
    return 0;
    }
    else
    {
    return (1 + interior(r->left) + interior(r->right) );
    }
    
    }
    
    
    
    
    
    
    int findMaxInTree(node * root)
    {
    
    int root_val;
    
    
    int left, right;
    
    
    int max = MIN;
    
    if(root != NULL)
    {
    
    root_val = root -> val;
    
    
    left = findMaxInTree(root -> left);
    
    
    right = findMaxInTree(root -> right);
    
    
    if(left > right)
    max = left;
    else
    max = right;
    
    
    if(root_val > max)
    max = root_val;
    }
    
    return max;
    }
    
    int level(node *root)
    {
    
    if (root == NULL)
    return 0;
    
    
    if (root->left == NULL && root->right == NULL)
    return 1;
    
    
    if (!root->left)
    return level(root->right) + 1;
    
    
    if (!root->right)
    return level(root->left) + 1;
    
    return (level(root->left), level(root->right)) + 1;
    }
    
    
    
    
    
    
    int height(node *Height)
    {
    int l,r;
    if(Height->left==NULL && Height->right==NULL)
    {
    return 0;
    }
    else
    {
    l=height(Height->left);
    r=height(Height->right);
    
    if (l>r)
    {l=l+1;
    return l;
    }
    else
    {
    r=r+1;
    return r;
    }
    }
    }
    
    
    
    int main(){
    node *root, *curr;
    int idcount=1, inp=0;
    root=NULL;
    int nums[50], value;
    int i,coun = 0;
    
    for (i =0; i<=50;++i){
    
    cout<<"enter a node: ";
    cin>>nums[i];
    if (nums[i] == -1)
    {
    break;
    
    
    }
    else 
    {
    curr=(node*)malloc(sizeof(node));
    curr->val=nums[i];
    curr->id=idcount++;
    curr->left = curr->right = NULL;
    insert(&root, curr);   
    }
    
    
    
    }
    
    
    cout<<"Entered Binary Tree is \n";
    PrintTree(root,0);
    
    int n,h,l,d = 0;
    n = countNodes(root);
    h = height(root);
    l = level(root);
    d = findMaxInTree(root);
    cout<<"Total numbers of node---------------------------:"<<n<<endl;
    cout<<"Height of Tree-------------------------------------:"<<h<<endl;
    cout<<"Level of Tree------------------------------------------:"<<l<<endl;
    cout<<"Maximum value in tree--------------------------------:"<<d<<endl;
    int leaf = 0;
    leaf = checkLeaf(root);
    cout<<"\nPossible Number of Leaf Nodes-------------------------: "<<leaf<<endl;
    int inte = 0;
    //inte = numI(root);
    //printf("\n%d",inte);
    cout<<"Range of Levels----------------------------------: 0-"<<l-1<<endl;
    
    inte = interior(root);
    cout<<"Interior nodes in complete binary Tree:------------"<<inte<<endl;
    system("Pause");
    }
    
    
    
    
