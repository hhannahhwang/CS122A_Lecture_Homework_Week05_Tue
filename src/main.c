/************* t.c file of C2.5 **************/
int v[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};  // data array
int sum;

#include <string.h>  // contains strlen(), strcmp(), etc.

#include "uart.h"  // UART driver code file

int cs122a_main() {
  int i;
  uart_init();  // initialize UARTs

  for (i = 0; i < 4; i++){
    unsigned int divisor = *((volatile unsigned int*)(uart[i].base + UARTIBRD));
    unsigned int lcr = *((volatile unsigned int*)(uart[i].base + UARTLCR_H));

    unsigned int baudrate = 7380000 / (16 * divisor);

    uprintf(&uart[0], "UART[%d] Baudrate: %d\n", i, baudrate);
    uprintf(&uart[0], "UART[%d] Line Control Register: 0x%x\n", i, lcr);
  }

}

