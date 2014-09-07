/*
	A very Efficient implementation of Binary Search Trees

	Author : Sourav Sarkar
	email:   souravmathlover@gmail.com
	date:	 16-June-2013-1:11 AAM
*/


#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>

class Bnode{
	public:
	int v;
	Bnode *left;
	Bnode *right;
	Bnode *parent;
	int t;
	
	
	Bnode(){
		v=-1;
		left=0;
		right=0;
		parent=0;
		t=0;
	}
	Bnode(int a,Bnode *p,int flag){
		v=a;
		left=0;
		right=0;
		parent=p;
		t=flag;
	}
	int getVal(){
		return v;
	}
	int setVal(int x){
		v=x;
	}
	void print(){
		printf(" %d ",v);
		return;
	}
	int clear(){

		return 1;
	}
};

class BST{
	Bnode *head;
	int size;
	public:
		BST(){
			head=0;
			size=0;
		}
		Bnode* getHead(){
			return head;
		}
		int clear(){
			printf("\nSize = %d",size);
			Bnode *t=head,*p;
			int seekleft=1,returnR=0,returnL=0;
			//int deleteCurrent=0;;
			while(1){
				//printf("\nLooping !!");
				if(seekleft==1){
					while(t->left!=0){
						t=t->left;
					}
					if(t->right==0){
						// we got a leaf !!!
						p=t->parent;
						if(p==0){
							// we are now deleting the root !!!
							delete t;
							//printf("\nNode Deleted !!");
							size--;
							break;
						}
						if(t->t==0){
							p->left=0;
							returnL=1;
							returnR=0;
						}else{
							p->right=0;
							returnR=1;
							returnL=0;
						}
						delete t;
						//printf("\nNode Deleted !!");
						size--;
						seekleft=0;
						t=p;
					}else{
						t=t->right;
						seekleft=1;
						returnL=0;
						returnR=0;
					}
					continue;
				}
				if(returnL==1){
					if(t->right==0){
						returnL=0;
						returnR=1;
						seekleft=0;
						continue;
					}
					t=t->right;
					seekleft=1;
					returnR=returnL=0;
				}
				if(returnR==1){
					p=t->parent;
					if(p==0){
						// we are now deleting the root !!!
						delete t;
						//printf("\nNode Deleted !!");
						size--;
						break;
					}
					if(t->t==0){
						p->left=0;
						returnL=1;
						returnR=0;
					}else{
						p->right=0;
						returnR=1;
						returnL=0;
					}
					delete t;
					//printf("\nNode Deleted !!");
					size--;
					seekleft=0;
					t=p;
				}
			}
			if(size==0){
				printf("\nBST successfully cleared !!");
				return 1;
			}else{
				printf("\n Memory Leak !!! %d nodes remain !!",size);
			}
			return 0;
		}

