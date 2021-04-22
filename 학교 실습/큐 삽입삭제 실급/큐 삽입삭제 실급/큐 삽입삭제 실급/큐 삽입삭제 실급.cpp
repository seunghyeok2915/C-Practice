//20312이승혁
#include <iostream>
using namespace std;
#define NEXT(index,QSIZE) ((index+1)%QSIZE)

typedef struct Queue
{
    int* buf;
    int qsize;
    int front;
    int rear;
    int count;
}Queue;

void InitQueue(Queue* queue, int qsize)
{
    queue->buf = new int[qsize];
    queue->qsize = qsize;
    queue->front = queue->rear = 0;
    queue->count = 0;
}

int IsFull(Queue* queue)
{
    return queue->count == queue->qsize;
}

int IsEmpty(Queue* queue)
{
    return queue->count == 0;
}
void Enqueue(Queue* queue, int data)
{
    if (IsFull(queue))
    {
        cout << "큐가꽉참\n";
        return;
    }
    queue->buf[queue->rear] = data;
    queue->rear = NEXT(queue->rear, queue->qsize);
    queue->count++;
}

int Dequeue(Queue* queue)
{
    int re = 0;
    if (IsEmpty(queue))
    {
        cout << "큐가빔\n";
        return re;
    }
    re = queue->buf[queue->front];
    queue->front = NEXT(queue->front, queue->qsize);
    queue->count--;
    return re;
}

int main()
{
    int select = -1;
    Queue queue;
    InitQueue(&queue,5);

    while (true)
    {
        cout << "1. enqueue 2.dequeue" << endl;
        cout << ">>";
        cin >> select;
        switch (select)
        {
        case 1:
            int value;
            cout << "inputdata: ";
            cin >> value;
            Enqueue(&queue, value);
            break;
        case 2:
            Dequeue(&queue);
            break;
        }
    }
}
