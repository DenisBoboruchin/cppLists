#include "cppLists.h"

CLists::CLists () :
	fictElem_ (new item[1]{}),
	size_ (0)
	{	
		fictElem_.data = 0;
		fictElem_.next = NULL;
		fictElem_.prev = NULL;		
	}


