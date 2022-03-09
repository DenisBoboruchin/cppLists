#include "cppLists.h"

CLists::CLists () :
	fictElem_ (new item),
    size_ (0)
    {
		fictElem_->data = 111111111;
		fictElem_->next = fictElem_;
		fictElem_->prev = fictElem_;

        this->ListOk_();        
	}

CLists::~CLists ()
{
    this->ListOk_();        
	
    item* workItem = fictElem_->next;
	item* nextItem = NULL;

	for (int i = 0; i < size_; i++)
	{
		nextItem = workItem->next;

		workItem->data =   DESTROYED;
		workItem->next =        NULL;
		workItem->prev =        NULL;

		delete[] workItem;

		workItem = nextItem;
	}

	delete[] workItem;

	size_ = DESTROYED;
}

int CLists::ListInsert (ElemType data, int num)
{
    this->ListOk_();        

    assert (this);
	assert (num > 0);

	if (num > size_ + 1)
		num = size_ + 1;

	item* nextElem = fictElem_->next;

	for (int index = 1; index < num; index++)
		nextElem = nextElem->next;

	item* newElem = new item;
	
	newElem->next = nextElem;
	newElem->prev = nextElem->prev;
	nextElem->prev->next = newElem;
	nextElem->prev = newElem;

	newElem->data = data;

	size_++;

	return this->ListOk_ ();
}

int CLists::ListDelete (int num)
{
    this->ListOk_ ();

	assert (this);
	assert (num > 0);

	if (num > size_)
		num = size_;

	item* workElem = fictElem_->next;

	for (int index = 1; index < num; index++)
		workElem = workElem->next;

	item* nextElem = workElem->next;
	item* prevElem = workElem->prev;

	workElem->data = DESTROYED;
	workElem->next = NULL;
	workElem->prev = NULL;

	delete[] workElem;

	nextElem->prev = prevElem;
	prevElem->next = nextElem;

    size_--;

	return this->ListOk_ ();
}

int CLists::ListInsertFront (ElemType data)
{
    return CLists::ListInsert (data, 1);
}

int CLists::ListInsertBack (ElemType data)
{
    return CLists::ListInsert (data, size_ + 1);
}

int CLists::ListOk_ ()
{
    int ERROR = 0;

    if (size_ < 0)
    {
        printf ("ERROR!!! Incorrect size\n");
        ERROR = MISTAKE;
    }

    assert (!ERROR);

    return NOMISTAKE;
}

int CLists::ListDump ()
{
    DotCtor ();

    item* nextElem = fictElem_->next;
   
    DotElemCtor (fictElem_, fictElem_->data, fictElem_->next, fictElem_->prev, "record", "grey");

    for (int i = 0; i < size_; i++)
    {
        DotElemCtor (nextElem, nextElem->data, nextElem->next, nextElem->prev);

        nextElem = nextElem->next;
    }

    nextElem = nextElem->next;

    for (int j = 0; j < size_ - 1; j++)
    {
        DotEdgeCtor (nextElem, nextElem->next);

        nextElem = nextElem->next;
    }

    DotEnd ();    

	return NOMISTAKE;
}
