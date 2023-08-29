#ifndef CUSTOM_COMMANDS_H
#define CUSTOM_COMMANDS_H

// Custom G-code commands
#define USER_GCODE_X "M300 S1000"
#define USER_GCODE_Y "G28 X Y"
#define USER_GCODE_Z "G28 Z"
#define USER_GCODE_HEAT_HOTEND "M104 S200"
#define USER_GCODE_COOL_DOWN "M104 S0"
#define USER_GCODE_EJECT_FILAMENT "G1 E-100 F300"
#define USER_GCODE_LOAD_FILAMENT "G1 E100 F300"
#define USER_GCODE_AUTO_BED_TRAMMING "G28 ; Auto home"
#define USER_GCODE_START_PRINT "G28 ; Auto home\nG1 X0 Y0 Z10 ; Move to start position\nG1 Z0.3 ; Lower nozzle\nG1 X100 E10 F100 ; Extrude a bit\nG1 X150 F3000 ; Fast wipe\nG1 X100 E15 F100 ; Extrude more\nG1 Z10 ; Raise nozzle\nG1 X0 Y0 Z10 ; Move to start position"
#define USER_GCODE_DISPLAY_MESSAGE "M117 Hello, Custom Message"
#define USER_GCODE_FAN_ON "M106 S255"
#define USER_GCODE_FAN_OFF "M107"
#define USER_GCODE_PAUSE "G91 ; Relative positioning\nG1 E-10 F300 ; Retract filament\nG1 Z15 F9000 ; Move Z-axis up\nG90 ; Absolute positioning\nG1 X0 Y0 ; Move print head away\nM117 Printing paused"

#endif // CUSTOM_COMMANDS_H
