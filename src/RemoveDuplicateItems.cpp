#include "RemoveDuplicateItems.h"

void RemoveDuplicateItems(CNode *list)
{
	if (list!=0)
	{
		CNode *temp=list;
		while(temp->next!=0)
			if(temp->data>temp->next->data)
				throw 1;
			else
				temp=temp->next;
	
		CNode *tmp=list,*node;
		while (tmp->next!=0)
			if (tmp->data==tmp->next->data)
			{	
				node=tmp->next;
				tmp->next=node->next;
				delete node;
			}
			else
				tmp=tmp->next;
	} else throw 1;
}