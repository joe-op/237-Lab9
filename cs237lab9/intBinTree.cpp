#include "intBinTree.h"
#include "intTreeNode.h"

using namespace std;


intBinTree::intBinTree() {
	root = NULL;
	numItems = 0;
}


intBinTree::intBinTree(const intBinTree & T) {
	// Use the data stored in the T's root to 
	// create a new intTreeNode as the root of this binary tree.
	//    THE FOLLOWING USES RECURSION.
	// Use the copy constructor to create a leftsubtree for this binary tree
	// from T's leftsubtree
	// Use the copy constructor to create a rightsubtree for this binary tree
	// from T's rightsubtree

	if(T.root == NULL) {
		root = NULL;
		numItems = 0;
	} else {
		root = copyNode(T.root);
		numItems = T.numItems;
	}	
}	

intBinTree & intBinTree::operator= (const intBinTree & T) {
	
	if (T.root == this->root)
		return *this;

	delete root;
	if (T.root == NULL) {
		root = NULL;
		numItems = 0;
	}
	else {
		root = copyNode(T.root);
		numItems = T.numItems;
	}

	return *this;
}


intBinTree::~intBinTree() {
	delete (root);  // will recursively call the intTreeNode destructor
	root = NULL;
}


int intBinTree::getSize() const {
	return numItems;
}


int intBinTree::getRoot() const {
	return root->getData();
	// Since the pre condition requires the tree object to have at least
	// one element, root-> will not give us a "de-referencing a null
	// pointer (dangling pointer)" error.
}

intTreeNode* intBinTree::getLeftSubTree() const {
	return root->getLeftChildPtr();
}


intTreeNode* intBinTree::getRightSubTree() const {
	return root->getRightChildPtr();
}


void intBinTree::addLeft(int num) {

	intTreeNode* nodeToAddPtr = new intTreeNode(num);
	if (root == NULL) {
		root = nodeToAddPtr;
	}
	else {
		intTreeNode* current = root;
		while (current->getLeftChildPtr() != NULL && current->getRightChildPtr() != NULL) {
			current = current->getLeftChildPtr();
		}
		if (current->getLeftChildPtr() == NULL) {
			current->setLeftPtr(nodeToAddPtr);
		}
		else {
			current->setRightPtr(nodeToAddPtr);
		}
	}






	// TODO: use the following pseudocode

	// Create a new intTreeNode pointed to by, say nodeToAddPtr, 
	// and store num in this node. 
	// Initialize an intTreeNode pointer, say currentPtr, to the root.
	// If the current tree is empty, then
	//   the new node is the root of the tree.
	// else
	//   Loop through the left child of currentPtr until a node is
	//     found that does not have two children
	//   ASSERT: currentPtr->getLeftChildPtr() == NULL or
    //           currentPtr->getRightChildPtr() == NULL
	//   if (currentPtr->getLeftChildPtr() == NULL) {
	//     add nodeToAddPtr as the left child of currentPtr
	//   }
	//   else {
	//     add nodeToAddPtr as the right child of currentPtr
	//   }
}


void intBinTree::addRight(int num) {
	intTreeNode* nodeToAddPtr = new intTreeNode(num);
	if (root == NULL) {
		root = nodeToAddPtr;
	}
	else {
		intTreeNode* current = root;
		while (current->getLeftChildPtr() != NULL && current->getRightChildPtr() != NULL) {
			current = current->getRightChildPtr();
		}
		if (current->getRightChildPtr() == NULL) {
			current->setRightPtr(nodeToAddPtr);
		}
		else {
			current->setLeftPtr(nodeToAddPtr);
		}
	}

}


void intBinTree::deleteLeft() {

	if (root != NULL) {
		intTreeNode *currentPtr = root;
		intTreeNode *currentParentPtr = NULL;
		while (currentPtr->getLeftChildPtr() != NULL) {
			currentParentPtr = currentPtr;
			currentPtr = currentPtr->getLeftChildPtr();
		}
		if (currentPtr == root) {
			intTreeNode *tempPtr = root;
			root = tempPtr->getRightChildPtr();
			delete tempPtr;
		}
		else if (currentPtr->getRightChildPtr() == NULL) {
			currentParentPtr->setLeftPtr(NULL);
			delete currentPtr;
		}
		else {
			currentParentPtr->setLeftPtr(currentParentPtr->getRightChildPtr());
			delete currentPtr;
		}
	}




	//TODO: use the following pseudocode
	
	// Initialize currrentPtr to the root.
	// Loop through the left child of currentPtr until a node is
	//   found that does not have a left child.
	// If currentPtr is the root, then 
	//   set a temp pointer to the current root
	//   set the root to be the right child of the current root
	//   delete the node pointed to by the temp pointer.
	// else 
	//   ASSERT: currentPtr does not have a left child
	//   if currentPtr->getRightChild() == NULL
	//     Set the left pointer of the parent of currentPtr to be NULL
	//     delete currentPtr
	//   else
	//     set the left child of the parent of currentPtr to be the
	//       right child of currentPtr
	//     delete currentPtr
}


void intBinTree::deleteRight() {
	
	if (root != NULL) {
		intTreeNode *currentPtr = root;
		intTreeNode *currentParentPtr = NULL;
		while (currentPtr->getRightChildPtr() != NULL) {
			currentParentPtr = currentPtr;
			currentPtr = currentPtr->getRightChildPtr();
		}
		if (currentPtr == root) {
			intTreeNode *tempPtr = root;
			root = tempPtr->getLeftChildPtr();
			delete tempPtr;
		}
		else if (currentPtr->getLeftChildPtr() == NULL) {
			currentParentPtr->setRightPtr(NULL);
			delete currentPtr;
		}
		else {
			currentParentPtr->setRightPtr(currentParentPtr->getLeftChildPtr());
			delete currentPtr;
		}
	}
}



void intBinTree::inOrderTraversal(ostream & stream, intTreeNode * current) {
		if (current != NULL) {
			inOrderTraversal(stream, current->getLeftChildPtr());
			stream << current->getData() << " ";
			inOrderTraversal(stream, current->getRightChildPtr());
		}

	}

intTreeNode * intBinTree::copyNode(intTreeNode * other)
{
	if (other == NULL)
		return NULL;
	else {
		intTreeNode* new_node = new intTreeNode(other->getData());
		new_node->setLeftPtr(copyNode(other->getLeftChildPtr()));
		new_node->setRightPtr(copyNode(other->getRightChildPtr()));
		return new_node;
	}
}


ostream & operator<< (ostream & stream, const intBinTree & T) {
		intTreeNode * current = T.root;
		intBinTree temp = intBinTree();
		temp.inOrderTraversal(stream, current);
		return stream;
	}


