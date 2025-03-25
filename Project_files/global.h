#pragma once
#include "FifoException.h"
#include <iostream>
using namespace std;

#define FQINFO FQInfo
struct FQInfo{
	FQInfo( int key);
	virtual ~FQInfo( );
	friend ostream& operator <<( ostream& out, const FQInfo& fqinfo );
	int nKey;
	int* pTab;
};

inline FQInfo::FQInfo( int key ){
	nKey = key;
	pTab = new(nothrow) int[2]{0, 0};
	if( !pTab ) {
		throw FifoException( FIFO_ALLOCATION_ERROR );
	}
}


inline FQInfo:: ~FQInfo( ){
	delete[] pTab;
}

inline ostream& operator <<( ostream& out, const FQInfo& FifoInfo ){
	if( !&FifoInfo ) out << "Pusty element";
	else   out << "Klucz: " << FifoInfo.nKey << "\tTablica: [" << FifoInfo.pTab[0] <<"," << FifoInfo.pTab[1] << "]" << endl;
	return out;
}
