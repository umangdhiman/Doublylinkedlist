#include<stdio.h>
struct node{
   int info;
   struct node *next;   //points to next node of struct node type
   struct node *back;   //points to previous node of struct node type
};
void insert_node(struct node **lp,int x){   //function to insert node
   struct node *p,*r,*s;
   p=(struct node *)malloc(sizeof(struct node *));  //allocate memory for new node
   p->info=x;
   p->next=NULL;
   if(*lp==NULL){       //if list is empty
       *lp=p;
   }
   else{                //list not empty
       r=s=*lp;
       while(r!=NULL&&r->info<x){   //to insert data in a sorted manner
           s=r;
           r=r->next;   //r remains ahead of s
       }
       if(r==s){        //insertion is to be done at the start of list
           p->next=*lp;
           s->back=p;
           *lp=p;
       }
       else if(r==NULL){    //insertion at end of list
           s->next=p;
           p->back=s;
       }
       else{        //insertion in-between
           s->next=p;
           p->next=r;
           p->back=s;
           r->back=p;
       }
   }
}
void delete_node(struct node **lp,int x){   //function to delete node
   struct node *r,*s;
   r=s=*lp;
   while(r!=NULL&&r->info!=x){      //to locate the node to be deleted
       s=r;
       r=r->next;
   }
   if(r==NULL){         //end of list reached
       printf("Item not found\n");
   }
   else{
       if(r==s){    //first node to be deleted
           *lp=r->next;
       }
       else{
           s->next=r->next;
       }
       free(r);     //free the node
   }
}
void show_node(struct node **lp){
    struct node *r,*s;
    r=*lp;
    while(r!=NULL){
        printf("%d\t",r->info);
        r=r->next;
    }
}
int main(){
   struct node *ls;
   ls=NULL;     //initially list is empty
   int choice,ele;
   while(1){
       printf("Enter 1 to insert into list\n2 to delete from list\n3 to show\n4 to exit\n");
       scanf("%d",&choice);
       switch(choice){
       case 1:
           printf("Enter a no. to insert\n");
           scanf("%d",&ele);
           insert_node(&ls,ele);
           break;
       case 2:
           printf("Enter a no. to delete\n");
           scanf("%d",&ele);
           delete_node(&ls,ele);
            break;
       case 3:
           show_node(&ls);
           break;
       case 4:
           exit(0);
       }
   }
   return 0;
}

