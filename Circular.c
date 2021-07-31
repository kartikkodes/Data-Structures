#include<stdio.h>
#include<malloc.h>

struct dot {
    int data;
    struct dot * is_holding;
};

void traversal(struct dot * node){
    struct dot * ptr = (struct dot *)malloc(sizeof(struct dot));
    ptr=node;
    do
    {
        printf("%d\n",node->data);
        node=node->is_holding;
    }while (node!=ptr);
    
}

struct dot * insertHead(struct dot * head , int info){
    struct dot * ptr = (struct dot *) malloc (sizeof (struct dot));
    struct dot * p = (struct dot *) malloc (sizeof (struct dot));
    ptr->data=info;
    ptr->is_holding=head;
    p=head;
    while (p->is_holding!=head)
    {
        p=p->is_holding;
    }
    p->is_holding=ptr;
    
    return ptr;
}
void insertLast(struct dot * head , int info){
    struct dot * ptr = (struct dot *)malloc(sizeof(struct dot *));
    struct dot * p = (struct dot *)malloc(sizeof(struct dot *));
    p=head;
    ptr->data=info;
    while (p->is_holding!=head)
    {
        p=p->is_holding;
    }
    ptr->is_holding=head;
    p->is_holding=ptr;
}
void insert_at_head(struct dot * node , int info ){
    struct dot * ptr = (struct dot *)malloc(sizeof(struct dot));
    ptr->is_holding=node->is_holding;
    node->is_holding=ptr;
    ptr->data=info;
    // return node;
}
int main(){
  struct dot * head =(struct dot *)malloc(sizeof(struct dot));  
  struct dot * second =(struct dot *)malloc(sizeof(struct dot));  
  struct dot * third =(struct dot *)malloc(sizeof(struct dot));  
  struct dot * fourth =(struct dot *)malloc(sizeof(struct dot));  

  head->data=10;
  head->is_holding=second;

  second->data=20;
  second->is_holding=third;

  third->data=30;
  third->is_holding=fourth;

  fourth->data=40;
  fourth->is_holding=head;

//   traversal(head);

//  insert_at_head(head,101);
    // head=insertHead(head,101);
    insertLast(head,101);
    traversal(head);
    return 0;
}
