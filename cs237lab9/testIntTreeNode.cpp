#include "intTreeNode.h"

/*
 * CS237 Lab 9
 * Joe Opseth
 * 21 April 2016
 */

int default_constructor();
int alternate_constructor(int num);
int get_data();
int child_ptr();
int set_data(int);
int destroy();

void pause_237(bool);






int main() {

	int failures = 0;
	failures += default_constructor() +
		alternate_constructor(5) +
		get_data() +
		set_data(4) +
		destroy();
	cout << "Number of failures: " << failures << endl;
	pause_237(false);
	
}

int default_constructor() {
	intTreeNode n;
	if (n.getData() == 0 &&
		n.getLeftChildPtr() == NULL &&
		n.getRightChildPtr() == NULL) {
		return 0;
	}
	else {
		cout << "Default constructor fail!" << endl;
		return 1;
	}
}

int alternate_constructor(int num)
{
	intTreeNode n = intTreeNode(num);
	if (n.getData() == num &&
		n.getLeftChildPtr() == NULL &&
		n.getRightChildPtr() == NULL) {
		return 0;
	}
	else {
		cout << "Alternate constructor fail!" << endl;
		return 1;
	}
}

int get_data()
{
	intTreeNode n = intTreeNode(3);
	if (n.getData() == 3) {
		return 0;
	}
	else {
		cout << "Get data fail!" << endl;
		return 1;
	}
}

int child_ptr()
{
	intTreeNode n;
	intTreeNode l = intTreeNode(2);
	intTreeNode r = intTreeNode(3);
	n.setLeftPtr(&l);
	n.setRightPtr(&r);
	if (n.getLeftChildPtr()->getData() == 2 &&
		n.getRightChildPtr()->getData() == 3) {
		return 0;
	}
	else {
		cout << "Child ptr fail!" << endl;
		return 1;
	}
}

int set_data(int i)
{
	intTreeNode n;
	n.setData(i);
	if (n.getData() == i) {
		return 0;
	}
	else {
		cout << "Set data fail!" << endl;
		return 1;
	}
}

int destroy()
{
	/*
	intTreeNode n, l, r;
	n.setLeftPtr(&l);
	n.setRightPtr(&r);
	delete &n;
	*/
	return 0; // TODO
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



