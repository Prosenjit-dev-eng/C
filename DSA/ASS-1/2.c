#include <stdio.h>
#define max_size 100

void insertAtAfter(int *arr, int data, int ele){
    int pos = 0;
    // find the element 'data'
    while (arr[pos] != 0 && arr[pos] != data) {
        pos++;
    }
    if (arr[pos] == 0) return; // not found

    // find last index before 0 (sentinel)
    int zero = 0;
    while (arr[zero] != 0) {
        zero++;
    }

    // shift elements right
    for (int i = zero; i > pos+1; i--) {
        arr[i] = arr[i-1];
    }

    // insert new element
    arr[pos+1] = ele;

}

void insertAtBefore(int *arr, int data, int ele){
    int pos = 0;
    // find the element 'data'
    while (arr[pos] != 0 && arr[pos] != data) {
        pos++;
    }
    if (arr[pos] == 0) return; // not found

    // find last index before 0 (sentinel)
    int zero = 0;
    while (arr[zero] != 0) {
        zero++;
    }

    // shift elements right
    for (int i = zero; i > pos; i--) {
        arr[i] = arr[i-1];
    }

    // insert new element
    
    arr[pos] = ele;

}

void delete(int *arr, int data){
    int pos = 0;
    // find the element 'data'
    while (arr[pos] != data) {
        pos++;
    }

    int zero = 0;
    while (arr[zero] != 0) {
        zero++;
    }

    // shift elements right
    for (int i = pos; i < zero; i++) {
        arr[i] = arr[i+1];
    }

}
void insertAtPosition(int *arr, int pos, int ele){
    int p = 0;
    while (p != pos)
    {
        p++;
    }
    arr[p] = ele;
}
void print(int arr[]){
    int pos = 0;
    while (arr[pos] != 0){
        printf("%d ", arr[pos]);
        pos++;
    }
    printf("\n");
}

int main(){
    int input;
    int arr[max_size] = {0};
    int pos = 0;

    // input until 0
    while (1){
        scanf("%d", &input);
        if(input == 0) break;
        if(pos < max_size){ 
            arr[pos] = input;
            pos++;
        }
    }

    // insertAtAfter(arr, 3, 67);
    // print(arr);
    insertAtPosition(arr,3,69);
    print(arr);
    return 0;
}
