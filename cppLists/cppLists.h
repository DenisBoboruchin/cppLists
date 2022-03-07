#ifndef CPPLISTS
#define CPPLISTS

#include <stdio.h>
#include <assert.h>


typedef int ElemType;

const int           DESTROYED   =    213;

const int           NOMISTAKE   =      0;

struct item
{
	ElemType		data	    =	   0;
	struct item*	next	    =	NULL;
    struct item*    prev        =   NULL;
};

class CLists
{
private:
	struct item     fictElem_;
    int             size_    ;
public:
    explicit        CLists  ();
                    ~CLists ();
    int             ListInsert (ElemType data, int num);
    int             ListDelete (int num);
    int             ListDump ();
};

#endif
