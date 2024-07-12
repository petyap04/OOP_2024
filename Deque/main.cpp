#include <iostream>
#include "Deque.hpp"
#include "Stack.hpp"
#include "Queue.hpp"
#include <deque>
int main()
{
  //this shows that the deque/queue/stack works even if there is no def const 
    class A {
    private:
        int x;
        int y;
    public:
        A(int x, int y):x(x),y(y){}
        int getX()const {
            return x;
        }
    };
    A a1(1,1);
    A a2(2,2);
    A a3(3,3);
    A a4(4,4);
    A a5(5,5);
    A a6(6,6);
    A a7(7,7);
    A a8(8,8);
    A a9(9,9);
    A a10(10,10);
    Deque<A> deque;
    deque.pushAtFront(a1);
    deque.pushAtFront(a2);
    deque.pushAtFront(a3);
    deque.pushAtFront(a4);
    deque.pushAtFront(a5);
    deque.pushAtFront(a6);
    deque.pushAtFront(a7);
    deque.pushAtFront(a8);
    deque.pushAtFront(a9);
    deque.pushAtFront(a10);
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();
    std::cout << deque.peekAtBack().getX() << std::endl;
    deque.popAtBack();

    Stack<A> stack;
    stack.push(a1);
    stack.push(a2);
    stack.push(a3);
    stack.push(a4);
    stack.push(a5);
    stack.push(a6);
    stack.push(a7);
    stack.push(a8);
    stack.push(a9);
    stack.push(a10);
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();
    std::cout << stack.peek().getX() << std::endl;
    stack.pop();

    Queue<A> queue;
    queue.push(a1);
    queue.push(a2);
    queue.push(a3);
    queue.push(a4);
    queue.push(a5);
    queue.push(a6);
    queue.push(a7);
    queue.push(a8);
    queue.push(a9);
    queue.push(a10);
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
    std::cout << queue.peek().getX() << std::endl;
    queue.pop();
}
