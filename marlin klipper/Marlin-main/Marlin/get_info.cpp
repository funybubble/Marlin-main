#include "Configuration.h"
#include "Configuration_adv.h"
#include "src/lcd/dogm/ultralcd_st7920_u8glib_rrd_AVR.h"

extern "C" {
#include "libs/U8glib/src/clib/u8g.h" // Include U8glib for PSTR macros
}

void customInfoMenu() {
    u8g.firstPage();
    do {
        u8g.setFont(u8g_font_6x10);
        u8g.drawStr(0, 10, "Information");

        float voltage = analogRead(VOLTAGE_PIN) * VOLTAGE_CONVERSION_FACTOR;
        u8g.setFont(u8g_font_8x13B);
        u8g.drawStr(0, 30, "Voltage:");
        u8g.drawStr(80, 30, ftostr3(voltage));

        u8g.setFont(u8g_font_6x10);
        u8g.drawStr(0, 40, "Motherboard:");
        u8g.drawStr(80, 40, "Creality V4 STM32F103RC");

        // Similar adjustments for motor voltages and temperature readings

    } while (u8g.nextPage());
}
