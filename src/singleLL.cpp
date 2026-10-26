#include<iostream>
using namespace std;

struct node {
    int data;
    node* next;
    node(int val);
};

node::node(int val)
{
    data = val;
    next = NULL;
}

class SinglyLinkedList
{
    node* head;
    public:
        SinglyLinkedList()
        {
            head = NULL;
        }
        void insertAtBeginning(int val);
        void insertAtEnd(int val);
        void deleteAtBeginning();
        void deleteAtEnd();
        void searchNode(int val);
        int countNode();
        void insertAtPos(int pos, int val);
        void deleteAtPos(int pos);
        void deleteByValue(int val);
        void insertAfter(int target, int val);
        void insertBefore(int target, int val);
        void updateNode(int oldVal,int newVal);
        void maxNode();
        void minNode();
        void middleElem();
        void reverseList();
        void sortNode();
        void removeDuplicate();
        void display();
};

void SinglyLinkedList::insertAtBeginning(int val)
{
    node* newNode = new node(val);
    newNode->next=head;
    head=newNode;
}

void SinglyLinkedList::insertAtEnd(int val)
{
    node* current = head;
    node* newNode = new node(val);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    while(current->next != NULL)
    {
        current=current->next;
    }
    current->next=newNode;
}

void SinglyLinkedList::deleteAtBeginning()
{
    node* current = head;
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    head=head->next;
    delete current;
}

void SinglyLinkedList::deleteAtEnd()
{
    node* current = head;
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    if(head->next==NULL)
    {
        delete head;
        head = NULL;
        return ;
    }
    while(current->next->next != NULL)
    {
        current=current->next;
    }
    node* temp = current->next;
    current->next = NULL;
    delete temp;
}

void SinglyLinkedList::searchNode(int val)
{
    node* current = head;
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    int pos = 1;
    while(current != NULL)
    {
        if(current->data==val)
        {
            cout << "found at position " << pos << endl;
            return;
        }
        current=current->next;
        pos++;
    }
    cout << "no match found" << endl;
}

int SinglyLinkedList::countNode()
{
    node* current = head;
    int count = 0;
    while(current != NULL)
    {
        count++;
        current=current->next;
    }
    return count;
}

void SinglyLinkedList::insertAtPos(int pos,int val)
{
    if(pos<1 || pos>countNode()+1)
    {
        cout<<"invalid"<<endl;
        return;
    }
    node* prev = head;
    node* newNode = new node(val);
    if(pos==1)
    {
        newNode->next=head;
        head=newNode;
        return;
    }
    int tempPos=1;
    while(tempPos < pos-1)
    {
        prev = prev->next;
        tempPos++;
    }
    newNode->next = prev->next; 
    prev->next = newNode;
}

void SinglyLinkedList::deleteAtPos(int pos)
{
    if(pos<1 || pos>countNode())
    {
        cout<<"invalid"<<endl;
        return;
    }
    node* temp=head;
    if(pos==1)
    {
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    node* prev=head;
    int tempPos=1;
    while(tempPos < pos-1)
    {
        prev=prev->next;
        tempPos++;
    }
    node* target = prev->next;
    prev->next=target->next;
    target->next=NULL;
    delete target;
}

void SinglyLinkedList::deleteByValue(int val)
{
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    if(head->data==val)
    {
        node* temp=head;
        head=temp->next;
        temp->next=NULL;
        delete temp;
        return;
    }
    node* prev=head;
    while(prev->next != NULL && prev->next->data != val)
    {
        prev=prev->next;
    }
    if(prev->next==NULL)
    {
        cout<<"not found"<<endl;
        return;
    }
    node* target=prev->next;
    prev->next=target->next;
    target->next=NULL;
    delete target;
}

void SinglyLinkedList::insertAfter(int target, int val)
{
    node* current=head;
    while(current != NULL && current->data != target)
    {
        current=current->next;
    }
    if(current==NULL)
    {
        cout<<"value not found"<<endl;
        return;
    }
    node*newNode=new node(val);
    newNode->next=current->next;
    current->next= newNode;
}

void SinglyLinkedList::insertBefore(int target, int val)
{
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    if(head->data == target)
    {
        node* newNode = new node(val);
        newNode->next=head;
        head=newNode;
        return;
    }
    node* prev=head;
    while(prev->next != NULL && prev->next->data != target)//prev is before the target here
    {
        prev=prev->next;
    }
    if(prev->next == NULL)
    {
        cout<<"value not found"<<endl;
        return;
    }
    node* newNode = new node(val);
    newNode->next=prev->next;
    prev->next=newNode;
}

void SinglyLinkedList::updateNode(int oldVal,int newVal)
{
    node* current=head;
    while(current != NULL)
    {
        if(current->data == oldVal)
        {
            current->data = newVal;
            cout<<"the data has been updated"<<endl;
            return;
        }
        current=current->next;
    }
    cout << "value not found"<<endl;
}

void SinglyLinkedList::maxNode()
{
    node* current = head;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    int max= head->data;
    while(current != NULL)
    {

        if(max<current->data)
        {
            max=current->data;
        }
        current=current->next;
    }
    cout << "max is " << max << endl;
}

void SinglyLinkedList::minNode()
{
    node* current = head;
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    int min= head->data;
    while(current != NULL)
    {

        if(min>current->data)
        {
            min=current->data;
        }
        current=current->next;
    }
    cout << "min is " << min << endl;  
}

void SinglyLinkedList::middleElem()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    node* slow=head;
    node* fast=head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    cout<<"the middle element is:"<<slow->data<<endl;
}

