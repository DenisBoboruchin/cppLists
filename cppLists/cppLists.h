#ifndef CPPLISTS
#define CPPLISTS

#include <stdio.h>
#include <assert.h>
#include <string.h>

#include "../graphviz/graphviz.h"

typedef int ElemType;

typedef enum 
{
        MIS = 0,
        INT,
        DOUBLE  
}   ElementType;

const int           DESTROYED   =   -213;

const int           NOMISTAKE   =      0;
const int           MISTAKE     =      1;

const int           NOTFOUND    =   -583;

struct item
{
    ElementType     Type                ;

	ElemType		data	    =	   0;
	
    struct item*	next	    =	NULL;
    struct item*    prev        =   NULL;
};

class CLists
{
private:
	struct item*    fictElem_   =   NULL;
    int             size_       =      0;

    int             ListOk_           ();

public:
    explicit        CLists            (const char* type);
                    ~CLists           ();
    
    int             ListInsert        (ElemType data, int num);
    int             ListInsertHead    (ElemType data);
    int             ListInsertTail    (ElemType data);
    
    int             ListDelete        (int num);
    int             ListDeleteHead    ();
    int             ListDeleteTail    ();
   
    int             FoundElem         (ElemType data);

    int             ListDump          ();
};

ElementType     CheckType (const char* type);

#endif
