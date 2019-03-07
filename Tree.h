/*
 * Tree.h
 *
 *  Created on: Mar 5, 2019
 *      Author: elazar
 */

#ifndef TREE_H_
#define TREE_H_

#include <stdexcept>
#include <vector>

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

	static std::exception m_ValueAlreadyExistedException;
	static std::exception m_RemoveNonExistValueException;
	static std::exception m_TreeNotInited;
	static std::exception m_RootNotHaveParent;
	static std::exception m_NotHaveLeft;
	static std::exception m_NotHaveRight;

	struct PrintCacheItem
	{
		PrintCacheItem(int _num, int _level):num(_num), level(_level)
		{}

		int num;
		int level;
	};

public:
	Tree();

	Tree(Tree *parent);

	virtual ~Tree();

	Tree& insert(int n);

	void remove(int n);

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

	void collectNumbers(std::vector<int> &collector);

	void countSomeSelf(int &counter);

	void collectPrintCache(std::vector<PrintCacheItem> &items, int level);
};

} /* namespace ariel */

#endif /* TREE_H_ */
