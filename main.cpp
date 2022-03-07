#include <stdio.h>
#include "cppLists/cppLists.h"

int main ()
{
	CLists l1;

	l1.ListInsert (5, 1);
	l1.ListInsert (10, 2);

	l1.ListDump ();

	return 0;
}
