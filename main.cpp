#include "Array.h"
#include "Fixed_Array.h"
#include "Queue.h"
#include "Stack.h"

#include <iostream>


int main (int argc, char * argv [])
{

    std::cout<<"Creating an Array"<<std::endl;
    Array<int> * arr = new Array<int>(10, 7);

    std::cout<<"Creating a Stack"<<std::endl;
    Stack<int> * stack = new Stack<int>();

    std::cout<<"Creating a Queue"<<std::endl;
    Queue<int> * queue = new Queue<int>();

    std::cout<<"Creating a Fixed Array"<<std::endl;
    Fixed_Array<int, 10> * fixedArr = new Fixed_Array<int, 10>(9);



    std::cout<<"\nValue of arr: "<< arr->get(2)<<std::endl;

    std::cout<<"\nPushing to the stack..."<<std::endl;
    stack->push(5);
    std::cout<<"Pushed to stack..."<<std::endl;

    std::cout<<"\nPushing to the stack..."<<std::endl;
    stack->push(6);
    std::cout<<"Pushed to stack..."<<std::endl;

    std::cout<<"\nPopping from the stack..."<<std::endl;
    stack->pop();
    
    std::cout<<"\nEnqueing into the queue..."<<std::endl;
    queue->enqueue(7);
    std::cout<<"\nEnqueing into the queue..."<<std::endl;
    queue->enqueue(7);
    std::cout<<"\nEnqueing into the queue..."<<std::endl;
    queue->enqueue(7);

    std::cout<<"Dequeing from the queue..."<<std::endl;
    queue->dequeue();

    std::cout<<"\nValue of fixedArr: "<< fixedArr->get(2)<<std::endl;

    delete arr;
    delete stack;
    delete queue;
    delete fixedArr;
    return 0;
}