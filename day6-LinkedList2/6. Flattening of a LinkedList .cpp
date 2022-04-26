/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

Node *mergeLists(Node* A,Node* B)
{
    Node* tmp = new Node(0);
    Node *merger_head=tmp;
    while(A!=NULL && B!=NULL){
        if(A->data <= B->data){
            tmp->bottom=A;
            tmp=A;
            A=A->bottom;
        }
        else{
            tmp->bottom=B;
            tmp=B;
            B=B->bottom;
        }
    }
    if(A!=NULL) tmp->bottom=A;
    if(B!=NULL) tmp->bottom=B;
    
    return merger_head->bottom;
}

/*  Function which returns the  root of the flattened linked list. */

Node *flatten(Node *root)
{
   if(root==NULL)
            return root;
   if(root->next==NULL)
            return root;  
   Node *res=flatten(root->next);
   return mergeLists(root,res);
}

// Time Complexity: O(N), where N is the total number of nodes present

// Reason: We are visiting all the nodes present in the given list.

// Space Complexity: O(1), w/o recursion stack which is O(n)n in worst case

// Reason: We are not creating new nodes or using any other data structure.
