#ifndef THIS_HEADER_H
#define THIS_HEADER_H

#include<iostream>
using namespace std;

//Single chain LinkedList.
//Node for single chain.
template<typename T> struct NodeChain {
	struct NodeChain<T> *next;
	T value;
};

//LinkedList definition. N is the length of the list.
template <typename T, int N>
class LinkedListChain {
private:
	NodeChain<T> *HeadNode;
	NodeChain<T> *TailNode;
public:
	
	//Initialization.
	//Build an empty list.
	LinkedListChain() {
		this->HeadNode = new NodeChain<T>();
		this->TailNode = new NodeChain<T>();
		this->TailNode->next = nullptr;
		this->HeadNode->value = 0;
		this->HeadNode->next = TailNode;
	}
	//Preallocate space for N elements. One has to provide a default n1 value.
	LinkedListChain(T n1) {
		this->HeadNode = new NodeChain<T>();
		this->TailNode = new NodeChain<T>();
		this->TailNode->next = nullptr;
		this->HeadNode->value = N;
		this->HeadNode->next = TailNode;
		for (int i = 0; i < N; i++)
		{
			NodeChain<T> *t = new NodeChain<T>();
			t->next = nullptr;
			t->value = n1;
			this->TailNode->next = t;
			this->TailNode = t;
		}
	}
	//Initialize a LinkedList with an array.
	LinkedListChain(T(&values)[N]) {
		//Note: here don't write NodeChain *HeadNode=new..., or the scope of this HeadNode is in the function.
		this->HeadNode = new NodeChain<T>();
		this->TailNode = new NodeChain<T>();
		this->TailNode->next = nullptr;
		this->HeadNode->value = N;
		this->HeadNode->next = TailNode;
		for (int i = 0; i < N; i++)
		{
			NodeChain<T> *t=new NodeChain<T>();
			t->next = nullptr;
			t->value = values[i];
			//First we link the previous tail node to the new node 
			// and then we set the new node to the tail node.
			this->TailNode->next = t;
			this->TailNode = t;
		}
	}

	//Insert an element before index. Index starts with 0.
	bool Insert(unsigned int index, T value) {
		NodeChain<T> *t = new NodeChain<T>();
		t->value = value;
		if (index==0)
		{
			//First link the new node to the rest of the list.
			t->next = this->HeadNode->next;
			//Next link the head node to the new node.
			this->HeadNode->next = t;
			
		}
		else
		{
			NodeChain<T> *p = this->HeadNode;
			for (int i = 0; i <= index; i++)
			{
				p = p->next;
			}
			t->next = p->next;
			p->next = t;
		}
		//Change the size of the list.
		this->HeadNode->value += 1;
		return 1;
		
	}
	bool Insert(unsigned int index, T value, T fillvalue) {
		if (index>this->HeadNode->value+1)
		{
			cout << "Warning: index is greater than the size of the list so that fillvalue will be used to fill the blank slots" << endl;
		}
		try
		{

		}
		catch (const std::exception&)
		{

		}
		//Change the size of the list.
		this->HeadNode->value += 1;
	}
	//Insert into the head of the list.
	bool Push(T value) {
		Insert(0, value);
		return 0;
	};

	//Delete the element by index.
	bool Delete(unsigned int index) {
		if (this->HeadNode->value == 0) {
			cout << "No elements to delete." << endl;
			return 0;
		}
		if (index==0)
		{
			this->HeadNode->next = this->HeadNode->next->next;
		}
		else
		{
			NodeChain<T> *p = this->HeadNode;
			for (int i = 0; i < index; i++)
			{
				p = p->next;
			}
			p->next = p->next->next;
		}
		this->HeadNode->value = this->HeadNode->value - 1;
		return 1;
	}
	//Delete the first element.
	bool Pop() {
		Delete(0);
		return 0;
	}
	//Print elements.
	void PrintElements() {
		NodeChain<T> *t=this->HeadNode;
		if (t->value==0)
		{
			cout << "There is no elements in the list." << endl;
			return;
		}
		cout << "There are " << t->value <<" elements in the list:" << endl;
		t = t->next;
		for (int i = 0; i < HeadNode->value; i++)
		{
			t = t->next;
			cout << t->value << endl;
		}
	}

	//Get length;
	int Length() {
		return HeadNode->value;
	}
};

#endif