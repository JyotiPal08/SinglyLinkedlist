// Linked list implementation in C
#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
struct node {  int value;  struct node *next;};// Creating a node
struct node *head; 
//-------------------------- print the linked list value
void printLinkedlist(){struct node* newNode;newNode=head;
    if(newNode==NULL){printf("Empty List");}
    else{printf("Values of List are:");
        while(newNode!= NULL){printf("%d ", newNode->value);newNode = newNode->next;}} 
}
//------------------------------FIRSTINSERT------------------------
void firstInsert(){int i;
    struct node *newNode;newNode = malloc(sizeof(struct node*));
    if(newNode==NULL){printf("Overflow");}
    else{ printf("Enter element to insert:");scanf("%d",&i);
    newNode->value=i; newNode->next=head; head=newNode;printf("1st Inserted..");}
}
//------------------------------LASTINSERT------------------------
void lastInsert(){int i;
    struct node *newNode,*temp;newNode = malloc(sizeof(struct node));
    if(newNode==NULL){printf("Overflow");}
    else{printf("\nEnter element to insert:");scanf("%d",&i);newNode->value=i;
        if (head==NULL){newNode->next=NULL; head=newNode;printf("\nList was empty thus Inserted at first..");}
        else{temp=head;while (temp->next!=NULL){temp=temp->next;}
            temp->next=newNode;newNode->next=NULL;
            printf("Inserted at last...");}
    }
}
//------------------------------INSERT@Position------------------------
void insertAtPos(){ int e,pos;struct node *newNode,*temp; newNode= malloc(sizeof(struct node));
    if(newNode==NULL){printf("Overflow");}
    else{   printf("Enter element to insert:");scanf("%d",&e);
            printf("Enter position for inserting element:");scanf("%d",&pos);
            temp=head;
            for (int i = 0; i < pos; i++){ temp=temp->next;
             if (temp==NULL){printf("cant insert");return;} }
            newNode->next=temp->next; temp->next=newNode;printf("Inserted at %d position.",pos);
    }
}
//------------------------------DELETE@Position------------------------
void deleteAtPos(){ int e,pos;  struct node *newNode,*temp;
    if (head==NULL){printf("List is empty.");}
    else{ printf("Enter position for deleting element:");scanf("%d",&pos);
          temp=head;
          for (int i = 0; i < pos; i++){ newNode=temp; temp=temp->next;
          if (temp==NULL){printf("cant delete");return;}}
        newNode->next=temp->next;free(temp);printf("deleted at %d position.",pos);}
}
//------------------------------FIRSTDELETE------------------------
void firstDelete(){struct node* newNode;
    if (head==NULL){printf("List is empty.");}
    else{newNode=head;head=newNode->next;free(newNode);printf("1st deleted.."); } 
}
//------------------------------LASTDELETE------------------------
void lastDelete(){  struct node* temp,*newNode;
    if (head==NULL){printf("List is empty.");}
    else if(head->next==NULL){head=NULL;free(head);printf("1st deleted..");}
    else{ temp=head;
         while (temp->next!=NULL){  newNode=temp;temp=temp->next;    }
         newNode->next=NULL;free(temp); printf("last deleted..");
    }
}
//------------------------------SEARCH------------------------
void searchNode(){int key,i;struct node* current = head;bool found=false;
    if (current==NULL) {printf("Empty List");  }
    else{ printf("Enter element to be searched:");scanf("%d",&key);
    while (current!=NULL)
    {if(current->value == key){found=true;printf("element found");}
    else{found=false;}i++;current=current->next;}
    if(found==false){printf("element not found");}
    }
}
//------------------------------MAIN------------------------
int main() {  int i;
 do{printf("\n\n*********Main Menu*********\n");  
    printf("1.First Insert\t\t2.Insert at position\t\t3.Last Insert\t\t4.First delete\n5.Delete at position\t6.last delete\t\t\t7.search element\t8.Print list\nEnter choice:"); scanf("%d",&i);
    switch (i){case 1:firstInsert();break;case 2:insertAtPos();break;case 3:lastInsert();break;
        case 4:firstDelete();break;case 5:deleteAtPos();break;case 6:lastDelete();break;
        case 7:searchNode(); break;case 8:printLinkedlist(); break;default: break;
    }} while (i!=9);
}
