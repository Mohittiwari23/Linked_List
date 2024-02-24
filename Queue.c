#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *front=NULL;
struct node *rear=NULL;

void enqueue(struct node *new1){
    rear=front;
    if(front==NULL)
        front=new1;
    else{
        while(rear->next!=NULL)
            rear=rear->next;
        rear->next=new1;    
    }    
}

void dequeue(){
    if(front==NULL)
        printf("underflow\n");
    else   
        front=front->next;
}

void traverse(){
    rear = front;
	if(front == NULL)
	    printf("underflow\n");
	while(rear != NULL){
		printf("%d ",rear->data);
		rear = rear->next;
	}
}
int main(){
    int choice;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. enqueue\n2. dequeue\n3. traverse\n4. exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					enqueue(new1);
					break;
            case 2:
					dequeue();
					break;              
			case 3:
					traverse();
					break;
			default:
					exit(1);
        }
    }
}