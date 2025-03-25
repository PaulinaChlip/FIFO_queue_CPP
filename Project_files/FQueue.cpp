#include "FQueue.h"

bool FQueue::FQEmpty( ){
	return (!m_pHead->m_pNext);
}

int FQueue::FQEnqueue( FQINFO* FifoInfo){
	FifoItem* pItem = new(nothrow) FifoItem(FifoInfo );
	if( !pItem ) throw FifoException( FIFO_ALLOCATION_ERROR );
	if( !pItem )return 0;

	if( FQEmpty( ) )
		m_pHead->m_pNext = pItem;
	else
		m_pTail->m_pNext = pItem;

	m_pTail = pItem;
	return 1;
}

FQINFO* FQueue::FQDequeue( ){
	if( FQEmpty( ) ) return NULL;
	FQINFO* FifoItem = m_pHead->m_pNext->m_pItem;
	FQDel( );
	return FifoItem;
}

void FQueue::FQClear( ){
	if( FQEmpty( ) ) return;
	while( !FQEmpty( ) )
		FQDequeue( );
}
