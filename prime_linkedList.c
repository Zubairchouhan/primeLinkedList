#include <stdio.h>
struct Node
{
    int data;
    struct Node *next;
};
struct Node *head = NULL, *tail = NULL;
void create()
{
    int n, i;
    printf("Enter the number of nodes which you want to create: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
        printf("enter your data ");
        scanf("%d", &temp->data);
        temp->next = NULL;
        if (i == 0)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            tail = temp;
        }
    }
}
int isprime(int n)
{
    int i;
    for (i = 2; i <= n / 2; i++)
    {
        if (n % i == 0)
            return 0;
        else
            return 1;
    }
}
void prime_only_list()
{
    struct Node *trav;
    trav = head;
    printf("\n List of primes: \n");
    while (trav != NULL)
    {
        if (isprime(trav->data) == 1)
            printf("%d\t", trav->data);
        trav = trav->next;
    }
}
void view_list()
{
    struct Node *trav;
    trav = head;
    while (trav != NULL)
    {
        printf("%d\t", trav->data);
        trav = trav->next;
    }
    printf("\n");
}
int main()
{
    int ch;
    while (1)
    {
        printf("\n Enter: ");
        printf("\n 1 to Create \n 2 to View \n 3 to Display Primes only");
        printf("\nplease enter ur choice ");
        scanf("%d", &ch);
        switch (ch)
        {
        case 1:
            create();
            break;
        case 2:
            view_list();
            break;
        case 3:
            prime_only_list();
            break;
        default:
            printf("ERROR! Wrong choice! Try again");
            return 0;
        }
    }
}
