#include <iostream>
using namespace std;

template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data) : data(data), next(nullptr) {}
};

template <typename T>
class Queue
{
private:
    Node<T> *front, *back;
    int size;

public:
    Queue() : front(nullptr), back(nullptr), size(0) {}

    ~Queue()
    {
        while (front != nullptr)
        {
            Node<T> *temp = front;
            front = front->next;
            delete temp;
        }
    }

    void push(T data)
    {
        if (back == nullptr)
        {
            front = back = new Node<T>(data);
            size++;
            return;
        }

        back->next = new Node<T>(data);
        back = back->next;
        size++;
    }

    T pop()
    {
        if (front == nullptr)
        {
            throw runtime_error("Queue is empty");
        }

        Node<T> *front_node = front;
        T data = front_node->data;

        front = front->next;

        if (front == nullptr)
            back = nullptr;

        delete front_node;
        size--;

        return data;
    }

    int getSize()
    {
        return size;
    }
};

int main()
{
    Queue<int> q;

    q.push(1);
    q.push(2);
    q.push(3);

    while (q.getSize() > 0)
    {
        cout << q.pop() << endl;
    }
}
