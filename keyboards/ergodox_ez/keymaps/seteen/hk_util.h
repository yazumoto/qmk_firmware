#ifndef CONFIG_DERUI_HK_UTIL_H
#define CONFIG_DERUI_HK_UTIL_H

#define HK_ALL_PRESSED() (hk_pressed[0] && hk_pressed[1])
#define HK_ALL_RELEASED() (!hk_pressed[0] && !hk_pressed[1])

#define HK_SHIFT_NOT_FOUND -1

void der_init_hk_variables(void);

bool der_mod_pressed(void);
bool der_process_hk(uint16_t keycode, keyrecord_t *record);

#endif
