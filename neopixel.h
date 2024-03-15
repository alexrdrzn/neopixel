#define NEOPIXEL_NUM_LED 2
#define NEOPIXEL_SPI_HANDLE  hspi1

#define NEOPIXEL_RESET_PULSE 50
#define NEOPIXEL_BUFFER_SIZE (NEOPIXEL_NUM_LED * 24 + NEOPIXEL_RESET_PULSE)

extern SPI_HandleTypeDef NEOPIXEL_SPI_HABDLE;
extern uint8_t neopixel_buffer[];

void neopixel_init();
void neopixel_send_spi();
void neopixel_single(uint16_t led, uint8_t r, uint8_t g, uint8_t b);
void neopixel_all(uint8_t r, uint8_t g, uint8_t b);
