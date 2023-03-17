/*stack implementation for int*/
struct stack {
    int *arr;
    int top;   /*it represents also the len*/
    int allocated;
};

/*push function*/
void push(struct stack *s, int elem) {
    if (s->top == s->allocated) {
        s->allocated *= 2;
        int *newarr = (int*) malloc(sizeof(int) * s->allocated);
        for (int i = 0; i < s->top; i++) {
            newarr[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = newarr;
    }
    s->arr[s->top] = elem;
    s->top++;
}

/*pop function*/

void pop(struct stack *s) {
    if (s->top == 0){
        printf("there is no element\n");
    }
    s->top--;
    int *newarr = (int*) malloc(sizeof(int) * s->top);
        for (int i = 0; i < s->top; i++) {
            newarr[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = newarr;
}

int peak(struct stack *s) {
    if (s->top == 0) {
        printf("there is no element in the stack\n");
        return 0;
    }
    return s->arr[s->top - 1];
}

int main() {
    struct stack s;
    s.top = 0;
    s.allocated = 1;
    s.arr = (int*) malloc(sizeof(int) * s.allocated);
    push(&s, 1);
    push(&s, 9);
    printf("%d\n", first(&s));  
    pop(&s);
    printf("%d\n", first(&s));
    free(s.arr);
    return 0;
}
/*stack implementation for char*/

struct stack {
    char *arr;
    int top;   /*it represents also the len*/
    int allocated;
};

void push(struct stack *s, char* elem) {
    if (s->top == s->allocated) {
        s->allocated *= 2;
        char *newarr = (char*) malloc(sizeof(char) * s->allocated);
        for (int i = 0; i < s->top; i++) {
            newarr[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = newarr;
    }
    s->arr[s->top] = elem;
    s->top++;
}

void pop(struct stack *s) {
    if (s->top == 0){
        printf("there is no element\n");
    }
    s->top--;
    char *newarr = (char*) malloc(sizeof(char) * s->top);
        for (int i = 0; i < s->top; i++) {
            newarr[i] = s->arr[i];
        }
        free(s->arr);
        s->arr = newarr;
}

char peak(struct stack *s) {
    if (s->top == 0) {
        printf("there is no element in the stack\n");
        return 0;
    }
    return s->arr[s->top - 1];
}

int main() {
    struct stack s;
    s.top = 0;
    s.allocated = 1;
    s.arr = (char*) malloc(sizeof(char) * s.allocated);
    push(&s,'a');
    push(&s, 'p');
    printf("%c\n", first(&s)); 
    pop(&s);
    printf("%c\n", first(&s)); 
    free(s.arr);
    return 0;
}