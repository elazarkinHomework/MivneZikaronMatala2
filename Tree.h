/*
 * Tree.h
 *
 *  Created on: Mar 5, 2019
 *      Author: elazar
 */

#ifndef TREE_H_
#define TREE_H_

#include <stdexcept>

namespace ariel
{

class Tree
{
private:

	int m_value[1];
	int m_valueAmount;

	Tree *m_left;
	Tree *m_right;

	Tree *m_root;
	Tree *m_parent;

	static std::exception m_ValueAlreadyExisted;

public:
	Tree();

	Tree(Tree *parent);

	virtual ~Tree();

	Tree& insert(int n);

	void remove(int i);

	int size();

	bool contains(int n);

	int root();

	int parent(int i);

	int left(int i);

	int right(int i);

	void print();

	//ostream& operator<<(ostream& out, Tree& B)

private:

	void init(Tree *parent);

	Tree *isValueAlreadyExist(int n);
};

} /* namespace ariel */

#endif /* TREE_H_ */
