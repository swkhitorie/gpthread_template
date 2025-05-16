#include <board_config.h>
#include <stdio.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    board_init();
    uint32_t m = HAL_GetTick();
    for (;;) {
        if (HAL_GetTick() - m >= 1) {
            m = HAL_GetTick();
            board_debug();
        }
    }
}

