/*
 * Tree.cpp
 *
 *  Created on: Mar 5, 2019
 *      Author: elazar
 */

#include "Tree.h"

#include <stdlib.h>
#include <stdio.h>

#include <string>

namespace ariel
{

std::exception Tree::m_ValueAlreadyExistedException = std::runtime_error("Error: This value already existed in tree!");

std::exception Tree::m_RemoveNonExistValueException = std::runtime_error("Error: Can't remove non exist value");

std::exception Tree::m_TreeNotInited = std::runtime_error("The root still not inited!");

std::exception Tree::m_RootNotHaveParent = std::runtime_error("root not have parent!");

std::exception Tree::m_NotHaveLeft = std::runtime_error("the node not have left!");

std::exception Tree::m_NotHaveRight = std::runtime_error("the not not have right!");

Tree::Tree()
{
	init(NULL);
}

Tree::Tree(Tree *parent)
{
	init(parent);
}

Tree::~Tree()
{
	if(m_left != NULL) delete m_left;
	if(m_right != NULL) delete m_right;

	m_left = NULL;
	m_right = NULL;
	m_root = NULL;
	m_parent = NULL;
}

Tree& Tree::insert(int n)
{
	Tree **next = NULL;

	if(m_root == this)
	{
		if(isValueAlreadyExist(n) != NULL)
		{
			throw m_ValueAlreadyExistedException;
		}
	}

	if(m_valueAmount <= 0)
	{
		m_value[m_valueAmount++] = n;
		printf("insert value %d here\n", m_value[0]);
	}
	else if(n < m_value[0])
	{
		printf("will insert value %d left of %d\n", n, m_value[0]);
		next = &m_left;
	}
	else if(n > m_value[0])
	{
		printf("will insert value %d right of %d\n", n, m_value[0]);
		next = &m_right;
	}

	if(next != NULL)
	{
		if(next[0] == NULL)
		{
			next[0] = new Tree(this);
		}
		next[0]->insert(n);
	}

	return *m_root;
}

void Tree::remove(int n)
{
	Tree *tree = isValueAlreadyExist(n);

	if(tree == NULL)
	{
		throw m_RemoveNonExistValueException;
	}
	else
	{
		std::vector<int> container;

		if(tree->m_left != NULL)
		{
			tree->m_left->collectNumbers(container);
			delete m_left;

			m_left = NULL;
		}

		if(tree->m_right != NULL)
		{
			tree->m_right->collectNumbers(container);
			delete m_right;

			m_right = NULL;
		}

		m_valueAmount = 0;

		if(!container.empty())
		{
			for(int i = 0; i < container.size(); i++)
			{
				insert(container[i]);
			}
		}
		else if(tree != m_root)
		{
			Tree *parentTree = tree->m_parent;

			if(parentTree->m_left == tree)
			{
				delete parentTree->m_left;
				parentTree->m_left = NULL;
			}
			else
			{
				delete parentTree->m_right;
				parentTree->m_right = NULL;
			}
		}
		else
		{
			// to root node we do nothing
		}
	}
}

void Tree::collectNumbers(std::vector<int> &collector)
{
	if(m_valueAmount > 0)
	{
		collector.push_back(m_value[0]);

		if(m_left != NULL)
		{
			m_left->collectNumbers(collector);
		}

		if(m_right != NULL)
		{
			m_right->collectNumbers(collector);
		}
	}
}

int Tree::size()
{
	int counter = 0;

	countSomeSelf(counter);

	return counter;
}

void Tree::countSomeSelf(int &counter)
{
	if(m_valueAmount > 0) counter++;

	if(m_left != NULL) m_left->countSomeSelf(counter);
	if(m_right != NULL) m_right->countSomeSelf(counter);
}

bool Tree::contains(int n)
{
	if(m_valueAmount > 0 && m_value[0] == n) return true;

	if(m_left != NULL && m_left->contains(n)) return true;
	if(m_right != NULL && m_right->contains(n)) return true;

	return false;
}

int Tree::root()
{
	if(m_valueAmount > 0)return m_value[0];
	else
	{
		throw m_TreeNotInited;
	}
}

int Tree::parent(int n)
{
	Tree *tree = isValueAlreadyExist(n);

	if(tree != NULL && tree != m_root && tree->m_parent->m_valueAmount > 0)
	{
		return tree->m_parent->m_value[0];
	}
	else
	{
		throw m_RootNotHaveParent;
	}
}

int Tree::left(int n)
{
	Tree *tree = isValueAlreadyExist(n);

	if(tree->m_left == NULL || tree->m_left->m_valueAmount < 0)
	{
		throw m_NotHaveLeft;
	}

	return tree->m_left->m_value[0];
}

int Tree::right(int n)
{
	Tree *tree = isValueAlreadyExist(n);

	if(tree->m_right == NULL || tree->m_right->m_valueAmount < 0)
	{
		throw m_NotHaveRight;
	}

	return tree->m_right->m_value[0];
}

void Tree::print()
{
	std::vector<PrintCacheItem> items;
	collectPrintCache(items, 0);

	// TODO sort
	// TODO print levels
}

void Tree::collectPrintCache(std::vector<PrintCacheItem> &items, int level)
{
	if(m_valueAmount > 0)
	{
		items.push_back(PrintCacheItem(m_value[0], level));
	}

	if(m_left != NULL)
	{
		m_left->collectPrintCache(items, level+1);
	}

	if(m_right != NULL)
	{
		m_right->collectPrintCache(items, level+1);
	}

}

void Tree::init(Tree *parent)

{
	m_root = parent == NULL ? this:parent->m_root;
	m_parent = parent;
	m_left = NULL;
	m_right = NULL;

	m_valueAmount = 0;
}

Tree *Tree::isValueAlreadyExist(int n)
{
	if(m_valueAmount > 0 && m_value[0] == n)
	{
		return this;
	}

	if(m_left != NULL)
	{
		Tree *possibleRet = m_left->isValueAlreadyExist(n);

		if(possibleRet != NULL) return possibleRet;
	}

	if(m_right != NULL)
	{
		Tree *possibleRet = m_right->isValueAlreadyExist(n);

		if(possibleRet != NULL) return possibleRet;
	}

	return NULL;
}

} /* namespace ariel */
