#ifndef mutex_H
#define mutex_H

typedef struct mutexData mutexData;
struct mutexData 
{
	int status;
	int count;
	void (*function)();
	
};

int acquireMutex(mutexData * data);
int releaseMutex(mutexData * data);

#endif // mutex_H
