#pragma once
#include "global.h"
class FifoItem 
{
public:
	FifoItem( FQINFO* pItem=NULL );
	virtual ~FifoItem( );
	
private:
	FQINFO* m_pItem;
	FifoItem* m_pNext;

friend class FQueue;
};

inline FifoItem::FifoItem( FQINFO* pItem /*= NULL*/ ){
	m_pItem = pItem ? new(nothrow) FQINFO( *pItem ) : NULL;
	if( !m_pItem ) throw FifoException( FIFO_ALLOCATION_ERROR );
	m_pNext = NULL;
}

inline FifoItem:: ~FifoItem( ){
	delete m_pItem;
	m_pNext = NULL;
}
