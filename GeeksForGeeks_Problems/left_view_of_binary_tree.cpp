/* A binary tree node has data, pointer to left child
   and a pointer to right child */
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};

// A wrapper over leftViewUtil()
void leftView(struct Node *root);


/* Driver program to test size function*/
int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);

        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];

        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }

     leftView(root);
     cout << endl;
  }
  return 0;
}
// } Driver Code Ends
/* A binary tree node

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
 */

// A wrapper over leftViewUtil()
//vector<int> v;
void leftViewx(Node* root,queue<Node*> &q,vector<int> &v){
    while(!q.empty()){
        Node* k = q.front();
        if(k == NULL){
            q.pop();
            if(!q.empty()){
            q.push(NULL);
            v.push_back(INT_MIN);
            }
            continue;
        }
        if(k->left != NULL){
        q.push(k->left);
        }
        if(k->right != NULL){
        q.push(k->right);
        }
        v.push_back(k->data);
        q.pop();
    }
}

void leftView(Node *root)
{
    vector<int> v;
    if(root == NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    leftViewx(root,q,v);
    cout<<v[0]<<" ";
    for(int i=1;i<v.size();i++){
        if(v[i] == INT_MIN){
            if(i+1 < v.size()){
                cout<<v[i+1]<<" ";
            }
        }
    }
   // Your code here
}