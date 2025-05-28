#include "RTE_Components.h"
#include CMSIS_device_header

#include "tusb.h"

static uint8_t charbuf[512];

static cdc_line_coding_t lc __attribute__((used));

void main (void)
{
    *(volatile uint32_t*) 0x4900C004 |= 8; // 12_0 + 12_3 as output (blue + red LED)
    *(volatile uint32_t*) 0x49007004 |= 16; // 7_4 as output (green LED)

    tusb_init();

    while (1) {
        tud_task();
        if (tud_cdc_available()) {
            uint32_t len = tud_cdc_read(charbuf, sizeof(charbuf));
            tud_cdc_write(charbuf, len);
            tud_cdc_write_flush();
        }
    }
}

void tud_cdc_line_coding_cb(uint8_t itf, cdc_line_coding_t const* p_line_coding)
{
    // line coding settings have changed
    lc = *p_line_coding;
}

void tud_cdc_line_state_cb(uint8_t itf, bool dtr, bool rts)
{
    // invoked on COM port open/close
}

