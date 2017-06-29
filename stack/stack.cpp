#include <string>
#include <iostream>

class Stack {
    private:
        int head;
        int cap;

    public:
        int size;
        int *items;

        Stack() {
            cap = 8;
            items = new int[cap];
            head = 0;
            size = 0;
        }

        void push(int val) {
            if (size == cap) {
                cap = cap * 2;
                int *copy = new int[cap];
                for (int i = 0; i < (sizeof(copy)/sizeof(*copy)); i++) {
                    copy[i] = items[i];
                }
                items = copy;
            }
            items[head] = val;
            head++;
            size++;
        }

        int pop() {
            if (empty()) {
                throw std::string("The stack is empty!");
            }             head--;
            size--;
            return items[head];
        }

        int peek() {
            if (empty()) {
                throw std::string("The stack is empty!");
            }
            return items[head - 1];
        }

        bool empty() {
            return (size == 0);
        }

        ~Stack() {
            delete[] items;
        }
};

int main() {
    Stack *stk = new Stack();
    for (int i = 0; i < 5; i++) {
        stk->push(i + 1);
    }
    for (int j = 0; j < 5; j++) {
        int curr = stk->pop();
        std::cout << "Popped the number: " << curr << std::endl;
    }
    return 0;
}