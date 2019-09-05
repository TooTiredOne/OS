#include <stdio.h>
#include <stdlib.h>

struct Node {
        int val;
        struct Node *next;
};

void print_list(struct Node *head)
{
        struct Node *current = head->next;

        if(current == NULL)
                return;

        while(current->next != NULL)
        {
                printf("%d -> ", current->val);
                current = current->next;
        }

        printf("%d", current->val);
}

//inserting node at the beginning  of the Linked List
void insert_node(struct Node *head, struct Node *node)
{
        node->next = head->next;
        head->next = node;
}

void delete_node(struct Node *head, struct Node *node)
{
        struct Node *current = head->next;
        struct Node *prev = head;


        while(current != NULL)
        {
                if(current == node)
                {
                        prev->next = current->next;
                        break;
                }
                prev = current;
                current = current->next;
        }

}

int main(int argc, char const *argv[]) {

        //head of the Linked List
        struct Node *head = (struct Node*) malloc(sizeof(struct Node));
        head->next = NULL;

        struct Node *node, *saved;
        //saved is used to store a node that will be deleted

        //adding nodes to Linked List
        for(int i = 1; i <= 10; i++)
        {
                node = (struct Node*) malloc(sizeof(struct Node));

                //we are going to delete 5th node, so we need to save it
                if(i == 5)
                {
                        saved = node;
                }

                node->val = i;
                insert_node(head, node);
        }

        //printing the Linked List
        print_list(head);

        printf("\n\n");

        //deleting the 5th node
        delete_node(head, saved);

        //printing the Linked List again
        print_list(head);

        return 0;
}
