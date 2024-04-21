#include <iostream>
#include <unordered_set>

//using namespace std;

struct Node {
    std::string val;
    Node* next;
    Node(std::string _val) : val(_val), next(nullptr) {}
};

struct list {
    Node* first;
    Node* last;
    list() : first(nullptr), last(nullptr) {}
    bool is_empty() {
        return first == nullptr;
    }
    void push_back(std::string _val) {
        Node* p = new Node(_val);
        if (is_empty()) {
            first = p;
            last = p;
            return;
        }
        last->next = p;
        last = p;
    }
    void print() {
        if (is_empty())
            return;
        Node* p = first;
        while(p) {
            std::cout << p->val << " ";
            p = p->next;
        }
        std::cout << std::endl;
    }
    Node* find(std::string _val) {
        Node* p = first;
        while (p && p->val != _val)
            p = p->next;
        return (p && p->val == _val) ? p : nullptr;
    }
    void remove(std::string _val) {
        if (is_empty())
            return;
        if (first->val == _val) {
            remove_first();
            return;
        }
        else if (last->val == _val) {
            remove_last();
            return;
        }
        Node* slow = first;
        Node* fast = first->next;
        while (fast && fast->val != _val) {
            fast = fast->next;
            slow = slow->next;
        }
        if (!fast) {
            std::cout << "This element does not exist" << std::endl;
            return;
        }
        slow->next = fast->next;
        delete fast;
    }
    void remove_first() {
        if (is_empty()) {
            return;
        }
        Node* temp = first;
        first = first->next;
        if (first == nullptr) {
            last = nullptr;
        }
        delete temp;
    }

    
    void remove_last() {
        if (is_empty()) {
            return; 
        }
        if (first == last) { 
            remove_first();
            return;
        }
        Node* current = first;
        while (current->next != last) {
            current = current->next;
        }
        last = current;
        last->next = nullptr;
        delete current->next; 
    }
    void insert_first(std::string val) {
        Node* new_node = new Node(val);
        new_node->next = first;
        first = new_node;
        if (is_empty()) {
            last = new_node;
        }
    }
    void remove_by_key(std::string key) {
        if (is_empty()) {
            return;
        }

        Node* prev = nullptr;
        Node* current = first;

        while (current && current->val != key) {
            prev = current;
            current = current->next;
        }

        if (!current) {
            std::cout << "Element with key '" << key << "' not found" << std::endl;
            return;
        }

        if (current == first) {
            remove_first();
            return;
        }

        prev->next = current->next;
        delete current;

        if (current == last) {
            last = prev;
        }
    }
    void create_list_manual() {
        std::string value;
        std::cout << "Вводите значения. Чтобы оастановиться введите 'done':" << std::endl;
        while (true) {
            std::cout << "Значение: ";
            std::cin >> value;
            if (value == "done") {
                break;
            }
            push_back(value);
        }
    }
    void create_list_from_array(std::string values[], int size) {
        for (int i = 0; i < size; i++) {
            push_back(values[i]);
        }
    }

    std::string has_duplicates() {
        if (is_empty()) {
            return "no";
        }
        std::unordered_set<std::string> seen_values;
        Node* current = first;
        while (current) {
            if (seen_values.find(current->val) != seen_values.end()) {
                return current->val;
            }

            seen_values.insert(current->val);
            current = current->next;
        }
        return "no";
    }
    void remove_max() {
        if (is_empty()) {
            return;
        }
        Node* max_node = nullptr;
        std::string max_value = "";
        Node* current = first;
        while (current) {
            if (current->val > max_value) {
                max_value = current->val;
                max_node = current;
            }
            current = current->next;
        }
        if (max_node == first) {
            remove_first();
            return;
        }
        Node* prev = nullptr;
        current = first;
        while (current != max_node) {
            prev = current;
            current = current->next;
        }

        prev->next = max_node->next;
        delete max_node;
    }
    void insert_before_even(std::string new_value) {
        if (is_empty()) {
            return;
        }
        int pos = 1;
        Node* prev = nullptr;
        Node* current = first;
        while (current) {
            Node* new_node = new Node(new_value);
            if (pos % 2 == 0) {
                new_node->next = current;
                prev->next = new_node;
            }
            prev = current;
            current = current->next;
            pos++;
        }
    }
    void menu() {
        std::cout << "ТЕКСТОВОЕ МЕНЮ" << std::endl;
        std::cout << "1.Добавить элемент в список" << std::endl;
        std::cout << "2.Вывести на экран список" << std::endl;
        std::cout << "3.Удалить элемент" << std::endl;
        std::cout << "4.Удалить максимальный элемент" << std::endl;
        std::cout << "5.Добавить первый элемент" << std::endl;
        std::cout << "6.Создать список из существующего" << std::endl;
        std::cout << "7.Определить, есть ли дубликаты" << std::endl;
        std::cout << "8.Загадочная функция)))" << std::endl;
        std::cout << "9.Создать массив самостоятельно" << std::endl;
        std::cout << "10.Выйти из программы" << std::endl;
        std::cout << "Выберите действие: ";
        choice();
    }

    void choice() {
        int c;
        std::string arr[10] = { "5", "4", "3", "131", "152", "72", "75849", "1", "3", "1" };
        std::string a;
        std::cin >> c;
        switch (c) {
        case 1:
            std::cin >> a;
            this -> push_back(a);
            break;
        case 2:
            this-> print();
            break;
        case 3:
            std::cin >> a;
            this->remove_by_key(a);
            break;
        case 4:
            this->remove_max();
            break;
        case 5:
            std::cin >> a;
            this->insert_first(a);
            break;
        case 6:
            this->create_list_from_array(arr, 10);
            break;
        case 7:
            std::cout << this->has_duplicates() << std::endl;
            break;
        case 8:
            std::cin >> a;
            this->insert_before_even(a);
            break;
        case 9:
            create_list_manual();
            break;
        case 10:
            return;
        }
        std::cout << std::endl;
        menu();
    }
};

int main()
{
    setlocale(LC_ALL, "Russian");
    list lst;
    lst.menu();
    lst.push_back("3");
    lst.print();
    return 0;
}