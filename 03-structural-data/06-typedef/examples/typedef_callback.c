/*
 * Language: C
 * Target: PC
 * Build: gcc typedef_callback.c -o typedef_callback
 * Run: ./typedef_callback
 * Expected output:
 *   [UART RX] Byte received: 0x41
 *   [UART RX] Byte received: 0x42
 * What to learn: How typedef simplifies function pointer declarations
 *                in embedded driver callback patterns
 */

#include <stdio.h>
#include <stdint.h>

/* --- typedef for callback --- */
typedef void (*uart_rx_callback_t)(uint8_t byte);

/* --- Simulated UART driver --- */
static uart_rx_callback_t registered_callback = NULL;

void uart_register_rx_callback(uart_rx_callback_t cb) {
    registered_callback = cb;
}

void uart_simulate_receive(uint8_t byte) {
    if (registered_callback != NULL) {
        registered_callback(byte);
    }
}

/* --- Application callback --- */
void my_rx_handler(uint8_t byte) {
    printf("[UART RX] Byte received: 0x%02X\n", byte);
}

int main(void) {
    uart_register_rx_callback(my_rx_handler);

    /* Simulate receiving two bytes */
    uart_simulate_receive(0x41);  /* 'A' */
    uart_simulate_receive(0x42);  /* 'B' */

    return 0;
}
