#include "project1_LinkedList.hpp"

Node::Node()
{
	m_ptrNext = m_ptrPrev = nullptr;

	CustomerData m_data;
    //throw runtime_error( "Node() not yet implemented" );
}

LinkedList::LinkedList()
{
	m_ptrFirst = nullptr;
	m_ptrLast = nullptr;
	m_itemCount = 0;
    //throw runtime_error( "LinkedList() not yet implemented" );
}

LinkedList::~LinkedList()
{
	Clear();
    //throw runtime_error( "~LinkedList() not yet implemented" );
}

void LinkedList::Clear()
{
	while (!IsEmpty())
	{
		PopFront();
	}
	//throw runtime_error( "Clear() not yet implemented" );
}

void LinkedList::PushFront( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;
	if (m_itemCount != 0) {
		m_ptrFirst->m_ptrPrev = newNode;
	}
	else {
		m_ptrLast = newNode;
	}
	newNode->m_ptrNext = m_ptrFirst;
	m_ptrFirst = newNode;
	m_itemCount++;
   // throw runtime_error( "PushFront() not yet implemented" );
}

void LinkedList::PushBack( CustomerData newData )
{
	Node* newNode = new Node;
	newNode->m_data = newData;

	if (m_itemCount != 0) {
		m_ptrLast->m_ptrNext = newNode;
	}
	else {
		m_ptrFirst = newNode;
	}
	newNode->m_ptrPrev = m_ptrLast;
	m_ptrLast = newNode;
	m_itemCount++;
	//throw runtime_error( "PusBack() not yet implemented" );
}

void LinkedList::PopFront() noexcept
{
	if (!IsEmpty()) {
		if (m_ptrFirst == m_ptrLast) {
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;

		}
		else {
			Node* m_ptrSecond = m_ptrFirst->m_ptrNext;
			m_ptrSecond->m_ptrPrev = nullptr;
			delete m_ptrFirst;
			m_ptrFirst = m_ptrSecond;
			m_itemCount--;
		}
	}
   // throw runtime_error( "PopFront() not yet implemented" );
}

void LinkedList::PopBack() noexcept
{
	if (!IsEmpty()) {
		if (m_ptrFirst == m_ptrLast) {
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;

		}
		else {
			Node* m_ptrSecondToLast = m_ptrLast->m_ptrPrev;
			m_ptrSecondToLast->m_ptrNext = nullptr;
			delete m_ptrLast;
			m_ptrLast = m_ptrSecondToLast;
			m_itemCount--;
		}
	}
  // throw runtime_error( "PopBack() not yet implemented" );
}

CustomerData LinkedList::GetFront()
{
	if (m_ptrFirst!=nullptr) {
		return m_ptrFirst->m_data;
	}
    throw runtime_error( "GetFront() not yet implemented" );
}

CustomerData LinkedList::GetBack()
{
	if (m_ptrLast!=nullptr) {
		return m_ptrLast->m_data;
	}
    throw runtime_error( "GetBack() not yet implemented" );
}

CustomerData& LinkedList::operator[]( const int index )
{
	if ((index < Size()) && (index >= 0) && (!IsEmpty())) {
		int counter = 0;
		Node* ptrCurrent = m_ptrFirst;
		while (counter != index)
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			counter++;
		}
		return ptrCurrent->m_data;
	}
    throw runtime_error( "operator[]() not yet implemented" );
}

bool LinkedList::IsEmpty()
{
	if (m_itemCount == 0) {
		return true;
	}
	return false;
    throw runtime_error( "IsEmpty() not yet implemented" );
}

int LinkedList::Size()
{
	return m_itemCount;
    throw runtime_error( "Size() not yet implemented" );
}

void LinkedList::Insert(CustomerData newData, const int index)
{


	if ((index < Size()) && (index >= 1) ) {
		int counter = 0;
		Node* ptrCurrent = m_ptrFirst;

		while (counter != index)
		{
			ptrCurrent = ptrCurrent->m_ptrNext;
			counter++;
		}
		Node* newNode = new Node;
		newNode->m_data = newData;
		newNode->m_ptrNext = ptrCurrent;
		newNode->m_ptrPrev = ptrCurrent->m_ptrPrev;

		ptrCurrent->m_ptrPrev->m_ptrNext = newNode;
		ptrCurrent->m_ptrPrev = newNode;
		m_itemCount++;
	}
	else if (index == Size()) {
		PushBack(newData);
	}
	else if (index == 0) {
		PushFront(newData);
	}

	
}
void LinkedList::Remove(const int index) noexcept
{
	if (!IsEmpty()) {
		if (m_ptrFirst == m_ptrLast) {
			delete m_ptrFirst;
			m_ptrFirst = nullptr;
			m_ptrLast = nullptr;
			m_itemCount--;

		}
		else {
			int counter = 0;
			Node* ptrCurrent = m_ptrFirst;

			while (counter != index)
			{
				ptrCurrent = ptrCurrent->m_ptrNext;
				counter++;
			}
			if (index < (Size() - 1) && index > 0) {
				ptrCurrent->m_ptrPrev->m_ptrNext = ptrCurrent->m_ptrNext;
				ptrCurrent->m_ptrNext->m_ptrPrev = ptrCurrent->m_ptrPrev;
				delete ptrCurrent;
				m_itemCount--;
			}
			else if (index == Size() - 1) {
				PopBack();
			}
			else if (index == 0) {
				PopFront();
			}

		}
	}
	
}