		int insert(int a){
			if(head==0){
				// tree is empty !!
				head=new Bnode(a,0,0);
				size++;
				return 1;
			}
			// the tree is not empty !!
			Bnode *t;
			t=head;
			int flag;
			while(1){
				if(t==0){
					printf("\nERROR in tree structure !!! abort");
					return 0;
				}
				if(a==t->getVal()){
					printf("\nERROR trying to enter duplicate value !!!");
					return 0;
				}
				if(a<t->getVal()){
					if(t->left==0){
						// if the left node of t is empty then new insertion here
						flag=0;
						break;
					}
					t=t->left;
				}
				if(a>t->getVal()){
					if(t->right==0){
						// if the right node of t is empty then new insertion here
						flag=1;
						break;
					}
					t=t->right;
				}
			}
			if(flag==0){
				t->left=new Bnode(a,t,0);
				size++;
				return 1;
			}
			if(flag==1){
				t->right=new Bnode(a,t,1);
				size++;
				return 1;
			}
		}
		Bnode* search(int a){
			Bnode *t;
			t=head;
			while(t!=0){
				if(t->getVal()==a){
					break;
				}
				if(t->getVal()>a){
					t=t->left;
					continue;
				}
				if(t->getVal()<a){
					t=t->right;
					continue;
				}
			}
			// if(t==0){
			// 	printf("\nNo such node found !!");
			// 	return 0;
			// }
			return t;
		}
		int deleteL(int a){
			// it deletes from the left tree
			printf("\nin deleteL");
			Bnode *t=search(a);
			if(t==0){
				printf("\nNo Such Node Exist !!!");
				return 0;
			}


			Bnode *p;
			p=t->parent;
			int rflag=0; // 0 means we are not deleting the root
			if(p==0){
				// we are going to delete the root
				t->parent=new Bnode();
				p=t->parent;
				p->left=t;
				rflag=1;
				// dummy node attacehd
			}
			if(t->left==0&&t->right==0){
				// t is just a leaf !! we are so lucky !!
				if(t->t==0){
					// if t is a left child
					p->left=0;
				}else{
					p->right=0;
				}
				t->clear();
				delete t;
				if(rflag==1){
					// if we have deleted the root
					delete p;
					head=0; // there was just only one node ... so tree is empty
				}
				return 1;
			}
			if(t->left!=0&&t->right==0){
				if(t->t==0){
					// if t is a left child
					p->left=t->left;
					t->left->parent=p;
					t->left->t=0;
				}else{
					p->right=t->left;
					t->left->parent=p;
					t->left->t=1;
				}
				t->clear();
				delete t;
				if(rflag==1){
					// if we have deleted the root
					head=p->left;// as we take the head always a left child
					head->t=0;
					head->parent=0;
					delete p;
				}
				return 1;
			}
			if(t->left==0&&t->right!=0){
				if(t->t==0){
					// if t is a left child
					p->left=t->right;
					t->right->parent=p;
					t->right->t=0;
				}else{
					p->right=t->right;
					t->right->parent=p;
					t->right->t=1;
				}
				t->clear();
				delete t;
				if(rflag==1){
					// if we have deleted the root
					head=p->left;
					head->t=0;
					head->parent=0;
					delete p;
				}
				return 1;
			}
			// if both t has both left and right child !!


			if(rflag==1){
				head=p->left;
				head->parent=0;
				delete p;
			}


			Bnode *l=t->left;
			while(l->right!=0){
				l=l->right;
			}
			// now l points to the rightmost node of the left tree of t

			t->setVal(l->getVal());
			p=l->parent;
			if(l->left!=0){
				if(l->t==0){
					// if t is a left child
					p->left=l->left;
					l->left->parent=p;
					l->left->t=0;
				}else{
					p->right=l->left;
					l->left->parent=p;
					l->left->t=1;
				}
			}else{
				if(l->t==0){
					// if t is a left child
					p->left=0;
				}else{
					p->right=0;
				}
			}
			l->clear();
			delete l;
			// here we ACTUALLY never delete the root node !!
			return 1;
		}

		int deleteR(int a){
			// it deletes from the right tree
			printf("\nin deleteR\n");
			Bnode *t=search(a);
			if(t==0){
				printf("\nNo Such Node Exist !!!");
				return 0;
			}


			Bnode *p;
			p=t->parent;
			int rflag=0; // 0 means we are not deleting the root
			if(p==0){
				// we are going to delete the root
				printf("\nGoing to delete Root !!");
				t->parent=new Bnode();
				p=t->parent;
				p->left=t;
				rflag=1;
				// dummy node attacehd
			}
			if(t->left==0&&t->right==0){
				// t is just a leaf !! we are so lucky !!
				if(t->t==0){
					// if t is a left child
					p->left=0;
				}else{
					p->right=0;
				}
				t->clear();
				delete t;
				if(rflag==1){
					// if we have deleted the root
					delete p;
					head=0; // there was just only one node ... so tree is empty
				}
				return 1;
			}
			if(t->left!=0&&t->right==0){
				if(t->t==0){
					// if t is a left child
					p->left=t->left;
					t->left->parent=p;
					t->left->t=0;
				}else{
					p->right=t->left;
					t->left->parent=p;
					t->left->t=1;
				}
				t->clear();
				delete t;
				if(rflag==1){
					// if we have deleted the root
					head=p->left;// as we take the head always a left child
					head->t=0;
					head->parent=0;
					delete p;
				}
				return 1;
			}
			if(t->left==0&&t->right!=0){
				if(t->t==0){
					// if t is a left child
					p->left=t->right;
					t->right->parent=p;
					t->right->t=0;
				}else{
					p->right=t->right;
					t->right->parent=p;
					t->right->t=1;
				}
				t->clear();
				delete t;
				if(rflag==1){
					// if we have deleted the root
					head=p->left;
					head->t=0;
					head->parent=0;
					delete p;
				}
				return 1;
			}
			// if both t has both left and right child !!
			
			if(rflag==1){
				head=p->left;
				head->parent=0;
				delete p;
			}

			Bnode *l=t->right;
			while(l->left!=0){
				l=l->left;
			}
			// now l points to the leftmost node of the right tree of t

			t->setVal(l->getVal());
			p=l->parent;
			if(l->right!=0){
				if(l->t==0){
					// if t is a left child
					p->left=l->right;
					l->right->parent=p;
					l->right->t=0;
				}else{
					p->right=l->right;
					l->right->parent=p;
					l->right->t=1;
				}
			}else{
				if(l->t==0){
					// if t is a left child
					p->left=0;
				}else{
					p->right=0;
				}
			}
			l->clear();
			delete l;
			// here we ACTUALLY never delete the root node !!
			return 1;
		}

