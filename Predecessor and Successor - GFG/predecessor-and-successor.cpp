//{ Driver Code Starts
// C++ program to find predecessor and successor in a BST
#include "bits/stdc++.h"
using namespace std;

// BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};


// } Driver Code Ends
/* BST Node
struct Node
{
	int key;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    key = x;
	    left = NULL;
	    right = NULL;
	}
};
*/

// This function finds predecessor and successor of key in BST.
// It sets pre and suc as predecessor and successor respectively
class Solution
{
    public:
    void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
    {
        // Your code goes here
        pre=NULL, suc=NULL;
        int maxi=-1, mini=-1;
        Node* temp=root;
        while(temp!=NULL){
            if(temp->key<key){
                if(temp->key>mini){
                    mini=temp->key;
                    pre=temp;
                }
                temp=temp->right;
            }
            else if(temp->key>=key){
                temp=temp->left;
            }
            // else if(temp->key>=key){
            //     break;
            // }
        }

        temp=root;
        while(temp!=NULL){
            if(temp->key>key){
                if(maxi==-1){
                    maxi=temp->key;
                    suc=temp;
                }
                else if(temp->key<maxi){
                    maxi=temp->key;
                    suc=temp;
                }
                temp=temp->left;
            }
            else if(temp->key<=key){
                temp=temp->right;
            }
            // else if(temp->key<=key){
            //     break;
            // }
        }
        
        // while(root!=NULL){
        //     if(root->key>key){
        //         if(maxi==-1){
        //             maxi=root->key;
        //             suc=root;
        //         }
        //         else if(maxi!=-1 && root->key<maxi){
        //             maxi=root->key;
        //             suc=root;
        //         }
        //         root=root->left;
        //     }
        //     else if(root->key<key){
        //         if(root->key>mini){
        //             mini=root->key;
        //             pre=root;
        //         }
        //         root=root->right;
        //     }
        //     else if(root->key==key){
        //         if(root->left){
        //             pre=root->left;
        //         }
        //         if(maxi==-1){
        //             maxi=root->key;
        //             suc=root;
        //         }
        //         while(root!=NULL && root->key<maxi){
        //             maxi=root->key;
        //             suc=root;
        //             root=root->right;
        //         }
        //         break;
        //     }
        // }
    }
};

//{ Driver Code Starts.

Node* buildTree(string str)
{
   // Corner Case
   if(str.length() == 0 || str[0] == 'N')
       return NULL;

   // Creating vector of strings from input
   // string after spliting by space
   vector<string> ip;

   istringstream iss(str);
   for(string str; iss >> str; )
       ip.push_back(str);

   // Create the root of the tree
   Node* root = new Node(stoi(ip[0]));

   // Push the root to the queue
   queue<Node*> queue;
   queue.push(root);

   // Starting from the second element
   int i = 1;
   while(!queue.empty() && i < ip.size()) {

       // Get and remove the front of the queue
       Node* currNode = queue.front();
       queue.pop();

       // Get the current node's value from the string
       string currVal = ip[i];

       // If the left child is not null
       if(currVal != "N") {

           // Create the left child for the current node
           currNode->left = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->left);
       }

       // For the right child
       i++;
       if(i >= ip.size())
           break;
       currVal = ip[i];

       // If the right child is not null
       if(currVal != "N") {

           // Create the right child for the current node
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}
// Driver program to test above functions
int main() {
   
   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
        getline(cin, s);
        Node* root = buildTree(s);
        getline(cin, s);
        int k = stoi(s);
        Node *pre=NULL,*succ=NULL;
        Solution ob;
        ob.findPreSuc(root,pre,succ,k);
        (pre!=NULL)?cout<<pre->key:cout<<-1;
        cout<<" ";
        (succ!=NULL)?cout<<succ->key:cout<<-1;
        cout<<endl;
        // inOrderTraversal(root);
   }
   return 0;
}
// } Driver Code Ends