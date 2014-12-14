#include "UartLoopBack.h"
#include <stdio.h>
#include "usart.h"

void uartLoopBackSM(LoopBackData *data)
{
	switch(data->state)
	{
		case WAIT_DATA:
			if(DataRdyUSART())
                        {
                            data->dataByte = getcUSART();
                            data->state = WAIT_FOR_TX;
                        }
			break;
		
		case WAIT_FOR_TX:
			if(!BusyUSART())
                        {
                            putcUSART(data->dataByte);
                            data->state = WAIT_DATA;
                        }
			break;
			
		default:
			//Should NOT reach here
			break;
	}
}
