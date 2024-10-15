#include <bits/stdc++.h>
using namespace std;

/**
 * 
 * 
 * * TREES
 * 
 * * Top down
 * ? in each rec call we visit the node first and come up with values that we pass 
 * ? on to the children nodes //! preorder
 * 
 * 
 * 
 * * example ogf rec function
 * 
 * ! top_down(root, params)
 * 1. return specific value for null node
 * 2. update the answer if needed                      // answer <-- params
 * 3. left_ans = top_down(root.left, left_params)      // left_params <-- root.val, params
 * 4. right_ans = top_down(root.right, right_params)   // right_params <-- root.val, params
 * 5. return the answer if needed                      // answer <-- left_ans, right_ans
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 * 
 */

int main()
{
}