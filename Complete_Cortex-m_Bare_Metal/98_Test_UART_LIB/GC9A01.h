#ifndef __GC9A01_H
#define __GC9A01_H

#include <stdint.h>
#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

// Hardware abstraction layer
// Should be defined by the user of the library
void GC9A01_set_reset(uint8_t val);
void GC9A01_set_data_command(uint8_t val);
void GC9A01_set_chip_select(uint8_t val);
void GC9A01_delay(uint16_t ms);
void GC9A01_spi_tx(uint8_t *data, size_t len);

struct GC9A01_point {
    uint16_t X, Y;
};

struct GC9A01_frame {
    struct GC9A01_point start, end;
};

void GC9A01_init(void);
void GC9A01_set_frame(struct GC9A01_frame frame);
void GC9A01_write(uint8_t *data, size_t len);
void GC9A01_write_continue(uint8_t *data, size_t len);

void GC9A01_write_frame(uint8_t *data, size_t len);
void GC9A01_write_continue_frame(uint8_t *data, size_t len);
void GC9A01_flush_frame(void);
void GC9A01_Fill_Display(uint8_t Color);
void GC9A01_Fill_Display_Color(uint8_t R_Color,uint8_t G_Color,uint8_t B_Color);
void drawPixel(int16_t x, int16_t y, uint8_t *data, size_t len);
void cler_drawPixel(void);

#ifdef __cplusplus
}
#endif

#endif
