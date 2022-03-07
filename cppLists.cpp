#include "cppLists.h"

CLists::CLists () :
	size_ (0)
	{	
		struct item* pfictElem_ = new item;

		pfictElem_->data = 0;
		pfictElem_->next = NULL;
		pfictElem_->prev = NULL;		

		fictElem_ = *pfictElem_;
	}

CLists::~CLists ()
{
	item* workItem = fictElem_.next;
	item* nextItem = NULL;

	for (int i = 0; i < size_; i++)
	{
		nextItem = workItem->next;

		workItem->data =   DESTROYED;
		workItem->next =   &workItem;
		workItem->prev =   &workItem;

		delete[] workItem;

		workItem = nextItem;
	}

	delete[] workItem;

	size_ = DESTROYED;
}

int CLists::ListInsert (ElemType data, int num)
{
	assert (this);
	assert (num > 0);

	if (num > size_ + 1)
		num = size_ + 1;

	item* nextElem = fictElem_.next;

	for (int index = 1; index < num; index++)
		nextElem = nextElem->next;

	item* newElem = new item;
	
	newElem->next = nextElem;
	newElem->prev = nextElem->prev;
	nextElem->prev->next = newElem;
	nextElem->prev = newElem;

	newElem->data = data;

	size_++;

	return NOMISTAKE;
}

int CLists::ListDelete (int num)
{
	assert (this);
	assert (num > 0);

	if (num > size_)
		num = size_;

	item* workElem = fictElem_.next;

	for (int index = 1; index < num; index++)
		workElem = workElem->next;

	item* nextElem = workElem->next;
	item* prevElem = workElem->prev;

	workElem->data = DESTROYED;
	workElem->next = NULL;
	workElem->prev = NULL;

	delete[] workItem;

	nextElem->prev = prevElem;
	prevElem->next = nextElem;

	return NOMISTAKE;
}
