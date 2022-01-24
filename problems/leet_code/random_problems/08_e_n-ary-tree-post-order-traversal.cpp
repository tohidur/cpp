/* N-ary Tree postorder traversal
 *
 * Given an n-ary tree return the post order traversal of it's node's values
 *
 */

#include<iostream>
#include<vector>
#include<stack>
#include "tools/node/node.h"

using namespace std;

stack<int> post_order(NTreeNode* root) {
    stack<int> result;
    stack<NTreeNode*> st{};

    st.push(root);
    while (!st.empty()) {
        NTreeNode* node = st.top();
        st.pop();
        result.push(node->data);
        for (NTreeNode* c : node->childs) {
            st.push(c);
        }
    }

    return result;
}


int main()
{
    NTreeNode* root = new NTreeNode(1);
    root->childs.push_back(new NTreeNode(3));
    root->childs.push_back(new NTreeNode(2));
    root->childs.push_back(new NTreeNode(4));
    root->childs[1]->childs.push_back(new NTreeNode(5));
    root->childs[1]->childs.push_back(new NTreeNode(6));
    root->childs[1]->childs.push_back(new NTreeNode(7));
    root->childs[1]->childs.push_back(new NTreeNode(8));

    stack<int> result = post_order(root);
    while (!result.empty()) {
        cout << result.top() << endl;
        result.pop();
    }
}

