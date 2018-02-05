#include "DynamicList.h"
#include <string>
#include <iostream>


using namespace std;

int list_capacity;
int size;
int *list;


DynamicList::DynamicList(int capacity)
{
this->list_capacity = capacity;
this->size = 0;
this->list = new int[list_capacity];

	for(int i = 0; i < list_capacity; i++)
		list[i] = 0;

}

void DynamicList::add_item(int item)
{
this->list[size] = item;
this->size++;
	if(size > (list_capacity/2))
		expand_list();
}

void DynamicList::remove_item()
{
	if(size == 0)
		cout << "error: list size is zero" << endl;
	else
	{
		this->size--;
		this->list[size] = 0;
	}
	if(size < (list_capacity/4))
		shrink_list();
}

void DynamicList::expand_list()
{
list_capacity*=2;
int *temp;
temp = new int[list_capacity];
	for(int i=0; i< size; i++)
		temp[i] = list[i];
delete[] list;
list = temp;	
}

void DynamicList::shrink_list()
{
list_capacity = list_capacity/2;
int *temp;
temp = new int[list_capacity];
	for(int i=0; i<size; i++)
		temp[i] = list[i];
delete[] list;
list = temp;
}

int DynamicList::get_size()
{
return this->size;
}

void DynamicList::print_list()
{
cout << "List max capacity = " << list_capacity << endl;
cout << "List current size = " << size << endl;
cout << "List contents ";
	if(size == 0)
		cout << "\n";
	else
	{
		for(int i=0; i<size; i++)
			if(i != (size -1))
				cout << this->list[i] << ", ";
			else
				cout << this->list[i] << endl;
	}
}
