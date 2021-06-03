#include "C03_stacks_queues.hpp"

using namespace std;


/** @brief QUESTION 3.1 - SOLUTION
 * 
*/









/** @brief QUESTION 3.2 - SOLUTION
 * 
 * The algorithm is to keep track of the min-values of entire Stack,
 * and the min-value of the Stack excluding Top. \n
 * When Popping the Top (actually minimum), we can easily compare these 2 values to return the new_min. \n
 * 
 * There are 2 ways to return 2 minimum-values from a function. \n
 * First, we can add 2 sub-elemtns inside the struct Stack. \n
 * Second, we can pass these 2 minimum by-reference. \n
 * 
 * @param[in] stack Pointer to the Stack object
 * @param[in] new_item  New value to add into the Stack
 * @param[in, out] min_all Minimum value of the entire Stack
 * @param[in, out] min_excld Minimum value of the Stack excluding the top-item
*/
void StacksQueues::Push_withMin(StacksQueues::Stack* stack, int new_item, int* min_all, int* min_excld)
{
    // Push 1st element
    if( StacksQueues::isEmpty(stack) )
    {
        stack->top ++;
        stack->items[stack->top] = new_item;
        *min_all = new_item;
    }
    // Push 2nd element onwards
    else
    {
        stack->top ++;
        stack->items[stack->top] = new_item;
        *min_excld = *min_all;
        *min_all = ( *min_all < new_item ) ? *min_all : new_item;
    }
}
void StacksQueues::Pop_withMin(StacksQueues::Stack* stack, int* min_all, int* min_excld)
{
    // If the Stack has only 1 item before Popping
    if( stack->top == 0 )   std::printf("After this Popping, there is no element inside the Stack. \n");

    // If the top-item is not the min-value of entire Stack
    if( stack->items[stack->top] > *min_all )
    {
        // Popping
        stack->top --;
    }
}





