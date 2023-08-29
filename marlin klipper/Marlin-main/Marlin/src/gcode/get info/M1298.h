#ifndef M1298_H
#define M1298_H

void customInfoMenu();
void handle_custom_Gcode_M1298();
void processGcode(const String& command);
void processGcode(const char* command);

#endif
