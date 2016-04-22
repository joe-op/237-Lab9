#include "intBinTree.h"
#include <iostream>

/*
 * CS237 Lab 9
 * Joe Opseth
 * 21 April 2016
 */

void pause_237(bool);

int main() {

	intBinTree the_tree = intBinTree();
	cout << "Call addLeft for 2, 3, 4, 5:" << endl;
	for (int i = 2; i <= 5; i++)
		the_tree.addLeft(i);
	cout << the_tree << endl;

	cout << endl << "Call deleteLeft() twice:" << endl;
	the_tree.deleteLeft();
	the_tree.deleteLeft();
	
	cout << the_tree << endl;
	pause_237(false);

	intBinTree the_tree_2 = intBinTree();
	cout << "Call addright for 2, 3, 4, 5:" << endl;
	for (int i = 2; i <= 5; i++)
		the_tree_2.addRight(i);
	cout << the_tree_2 << endl;
	
	cout << endl << "Call deleteRight() twice:" << endl;
	the_tree_2.deleteRight();
	the_tree_2.deleteRight();

	cout << the_tree_2 << endl;
	pause_237(false);

	intBinTree the_tree_3 = intBinTree();
	intBinTree the_tree_4 = intBinTree();

	for (int i = 0; i < 10; i++)
		the_tree_3.addLeft(i);
	cout << "Original tree:" << endl << the_tree_3 << endl;

	the_tree_4 = the_tree_3;
	cout << "Copied tree:" << endl << the_tree_4 << endl;

	cout << "Deleting two items from original tree..." << endl;
	the_tree_3.deleteLeft();
	the_tree_3.deleteRight();
	cout << "Original tree:" << endl << the_tree_3 << endl;
	cout << "Copied tree:" << endl << the_tree_4 << endl;
	pause_237(false);


}

void pause_237(bool have_newline)
{
	if (have_newline) {
		// Ignore the newline after the user's previous input.
		cin.ignore(200, '\n');
	}

	// Prompt for the user to press ENTER, then wait for a newline.
	cout << endl << "Press ENTER to continue." << endl;
	cin.ignore(200, '\n');
}