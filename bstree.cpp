#include <iostream>
#include <string>
using namespace std;

class bstree{
	public:
		bstree();
		int leftheight();
		void insert(struct Node* &root,int x);
		int search(int x);
		int min();
		int max();
		int height(struct Node* node);
		void inorder(struct Node* root);
		void preorder(struct Node* root);
		void postorder(struct Node* root);
};

struct Node{
	int data;
	Node* left, *right;
	};
	struct Node* root;
	
bstree::bstree(){
	root=NULL;
}

void bstree::insert(struct Node* &root,int x){
    Node* newnode = new Node();
	newnode->data=x;
	newnode->left=newnode->right=NULL; 
  
    Node* temp = root; 
    Node* y = NULL; 

    while (temp != NULL) { 
        y = temp; 
        if (x < temp->data){
            temp = temp->left;
			 } 
        else{
            temp = temp->right; 
    	} 
	}

    if (root == NULL){
        root = newnode; 
	}	
    else if (x < y->data) {
       y->left = newnode; 
	}
 
    else{
        y->right = newnode; 
	}	
    return;
}

int bstree::search(int x) { 
	int level=1;
	Node* temp=root;
    while (temp != NULL) { 
        if (x > temp->data){
        	level++;
            temp = temp->right; 
  		}
        else if (x < temp->data){
        	level++;
            temp = temp->left; 
        }
        else
            return level;  
    } 
    return 0;
} 

int bstree::max(){
	Node* temp;
	temp=root;
	while(temp->right!=NULL){
		temp=temp->right;
	}
	cout<<temp->data;
}

int bstree::min(){
	Node* temp;
	temp=root;
	while(temp->left!=NULL){
		temp=temp->left;
	}
	cout<<temp->data;
}

int bstree::height(Node* node){
    if (node == NULL)  
        return 0;  
    else{  
        int lDepth = height(node->left);  
        int rDepth = height(node->right);  
      
        if (lDepth > rDepth)  
            return(lDepth + 1);  
        else return(rDepth + 1);  
    }  
}

void bstree::postorder(struct Node* root){;
	if(root == NULL) {
		return;
	}
	postorder(root->left);    
	postorder(root->right);   
	printf("%d ",root->data); 
	return;
}

void bstree::preorder(struct Node* root){

	if(root == NULL) return;

	printf("%d ",root->data); 
	preorder(root->left);     
	preorder(root->right);    
}

void bstree::inorder(struct Node* root){
	if(root == NULL) return;

	inorder(root->left);       
	printf("%d ",root->data); 
	inorder(root->right);      
}

int main(){
	bstree T;
	int N,M,node,value;
	
	//Εισαγωγή Πλήθους Ν ακεραίων προς εισαγωγή στο ΔΔΑ
	cin>>N;
	for(int i=0;i<N;i++){
		cin>>node;
		T.insert(root,node);
	}

	//Εισαγωγή πλήθους Μ ακεραίων προς αναζήτηση στο ΔΔΑ
	cin>>M;
	int level[M],height,a,j=0;
	string s;
	for(j;j<M-1;j++){
		scanf("%d",&value);
		a=T.search(value);
		s+=to_string(a)+" ";
	}
	scanf("%d",&value);
	a=T.search(value);
	s+=to_string(a);
	
	//1η Γραμμή: Εκτύπωση Ύψους ΔΔΑ
	height=T.height(root);
	cout<<height;
	cout<<endl;
	
	//2η Γραμμή: Εκτύπωση Ελαχίστου και Μεγίστου ακεραίου στο ΔΔΑ
	T.min();
	cout<<" ";
	T.max();
	cout<<endl;
	
	//3η Γραμμή: Εκτύπωση αποτελεσμάτων αναζητήσεων
	cout<<s;
	cout<<endl;
	
	//4η Γραμμή: Εκτύπωση στοιχείων ΔΔΑ (ενδοδιατεταγμένα,προδιατεταγμένα,μεταδιατεταγμένα)
	T.inorder(root);
	cout<<"end"<<endl;
	T.preorder(root);
	cout<<"end"<<endl;
	T.postorder(root);
	cout<<"end"<<endl;
	
	return 0;
}
