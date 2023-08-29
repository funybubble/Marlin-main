#include "Arduino.h" // Include Arduino.h to use Serial and other Arduino functions
#include "M1298.h"
#include "src/lcd/dogm/ultralcd_st7920_u8glib_rrd_AVR.h" // Include the necessary LCD library

extern U8GLIB_ST7920_128X64_1X u8g;

void customInfoMenu() {
    Serial.println("Information");
    Serial.println("--------------------");

    float voltage = analogRead(A0) * 0.0048828125; // Calculate voltage from analog reading
    Serial.print("Voltage: ");
    Serial.println(voltage, 2);

    Serial.print("Motherboard: ");
    Serial.println("Creality V427 STM32F103RC");

    // Display information on the LCD
    u8g.firstPage();
    do {
        u8g.setFont(u8g_font_6x10);
        u8g.drawStr(0, 10, "Information");

        char voltageStr[10];
        dtostrf(voltage, 4, 2, voltageStr); // Convert voltage to string
        u8g.setFont(u8g_font_8x13B);
        u8g.drawStr(0, 30, "Voltage:");
        u8g.drawStr(80, 30, voltageStr);

        u8g.setFont(u8g_font_6x10);
        u8g.drawStr(0, 40, "Motherboard:");
        u8g.drawStr(80, 40, "Creality V427 STM32F103RC");
    } while (u8g.nextPage());
}

void handle_custom_Gcode_M1298() {
    customInfoMenu();
}

void processGcode(const String& command) {
    if (command == "M1298") {
        handle_custom_Gcode_M1298();
    }
    // Handle other G-code commands here
}

void processGcode(const char* command) {
    processGcode(String(command));
}
