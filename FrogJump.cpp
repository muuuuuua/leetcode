/**
 * 403. Frog Jump
 */

#include "inc/common.h"

bool canCross(vector<int>& stones) {
    if(stones.size() <= 1)
        return true;
    if(stones[1] != stones[0]+1)
        return false;

    for(int i = 2;i < stones.size();i++) {
        
    }
    
}
