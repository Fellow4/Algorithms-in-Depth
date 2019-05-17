#include <stdio.h>
#include <stdlib.h>


typedef struct node{
    float data;
    struct node* ptr;
}node;

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


void push(node **ref,float val){
    node *temp=(node*)malloc(sizeof(node));
    temp->data = val;
    temp->ptr=*ref;
    *ref=temp;
}
#define n 1e3

int main(){
    node **org=(node**)malloc(MAX*sizeof(node*));
    for(int i=0;i<n;++i) org[i]=NULL;
    int x,y,z,u,v,counter;
    float val;
    counter = 0;
    while((scanf("%d %d:%d-%d:%d %f",&x,&y,&z,&u,&v,&val) != EOF){
        push(&org[x],val);
    }
    for(int i=0;i<n;++i) mergesort(&org[i]);
    for(int i=1;i<n+1;++i){
        printf("%d ",i);
        print(org[i]);
    }
    return 0;
}
