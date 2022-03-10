#include <stdio.h>
#include "cppLists/cppLists.h"

int main ()
{
	CLists l1;

	l1.ListInsertHead (5);
	l1.ListInsertHead (10);
	l1.ListInsertTail  (15);
	
	l1.ListDeleteTail ();

	l1.ListDump ();

	return 0;
}
