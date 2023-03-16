#include<stdio.h>

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
    A->len=1;
    A->allocated=1;
    append(A,1);
    for(int i=0,i<A->len;i++){
        printf("%d",A->arr[i]);
    }
    
}
