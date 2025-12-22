#include <iostream>
#include <string>
#include <vector>

class Stack {
public:
    Stack() {}
    ~Stack() = default;

    int top()
    {
        return stack.empty() ? -1 : stack.back();
    }

    void push(int x)
    {
        stack.push_back(x);
    }

    int pop()
    {
        if (stack.empty()) return -1;
        int v = stack.back();
        stack.pop_back();

        return v;
    }

    bool isEmpty() const
    {
        return stack.empty();
    }

    int size() const
    {
        return stack.size();
    }


private:
    std::vector<int> stack;
};


int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
    Stack stack;

    int N;
    std::cin >> N;

    while (N--)
    {
        int cmd;
        std::cin >> cmd;

        switch (cmd)
        {
        case 1:
            int x;
            std::cin >> x;
            stack.push(x);
            break;
        case 2:
            std::cout << stack.pop() << "\n";
            break;
        case 3:
            std::cout << stack.size() << "\n";
            break;
        case 4:
            std::cout << stack.isEmpty() << "\n";
            break;
        case 5:
            std::cout << stack.top() << "\n";
            break;
        default:
            std::cout << -1 << "\n";
            break;
        }
    }

    return 0;
}
