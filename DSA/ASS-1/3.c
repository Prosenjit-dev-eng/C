
#include<stdio.h>
#include<stdlib.h>
typedef struct Node{
    int data;
    struct Node *next;
}Node;
Node *createNode(int val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = NULL;
    return newNode;
}
Node *LinkedList(){
    int n;
    scanf("%d",&n); 
    Node *head = createNode(n);
    Node *temp = head;
    
    int input;
    while (1)
    {
        scanf("%d",&input);
        if(input == -1) break;
        Node *curr = createNode(input);
        temp->next = curr;
        temp = temp->next;
    }
    return head;

}
void insertAtAfter(Node *head, int val, int n){
    if(head == NULL) return;
    Node* temp = head;
    while (temp->data != val)
    {
        temp = temp->next;
                                                                                                                                         
    }
    Node* newNode = createNode(n);
    newNode->next = temp->next;
    temp->next = newNode;
    
}
void insertAtBefore(Node *head, int val, int n){
    if(head == NULL) return;
    Node* curr = head;
    Node* currnext = head->next;
    while (currnext->data != val)
    {
        currnext = currnext->next;
        curr = curr->next;                                                                                                                                   
    }
    Node* newNode = createNode(n);
    newNode->next = currnext;
    curr->next = newNode;
    
}
void deletedata(Node *head, int val){
    Node* curr = head;
    Node* curr_next = head->next;
    while (curr_next->data != val)
    {
        curr_next = curr_next->next;
        curr = curr->next;
    }
    curr->next = curr_next->next;
    free(curr_next);    
}
void insertAtNthPositon(Node *head,int pos, int n){
    Node *temp = head;
    int cnt = 1;
    while (temp != NULL || temp->next != NULL)
    {
       if(cnt == pos-1) break;
       cnt++;
       temp = temp->next; 
    }
    Node *newNode = createNode(n);
    newNode->next = temp->next;
    temp->next = newNode;
}
int findMiddleData(Node *head){
    Node *temp = head;
    Node *curr = head;

    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;

    }
    for (int i = 0; i < cnt/2; i++)
    {
        curr = curr->next;
    }
    return curr->data;

}
int endData(Node *head,int n){
    Node *temp = head;
    Node *curr = head;

    int cnt = 0;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;

    }
    for (int i = 0; i < (cnt-n); i++)
    {
        curr = curr->next;
    }
    return curr->data;
}
void display(Node *head){
    Node *temp = head;
    while (temp != NULL)
    {
        printf("%d->",temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main(){
    Node*head = LinkedList();
    display(head);
    // insertAtBefore(head,3,68);
    // display(head);
    // printf("\n");
    // insertAtAfter(head,3,67);
    // display(head);
    // printf("\n");
    // deletedata(head,3);
    // display(head);
    // insertAtNthPositon(head,3,98);
    // display(head);
    // int middle = findMiddleData(head);
    // printf("Middle data is: %d\n",middle);
    int end = endData(head,6);
    printf("%d\n",end);
    return 0;
}
