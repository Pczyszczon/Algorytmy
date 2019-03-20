#include <iostream>
#include <stack>

using namespace std;

struct node{
	int x;
	node* left;
	node* right;
    node* parent;
	
	node(int x0, node* l=NULL, node* r=NULL)
		:x(x0), left(l), right(r)
	{}
};

void display(node *t,char z1=' ',char z2=' '){
	if(t){
		std::cout<<z1;
		display(t->left,'(',')');
		std::cout<<t->x;
		display(t->right,'[',']');
		std::cout<<z2;
	}
}

void insert(node *& t, int x){
	node **t1=&t;
	while(*t1)
		if(x<(*t1)->x)
			t1=&((*t1)->left);
		else
			t1=&((*t1)->right);
	*t1=new node(x);
} 

node* find(node* t,int x){
	while(t && t->x!=x){
		if(x<t->x) 
			t=t->left; 
		else
			t=t->right; 
	}
	return t;
}

void remove(node *&t, int x){
	node **t1=&t;
	while (*t1 && (*t1)->x!=x){
		if(x<(*t1)->x) 
			t1=&((*t1)->left); 
		else
			t1=&((*t1)->right); 
	}
	if(*t1){
		if((*t1)->right && (*t1)->left){
			node **t2=&((*t1)->right);
			while ((*t2)->left)
				t2=&((*t2)->left);
			(*t1)->x=(*t2)->x;
			t1=t2;
		}	
		if((*t1)->left==NULL){
			node *d=(*t1)->right;
			delete *t1;
			(*t1)=d;
		}
		else{
		    node *d=(*t1)->left;	
			delete *t1;
			(*t1)=d;
		}
	}
}

void inorder(node *t){
	if(t){
		inorder(t->left);
		std::cout<<t->x<<" ";
		inorder(t->right);
	}
}

void inorder_do(node *t, void f(node*)){
	if(t){
		inorder_do(t->left, f);
		f(t);
		inorder_do(t->right, f);
	}
}

void inorder_do_iterative(node *t, void f(node*)){
    node * current = t;
    std::stack<node*> s;

    while(1){
        if (current != NULL){
            s.push(current);
            current = current->left;
        }
        else{
            if (!s.empty()){
                current = s.top(); s.pop();
                cout << current->x << endl;
                current = current->right;
            }
            else
                return;
        }
    }
}

void g(node*const root){
    std::cout << root->x << endl;
}

int main(){
    node* t=NULL;
    
    insert(t,3);
    insert(t,4);
    insert(t,1);
    insert(t,7);
    insert(t,-4);
    insert(t,9);
    insert(t,2);
    
    cout<<"all Node: "; display(t);cout<<endl;
    cout<<"find 7: "<<find(t,7)->x<<endl;
    cout<<"remove("<<t->x<<"): "; remove(t,t->x); display(t); cout<<endl;
    cout<<"remove 2: "; remove(t,2); display(t); cout<<endl;

	inorder_do_iterative(t,g);
    return 0;
}
