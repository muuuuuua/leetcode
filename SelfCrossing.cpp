/**
 * 335. Self Crossing
 */
#include "inc/common.h"

/*               i-2
    case 1 : i-1┌─┐
                └─┼─>i
                 i-3
 
                    i-2
    case 2 : i-1 ┌────┐
                 └─══>┘i-3
                 i  i-4      (i overlapped i-4)
 
    case 3 :    i-4
               ┌──┐ 
               │i<┼─┐
            i-3│ i-5│i-1
               └────┘
                i-2
 
*/

bool isSelfCrossing(vector<int> &x) {
    int n = x.size();
    if(n <= 3) return false;
    for(int i=3; i<n; i++) {
        // Case 1: current line crosses the line 3 steps ahead of it
        if(x[i]>=x[i-2] && x[i-1]<=x[i-3]) return true;  
        // Case 2: current line crosses the line 4 steps ahead of it
        else if(i>=4 && x[i-1]==x[i-3] && x[i]+x[i-4]>=x[i-2]) return true; 
        // Case 3: current line crosses the line 6 steps ahead of it
        else if(i>=5 && x[i-2]>=x[i-4] && x[i]+x[i-4]>=x[i-2] && x[i-1]<=x[i-3] && x[i-1]+x[i-5]>=x[i-3]) return true;  
    }
    return false;
}

int main() {
    int a[] = {2,1,1,2};
    vector<int> b = arrayToVector(a);
    cout<<isSelfCrossing(b)<<endl;
    return 0;
}
