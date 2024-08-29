#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *head=NULL;
struct node *temp=NULL;
char count=0;
void ins_beg(struct node *new1){
    if(head==NULL)
        head=new1;
    else{
        new1->next=head;
        head=new1;
    }
    count+=1;     
}
void ins_end(struct node *new1){
    temp=head;
    if(head==NULL)
        head=new1;
    else{
        while(temp->next!=NULL)
            temp=temp->next;
        temp->next=new1;    
    }
    count+=1;    
}
void ins_specific(struct node *new1,int n){
    int i=1;
    temp=head;
    struct node *temp1=head;                                       
    if(n<=count)
    {
        if(head==NULL)
            head=new1;
        else{
            temp1=temp->next;
            while(i<n-1)
            {
                temp=temp->next;
                temp1=temp1->next;
                i++;
            }    
            new1->next=temp1;
            temp->next=new1;    
        }
        count+=1; 
    }
    else
        printf("Numnber of nodes exceeded\n");        
}
void del_beg(){
    if(head==NULL)
        printf("No nodes\n");
    else
    {    
        head=head->next;
        count-=1;
    }
}
void del_end(){
    temp=head;
    struct node *temp1=head;
    if(head==NULL)
        printf("No nodes\n");
    else{
        temp1=temp1->next;
        while(temp->next!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        if(temp1==head)
            head=NULL;
        else{
            temp->next=NULL;
            temp1=NULL;
        }    
        count-=1;    
    }    
}
void del_specific(int n){
    int i=1;
    temp=head;
    struct node *temp1=head;
    if(n<=count)
    {
        if(head==NULL)
            printf("No nodes to delete\n");
        else{
            temp1=temp->next;
            while(i<n-1)
            {
                temp=temp->next;
                temp1=temp1->next;
                i++;
            }    
            temp->next=temp1->next;
            temp1->next=NULL;    
        }
        count-=1;
    }
    else
        printf("Numnber of nodes exceeded\n");  
}
void search(int n){
    int i=1;
    temp=head;
    if(n<=count)
    {
        if(head==NULL)
            printf("No nodes to delete\n");
        else{
            temp=temp->next;
            while(i<n-1)
            {
                temp=temp->next;
                i++;
            }    
            printf("Data at %d = %d",n,temp->data);    
        }
    }
    else
        printf("Numnber of nodes exceeded\n");  
}
void traverse(){
    temp = head;
	if(head == NULL)
	    printf("no item to traverse\n");
	while(temp != NULL){
		printf("%d ",temp->data);
		temp = temp->next;
	}
}
void reverse(){
    struct node *temp1=head;
    if(head==NULL)
        printf("No nodes\n");
    else{    
        temp=head->next;
        head->next=NULL;
        while(temp!=NULL){
            temp1=temp;
            temp=temp->next;
            temp1->next=head;
            head=temp1;
        }
    }
}

void count(){
    printf("%d", count);
}
int main(){
    int choice,n;
	struct node *new1;
	
	while(1){
		printf("\nenter the choice\n");
		printf("1. ins_beg\n2. ins_end\n3. ins_specific\n4. del_beg\n5. del_end\n6. del_specific\n7. search\n8. traverse\n9. reverse\n10. exit\n");
		scanf("%d",&choice);
		switch(choice){
			case 1:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_beg(new1);
					break;
			case 2:
					new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_end(new1);
					break;
			case 3:
                    printf("Enter n: ");
                    scanf("%d",&n);
                    new1 = (struct node*)malloc(sizeof(struct node));
					printf("enter the data\n");
					scanf("%d",&new1->data);
					new1->next = NULL;
					ins_specific(new1,n);
					break;
            case 4:
					del_beg();
					break;
			case 5:
					del_end();
					break;
            case 6:
                    printf("Enter n: ");
                    scanf("%d",&n);
                    del_specific(n);
                    break;
            case 7:
                    printf("Enter n: ");
                    scanf("%d",&n);
                    search(n);
                    break;                
			case 8:
					reverse();
					break;
			case 9:
					traverse();
					break;
			default:
					exit(1);
        }
    }
}