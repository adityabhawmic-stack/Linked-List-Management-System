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
        void updateNode(int oldVal, int newVal);
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
    newNode->next = head;
    head = newNode;
}

void SinglyLinkedList::insertAtEnd(int val)
{
    node* newNode = new node(val);
    if(head==NULL)
    {
        head = newNode;
        return;
    }
    node* current = head;
    while(current->next != NULL)
    {
        current = current->next;
    }
    current->next = newNode;
}

void SinglyLinkedList::deleteAtBeginning()
{
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    node* current = head;
    head = head->next;
    delete current;
}

void SinglyLinkedList::deleteAtEnd()
{
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    if(head->next==NULL)
    {
        delete head;
        head = NULL;
        return;
    }
    node* current = head;
    while(current->next->next != NULL)
    {
        current = current->next;
    }
    node* temp = current->next;
    current->next = NULL;
    delete temp;
}

void SinglyLinkedList::searchNode(int val)
{
    node* current = head;
    int pos = 1;
    while(current != NULL)
    {
        if(current->data==val)
        {
            cout<<"found at position "<<pos<<endl;
            return;
        }
        current = current->next;
        pos++;
    }
    cout<<"no match found"<<endl;
}

int SinglyLinkedList::countNode()
{
    int count = 0;
    node* current = head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void SinglyLinkedList::insertAtPos(int pos, int val)
{
    if(pos<1 || pos>countNode()+1)
    {
        cout<<"invalid"<<endl;
        return;
    }
    node* newNode = new node(val);
    if(pos==1)
    {
        newNode->next = head;
        head = newNode;
        return;
    }
    node* prev = head;
    int tempPos = 1;
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
    if(pos==1)
    {
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node* prev = head;
    int tempPos = 1;
    while(tempPos < pos-1)
    {
        prev = prev->next;
        tempPos++;
    }
    node* target = prev->next;
    prev->next = target->next;
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
        node* temp = head;
        head = head->next;
        delete temp;
        return;
    }
    node* prev = head;
    while(prev->next != NULL && prev->next->data != val)
    {
        prev = prev->next;
    }
    if(prev->next==NULL)
    {
        cout<<"not found"<<endl;
        return;
    }
    node* target = prev->next;
    prev->next = target->next;
    delete target;
}

void SinglyLinkedList::insertAfter(int target, int val)
{
    node* current = head;
    while(current != NULL && current->data != target)
    {
        current = current->next;
    }
    if(current==NULL)
    {
        cout<<"value not found"<<endl;
        return;
    }
    node* newNode = new node(val);
    newNode->next = current->next;
    current->next = newNode;
}

void SinglyLinkedList::insertBefore(int target, int val)
{
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    if(head->data==target)
    {
        node* newNode = new node(val);
        newNode->next = head;
        head = newNode;
        return;
    }
    node* prev = head;
    while(prev->next != NULL && prev->next->data != target)
    {
        prev = prev->next;
    }
    if(prev->next==NULL)
    {
        cout<<"value not found"<<endl;
        return;
    }
    node* newNode = new node(val);
    newNode->next = prev->next;
    prev->next = newNode;
}

void SinglyLinkedList::updateNode(int oldVal, int newVal)
{
    node* current = head;
    while(current != NULL)
    {
        if(current->data==oldVal)
        {
            current->data = newVal;
            cout<<"the data has been updated"<<endl;
            return;
        }
        current = current->next;
    }
    cout<<"value not found"<<endl;
}

void SinglyLinkedList::maxNode()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    int max = head->data;
    node* current = head;
    while(current != NULL)
    {
        if(max<current->data)
        {
            max = current->data;
        }
        current = current->next;
    }
    cout<<"max is "<<max<<endl;
}

void SinglyLinkedList::minNode()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    int min = head->data;
    node* current = head;
    while(current != NULL)
    {
        if(min>current->data)
        {
            min = current->data;
        }
        current = current->next;
    }
    cout<<"min is "<<min<<endl;
}

