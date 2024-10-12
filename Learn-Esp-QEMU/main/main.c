#include <stdio.h>
#include "esp_log.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

void app_main(void)
{
  // Sample follows the ESP32 Emulation with QEMU video:
  // https://www.youtube.com/watch?v=lZp9L7Ij4Yo&t=29s

  int i = 0;

  while (true)
  {
    ESP_LOGI("QEMU", "Hello QEMU %d", i++);

    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}
