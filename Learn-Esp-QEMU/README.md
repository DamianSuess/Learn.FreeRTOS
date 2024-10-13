# ESP32 with QEMU

This example follows the [ESP32 Emulation with QEMU](https://www.youtube.com/watch?v=lZp9L7Ij4Yo&t=29s) example.

## Tools Required

* VS Code
* VS Code Extensions:
  * ESP-IDF
  * C++
* Docker

## Steps to Recreate

### Create Project

1. Create an empty project with a simple logger
   * Add a basic logging line
2. ESP-IDF > ESP-IDF Terminal
   * Execute: `idf.py build`
3. Start in Docker
   * Path: `/workspaces/Learn.FreeRTOS/Learn-Esp-QEMU/`

### Run Application

```sh
idf.py qemu monitor
```

[Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/tools/qemu.html#running-an-application)

### Debugging

To debug in an qemu, you'll use 2 terminal sessions. First to launch the QEMU monitor and the 2nd to start debugging.

1. Commands > `ESP-IDF Terminal` to launch
2. Build app and start QEMU with GDB server enabled
   * `idf.py qemu gdb`
2. Start QEMU Monitor: `idf.py qemu --gdb monitor`
3. Run with Debugging: `idf.py gdb`
4. The 1st session will display the apps output and 2nd for GDB controls
   1. Press `ctrl + c` to initiate a breakpoint at the current execution and input a command
   2. Command: `c` to continue execution
   3. Command: `q` quit debugging

[Reference](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/api-guides/tools/qemu.html#debugging)

### Commands.txt

See `build\flash_args` for BIN locations

| Command | Description |
|-|-|
| `/./opt/esp/idf/components/esptool_py/esptool/esptool.py` | Launch `esptool.py`. `./` execute command |
| `--chip esp32`  | Chip we're targeting (can also be C3, etc) |
| `merge_bin`     | We are merging all BIN files together |
| `--output result.bin` | New BIN file we're creating |
| `--fill-flash-size 4MB` | Size of our Flash |
| `0x1000 build/bootloader/bootloader.bin` | Starting at `0x1000` get our `bootloader.bin` |
| `0x8000 build/partition_table/partition-table.bin` | Our potition table starting at `0x8000` |
| `0x10000 build/Learn-Esp-QEMU.bin` | Operational code starting at `0x10000` |
| `--flash_mode dio` | Flash Mode |
| `--flash_freq 40m` | Flash Frequency |
| `--flash_size 2MB` | Flash Size |


## More ESP Examples

The example is used by command `idf.py create-project`

For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)

We encourage the users to use the example as a template for the new projects.
A recommended way is to follow the instructions on a [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project).

## Example folder contents

The project **sample_project** contains one source file in C language [main.c](main/main.c). The file is located in folder [main](main).

ESP-IDF projects are built using CMake. The project build configuration is contained in `CMakeLists.txt`
files that provide set of directives and instructions describing the project's source files and targets
(executable, library, or both). 

Below is short explanation of remaining files in the project folder.

```
├── CMakeLists.txt
├── main
│   ├── CMakeLists.txt
│   └── main.c
└── README.md                  This is the file you are currently reading
```
Additionally, the sample project contains Makefile and component.mk files, used for the legacy Make based build system. 
They are not used or needed when building with CMake and idf.py.

## References

* [ESP32 Emulation with QEMU](https://www.youtube.com/watch?v=lZp9L7Ij4Yo&t=29s)
* https://developer.espressif.com/blog/whats-new-in-the-esp-idf-extension-for-vscode/
* https://github.com/espressif/esp-toolchain-docs/blob/main/qemu/esp32/README.md
  * See sections: Run QEMU