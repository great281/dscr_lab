typedef struct Stack_num
{
    int x;
    struct Stack_num *next;
}stack_num;

int empty_num(stack_num *s);

stack_num *push_num(stack_num *s, int x);

stack_num *pop_num(stack_num *s, int *value);