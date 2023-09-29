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

    // Default assignment operator
    List& operator=(const List& other) {
        if (this != &other) { // Check for self-assignment
            // Clean up existing list
            clear();

            // Copy elements from the other list
            Node* current = other.head;
            while (current != nullptr) {
                push_back(current->data);
                current = current->next;
            }
        }
        return *this;
    }

    void clear() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    ~List() {
        clear();
    }
};

int main() {
    std::cout << "Output of Part 2 Test Cases: ";
    // Create the original list
    List originalList;
    originalList.push_back(1);
    originalList.push_back(2);
    originalList.push_back(3);

    // Create a copy of the original list using the assignment operator
    List copyList;
    copyList = originalList;

    // Display the original and copied lists
    std::cout << "Original List: ";
    originalList.display();
    std::cout << "Copied List (assignment): ";
    copyList.display();
    
    // Test Case 1: Create an original list with elements (1, 2, 3) and display it
    List originalList1;
    originalList1.push_back(1);
    originalList1.push_back(2);
    originalList1.push_back(3);

    std::cout << "Test Case 1 - Original List:" << std::endl;
    std::cout << "Original List contents: ";
    originalList1.display();

    // Test Case 2: Create an empty list and assign the original list to it using the assignment operator
    List emptyList;
    emptyList = originalList1;

    std::cout << "\nTest Case 2 - Empty List Assignment:" << std::endl;
    std::cout << "Empty List contents (after assignment): ";
    emptyList.display();

    // Test Case 3: Modify the original list and ensure it does not affect the copied list
    originalList1.push_back(4);

    std::cout << "\nTest Case 3 - Modify Original List:" << std::endl;
    std::cout << "Original List contents (after modification): ";
    originalList1.display();
    std::cout << "Copied List contents (should remain the same): ";
    emptyList.display();

    return 0;
}


