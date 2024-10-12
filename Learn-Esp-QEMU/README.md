# ESP32 with QEMU

This example follows the [ESP32 Emulation with QEMU](https://www.youtube.com/watch?v=lZp9L7Ij4Yo&t=29s) example.

## Tools Required

* VS Code
* VS Code Extensions:
  * ESP-IDF
  * C++
* Docker

## Steps to Recreate

1. Install Docker
2. Create an empty project with a simple logger
   * Add a basic logging line
3. Select TERMINAL tab to build app
   * Execute: `idf.py build`
3. Create `commands.txt` file
   * This contains how to generate the BIN file (bootloader and operation code)
4. Execute in terminal contents of `commands.txt`


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



This is the simplest buildable example. The example is used by command `idf.py create-project`
that copies the project to user specified path and set it's name. For more information follow the [docs page](https://docs.espressif.com/projects/esp-idf/en/latest/api-guides/build-system.html#start-a-new-project)



## How to use example
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
