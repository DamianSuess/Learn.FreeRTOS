# Lesson 1 - Hello FreeRTOS!

## Visual Studio - Recreate Project

1. Download FreeRTOS and extract in root folder (_../FreeRTOSv202212.00_)
   1. Optionally (saves 250 MB): Remove folder `FreeRTOS/Demo/`
2. Create new Windows Console application
3. `Project` > `Properties`
4. C++ > General > `Additional Include Directories`
   1. `..\FreeRTOSv202212.00\FreeRTOS\Source\include`
   2. `..\FreeRTOSv202212.00\FreeRTOS\Source\portable\MSVC-MingW`
5. Create file `FreeRTOSConfig.h`
6. Replace the `Main.cpp` (`Lesson1-HelloRTOS.cpp`) with the following:

```cpp
#include <stdio.h>
#include "FreeRTOS.h"

int main()
{
  printf("Hello");
}
```
