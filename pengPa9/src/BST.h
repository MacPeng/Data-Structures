/*
 * BST.h
 *
 *  Created on: Dec 6, 2019
 *      Author: mikepeng
 */

#ifndef BST_H_
#define BST_H_

#include <iostream>
using namespace std;

struct Treenode
{
	int nodeValue;
	int bf;
	Treenode * Lchild;
	Treenode * Rchild;
};

class BST
{
private:
	Treenode * root;

	void traverseInOrderInternal(Treenode *);		// internal functions - all by subtree
	void traversePreOrderInternal(Treenode *);
	void traversePostOrderInternal(Treenode *);
	bool traverseLevelOrderInternal(Treenode *, int);
	void print2DInternal(Treenode *, int);

	void deleteInternal (Treenode * &);				// internal delete function

	int heightInternal(Treenode *);					// internal BF functions
	void setallBFInternal(Treenode *);
	int getLargestBFInternal(Treenode *);

public:
	BST();
	void insert (int &);				// user functions - all whole tree
	bool search (int &);
	void udelete (int &);

	void setallBF();					// sets BF for whole tree
	int height();						// height of whole tree
	int getLargestBF();					// largest BF in whole tree

	void traverseLevelOrder();			// traversal functions
	void print2D();
	void traverseInOrder();
	void traversePreOrder();
	void traversePostOrder();
};

#endif /* BST_H_ */
