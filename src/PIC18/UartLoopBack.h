#ifndef UartLoopBack_H
#define UartLoopBack_H


typedef enum 
{
	WAIT_DATA,
	WAIT_FOR_TX
}LoopBackState;

typedef struct LoopBackData LoopBackData;

struct LoopBackData
{
	LoopBackState state;
	char dataByte;
};

void uartLoopBackSM(LoopBackData *data);


#endif // UartLoopBack_H
