#include <iostream>
#include <cstdio>
#define MAX_ELEMENT 200

using namespace std;
class HeapNode
{
    int key; // 노드 Key 값
public:
    HeapNode(int k = 0) : key(k) { }
    void 	setKey(int k) { key = k; }  	// 노드에 키값 저장하기
    int 	getKey() { return key; }		// 노드에서 키값 받아오기
    void 	display() { printf("%4d", key); }// 노드 디스플레이
};


class MinHeap {
    HeapNode node[MAX_ELEMENT];
    int size;
public:
    MinHeap() : size(0) { }
    bool isEmpty() { return size == 0; }
    bool isFull() { return size == MAX_ELEMENT - 1; }

    HeapNode& getParent(int i) { return node[i / 2]; }
    HeapNode& getLeft(int i) { return node[i * 2]; }
    HeapNode& getRight(int i) { return node[i * 2 + 1]; }

    void insert(int key) {
        if (isFull()) return;
        int i = ++size;

        while (i != 1 && key < getParent(i).getKey()) {	// 부모보다 키값이 작은 동안 반복
            node[i] = getParent(i);
            i /= 2;
        }
        node[i].setKey(key);
    }

    HeapNode remove() {
        if (isEmpty()) return NULL;
        HeapNode item = node[1];
        HeapNode last = node[size--];
        int parent = 1;
        int child = 2;

        while (child <= size) {
            if (child < size
                && getLeft(parent).getKey() > getRight(parent).getKey())
                child++;      // 현재 자식 중 더 작은 자식 노드 찾기
            if (last.getKey() <= node[child].getKey()) break;
            //자식 노드보다 작으면 이동 완료
            node[parent] = node[child];

            parent = child;
            child *= 2;
        }
        node[parent] = last;     	// 최종 위치에 마지막 노드 저장
        return item;
    }

};

int main()
{
    int n = 0;
    int a = 0;
    cin >> n;
    MinHeap heap;

    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (!num && heap.isEmpty())
        {
            cout << "출력 "<< "0";
            cout << endl;
        }
        else if (!num)
        {
            cout << "출력 ";
            heap.getParent(3).display();
            heap.remove();
            cout << endl;
        }
        else
            heap.insert(num);
    }
}
