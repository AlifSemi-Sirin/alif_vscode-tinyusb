#include "RTE_Components.h"
#include CMSIS_device_header

// Stubs to suppress missing stdio definitions for nosys
#define TRAP_RET_ZERO  {__BKPT(0); return 0;}
int _close(int val) TRAP_RET_ZERO
int _lseek(int val0, int val1, int val2) TRAP_RET_ZERO
//int _read(int val0, char * val1, int val2) TRAP_RET_ZERO
//int _write(int val0, char * val1, int val2) TRAP_RET_ZERO
int _fstat(int val0, void * val1) TRAP_RET_ZERO
int _isatty(int val0) TRAP_RET_ZERO
int _getpid(void) TRAP_RET_ZERO
void _kill(int val0, int val1) {__BKPT(0);}

void board_init(void)
{
}

uint32_t board_millis(void)
{
    return 0;
}

void board_led_write(bool state)
{
    (void)state;
}

int board_uart_read(uint8_t *buf, int len) {
    (void) buf;
    (void) len;
    return 0;
}

int board_uart_write(void const *buf, int len) {
    (void) buf;
    (void) len;
    return 0;
}

void dcd_edpt_close(uint8_t rhport, uint8_t ep_addr)
{
    (void) rhport;
    (void) ep_addr;
}
