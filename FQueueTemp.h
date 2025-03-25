#pragma once
#include "FifoItem.h"

template <class T>
class FQueue{
private:
public:
	FQueue( );
	virtual ~FQueue( );
	bool FQEmpty( );
	int FQEnqueue( FQINFO*FifoInfo );
	FQINFO* FQDequeue( );
	void FQClear( );

private:
	FifoItem<T>* m_pHead;
	FifoItem<T>* m_pTail;
	void FQDel( );

	friend class FifoException;
};

template <class T> FQueue<T>::FQueue( ){
	T* QueueInfo = new(nothrow) T( 0 );
	if( !QueueInfo ) throw FifoException( FIFO_ALLOCATION_ERROR );
	m_pHead = new(nothrow) FifoItem<T>( QueueInfo );
	if( !m_pHead ) throw FifoException( FIFO_ALLOCATION_ERROR );
	m_pTail = m_pHead;
}

template <class T> FQueue<T>:: ~FQueue( ){
	FQClear( );
	delete m_pHead;
	delete m_pTail;
}

template <class T> void FQueue<T>::FQDel( ){
	if( FQEmpty( ) ) return;

	FifoItem<T>* pom = m_pHead;
	m_pHead = pom->m_pNext;
	delete pom;
	if( FQEmpty( ) ){
		m_pTail = NULL;
		m_pHead->m_pNext = NULL;
	}
}

template <class T> bool FQueue<T>::FQEmpty( ){
	return (!m_pHead->m_pNext);
}

template <class T> int FQueue<T>::FQEnqueue( FQINFO* FifoInfo ){
	FifoItem<T>* pItem = new(nothrow) FifoItem<T>( FifoInfo );
	if( !pItem ) throw FifoException( FIFO_ALLOCATION_ERROR );
	if( !pItem )return 0;

	if( FQEmpty( ) )
		m_pHead->m_pNext = pItem;
	else
		m_pTail->m_pNext = pItem;

	m_pTail = pItem;
	return 1;
}

template <class T> FQINFO* FQueue<T>::FQDequeue( ){
	if( FQEmpty( ) ) return NULL;
	FQINFO* FifoItem = m_pHead->m_pNext->m_pItem;
	FQDel( );
	return FifoItem;
}

template <class T> void FQueue<T>::FQClear( ){
	if( FQEmpty( ) ) return;
	while( !FQEmpty( ) )
		FQDequeue( );
}