#ifndef CPPLISTS
#define CPPLISTS

#include <stdio.h>
#include <assert.h>

#include "../graphviz/graphviz.h"

typedef int ElemType;

const int           DESTROYED   =    213;

const int           NOMISTAKE   =      0;
const int           MISTAKE     =      1;

struct item
{
	ElemType		data	    =	   0;
	struct item*	next	    =	NULL;
    struct item*    prev        =   NULL;
};

class CLists
{
private:
	struct item*    fictElem_   =   NULL;
    int             size_       =      0;

    int             ListOk_             ();
public:
    explicit        CLists              ();
                    ~CLists             ();
    int             ListInsert          (ElemType data, int num);
    int             ListInsertFront     (ElemType data);
    int             ListInsertBack      (ElemType data);
    int             ListDelete          (int num);
    int             ListDump            ();
};

#endif
