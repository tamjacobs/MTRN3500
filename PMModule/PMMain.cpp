// #include "../Include/SMObject.h"

#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <structs.h>
#include <SM.h>

int main(int argc, char* argv[])
{
    Laser Lsr;
	Laser* Lsrptr;
	void* shm;
    
	shm = SMCreate(LASER_KEY,sizeof(Laser));

	Lsr.numData = 40;
	Lsr.data[0] = 10;
// Write to SM
	Lsrptr = (Laser *)shm;
	Lsrptr->numData = Lsr.numData;
	Lsrptr->data[0] = Lsr.data[0];
	while(getchar()!= 'Q');
	shmdt(shm);
	return 0;
}