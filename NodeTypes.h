#ifndef _NODETYPES_H
#define _NODETYPES_H

#include <iostream>
	using namespace std;
	
struct BTNode {
	string data;
	BTNode * left;
	BTNode * right;
	BTNode * parent;
};

struct LLNode {
	BTNode * data;
	LLNode * next;
};

#endif