		int pop(int a){
			//return deleteR(a);
			if(rand()%2){
				return deleteL(a);
			}else{
				return deleteR(a);
			}
		}


		void printInorder(int a[],int *count){
			*count=0;
			if(head==0){
				printf("Tree is empty !! ");
				return;
			}
			Bnode *t;
			t=head;
			int flag=0;
			int returnR=0;
			int ujump,seekleft;
			seekleft=1;
			while(1){
				if(seekleft==1){
					while(t->left!=0){
						t=t->left;
					}
				}
				if(returnR==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				//t->print();
				a[*count]=t->getVal();
				(*count)++;
				if(t->right==0){
					// t is a leave
					ujump=1;
				}else{
					t=t->right;
					seekleft=1;
					returnR=0;
					continue;
				}
				if(ujump==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
			}
			return;
		}

		void printInorder(){
			//*count=0;
			if(head==0){
				printf("Tree is empty !! ");
				return;
			}
			Bnode *t;
			t=head;
			int flag=0;
			int returnR=0;
			int ujump,seekleft;
			seekleft=1;
			while(1){
				if(seekleft==1){
					while(t->left!=0){
						t=t->left;
					}
				}
				if(returnR==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				t->print();
				//a[*count]=t->getVal();
				//(*count)++;
				if(t->right==0){
					// t is a leave
					ujump=1;
				}else{
					t=t->right;
					seekleft=1;
					returnR=0;
					continue;
				}
				if(ujump==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
			}
			return;
		}

		void printPreorder(int *a,int *count){
			//printf("\nhere");
			*count=0;
			if(head==0){
				printf("Tree is empty !! ");
				return;
			}
			Bnode *t;
			t=head;
			int flag=0;
			int returnR=0;
			int ujump,seekleft;
			seekleft=1;
			while(1){
				if(seekleft==1){
					while(t->left!=0){
						//t->print();
						a[*count]=t->getVal();
						(*count)++;
						t=t->left;
					}
					a[*count]=t->getVal();
					(*count)++;
					//t->print();
				}
				if(returnR==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				
				if(t->right==0){
					// t is a leave
					ujump=1;
				}else{
					t=t->right;
					seekleft=1;
					returnR=0;
					continue;
				}
				if(ujump==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
			}
			return;


			return;
		}
		void printPreorder(){

			if(head==0){
				printf("Tree is empty !! ");
				return;
			}
			Bnode *t;
			t=head;
			int flag=0;
			int returnR=0;
			int ujump,seekleft;
			seekleft=1;
			while(1){
				if(seekleft==1){
					while(t->left!=0){
						t->print();
						t=t->left;
					}
					t->print();
				}
				if(returnR==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				
				if(t->right==0){
					// t is a leave
					ujump=1;
				}else{
					t=t->right;
					seekleft=1;
					returnR=0;
					continue;
				}
				if(ujump==1){
					if(t->t==0){
						returnR=0;
						seekleft=0;
					}else{
						returnR=1;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
			}
			return;


			return;
		}
	void printPostorder(int *a,int *count){
			*count=0;
			if(head==0){
				printf("Tree is empty !! ");
				return;
			}
			Bnode *t;
			t=head;
			int flag=0;
			int returnR=0,returnL=0;
			int ujump,seekleft;
			seekleft=1;
			while(1){
				if(seekleft==1){
					if(t->left==0){
						if(t->right==0){
							// we are at a leaf
							//t->print();
							a[*count]=t->getVal();
							(*count)++;
							if(t->t==0){
								returnR=0;
								returnL=1;
								seekleft=0;
							}else{
								returnR=1;
								returnL=0;
								seekleft=0;
							}
							t=t->parent;
							if(t==0){
								break;
							}
							continue;
						}else{
							returnL=1;
							returnR=0;
							seekleft=0;
							continue;
						}
					}
					while(t->left!=0){
						t=t->left;
						
					}
					if(t->right!=0){
						t=t->right;
						seekleft=1;
						returnR=0;
						returnL=0;
						continue;
					}
					//t->print();
					a[*count]=t->getVal();
					(*count)++;
					//printf("\n");
					if(t->t==0){
						returnR=0;
						returnL=1;
						seekleft=0;
					}else{
						returnR=1;
						returnL=0;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				if(returnR==1){
					//t->print();
					a[*count]=t->getVal();
					(*count)++;
					if(t->t==0){
						returnR=0;
						returnL=1;
						seekleft=0;
					}else{
						returnR=1;
						returnL=0;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				if(returnL==1){
					if(t->right==0){
						//t->print();
						a[*count]=t->getVal();
						(*count)++;
						// t is a leave
						ujump=1;
					}else{
						t=t->right;
						seekleft=1;
						returnR=0;
						returnL=0;
						continue;
					}
				}
				if(ujump==1){
					if(t->t==0){
						returnR=0;
						returnL=1;
						seekleft=0;
					}else{
						returnR=1;
						returnL=0;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
			}
			return;


			return;
		}
		void printPostorder(){

			if(head==0){
				printf("Tree is empty !! ");
				return;
			}
			Bnode *t;
			t=head;
			int flag=0;
			int returnR=0,returnL=0;
			int ujump,seekleft;
			seekleft=1;
			while(1){
				if(seekleft==1){
					if(t->left==0){
						if(t->right==0){
							// we are at a leaf
							t->print();
							if(t->t==0){
								returnR=0;
								returnL=1;
								seekleft=0;
							}else{
								returnR=1;
								returnL=0;
								seekleft=0;
							}
							t=t->parent;
							if(t==0){
								break;
							}
							continue;
						}else{
							returnL=1;
							returnR=0;
							seekleft=0;
							continue;
						}
					}
					while(t->left!=0){
						t=t->left;
						
					}
					if(t->right!=0){
						t=t->right;
						seekleft=1;
						returnR=0;
						returnL=0;
						continue;
					}
					t->print();
					//printf("\n");
					if(t->t==0){
						returnR=0;
						returnL=1;
						seekleft=0;
					}else{
						returnR=1;
						returnL=0;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				if(returnR==1){
					t->print();
					if(t->t==0){
						returnR=0;
						returnL=1;
						seekleft=0;
					}else{
						returnR=1;
						returnL=0;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
				if(returnL==1){
					if(t->right==0){
						t->print();
						// t is a leave
						ujump=1;
					}else{
						t=t->right;
						seekleft=1;
						returnR=0;
						returnL=0;
						continue;
					}
				}
				if(ujump==1){
					if(t->t==0){
						returnR=0;
						returnL=1;
						seekleft=0;
					}else{
						returnR=1;
						returnL=0;
						seekleft=0;
					}
					t=t->parent;
					if(t==0){
						break;
					}
					continue;
				}
			}
			return;


			return;
		}

		void printInorderRecursive(Bnode *h){
			if(h==0){
				return;
			}
			printInorderRecursive(h->left);
			h->print();
			printInorderRecursive(h->right);
			return;
		}
		void printInorderRecursive(Bnode *h,int *a,int *count){
			if(h==0){
				return;
			}
			printInorderRecursive(h->left,a,count);
			//h->print();
			a[*count]=h->getVal();
			(*count)++;
			printInorderRecursive(h->right,a,count);
			return;
		}
		void printPreorderRecursive(Bnode *h){
			if(h==0){
				return;
			}
			h->print();
			printPreorderRecursive(h->left);
			printPreorderRecursive(h->right);
			return;
		}
		void printPreorderRecursive(Bnode *h,int *a,int *count){
			if(h==0){
				return;
			}
			//h->print();
			a[*count]=h->getVal();
			(*count)++;
			printPreorderRecursive(h->left,a,count);
			printPreorderRecursive(h->right,a,count);
			return;
		}
		void printPostorderRecursive(Bnode *h){
			if(h==0){
				return;
			}
			printPostorderRecursive(h->left);
			printPostorderRecursive(h->right);
			h->print();
			return;
		}
		void printPostorderRecursive(Bnode *h,int *a,int *count){
			if(h==0){
				return;
			}
			printPostorderRecursive(h->left,a,count);
			printPostorderRecursive(h->right,a,count);
			//h->print();
			a[*count]=h->getVal();
			(*count)++;
			return;
		}

		void printSpace(int d){
			while(d>0){
				printf(" ");
			}
			return;
		}
		void printTab(int d){
			while(d>0){
				printf("\t");
			}
			return;
		}

};

/**********************Testing Functions*************************/
int isSorted(int a[],int n){
	for(int i=0;i<=n-2;i++){
		if(a[i]>a[i+1]){
			return 0;
		}
	}
	return 1;
}
int isSame(int *a,int *b,int size,int size2){
	if(size!=size2){
		printf("\nsizea = %d\tsizeb = %d",size,size2);
		return 0;
	}
	for(int i=0;i<size;i++){
		if(a[i]!=b[i]){
			return 0;
		}
	}
	return 1;
}
int randomize(int *a,int n){
	int i=0,t,x;
	int b[n];
	for(i=0;i<n;i++){
		t=rand()%(n-i)+i;
		b[i]=a[t];
		x=a[i];
		a[i]=a[t];
		a[t]=x;
	}
	printf("\n");
	for(i=0;i<n;i++){
		a[i]=b[i];
		printf(" %d ",a[i]);
	}
	return 1;
}
/***************************************************************/



int main(){



	/*****************Testing***********************************/
	{
		int n,x,s;
		BST t;
		scanf("%d",&n);
		s=n;
		int a[n],b[n];
		int counta,countb;
		srand ( (unsigned)time ( NULL ) );
		while(n>0){
			//printf("\nEnter node :");
			//scanf("%d",&x);
			x=rand()%(100*s);
			printf("\nX = %d",x);
			t.insert(x);
			t.printInorder(a,&counta);
			if(isSorted(a,counta)){
				//printf("\nInorder Passed !!");
			}else{
				printf("\nInorder Failed :(");
				break;
			}
			//printf("\nPre order : ");
			//printf("\n");
			t.printPreorder(a,&counta);
			//printf("\n");
			countb=0;
			t.printPreorderRecursive(t.getHead(),b,&countb);
			if(isSame(a,b,counta,countb)){
				//printf("\nPreorder Passed !!");
			}else{
				printf("\nPreorder Failed :(");
				printf("\n");
				t.printPreorder();
				printf("\n");
				t.printPreorderRecursive(t.getHead());
				break;
			}

			//printf("\nPost order :");
			//printf("\n");
			t.printPostorder(a,&counta);
			//printf("\n");
			countb=0;
			t.printPostorderRecursive(t.getHead(),b,&countb);
			if(isSame(a,b,counta,countb)){
				//printf("\nPostorder Passed !!");
			}else{
				printf("\nPostorder Failed :(");
				printf("\n");
				t.printPostorder();
				printf("\n");
				t.printPostorderRecursive(t.getHead());
				break;
			}


			n--;
		}
		printf("\n");
		t.printInorder();
		int r[s],count;
		t.printPostorder(r,&count);
		randomize(r,count);
		printf("\n");

		t.clear();


	// 	n=s;
	// 	int i=0;
	// 	while(n>0){
	// 		printf("\nEnter node :");
	// 		//scanf("%d",&x);
	// 		if(i==count){
	// 			break;
	// 		}
	// 		x=r[i];
	// 		printf("\nX=%d",x);
	// 		i++;
			
	// 		t.pop(x);
	// 		t.printInorder(a,&counta);
	// 		if(isSorted(a,counta)){
	// 			printf("\nInorder Passed !!");
	// 		}else{
	// 			printf("\nInorder Failed :(");
	// 			t.printInorder();
	// 			break;
	// 		}
	// 		//printf("\nPre order : ");
	// 		//printf("\n");
	// 		t.printPreorder(a,&counta);
	// 		//printf("\n");
	// 		countb=0;
	// 		t.printPreorderRecursive(t.getHead(),b,&countb);
	// 		if(isSame(a,b,counta,countb)){
	// 			printf("\nPreorder Passed !!");
	// 		}else{
	// 			printf("\nPreorder Failed :(");
	// 			printf("\n");
	// 			t.printPreorder();
	// 			printf("\n");
	// 			t.printPreorderRecursive(t.getHead());
	// 			break;
	// 		}

	// 		//printf("\nPost order :");
	// 		//printf("\n");
	// 		t.printPostorder(a,&counta);
	// 		//printf("\n");
	// 		countb=0;
	// 		t.printPostorderRecursive(t.getHead(),b,&countb);
	// 		if(isSame(a,b,counta,countb)){
	// 			printf("\nPostorder Passed !!");
	// 		}else{
	// 			printf("\nPostorder Failed :(");
	// 			printf("\n");
	// 			t.printPostorder();
	// 			printf("\n");
	// 			t.printPostorderRecursive(t.getHead());
	// 			break;
	// 		}


	// 		n--;
	// 	}
	// 	printf("\n");
	// 	//t.printInorder();
	// 	printf("\n");

	}
	/*********************************Testing**********************/

	return 0;
}


