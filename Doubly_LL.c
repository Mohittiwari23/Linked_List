#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
    struct node* prev;
};

typedef struct node node;

node *head=NULL;

void ins_beg(node* new1){
    if(head==NULL)
        head=new1;
    else{
        head->prev=new1;
        new1->next=head;
        head=new1;
    }
}  
void ins_end(node* new1){
    node* temp=head;
    if(head==NULL)
        head=new1;
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new1;
        new1->prev=temp;
    }
} 
void del_beg(){
    node *temp=head;
    if(head==NULL)
        printf("No item to delete!");
    else{
        head=head->next;
        head->prev=NULL;
        temp->next=NULL;
        free(temp);
        temp=NULL;
    }
}
void del_end(){
    node *temp=head;
    node *temp1=head;
    if(head==NULL)
        printf("No item to delete!");
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp1=temp->prev;
        temp->prev=NULL;
        temp1->next=NULL;
        free(temp);
        temp=NULL;
    }
}
void traverse1(){
    node *temp=head;
    if(head==NULL)
        printf("No nodes exist!");
    else{
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->next;
        }
    }
}
void traverse2(){
    node *temp=head;    
    if(head==NULL)
        printf("No nodes exist!");
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        while(temp!=NULL){
            printf("%d ",temp->data);
            temp=temp->prev;
        }
    }    
}
void ins_specific(node *new1,int n){
    node *temp=head;
    node *temp1=head;
    int i=1,count=1;
    while(temp->next!=NULL){
       temp=temp->next;
       count++;
    }
    temp=head;
    if(n<=count)
    {
        if(head==NULL)
            head=new1;
        else{
            while(i<n){
                temp=temp->next;
                i++;
            }    
            temp1=temp->prev;
            new1->prev=temp1;
            temp1->next=new1;
            new1->next=temp;
            temp->prev=new1;    
        }
    }
    else
        printf("Numnber of nodes exceeded\n");        
}

int main(){
    node *new1;
    int choice,n;
   
    while(1){
	    printf("\nEnter the choice\n");
    	printf("1) ins_beg\n2) ins_end\n3) del_beg\n4) del_end\n5) traverse frd\n6) traverse bkd\n7) ins_specific\n8) exit\n");
    	scanf("%d",&choice);
        switch(choice){
            case 1:
                new1=(node*)malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d",&new1->data);
                new1->next=NULL;
                new1->prev=NULL;
                ins_beg(new1);
                break;
            case 2:
                new1=(node*)malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d",&new1->data);
                new1->next=NULL;
                new1->prev=NULL;
                ins_end(new1);
                break;
            case 3:
                del_beg();
                break;
            case 4:
                del_end();
                break;
            case 5:
                traverse1();
                break;
            case 6:
                traverse2();
                break;
            case 7:
                new1=(node*)malloc(sizeof(node));
                printf("enter data: ");
                scanf("%d",&new1->data);
                new1->next=NULL;
                new1->prev=NULL;
                printf("enter position: ");
                scanf("%d",&n);
                ins_specific(new1,n);
                break;
            default:
                exit(1);
        }
    }
}