void SinglyLinkedList::reverseList()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    node* prev=NULL;
    node* current=head;
    node* next=NULL;
    while(current != NULL)
    {
        next=current->next;
        current->next=prev;
        prev=current;
        current=next;
    }
    head=prev;
}

void SinglyLinkedList::sortNode()
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    bool swapped;
    do
    {
        swapped=false;
        node* current=head;
        while(current->next != NULL)
        {
            if(current->data>current->next->data)
            {
                int temp = current->data;
                current->data=current->next->data;
                current->next->data=temp;
                swapped=true;
            }
            current=current->next;
        }
    }while(swapped);
}

void SinglyLinkedList::removeDuplicate()
{
    if(head==NULL)
    {
        return;
    }
    node* current=head;
    while(current != NULL)
    {
        node* checker=current;
        while(checker->next != NULL)
        {
            if(checker->next->data==current->data)
            {
                node* temp=checker->next;
                checker->next=temp->next;
                delete temp;
            }
            else
            {
                checker=checker->next;
            }
        }
        current=current->next;
    }
}

void SinglyLinkedList::display()
{
    node* current = head;
    while(current != NULL)
    {
        cout<< current->data << "-->";
        current=current->next;
    }
    cout << "NULL" << endl;
}

void singlyMenu()
{
    SinglyLinkedList List;
    int choice, n, pos, target, oldVal, newVal;

    do {
        cout << "\n********** Operation on Singly Linked List **********\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Insert After a Node\n5. Insert Before a Node\n6. Delete from Beginning\n";
        cout << "7. Delete from End\n8. Delete from Position\n9. Delete by Value\n";
        cout << "10. Search\n11. Update\n12. Display\n13. Count Nodes\n";
        cout << "14. Find Maximum\n15. Find Minimum\n16. Find Middle Element\n";
        cout << "17. Reverse\n18. Sort\n19. Remove Duplicates\n20. Exit\n";
        cout << "Enter the choice:- ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                cout << "Enter value: "; cin >> n;
                List.insertAtBeginning(n);
                break;
            case 2:
                cout << "Enter value: "; cin >> n;
                List.insertAtEnd(n);
                break;
            case 3:
                cout << "Enter position: "; cin >> pos;
                cout << "Enter value: "; cin >> n;
                List.insertAtPos(pos, n);
                break;
            case 4:
                cout << "Insert after which value: "; cin >> target;
                cout << "Enter value: "; cin >> n;
                List.insertAfter(target, n);
                break;
            case 5:
                cout << "Insert before which value: "; cin >> target;
                cout << "Enter value: "; cin >> n;
                List.insertBefore(target, n);
                break;
            case 6:
                List.deleteAtBeginning();
                break;
            case 7:
                List.deleteAtEnd();
                break;
            case 8:
                cout << "Enter position: "; cin >> pos;
                List.deleteAtPos(pos);
                break;
            case 9:
                cout << "Enter value to delete: "; cin >> n;
                List.deleteByValue(n);
                break;
            case 10:
                cout << "Enter value to search: "; cin >> n;
                List.searchNode(n);
                break;
            case 11:
                cout << "Enter old value: "; cin >> oldVal;
                cout << "Enter new value: "; cin >> newVal;
                List.updateNode(oldVal, newVal);
                break;
            case 12:
                List.display();
                break;
            case 13:
                cout << "Number of nodes: " << List.countNode() << endl;
                break;
            case 14:
                List.maxNode();
                break;
            case 15:
                List.minNode();
                break;
            case 16:
                List.middleElem();
                break;
            case 17:
                List.reverseList();
                break;
            case 18:
                List.sortNode();
                break;
            case 19:
                List.removeDuplicate();
                break;
            case 20:
                cout << "Exiting singly linked list menu." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 20);
}

int main()
{
    singlyMenu();
    return 0;
}