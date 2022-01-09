#include <iostream>
using namespace std;

struct node {
    int info;
    node* next;
    node(int i, node* n) : info(i), next(n) { }
    node(int i) : info(i) { next = nullptr; }
};

void cycleDetect(node* head)
{
     node* slow = head;
    node* fast = head->next;
    while (fast != nullptr && fast->next != nullptr)
    {
        cout<<"Slow Pointer: "<<slow->info<<"\n";
        cout<<"Fast Pointer: "<<fast->info<<"\n";
        if (slow->info == fast->info)
        {
            cout<<"Cycle Detected: "<<slow->info<<" == "<<fast->info<<"\n";
            return;
        }
        slow = slow->next;
        fast = fast->next;
        if (fast->next != nullptr)
        {
            fast = fast->next;
        }
    }
}


int main()
{
    node* head = new node(5);
    node* temp = head;
    for (int i = 0; i < 10; i++)
    {
        head->next = new node(rand() % 10);
        head = head->next;
    }
    head->next = temp;
    head = temp;
    cycleDetect(head);
    return 0;
}