#include <iostream>
using namespace std;
struct Node {
    int data;
    struct Node* nextNode;
    struct Node* prevNode;
};

struct Node* CreateNode(int data)
{
    Node* temp = new Node;
    temp->data = data;
    temp->nextNode = NULL;
    temp->prevNode = NULL;
    return temp;
}

void AppendNode(Node** head, Node* newNode)
{
    if (*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        Node* tail = *head;
        while (tail->nextNode != NULL)
        {
            tail = tail->nextNode;
        }
        tail->nextNode = newNode;
        newNode->prevNode = tail;
        newNode->nextNode = NULL;
    }
}

int CountNode(Node** head)
{
    int count = 0;
    struct Node* current = *head;
    while (current != NULL)
    {
        current = current->nextNode;
        count++;
    }
    return count;
}

struct Node* SearchNode(Node** head, int index)
{
    struct Node* current = *head;
    while (current->nextNode != NULL && (--index) >= 0)
    {
        current = current->nextNode;
    }
    return current;
};

void RemoveNode(Node** head, Node* remove)
{
    if (*head == NULL)
    {
        cout << "\n There is no list data. \n" << endl;
        *head = remove->nextNode;
        remove->prevNode = NULL;
        remove->nextNode = NULL;
        delete(remove);
    }
    else
    {
        Node* temp = *head;
        while (temp->nextNode != remove)
        {
            temp = temp->nextNode;
        }
        temp->nextNode = remove->nextNode;
        remove->nextNode->prevNode = temp;
        remove->nextNode = NULL;
        remove->prevNode = NULL;
        delete(remove);
    }
}

void InsertNodeAfter(Node* current, Node* newNode)
{
    newNode->prevNode = current;
    newNode->nextNode = current->nextNode;
    current->nextNode->prevNode = newNode;
    current->nextNode = newNode;
}

void InsertNodeBefore(Node* current, Node* newNode)
{
    newNode->nextNode = current;
    newNode->prevNode = current->prevNode;
    current->prevNode->nextNode = newNode;
}

int main()
{
    Node* node = NULL;
    Node* head = NULL;
    Node* mynode = NULL;

    int i = 0;
    int count = 0;
    for (int i = 0; i < 10; i++)
    {
        node = CreateNode(i);
        AppendNode(&head, node);
    }
    cout << "\ncounting node.." << endl;
    count = CountNode(&head);
    cout << count << endl;
    cout << "\nChecking node.." << endl;
    for (int i = 0; i < count; i++)
    {
        mynode = SearchNode(&head, i);
        cout << "[" << i << "]" << mynode->data << endl;
    }
    cout << "\nremoving node...\\n" << endl;
    mynode = SearchNode(&head, 3);
    RemoveNode(&head, mynode);
    count = CountNode(&head);
    for (int i = 0; i < count; i++)
    {
        mynode = SearchNode(&head, i);
        cout << "[" << i << "]" << mynode->data << endl;
    }
    cout << "\ninserting after node...\n" << endl;
    node = CreateNode(3000);
    mynode = SearchNode(&head, 6);
    InsertNodeAfter(mynode, node);;
    count = CountNode(&head);
    for (int i = 0; i < count; i++)
    {
        mynode = SearchNode(&head, i);
        cout << i << " " << mynode->data << endl;
    }
    cout << "\ninserting before node...." << endl;
    node = CreateNode(1000);
    mynode = SearchNode(&head, 2);
    InsertNodeBefore(mynode, node);
    count =  CountNode(&head);
    for (int i = 0; i < count; i++)
    {
        mynode = SearchNode(&head, i);
        cout << "[" << i << "]" << mynode->data << endl;
    }
    return 0;
}