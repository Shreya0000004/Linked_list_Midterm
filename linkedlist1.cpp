#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) : data(value), next(nullptr) {}
};

class List {
private:
    Node* head;

public:
    List() : head(nullptr) {}

    void push_back(int value) {
        Node* newNode = new Node(value);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }
            current->next = newNode;
        }
    }

    void display() {
        Node* current = head;
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    std::cout << "Output of Part 1 Test Cases: ";
    List myList;

    // Test Case 1: Create a list with multiple elements and display them
    myList.push_back(1);
    myList.push_back(2);
    myList.push_back(3);

    std::cout << "Test Case 1 - List contents: ";
    myList.display();

    // Test Case 2: Create an empty list and display its contents
    List emptyList;
    std::cout << "Test Case 2 - Empty List:" << std::endl;
    std::cout << "List contents: ";
    emptyList.display();

    // Test Case 3: Create a list with one element and display it
    List oneElementList;
    oneElementList.push_back(42);
    std::cout << "\nTest Case 3 - List with One Element:" << std::endl;
    std::cout << "List contents: ";
    oneElementList.display();

    // Test Case 4: Create a list with multiple elements and display them
    List multipleElementList;
    multipleElementList.push_back(10);
    multipleElementList.push_back(20);
    multipleElementList.push_back(30);
    std::cout << "\nTest Case 4 - List with Multiple Elements:" << std::endl;
    std::cout << "List contents: ";
    multipleElementList.display();

    // Test Case 5: Create a list with a large number of elements
    List largeList;
    for (int i = 1; i <= 1000; ++i) {
        largeList.push_back(i);
    }
    std::cout << "\nTest Case 5 - List with a Large Number of Elements (1-1000):" << std::endl;
    std::cout << "List contents (partial): ";
    largeList.display();
    
    return 0;
}

