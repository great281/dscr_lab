#include <stdio.h>
#include <stdlib.h>

#include "graph.h"
#include "stack.h"

void swap(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int check_visited(int *visited, int size)
{
    for(int i = 0; i < size; i++)
    {
        if(visited[i] == 0)
            return i + 1;
    }
    return -1;
}

void read_file(FILE *fp, graph *g, int size)
{
    int x;
    for(int i = 1; i < size + 1; i++)
    {
        for(int j = 1; j < size + 1; j++)
        {
            fscanf(fp, "%d", &x);
            graph_set_edge(g, i, j, x);
        }
    }
}

void bypass(graph *g, int size, int num, int comp)
{
    stack_num *stack = NULL;
    while(1)
    {
        g->visited[num - 1] = comp;
        for(int i = 0; i < size; i++)
        {
            if(g->visited[i] != 0)
                continue;
            if(graph_get_edge(g, num, i + 1))
                stack = push_num(stack, i + 1);
        }
        if(empty_num(stack))
            break;
        else
            stack = pop_num(stack, &num);
    }
}

// int dfs(graph *g, int v, int size, int num)
// {
//     g->visited[v - 1] = num;
//     num++;
//     for(int i = 0; i < size; i++)
//     {
//         if(g->visited[i] != 0)
//             continue;
        
//         num = dfs(g, i + 1, size, num);
//     }
//     g->visited[v - 1] = num;
//     num++;
//     return num;
// }

void res_output(int *visited, int num, int size)
{
    for(int i = 1; i <= num; i++)
    {
        printf("%d: ( ", i);
        for(int j = 0; j < size; j++)
        {
            if(visited[j] == i)
                printf(" %d", j + 1);
        }
        printf(")\n");
    }
}

// void output_dfs(int *visited, int num, int size)
// {
//     int max;
//     for(int i = 1; i <= num; i++)
//     {
//         printf("%d: ( ", i);
//         for(int b = 0; b < size - 1; b++)
//         {
//             max = b + 1;
//             for(int j = 0; j < size - b; j++)
//             {
//                 if(visited[j] > visited[max - 1])
//                     max = j + 1;
//             }
//             printf("%d ", max);
//             swap(&visited[max - 1], &visited[size - b - 1]);
//         }

//     }
// }

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        fprintf(stderr, "Использование: ./lab5 <имя файла с матрицей смежности\n>");
        exit(EXIT_FAILURE);
    }
    FILE *fp;
    int sum, comp, x, num;
    graph *g;
    while(1)
    {
    fp = fopen(argv[1], "r");
    if(!fp)
    {
        fprintf(stderr, "Файл не найден\n");
        exit(EXIT_FAILURE);
    }
    printf("Количество вершин графа для обработки: ");
    scanf("%d", &sum);

    g = graph_create(sum);
    read_file(fp, g, sum);
    
    comp = 0;
    num = 0;
    while(1)
    {
        if((x = check_visited(g->visited, sum)) == -1)
            break;
        // num = dfs(g, x, sum, num);
        comp++;
        bypass(g, sum, x, comp);
    }

    printf("Компоненты связанности:\n");
    res_output(g->visited, comp, sum);
    // printf("Компоненты сильной связанности:\n");
    // output_dfs(g->visited, comp, sum);
    graph_free(g);
    fclose(fp);
    printf("Внесите изменения в матрицу смежности в файле %s и перезапустите программу, или завершите её работу\n", argv[1]);
    printf("1 - перезапуск программы\n");
    printf("2 - выход из программы\n>>");
    while(getchar() != '\n')
        continue;
    if(getchar() == '2')
        break;
    while(getchar() != '\n')
        continue;
    }
    printf("Завершение программы\n");
    return 0;
}