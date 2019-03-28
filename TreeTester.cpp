/**
 * @author Elazar Elkin
 */

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Tree.hpp"

#define TEST_CASE2(FUNC_NAME) {bool ret = FUNC_NAME();fprintf(stdout, "%s test %s!\n", #FUNC_NAME, ret?"success":"fail");}

class RandomNonEqualRandomNumbers
{
private:
	int m_size;
	int *m_arr;

public:
	RandomNonEqualRandomNumbers(int size)
	{
		m_size = size < 0 ? 1 : size;

		m_arr = (int *) malloc(m_size*sizeof(int));

		createRandomNonEqualValuesInArray();
	}

	virtual ~RandomNonEqualRandomNumbers()
	{
		if(m_arr != NULL)
		{
			free(m_arr);
		}
	}

	int operator [](int index)
	{
		if(index < m_size)
		{
			return m_arr[index];
		}

		return (1<<30);
	}

	void printArray()
	{
		for(int i = 0; i < m_size; i++)
		{
			fprintf(stdout, "%d ", m_arr[i]);
		}
		fprintf(stdout, "\n");
	}

	void shuffleArray()
	{
		// shuffer
		for(int i = m_size; i > 0 ; i--)
		{
			int randomIndex = rand()%i;
			int temp = m_arr[i-1];

			m_arr[i-1] = m_arr[randomIndex];
			m_arr[randomIndex] = temp;
		}
	}

	int size()
	{
		return m_size;
	}

private:

	void createRandomNonEqualValuesInArray()
	{
		for(int i = 0; i < m_size; i++)
		{
			m_arr[i] = i;
		}

		shuffleArray();
	}
};


bool TestEmptyTree()
{
	ariel::Tree tree;
	RandomNonEqualRandomNumbers arr(1 + rand()%10);

	arr.printArray();

	if(tree.size() != 0)
	{
		return false;
	}

	for(int i = 0; i < arr.size(); i++)
	{
		tree.insert(arr[i]);
	}

	tree.print();

	if(tree.size() == arr.size())
	{
		return false;
	}

	return true;
}

int main()
{
	int counterError = 0;

	srand(time(NULL));

	try
	{
		TEST_CASE2(TestEmptyTree)
//		threetree.insert(5).insert(3).insert(7);
//		cout << "threetree: size=" << threetree.size() << " root="
//				<< threetree.root() << " data=" << endl;  // size=3, root=5.
//		threetree.print();
//
//		cout << threetree.size()      // should print 3
//				<< threetree.parent(3)   // should print 5
//				<< threetree.parent(7)   // should print 5
//				<< threetree.left(5)     // should print 3
//				<< threetree.right(5)    // should print 7
//				//<< threetree.insert(5)    // should throw an exception: "5 already exists"
//				<< endl;
	}
	catch (std::exception &e)
	{
		fprintf(stderr, "Caught exception: %s\n", e.what());
	}
}
