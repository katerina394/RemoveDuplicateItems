#include "RemoveDuplicateItems.h"
#include <gtest/gtest.h>
	
TEST(RemoveDuplicateItems,throws_when_a_pointer_to_the_beginning_of_the_list_points_to_NULL)
{ 
	CNode *list=0;

	EXPECT_ANY_THROW(RemoveDuplicateItems(list));

}

TEST(RemoveDuplicateItems, throws_when_the_list_is_not_ordered)
{
	CNode *list=0;
    CNode *node=new CNode;
	node->next=list;
	node->data=5;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=6;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=1;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=6;
	list=node;

	EXPECT_ANY_THROW(RemoveDuplicateItems(list));
	
	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}
TEST(RemoveDuplicateItems,list_with_different_items)
{
	CNode *list=0;
	int a[4]={1,2,3,4};
	int b[4];
    for (int i=4; i>0; i--)
	{
		CNode *node=new CNode;
		node->next=list;
		node->data=i;
		list=node;
	}

	RemoveDuplicateItems(list);

	CNode *tmp=list;
	for(int i=0; tmp!=0; i++)
	{
		b[i]=tmp->data;
		tmp=tmp->next;
	}
	for (int i=0; i<4; i++) 
		EXPECT_EQ(a[i],b[i]);

	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}

TEST(RemoveDuplicateItems,can_remove_duplicate_items)
{
	CNode *list=0;
	int a[3]={1,3,5};
	int b[3];
    CNode *node=new CNode;
	node->next=list;
	node->data=5;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=3;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=1;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=1;
	list=node;

	RemoveDuplicateItems(list);

	CNode *tmp=list;
	for(int i=0; tmp!=0; i++)
	{
		b[i]=tmp->data;
		tmp=tmp->next;
	}
	for (int i=0; i<3; i++) 
		EXPECT_EQ(a[i],b[i]);

	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}
	
TEST(RemoveDuplicateItems,can_remove_duplicate_items_in_the_end)
{
	CNode *list=0;
	int a[3]={1,3,5};
	int b[3];
    CNode *node=new CNode;
	node->next=list;
	node->data=5;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=5;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=3;
	list=node;
	node=new CNode;
	node->next=list;
	node->data=1;
	list=node;

	RemoveDuplicateItems(list);

	CNode *tmp=list;
	for(int i=0; tmp!=0; i++)
	{
		b[i]=tmp->data;
		tmp=tmp->next;
	}
	for (int i=0; i<3; i++) 
		EXPECT_EQ(a[i],b[i]);

	while (list!=0)
	{
		CNode *node=list;
		list=list->next;
		delete node;
	}
}
	