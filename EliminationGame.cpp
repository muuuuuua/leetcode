/**
 * 390. Elimination Game
 */

#include "inc/common.h"

/**
 * lastRemaining(n) + EliminateFromRightFirst(n) = n + 1;
 * <=> lastRemaining(n/2) + EliminateFromRightFirst(n/2) = n/2 + 1;
 * <=> EliminateFromRightFirst(n/2) = 1 + n/2 - lastRemaining(n/2);
 * For the original sequence 1,2,3,...,n, 
 * after first elimination from left side, 
 * we have a new sequence 2,4,6,...,(n-1 or n). 
 * The new sequence consists of even numbers. 
 * Then actually it is 2 * (1, 2, 3, ..., n/2), 
 * in which the elimination for the (1, 2, 3, ... n/2) now starts from the right side. 
 * It is exactly EliminateFromRightFirst(n/2).
 */
int lastRemaining(int n) {
    if(n == 1) return 1;
    return 2*(1+n/2-lastRemaining(n/2));
}

int main() {
    cout<<lastRemaining(10)<<endl;
    return 0;
}
