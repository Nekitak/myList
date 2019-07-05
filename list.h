#pragma once

#include <iostream>


namespace Reality
{
	template<typename T>
	class list
	{
		public:

			list();
			~list();

			void pop_back();
			void pop_front();
			void push_back(T _data);
			void clear();


			int GetSize() { return Size; }
			 
			void printOn();
			T& operator[](const int index);


		private:

			template<typename T>
			class Node 
			{
				public:
					Node* _next_element;
					T _data;

					Node(T _data = T() ) : _data(_data) , _next_element(nullptr)
					{
					 
					}
			};

			int Size;
			Node<T> *head;
	};
	  
	template<typename T>
	list<T>::list() : Size(0) , head(nullptr)
	{
		 
	 
	}

	template<typename T>
	list<T>::~list()
	{
		clear();
	}

	template<typename T>
	void list<T>::pop_back()
	{
		Node<T> *current = this->head;

		while (current->_next_element != nullptr)
		{
			current = current->_next_element;
		}

		delete current;
		Size--;
	}

	template<typename T>
	 void list<T>::pop_front()
	{
		 Node<T> *temp = head;

		 head = head->_next_element;

		delete temp;

		Size--;
	}

	template<typename T>
	 void list<T>::push_back(T _data)
	{
		 if (head == nullptr){

			 head = new Node<T>(_data);
		 }
		 else {
			 Node<T> *current = this->head;
			 while (current->_next_element != nullptr)
			 {
				 current = current->_next_element;	 
			 }

			 current->_next_element = new Node<T>(_data);
		 }

		 Size++;
	}

	 template<typename T>
	 void list<T>::clear()
	 {
		 while (Size)
		 {
			 pop_front();			 
		 }
	 }
		
	 
	 template<typename T>
	 void list<T>::printOn()
	 {
		 Node<T> *current = this->head;

		 while (current != nullptr)
		 {
			  std::cout << current->_data << " " ;
			  current = current->_next_element;
		 }
	 }

	 template<typename T>
	 T & list<T>::operator[](const int index)
	 {
		 int counter = 0;
		 Node<T> *current = this->head;

		 while (current!=nullptr) 
		 {
			 if (counter == index) {
				 return current->_data;
			 }
			 current = current->_next_element;
			 counter++;
		 }
	 }


}