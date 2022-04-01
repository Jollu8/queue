#include <iostream>
#include <algorithm>
#include <numeric>
#include <stack>


template<typename Type>
class Queue {
public:
    void Push(const Type &element);

    void Pop() {
        if (!stack1_.empty()) {
            Type x = stack1_.top();
            stack1_.pop();
        }
    }

    Type &Front() {
        if (!stack1_.empty()) {
            return stack1_.top();
        }
    }

    const Type &Front() const {
        return stack1_.top();
    }

    uint64_t Size() const {
        return stack1_.size();
    }

    bool IsEmpty() const {
        return stack1_.empty();
    }

private:
    std::stack<Type> stack1_;
    std::stack<Type> stack2_;
};

template<typename Type>
void Queue<Type>::Push(const Type &element) {
    while (!stack1_.empty()) {
        stack2_.push(stack1_.top());
        stack1_.pop();
    }
    stack1_.push(element);
}


template<typename T>
void PrintRange(const T &start, const T &end) {
    for (auto it = start; it != end; ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main() {
    Queue<int> queue;
    std::vector<int> values(5);

    std::iota(values.begin(), values.end(), 1);
    std::random_shuffle(values.begin(), values.end());
    PrintRange(values.begin(), values.end());
    std::cout << "Contains stack" << std::endl;
    for (int i = 0; i < 5; ++i) {
        queue.Push(values[i]);
        std::cout << "Push  element " << values[i] << std::endl;
        std::cout << "First element stack " << queue.Front() << std::endl;
    }

    std::cout << "Attention element from stack" << std::endl;

    while (!queue.IsEmpty()) {
        std::cout << "Do front element " << queue.Front() << std::endl;
        queue.Pop();
    }

}

