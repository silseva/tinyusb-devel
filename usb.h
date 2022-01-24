#ifndef USB_H
#define USB_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//#include <bsp/board.h>
#include <tusb_config.h>
#include <tusb.h>

int usb_init();
void echo_serial_port(uint8_t itf, uint8_t buf[], uint32_t count);
void cdc_task();

void tud_mount_cb();  // Invoked when device is mounted
void tud_umount_cb();  // Invoked when device is unmounted
void tud_suspend_cb(bool remote_wakeup_en); // Invoked when usb bus is suspended
void tud_resume_cb(); // Invoked when usb bus is resumed

uint8_t const * tud_descriptor_device_cb();
uint8_t const * tud_descriptor_configuration_cb(uint8_t index);
uint16_t const* tud_descriptor_string_cb(uint8_t index, uint16_t langid);

#ifdef __cplusplus
}
#endif

#endif /* USB_H */