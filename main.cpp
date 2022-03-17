#include <stdio.h>
#include "cppLists/cppLists.h"

int main ()
{
	DotCtor ();

	CLists l1;

	l1.ListInsertHead  (5);
	l1.ListInsert  (10, 2);
	l1.ListInsert  (15, 4);
	l1.ListInsert  (20, 4);
	l1.ListInsert  (25, 2);
	l1.ListInsert  (30, 3);
	l1.ListInsert  (35, 5);
	l1.ListInsertHead  (40);
	l1.ListInsertTail  (45);
	
	l1.ListDelete (6);
	l1.ListDeleteTail ();

	printf ("%d\n", l1.FoundElem (20));

	l1.ListDump ();

	CLists l2;

	l2.ListInsert (12, 1);

	l2.ListDump ();

	DotEnd ();

	return 0;
}
