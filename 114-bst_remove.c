/**
 * bst_delete - Deletes a node from a binary search tree.
 * @root: A pointer to the root node of the BST.
 * @node: A pointer to the node to delete from the BST.
 *
 * Return: A pointer to the new root node after deletion.
 */

bst_t *bst_delete(bst_t *root, bst_t *node)
{
    bst_t *parent = node->parent, *successor = NULL;

    /* No children or right-child only */
    if (node->left == NULL)
    {
        if (parent != NULL && parent->left == node)
            parent->left = node->right;
        else if (parent != NULL)
            parent->right = node->right;
        if (node->right != NULL)
            node->right->parent = parent;
        free(node);
        return (parent == NULL ? node->right : root);
    }

    /* Left-child only */
    if (node->right == NULL)
    {
        if (parent != NULL && parent->left == node)
            parent->left = node->left;
        else if (parent != NULL)
            parent->right = node->left;
        if (node->left != NULL)
            node->left->parent = parent;
        free(node);
        return (parent == NULL ? node->left : root);
    }

    /* Two children */
    successor = inorder_successor(node->right);
    node->n = successor->n;

    if (parent == NULL)
        bst_delete(root, successor);
    else
        bst_delete(parent, successor);

    return root;
}
