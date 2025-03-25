/*
#include "FQueue.h"

int main( )
{
	try{
		FQueue FIFO;
		int x = FIFO.FQEmpty( );
		cout << "Czy kolejka pusta: " << x << endl;
		FQINFO* info1 = new FQINFO( 1 );
		info1->pTab[0] = 3;
		info1->pTab[1] = 5;
		FIFO.FQEnqueue( info1 );
		FQINFO* info2 = new FQINFO( 2 );
		info2->pTab[0] = 4;
		info2->pTab[1] = 8;
		FIFO.FQEnqueue( info2 );
		FQINFO* info3 = new FQINFO( 3 );
		info3->pTab[0] = 2;
		info3->pTab[1] = 11;
		FIFO.FQEnqueue( info3 );
		x = FIFO.FQEmpty( );
		cout << "Czy kolejka pusta: " << x << endl;
		cout << *FIFO.FQDequeue( );
		cout << *FIFO.FQDequeue( );
		cout << *FIFO.FQDequeue( );
		x = FIFO.FQEmpty( );
		cout << "Czy kolejka pusta: " << x << endl;
	}
	catch( FifoException& except ) {
		cerr << except.getReason( ) << endl;
	}
	catch( ... ) {
		cerr << "Caught all other exceptions." << endl;
	}

   return 0;
}
*/