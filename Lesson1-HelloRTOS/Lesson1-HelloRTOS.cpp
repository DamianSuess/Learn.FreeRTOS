// Lesson1-HelloRTOS.cpp
//  Simple Task that prints Hello and Goodbye at an interval
//

#include <stdio.h>
#include "FreeRTOS.h"
#include "FreeRTOSConfig.h"
#include "task.h"

void ToggleHelloGoodbye(void* parameters);

void ToggleHelloGoodbye(void *parameters)
{
  while (true)
  {
    printf("Hello\n");
    // vTaskDelay(500 / portTICK_PERIOD_MS);
    printf("Goodbye\n");
    // vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

int main()
{
  printf("Welcome to a simple task solution");
  // xTaskCreate(taskCode, name, stackdepth, params, priority, createdTaskHandle);
  xTaskCreate(
    ToggleHelloGoodbye, // method to call
    "Toggle Message",   // name of Task
    1024,               // Stack size
    NULL,               // Parameters to pass to function
    1,                  // Task Priority (0 to configMAX_PRIORITIES - 1)
    NULL);              // Task handle

  ////auto queueHandle = xQueueCreate(32, sizeof(USER_EVENT_T));
  ////auto timerHandle = xTimerCreate("Timer", 1000, true, NULL, timerCallback);
  ////xTimerStart(timerHandle, 0);

  // Start the tasks
  vTaskStartScheduler();
}
