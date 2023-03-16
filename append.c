
/*append function for int*/

struct dynamicarray
{
    int*arr;
    int len;
    int allocated;
};
void append(struct dynamicarray *A,int elem){
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
    struct dynamicarray A;
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
/*append function for char*/
struct dynamicarray
{
    char*arr;
    int len;
    int allocated;
};
void append(struct dynamicarray *A,char elem){
    if(A->len==A->allocated){
        A->allocated*=2;
          char*newarr=(char*)malloc(sizeof(char)*(A->allocated));
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
    struct dynamicarray A;
    A.len=0;
    A.allocated=1;
    A.arr=(char*)malloc(sizeof(char)*A.allocated);
    append(&A,'a');
    append(&A,'l');
    append(&A,'k');
    append(&A,'h');
    append(&A,'a');
    append(&A,'w');
    append(&A,'a');
    append(&A,'r');
    append(&A,'i');
    append(&A,'z');
    append(&A,'m');
    append(&A,'i');
    for(int i=0;i<A.len;i++){
        printf("%c",A.arr[i]);
    }
    free(A.arr);
    return 0;
}

