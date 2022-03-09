#include <stdio.h>
#include "cppLists/cppLists.h"

int main ()
{
	CLists l1;

	l1.ListInsertFront (5);
	l1.ListInsertFront (10);
	l1.ListInsertBack  (15);
	
	l1.ListDelete (1);

	l1.ListDump ();

	return 0;
}
