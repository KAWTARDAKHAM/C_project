/*queu implementation for char*/

struct queue{
    char*arr;
    int front; 
    int rear;/*it represents the index of last element and also the len*/
    int allocated;
};

void push(struct queue *A,char elem){
    if(A->rear+1 == A->allocated) {
        A->allocated *= 2;
    char *newarr=(char*)malloc(sizeof(char)*(A->allocated));
    for (int i = 0; i < A->rear+1; i++) {
            newarr[i] = A->arr[i];
    }
    free(A->arr);
    A->arr = newarr;
    }
    if(A->front==-1 &&A->rear==-1){
        A->front=A->rear=0;
        A->arr[A->rear]=elem;
    }
    else{
        A->rear++;
        A->arr[A->rear]=elem;
    }
    }

/*pop function*/
void pop(struct queue *A){ 
    if(A->front==-1 && A->rear==-1){
        printf("there is no element to be removed");
    }
    else if(A->front==A->rear){
        A->front=A->rear=-1;
    }
    else{
        A->front++;
    }
}
/*peak function*/
char peak(struct queue *A){
    if(A->front==-1 && A->rear==-1){
        printf("the queu is empty");
        return 0;
    }
    else{
        return  A->arr[A->front];
    }
}
int main(){
    struct queue A;
    A.front = -1;
    A.rear=-1;
    A.allocated = 1;
    A.arr = (char*) malloc(sizeof(char) * A.allocated);
    push(&A,'a');
    push(&A,'b');
    push(&A,'c');
    printf("%c\n",peak(&A));
    pop(&A);
    printf("%c\n",peak(&A));
    pop(&A);
    printf("%c\n",peak(&A));
    free(A.arr);
    return 0;
}
