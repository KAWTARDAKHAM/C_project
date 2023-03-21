
/*append function for int*/

struct list
{
    int*arr;
    int len;
    int allocated;
};
void append(struct list *A,int elem){
    if(A->len==A->allocated){
        A->allocated*=2;
          int*newarr=(int*)malloc(sizeof(int)*(A->allocated));
          for(int i=0;i<A->len;i++){
            newarr[i]=A->arr[i];
          }
          free(A->arr);
          A->arr=newarr;
    }
    A->arr[A->len]=elem;
    A->len+=1;
}

int main(){
    struct list A;
    A.len=0;
    A.allocated=1;
    A.arr=(int*)malloc(sizeof(int)*A.allocated);
    append(&A,1);
    append(&A,9);
    for(int i=0;i<A.len;i++){
        printf("%d",A.arr[i]);
    }
    free(A.arr);
    return 0;
}

