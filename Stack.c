#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *top=NULL;

void push(struct node *new1){
    if(top==NULL)
        top=new1;
    else{
        new1->next=top;
        top=new1;
    }   
}

void pop(){
    if(top==NULL)
        printf("underflow\n");
    else  
        top=top->next;
}

void display(){
    struct node *temp = top;
	if(top == NULL)
	    printf("underflow\n");
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
int main(){
    int choice,n;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. push\n2. pop\n3. display\n4. exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					push(new1);
					break;
            case 2:
					pop();
					break;               
			case 3:
					display();
					break;
			default:
					exit(1);
        }
    }
}