void SinglyLinkedList::middleElem()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    node* slow = head;
    node* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"the middle element is: "<<slow->data<<endl;
}

void SinglyLinkedList::reverseList()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    node* prev = NULL;
    node* current = head;
    node* next = NULL;
    while(current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    head = prev;
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
        swapped = false;
        node* current = head;
        while(current->next != NULL)
        {
            if(current->data>current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    }while(swapped);
}

void SinglyLinkedList::removeDuplicate()
{
    node* current = head;
    while(current != NULL)
    {
        node* checker = current;
        while(checker->next != NULL)
        {
            if(checker->next->data==current->data)
            {
                node* temp = checker->next;
                checker->next = temp->next;
                delete temp;
            }
            else
            {
                checker = checker->next;
            }
        }
        current = current->next;
    }
}

void SinglyLinkedList::display()
{
    node* current = head;
    while(current != NULL)
    {
        cout<<current->data<<" --> ";
        current = current->next;
    }
    cout<<"NULL"<<endl;
}

struct dnode {
    int data;
    dnode* prev;
    dnode* next;
    dnode(int val);
};

dnode::dnode(int val)
{
    data = val;
    prev = NULL;
    next = NULL;
}

class DoublyLinkedList
{
    dnode* head;
    dnode* tail;
    public:
        DoublyLinkedList()
        {
            head = NULL;
            tail = NULL;
        }
        void insertAtBeginning(int val);
        void insertAtEnd(int val);
        void insertAtPos(int pos, int val);
        void insertAfter(int target, int val);
        void insertBefore(int target, int val);
        void deleteAtBeginning();
        void deleteAtEnd();
        void deleteAtPos(int pos);
        void deleteByValue(int val);
        void searchNode(int val);
        void updateNode(int oldVal, int newVal);
        void displayForward();
        void displayBackward();
        int countNode();
        void maxNode();
        void minNode();
        void middleElem();
        void reverseList();
        void sortNode();
        void removeDuplicate();
};

void DoublyLinkedList::insertAtBeginning(int val)
{
    dnode* newNode = new dnode(val);
    if(head==NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void DoublyLinkedList::insertAtEnd(int val)
{
    dnode* newNode = new dnode(val);
    if(tail==NULL)
    {
        head = newNode;
        tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

int DoublyLinkedList::countNode()
{
    int count = 0;
    dnode* current = head;
    while(current != NULL)
    {
        count++;
        current = current->next;
    }
    return count;
}

void DoublyLinkedList::insertAtPos(int pos, int val)
{
    int n = countNode();
    if(pos<1 || pos>n+1)
    {
        cout<<"invalid"<<endl;
        return;
    }
    if(pos==1)
    {
        insertAtBeginning(val);
        return;
    }
    if(pos==n+1)
    {
        insertAtEnd(val);
        return;
    }
    dnode* current = head;
    for(int i=1;i<pos-1;i++)
    {
        current = current->next;
    }
    dnode* newNode = new dnode(val);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void DoublyLinkedList::insertAfter(int target, int val)
{
    dnode* current = head;
    while(current != NULL && current->data != target)
    {
        current = current->next;
    }
    if(current==NULL)
    {
        cout<<"value not found"<<endl;
        return;
    }
    if(current==tail)
    {
        insertAtEnd(val);
        return;
    }
    dnode* newNode = new dnode(val);
    newNode->next = current->next;
    newNode->prev = current;
    current->next->prev = newNode;
    current->next = newNode;
}

void DoublyLinkedList::insertBefore(int target, int val)
{
    dnode* current = head;
    while(current != NULL && current->data != target)
    {
        current = current->next;
    }
    if(current==NULL)
    {
        cout<<"value not found"<<endl;
        return;
    }
    if(current==head)
    {
        insertAtBeginning(val);
        return;
    }
    dnode* newNode = new dnode(val);
    newNode->prev = current->prev;
    newNode->next = current;
    current->prev->next = newNode;
    current->prev = newNode;
}

void DoublyLinkedList::deleteAtBeginning()
{
    if(head==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    dnode* temp = head;
    if(head==tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        head = head->next;
        head->prev = NULL;
    }
    delete temp;
}

void DoublyLinkedList::deleteAtEnd()
{
    if(tail==NULL)
    {
        cout<<"invalid"<<endl;
        return;
    }
    dnode* temp = tail;
    if(head==tail)
    {
        head = NULL;
        tail = NULL;
    }
    else
    {
        tail = tail->prev;
        tail->next = NULL;
    }
    delete temp;
}

void DoublyLinkedList::deleteAtPos(int pos)
{
    int n = countNode();
    if(pos<1 || pos>n)
    {
        cout<<"invalid"<<endl;
        return;
    }
    if(pos==1)
    {
        deleteAtBeginning();
        return;
    }
    if(pos==n)
    {
        deleteAtEnd();
        return;
    }
    dnode* target = head;
    for(int i=1;i<pos;i++)
    {
        target = target->next;
    }
    target->prev->next = target->next;
    target->next->prev = target->prev;
    delete target;
}

void DoublyLinkedList::deleteByValue(int val)
{
    dnode* current = head;
    while(current != NULL && current->data != val)
    {
        current = current->next;
    }
    if(current==NULL)
    {
        cout<<"not found"<<endl;
        return;
    }
    if(current==head)
    {
        deleteAtBeginning();
        return;
    }
    if(current==tail)
    {
        deleteAtEnd();
        return;
    }
    current->prev->next = current->next;
    current->next->prev = current->prev;
    delete current;
}

void DoublyLinkedList::searchNode(int val)
{
    dnode* current = head;
    int pos = 1;
    while(current != NULL)
    {
        if(current->data==val)
        {
            cout<<"found at position "<<pos<<endl;
            return;
        }
        current = current->next;
        pos++;
    }
    cout<<"no match found"<<endl;
}

void DoublyLinkedList::updateNode(int oldVal, int newVal)
{
    dnode* current = head;
    while(current != NULL)
    {
        if(current->data==oldVal)
        {
            current->data = newVal;
            cout<<"the data has been updated"<<endl;
            return;
        }
        current = current->next;
    }
    cout<<"value not found"<<endl;
}

void DoublyLinkedList::displayForward()
{
    if(head==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    dnode* current = head;
    cout<<"NULL <- ";
    while(current != NULL)
    {
        cout<<current->data;
        if(current->next != NULL)
        {
            cout<<" <-> ";
        }
        current = current->next;
    }
    cout<<" -> NULL"<<endl;
}

void DoublyLinkedList::displayBackward()
{
    if(tail==NULL)
    {
        cout<<"NULL"<<endl;
        return;
    }
    dnode* current = tail;
    cout<<"NULL <- ";
    while(current != NULL)
    {
        cout<<current->data;
        if(current->prev != NULL)
        {
            cout<<" <-> ";
        }
        current = current->prev;
    }
    cout<<" -> NULL"<<endl;
}

void DoublyLinkedList::maxNode()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    int max = head->data;
    dnode* current = head;
    while(current != NULL)
    {
        if(max<current->data)
        {
            max = current->data;
        }
        current = current->next;
    }
    cout<<"max is "<<max<<endl;
}

void DoublyLinkedList::minNode()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    int min = head->data;
    dnode* current = head;
    while(current != NULL)
    {
        if(min>current->data)
        {
            min = current->data;
        }
        current = current->next;
    }
    cout<<"min is "<<min<<endl;
}

void DoublyLinkedList::middleElem()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    dnode* slow = head;
    dnode* fast = head;
    while(fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    cout<<"the middle element is: "<<slow->data<<endl;
}

void DoublyLinkedList::reverseList()
{
    if(head==NULL)
    {
        cout<<"list is empty"<<endl;
        return;
    }
    dnode* current = head;
    dnode* temp = NULL;
    while(current != NULL)
    {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }
    temp = head;
    head = tail;
    tail = temp;
}

void DoublyLinkedList::sortNode()
{
    if(head==NULL || head->next==NULL)
    {
        return;
    }
    bool swapped;
    do
    {
        swapped = false;
        dnode* current = head;
        while(current->next != NULL)
        {
            if(current->data>current->next->data)
            {
                int temp = current->data;
                current->data = current->next->data;
                current->next->data = temp;
                swapped = true;
            }
            current = current->next;
        }
    }while(swapped);
}

void DoublyLinkedList::removeDuplicate()
{
    dnode* current = head;
    while(current != NULL)
    {
        dnode* checker = current->next;
        while(checker != NULL)
        {
            if(checker->data==current->data)
            {
                dnode* temp = checker;
                checker = checker->next;
                if(temp->prev != NULL) temp->prev->next = temp->next;
                if(temp->next != NULL) temp->next->prev = temp->prev;
                if(temp==tail) tail = temp->prev;
                delete temp;
            }
            else
            {
                checker = checker->next;
            }
        }
        current = current->next;
    }
}

void singlyMenu(SinglyLinkedList& List)
{
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

void doublyMenu(DoublyLinkedList& List)
{
    int choice, n, pos, target, oldVal, newVal;

    do {
        cout << "\n********** Operation on Doubly Linked List **********\n";
        cout << "1. Insert at Beginning\n2. Insert at End\n3. Insert at Position\n";
        cout << "4. Insert After a Node\n5. Insert Before a Node\n6. Delete from Beginning\n";
        cout << "7. Delete from End\n8. Delete from Position\n9. Delete by Value\n";
        cout << "10. Search\n11. Update\n12. Display Forward\n13. Display Backward\n";
        cout << "14. Count Nodes\n15. Find Maximum\n16. Find Minimum\n";
        cout << "17. Find Middle Element\n18. Reverse\n19. Sort\n20. Remove Duplicates\n21. Exit\n";
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
                List.displayForward();
                break;
            case 13:
                List.displayBackward();
                break;
            case 14:
                cout << "Number of nodes: " << List.countNode() << endl;
                break;
            case 15:
                List.maxNode();
                break;
            case 16:
                List.minNode();
                break;
            case 17:
                List.middleElem();
                break;
            case 18:
                List.reverseList();
                break;
            case 19:
                List.sortNode();
                break;
            case 20:
                List.removeDuplicate();
                break;
            case 21:
                cout << "Exiting doubly linked list menu." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 21);
}

void compareLists()
{
    cout << "\n=========== Singly vs Doubly Linked List ===========\n";
    cout << "Pointers per node      : Singly = 1 (next)          | Doubly = 2 (prev, next)\n";
    cout << "Memory per node        : Singly = less              | Doubly = more\n";
    cout << "Traversal              : Singly = forward only      | Doubly = forward and backward\n";
    cout << "Insert at beginning    : O(1) in both\n";
    cout << "Insert at end          : Singly O(n) without tail   | Doubly O(1) with tail\n";
    cout << "Delete from end        : Singly O(n)                | Doubly O(1) with tail\n";
    cout << "Delete a given node    : Singly needs previous node | Doubly uses prev directly\n";
    cout << "Reverse                : Singly flips next          | Doubly swaps prev and next\n";
    cout << "Search / Count / Max   : O(n) in both\n";
    cout << "Implementation         : Singly = simpler           | Doubly = more pointer updates\n";
}

int main()
{
    SinglyLinkedList singly;
    DoublyLinkedList doubly;
    int choice;

    do {
        cout << "\n==================================================\n";
        cout << " LINKED LIST MANAGEMENT SYSTEM\n";
        cout << "==================================================\n";
        cout << "1. Singly Linked List\n";
        cout << "2. Doubly Linked List\n";
        cout << "3. Compare Singly vs Doubly Linked List\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                singlyMenu(singly);
                break;
            case 2:
                doublyMenu(doubly);
                break;
            case 3:
                compareLists();
                break;
            case 4:
                cout << "Goodbye" << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 4);

    return 0;
}