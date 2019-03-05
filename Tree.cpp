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

std::exception Tree::m_ValueAlreadyExisted = std::runtime_error("Error: This value already existed in tree!");

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
		if(isValueAlreadyExist(n) == NULL)
		{
			throw m_ValueAlreadyExisted;
		}
	}

	if(m_valueAmount <= 0)
	{
		m_value[m_valueAmount++] = n;
	}
	else if(n < m_value[0])
	{
		next = &m_left;
	}
	else if(n > m_value[0])
	{
		next = &m_right;
	}

	if(next != NULL)
	{
		if(next[0] == NULL)
		{
			next[0] = new Tree();
		}
		next[0]->insert(n);
	}

	return *m_root;
}

void Tree::remove(int i)
{

}

int Tree::size()
{
	return 0;
}

bool Tree::contains(int n)
{
	return false;
}

int Tree::root()
{
	return 0;
}

int Tree::parent(int i)
{
	return 0;
}

int Tree::left(int i)
{
	return 0;
}

int Tree::right(int i)
{
	return 0;
}

void Tree::print()
{

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
