#pragma once
#include "FifoItem.h"
class FQueue {
public:
	FQueue( );
	virtual ~FQueue( );
	bool FQEmpty( );
	int FQEnqueue( FQINFO* FifoInfo);
	FQINFO* FQDequeue( );
	void FQClear( );

private:
	FifoItem* m_pHead;
	FifoItem* m_pTail;
	void FQDel( );

	friend class FifoException;
};

inline FQueue::FQueue( ){
	FQINFO* QueueInfo = new(nothrow) FQINFO( 0 );
	if( !QueueInfo ) throw FifoException( FIFO_ALLOCATION_ERROR );
	m_pHead = new(nothrow) FifoItem(QueueInfo);
	if( !m_pHead ) throw FifoException( FIFO_ALLOCATION_ERROR );
	m_pTail = m_pHead;
}

inline FQueue:: ~FQueue( ){
	FQClear( );
	delete m_pHead;
	delete m_pTail;
}

inline void FQueue::FQDel( ){
	if( FQEmpty( ) ) return;

	FifoItem* pom = m_pHead;
	m_pHead = pom->m_pNext;
	delete pom;
	if( FQEmpty( ) ){
		m_pTail = NULL;
		m_pHead->m_pNext = NULL;
	}
}

