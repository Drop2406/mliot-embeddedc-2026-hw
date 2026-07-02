// HW01: H? TH?NG GIÁM SÁT LÒ NHI?T CÔNG NGHI?P

#include <stdio.h>
#include <stdint.h>

// TASK 1: POINTERS & MEMORY

void parse_config(const uint8_t *config_packet, int16_t *high_threshold) {

    if (config_packet == NULL || high_threshold == NULL) {
        return;
    }

    uint8_t lsb = config_packet[0];
    uint8_t msb = config_packet[1];

    *high_threshold = (int16_t)((msb << 8) | lsb);
}

// TASK 2: COMPILER & VOLATILE

int16_t read_temperature_reg(void *hw_sensor_reg) {
    if (hw_sensor_reg == NULL) {
        return 0;
    }

    volatile int16_t *sensor = (volatile int16_t *)hw_sensor_reg;

    return *sensor;
}

// TASK 3: DATA TYPES & BITWISE OPERATIONS
#define FAN_MASK    (1U << 0)
#define ALARM_MASK  (1U << 1)
void control_output(uint8_t *control_reg, uint8_t fan_enable, uint8_t alarm_enable) {
    if (control_reg == NULL) {
        return;
    }

    if (fan_enable) {
        *control_reg |= FAN_MASK;
    }
    else {
        *control_reg &= ~FAN_MASK;
    }

    if (alarm_enable) {
        *control_reg |= ALARM_MASK;
    }
    else {
        *control_reg &= ~ALARM_MASK;
    }
}

// HÀM MAIN KI?M TRA (H?c viên gi? nguyên d? ch?y th? nghi?m, ch? thay d?i input n?u c?n)

int main() {

    // 1. Test Task 1
    int16_t threshold = 0;
    uint8_t mock_packet[2] = {0x64, 0x00};
    parse_config(mock_packet, &threshold); // Có th? thay mock_packet thành NULL d? test ch?ng crash khi g?p NULL
    printf("Threshold Parsed: %d C\n", threshold);

    // 2. Test Task 2
    volatile int16_t mock_hardware_sensor = 105; 
    int16_t current_temp = read_temperature_reg((void*)&mock_hardware_sensor);
    printf("Current Temp Read: %d C\n", current_temp);

    // 3. Test Task 3
    uint8_t system_control_register = 0xFC; // 1111 1100
    if (current_temp >= threshold) {
        // Yêu c?u: fan = 1, alarm = 0
        control_output(&system_control_register, 1, 0);
    }
    printf("Control Reg Output: 0x%02X\n", system_control_register);

    return 0;
}
