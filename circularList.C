#include "circularList.h"

template <class T>
ostream& operator<<(ostream& os, CircularList<T>& cl)
{
	return cl.print(os);
}

template <class T>
ostream& CircularList<T>::print(ostream& os)
{
	if (tail==NULL)
	{
		os<<"[]";
		return os;
	}
	os<<"[";
	Node<T>*ptr=tail->next;
	while(ptr!=tail)
	{
		os<<ptr->element<<',';
		ptr=ptr->next;
	}

	os<<ptr->element<<']';


	return os;
}

template <class T>
CircularList<T>::CircularList()
{
	tail=NULL;
}

template <class T>
CircularList<T>::CircularList(const CircularList<T>& other)
{
	if(other.tail==NULL)
	{
		tail=NULL;
		return;
	}

	Node<T> *ptr=other.tail;
	tail= new Node<T>(ptr->element, NULL);
	Node<T> *node=tail;
	while(ptr->next!=other.tail)
	{
		ptr=ptr->next;
		node->next=new Node<T>(ptr->element,NULL);
		node=node->next;
	}
	node->next=tail;
}

template <class T>
CircularList<T>& CircularList<T>::clone()
{
	return *(new CircularList<T>(*this));
}

template<class T>
CircularList<T>::~CircularList()
{
	if(tail==NULL) return;

	Node<T>*ptr=tail;
	Node<T> *p=ptr;
	ptr=ptr->next;
	delete p;
	p=ptr;

	while(ptr!=tail)
	{
		ptr=ptr->next;
		delete p;
		p=ptr;
	}


}

template<class T>
void CircularList<T>::insert(int index, T element)
{
	if(index<0||index>size()) return;

	if(index==0)
	{
		if(tail==NULL)
		{
			tail=new Node<T>(element);
			tail->next=tail;
			return;
		}
		Node<T>*ptr=new Node<T>(element, tail->next);
		tail->next=ptr;
		return;
	}

	if(index==size())
	{
		tail->next=new Node<T>(element,tail->next);
		tail=tail->next;
		return;
	}

	int count=1;
	Node<T> *ptr=tail->next;
	while(count<index)
	{
		ptr=ptr->next;
		count++;
	}
	ptr->next=new Node<T>(element, ptr->next);
}

template <class T>
T CircularList<T>::remove(int index)
{
	int size=this->size();
	if(index<0||index>=size)
	{
		throw RemoveException("empty structure");
	}
	if (tail->next==tail)
	{
		T val=tail->element;
		delete tail;
		tail=NULL;
		return val;
	}

	int count=0;
	Node<T> *ptr=tail;
	while(count<index)
	{
		ptr=ptr->next;
		count++;
	}

	T val=ptr->next->element;
	ptr->next=ptr->next->next;
	if (index==size-1) tail=ptr;
	return val;
}

template <class T>
bool CircularList<T>::isEmpty()
{
	return (tail==NULL);
}

template <class T>
void CircularList<T>::clear()
{
	if(tail==NULL) return;

	Node<T>*ptr=tail;
	Node<T> *p=ptr;
	ptr=ptr->next;
	while(ptr!=tail)
	{
		ptr=ptr->next;
		delete p;
		p=ptr;
	}

	delete tail;
	tail=NULL;

}

template <class T>
Node<T>* CircularList<T>::getLeader()
{
	return tail;
}

template <class T>
int CircularList<T>::size()
{
	if (tail==NULL) return 0;
	Node<T>*ptr=tail->next;
	int count=1;
	while(ptr!=tail)
	{
		ptr=ptr->next;
		count++;
	}

	return count;
}

template <class T>
CircularList<T>& CircularList<T>::operator=(const CircularList<T>& other)
{
	this->clear();
	if(other.tail==NULL)
	{
		tail=NULL;
		return (*this);
	}
	Node<T> *ptr=other.tail;
	tail= new Node<T>(ptr->element);
	Node<T> *node=tail;
	while(ptr->next!=other.tail)
	{
		ptr=ptr->next;
		cout<<ptr->element<<endl;
		node->next=new Node<T>(ptr->element);
		node=node->next;
	}
	node->next=tail;
	return *(this);
}
