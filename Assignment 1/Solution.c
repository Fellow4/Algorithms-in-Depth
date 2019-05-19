#include <stdio.h>
#include <stdlib.h>

//NODE TYPE-1
typedef struct node{
    float data;
    struct node* ptr;
}node;

//NODE TYPE-2
typedef struct NODE{
    int mark;
    float imp;
    struct NODE *PTR;
}NODE;

//FUNCTION TO PUSH AN ELEMENT INTO A NODE OF A LINKED LIST
void push(node **ref,float val){
    node *temp=(node*)malloc(sizeof(node));
    temp->data = val;
    temp->ptr=*ref;
    *ref=temp;
}


void PUSH(NODE **ref,int a,float b){
    NODE *temp=(NODE*)malloc(sizeof(NODE));
    temp->mark = a;
    temp->imp = b;
    temp->PTR = *ref;
    *ref = temp;
}

//FUNCTION TO COUNT THE NUMBER OF DISTICT ELEMENTS IN A LINKED LIST
int dist(node *head){
    int counter = 1;
    node *temp = head;
    node *prev = head;
    while(temp != NULL){
        if(temp->data != prev->data){
            counter++;
            prev = temp;
        }
        temp = temp->ptr;
    }
    return counter;
}

//FUNCTION TO PRINT THE ELEMENTS OF A LINKED LIST.USES THE FORWARD ITERATOR METHOD
void print(struct node* root){
    while(1){
        printf("%f", root->data);
        printf(" ");
        if(root->ptr==NULL) break;
        root=root->ptr;
    }
    printf("\n");
    return ;
 }

//SPLIT THE A LINKED LIST INTO 2 PARTS-FRONT AND BACK BY BREAKING THE LINK IN THE MIDDLE
 void split(node *a,node **l,node **r){
   int counter=0;
   node *t=a;
   while(t != NULL) {
        t=t->ptr;
        counter++;
   }
   int val=0;
   t=a;
   while(1){
    val++;
    if(val == counter/2) break;
    t=t->ptr;
   }
   *r=t->ptr;
   t->ptr=NULL;
   *l=a;
   return ;
}

//MERGE TWO SORTED LINKED LISTS
node* mergelist(node *a,node *b){
   node *p=a,*q=b,*temp,*counter;
   if(p->data < q->data){
        temp=p;
        counter=p;
        p=p->ptr;
   }
   else {
        temp=q;
        counter=q;
        q=q->ptr;
   }
   while(p!=NULL && q!=NULL){
     if(p->data < q->data){
        temp->ptr=p;
        temp=p;
        p=p->ptr;
     }
     else {
        temp->ptr=q;
        temp=q;
        q=q->ptr;
     }
   }
   if(q == NULL) temp->ptr=p;
   else if(p == NULL) temp->ptr=q;
   return counter;
}

//MERGESORT FUNCTION SPLITS THE LINKED LIST BY CALLING SPLIT
//RECURSIVELY SORTS BOTH HALVES AND CALLS MERGELIST
void mergesort(node **ref){
   node *head = *ref;
   node *a;
   node *b;
   if(head->ptr == NULL) return;
   split(head,&a,&b);
   mergesort(&a);
   mergesort(&b);
   *ref=mergelist(a,b);
}


int main(){
  //SINGLE STORES THE INDEX OF A COMPANY TO DETERMINE THE NUMBER OF COMPANIES
  node *SINGLE = NULL;
  NODE *DOUBLE = NULL;
  int x,y,z,u,v;
  float val;
  //SCAN VALUES TILL THE END OF FILE
  while(scanf("%d %d:%d-%d:%d %f",&x,&y,&z,&u,&v,&val) !=  EOF){
    push(&SINGLE,x);
    PUSH(&DOUBLE,x,val);
    }
  mergesort(&SINGLE);
  int N = dist(SINGLE);
  node **org = (node**)malloc(N*sizeof(node*));
  for(int i=0;i<N;++i) org[i] = NULL;
  NODE *TEMP = DOUBLE ;
  while(TEMP != NULL){
    push(&org[TEMP->mark -1],TEMP->imp);
    TEMP = TEMP->PTR ;
  }
  for(int i=0;i<N;++i) mergesort(&org[i]);
  for(int i=0;i<N;++i){
    printf("%d ",i+1);
    print(org[i]);
  }
  return 0;
}
