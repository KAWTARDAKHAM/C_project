#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*append function for char*/
struct list
{
    char*arr;
    int len;
    int allocated;
};
void append(struct list *A,char elem){
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
    A->arr[A->len] = '\0';
}

int main(){
    struct list A;
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
