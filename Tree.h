/*
 * Tree.h
 *
 *  Created on: Mar 5, 2019
 *      Author: elazar
 */

#ifndef TREE_H_
#define TREE_H_

namespace ariel
{

class Tree
{
private:

	Tree *m_left;
	Tree *m_right;

public:
	Tree();
	virtual ~Tree();

	int size();

	Tree& insert(int n);

	int root();

	void print();

	int parent(int i);

	int left(int i);

	int right(int i);

	bool contains(int n);
};

} /* namespace ariel */

#endif /* TREE_H_ */
