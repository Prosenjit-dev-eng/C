#include <stdio.h>
#include <stdlib.h>

typedef struct Stu
{
    int roll;
    char name[31];
    float score;
    struct Stu *next;
}Stu;
// We have to change the head
void create(Stu **head){
    *head = (Stu*)malloc(sizeof(Stu));
    if(*head == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    (*head)->next = NULL;

    printf("Enter roll: ");
    scanf("%d",&((*head)->roll));
    printf("\n");

    printf("Enter name: \n");
    getchar();
    gets((*head)->name);
    printf("\n");
    
    printf("Enter score: \n");
    scanf("%f",&((*head)->score));
    printf("\n");
}
void append(Stu *head){
    while (head->next != NULL)
    {
        head = head->next;
    }
    Stu *p = (Stu*)malloc(sizeof(Stu));
    // As like create there head is here p;
    p->next = NULL;
    printf("Enter roll: ");
    scanf("%d",&(p->roll));
    printf("\n");

    printf("Enter name: \n");
    getchar();
    gets(p->name);
    printf("\n");
    
    printf("Enter score: \n");
    scanf("%f",&(p->score));
    printf("\n");

    p->next = NULL;
    head->next = p;
}
void delete(Stu *head){
    Stu* temp = head->next;
    Stu* prev = head;
    while (temp->next!=NULL)
    {
       temp = temp->next;
       prev = prev->next; 
    }
    prev->next = NULL;
    free(temp);
}
void diaplay(Stu *head){
    while (head != NULL)
    {
        printf("Roll: %d\n",(head->roll));
        printf("Name: %s\n",(head->name));
        printf("Score: %.2f\n",(head->score));
        head = head->next;
    }
    
}
int main()
{
    Stu *head = NULL;

    create(&head);
    append(head);
    diaplay(head);
    printf("\n");
    delete(head);
    diaplay(head);
    printf("\n");

    return 0;
}