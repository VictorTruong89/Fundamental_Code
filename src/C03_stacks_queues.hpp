#ifndef _CO3_STACKS_QUEUES_HPP_
#define _CO3_STACKS_QUEUES_HPP_

#include <iostream>
#include <stdlib.h>

using namespace std;
#define MAX_STACK 10

/** @brief QUESTION 3.1
 * 
 * How to use a single array to implement 3 Stacks.
 * Assumption: The division among Stacks are flexible.
*/
class MultiStack
{
    /* 
    Stack info is the simplest Stack that holds a set of data about each Stack.
    It does not hold the actual items inside the Stack
    */
    class StackInfo
    {
    public:
        int start, size, capacity;
        StackInfo(int start, int capacity)
        {
            this->start = start;
            this->capacity = capacity;
        }
    };
};





class StacksQueues
{
public:
    struct Stack
    {
        int items[MAX_STACK];
        int top;
    };

    // Print all elements of a Stack
    void PrintStack(StacksQueues::Stack* stack)
    {
        std::printf("Display Stack : ");
        for(int i = stack->top; i > -1; i--)
        {
            std::printf(" %d ", stack->items[i]);
        }
        std::printf("\n");
    }


    /** @brief QUESTION 3.1
     * 
     * How do we use a single array to implement 3 stacks.
     * Assumption:  The division between Stacks are flexible.
    */


    /** @brief QUESTION 3.2
     * 
     * Design a Push, Pop method that returns the minimum elements inside a Stack.
     * Requirement: run time is O(1).
    */
    void Push_withMin(StacksQueues::Stack* stack, int new_item, int* min_all, int* min_excld);
    void Pop_withMin(StacksQueues::Stack* stack, int* min_all, int* min_excld);


    /** @brief QUESTION 3.3
     * 
     * Design a Stack such that if too many items are "pushed" to a Stack, create a new Stack.
    */




private:
    // Create an empty Stack
    void CreateEmptyStack(StacksQueues::Stack* stack)
    {
        stack->top = -1;
    }

    // Check if the Stack is full
    bool isFull(StacksQueues::Stack* stack)
    {
        if(stack->top == MAX_STACK - 1) return true;
        else    return false;
    }

    // Check if the Stack is empty
    bool isEmpty(StacksQueues::Stack* stack)
    {
        if(stack->top == -1)    return true;
        else    return false;
    }

    // Add an element to Stack
    void Push(StacksQueues::Stack* stack, int new_item)
    {
        if(isFull(stack))   std::printf("Stack is FULL. \n");
        else
        {
            stack->top ++;
            stack->items[stack->top] = new_item;
        }
    }

    // Remove an element from Stack
    void Pop(StacksQueues::Stack* stack)
    {
        if( isEmpty(stack) )    std::printf("Stack is EMPTY. Nothing to remove. \n");
        else
        {
            std::printf("The removed item is : %d \n", stack->items[stack->top]);
            stack->top --;
        }
    }

};


#endif // _CO3_STACKS_QUEUES_HPP_