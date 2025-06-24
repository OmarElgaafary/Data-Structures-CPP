#include <iostream>

struct Node
{
    int value;
    Node* next;
};


class Queue
{
private:
    Node* front = nullptr;
    Node* rear = nullptr;


public:

    void enqueue(int data)
    {
        Node* new_queue = new Node{data, nullptr};

        if (front == nullptr)
        {
            front = rear = new_queue;
            rear->next = nullptr;
            return;
        }

        rear->next = new_queue;
        rear = new_queue;
    }

    void dequeue()
    {
        if (front == nullptr)
            return;

        Node* tmp = front;

        
        if (front == rear)
        {
            front = nullptr;
            rear = nullptr;
        }
        else
        {
            front = front->next;
        }
        delete tmp;
    }

    void print_recursion(Node* node)
    {
        std::cout << node->value << ", ";
        if (node->next == nullptr)
            return;
        print_recursion(node->next);
    }
    
    void print_list()
    {
        if (front == nullptr)
        {
            std::cout << "[Queue Empty]\n";
            return;
        }

        print_recursion(front);
    }
};

int main()
{
    Queue my_queue;
    my_queue.enqueue(5);
    my_queue.enqueue(15);
    my_queue.enqueue(25);
    my_queue.enqueue(35);
    my_queue.enqueue(45);

    my_queue.print_list();


    std::cout << "\n\n------------------------\n\n";
    
    my_queue.dequeue();
    my_queue.dequeue();
    my_queue.dequeue();
    my_queue.dequeue();


    my_queue.enqueue(55);
    my_queue.enqueue(65);
    my_queue.enqueue(75);

    my_queue.print_list();
}
