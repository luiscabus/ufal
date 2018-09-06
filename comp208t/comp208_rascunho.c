#include <stdio.h>
#include <string.h>
#include <stdlib.h>
// binary_tree* create_empty_binary_tree();

binary_tree* create_binary_tree(int item, binary_tree *left, binary_tree *right) {
	binary_tree *new_leaf = malloc(sizeof(binary_tree));
	new_leaf->item = item;
	new_leaf->left = NULL;
	new_leaf->right = NULL;
	// *raiz = new_leaf;
	return new_leaf;
}

binary_tree* rotate_left(binary_tree *bt) {
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->right != NULL) {
		subtree_root = bt->right;
		bt->right = subtree_root->left;
		subtree_root->left = bt;
	}
	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	return subtree_root;
}

binary_tree* rotate_right(binary_tree *bt) {
	binary_tree *subtree_root = NULL;
	if (bt != NULL && bt->left != NULL) {
		subtree_root = bt->left;
		bt->left = subtree_root->right;
		subtree_root->right = bt;
	}
	subtree_root->h = h(subtree_root);
	bt->h = h(bt);
	return subtree_root;
}


binary_tree* add(binary_tree *bt, int item)
{
	if (bt == NULL) {
		return create_binary_tree(item, NULL, NULL);
	} else if (bt->item > item) {
		bt->left = add(bt->left, item);
	} else {
		bt->right = add(bt->right, item);
	}

	bt->h = h(bt);
	binary_tree *child;

	if (balance_factor(bt) == 2 || balance_factor(bt) == -2) {
		if (balance_factor(bt) == 2) {
			child = bt->left;
			if (balance_factor(child) == -1) {
				bt->left = rotate_left(child);
			}
			bt = rotate_right(bt);
		} else if (balance_factor(bt) == -2) {
			child = bt->right;
			if (balance_factor(child) == 1) {
				bt->right = rotate_right(child);
			}
			bt = rotate_left(bt);
		}
	}
	return bt;
}







int main() {

	return 0;
}