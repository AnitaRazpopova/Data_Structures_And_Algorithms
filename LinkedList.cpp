// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next = nullptr;

    Node(int data, Node* next = nullptr) {
        this->data = data;
        this->next = next;
    }

};

class List {
private:
    Node* head, * tail;
public:
    List() {
        head = nullptr;
        tail = nullptr;
    }

    void push_back(int number) {
        if (head == nullptr) {
            head = new Node(number);
            tail = head;
        } else{
            tail->next = new Node(number);
            tail = tail->next;
        }
    }

    void push_front(int number) {
        Node* newHead = new Node(number, head);
        head = newHead;
        if (tail == nullptr) {
            tail = head;
        }
    }

    void print()const {
        Node* i = head;
        while (i != nullptr) {
            cout << i->data << " ";
            i = i->next;
        }
        cout << endl;
    }

    void insert(int number, int position) {
    	if (position == 0) {
        		push_front(number);
        		return;
    	}else if (head == nullptr) {
        		throw std::out_of_range("Invalid insert index, list is empty");
    	}

    	Node* current = head;
    	Node* previous = nullptr;
    	for (int i = 0; i < position; i++) {
        	if (current != nullptr) {
            	previous = current;
            	current = current->next;
        	}
        	else {
            	throw std::out_of_range("Cannot insert in invalid position");
        	}
    	}
    	previous->next = new Node(number, current);
    	if (tail == previous) {
        		tail = previous->next;
    	}
    }

    
    void delete_first()
    {
        Node* temp;
        temp = head;
        if (head != nullptr) {
            head = head->next;
            delete temp;
        }
    }
   
    void delete_last()
    {
        Node* current = nullptr;
        Node* previous = nullptr;
        current = head;
        while (current->next != nullptr)
        {
            previous = current;
            current = current->next;
        }
        this->tail = previous;
        previous->next = nullptr;
        delete current;
    }
    
    void remove(int position) {
        if (position == 0) {
            delete_first();
            return;
        }
        else if (head == nullptr) {
            throw std::out_of_range("Invalid remove index, list is empty");
        }

        Node* current = head;
        Node* previous = nullptr;
        for (int i = 0; i < position; i++) {
            if (current->next != nullptr) {
                previous = current;
                current = current->next;
            }
            else {
                throw std::out_of_range("Cannot insert in invalid position");
            }
        }
        previous->next = current->next;
        if (tail == current) {
            tail = previous;
        }
        delete current;
    }
   
    bool search(int x) {
        Node* iter = head;
        while (iter != nullptr) {
            if (iter->data == x) {
                return true;
            }
            iter = iter->next;
        }
        return false;
    }

    void AddList(const List& other) {

        if (this->tail == nullptr) {
            head = other.head;
        }
        else {
            this->tail->next = other.head;
            this->tail = other.tail;
        }
    }
    void ReverseOrder() {
        Node* current = nullptr;
        if()
    }
};

int main()
{
    List list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);
    //list.print();
    
    list.push_front(6);
   // list.print();
    
    list.insert(3, 3);
   // list.print();

    //list.delete_first();
    list.delete_last();
    //list.print();

    list.remove(2);
   // list.print();

    //cout << list.search(3);

    List list2;
    list2.push_back(1);
    list2.push_back(2);
    list2.push_back(3);
    list2.push_back(4);

    list.AddList(list2);
    //list.ReverseOrder();
    list.print();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
