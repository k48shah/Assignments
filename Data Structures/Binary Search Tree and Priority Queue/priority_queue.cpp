#include "priority_queue.hpp"

using namespace std;
PriorityQueue::PriorityQueue(unsigned int capacity) {
	if (capacity > 0)
	{
		capacity_ = capacity + 1; //Checking if someone inputs a negative or zero capacity
	}
	else
	{
		capacity_ = 2; //default capacity_
	}
	size_ = 0;
	heap_ = new TaskItem*[capacity_]();
}

PriorityQueue::~PriorityQueue() {
	for(int i = 1; i <= size_; i++)
	{
		if (heap_[i])
		{
			delete heap_[i];
			heap_[i] = NULL;
		}
	}	
	delete [] heap_;
	size_ = 0;
}

unsigned int PriorityQueue::size() const {
	return size_;
}

bool PriorityQueue::empty() const {
	if (size_ == 0)
	{
		return true;
	}
	return false;
}

bool PriorityQueue::full() const {
	if (size_ == capacity_ - 1)
	{
		return true;
	}
	return false;
}

void PriorityQueue::print() const {
}

PriorityQueue::TaskItem PriorityQueue::max() const {
	if (size_ == 0)
	{
		return TaskItem(-1, "NULL");
	}
	return *heap_[1];
}

bool PriorityQueue::enqueue( TaskItem val ) {
	if (full())
	{
		return false;
	}
	else if (empty())
	{
		heap_[1] = new TaskItem(val);
		size_++;
		return true;
	}
	int i = size_ + 1;
	heap_[i] = new TaskItem(val);
	while (i > 1 && heap_[i/2]->priority < heap_[i]->priority)
	{
		TaskItem* temp = heap_[i];
		heap_[i] = heap_[i/2];
		heap_[i/2] = temp;
		i = i/2;
	}
	size_++;
	return true;
}

bool PriorityQueue::dequeue() {
	if (empty())
	{
		return false;
	}
	else if (size_ == 1)
	{
		delete heap_[1];
		heap_[1] = NULL;
		size_--;
		return true;
	}
	*heap_[1] = *heap_[size_];
	delete heap_[size_];
	int i = 1;
	while(i < size_/2 && 
		 (heap_[2*i+1]->priority > heap_[i]->priority || 
		  heap_[2*i]->priority > heap_[i]->priority))
	{
		
		TaskItem *temp = heap_[i];
		if (heap_[2*i]->priority > heap_[i]->priority && heap_[2*i] != NULL)
		{
			heap_[i] = heap_[2*i];
			heap_[2*i] = temp;
			i = 2*i;
		}
		else if (heap_[2*i+1]->priority > heap_[i]->priority && heap_[2*i+1] != NULL)
		{
			heap_[i] = heap_[2*i+1];
			heap_[2*i+1] = temp;
			i = 2*i+1;
		}
	}
	size_--;
	return true;
}
