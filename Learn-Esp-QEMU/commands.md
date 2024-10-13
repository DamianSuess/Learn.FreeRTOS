# Build Commands

## Build Project (Video Tutorial)

Build the project

```sh
## Build the project and merge BIN files into `merged_qemu.bin`
/./opt/esp/idf/components/esptool_py/esptool/esptool.py --chip esp32 merge_bin --output merged_qemu.bin --fill-flash-size 4MB 0x1000 build/bootloader/bootloader.bin 0x8000 build/partition_table/partition-table.bin 0x10000 build/Learn-Esp-QEMU.bin --flash_mode dio --flash_freq 40m --flash_size 2MB

# Begin Debugging
# NOTE: There's not GDB hooked up to listen
qemu-system-xtensa -s -S -nographic -machine esp32 -drive file=merged_qemu.bin,if=mtd,format=raw
```


## My Updates

### Combile BIN files

1. Click on, ESP-IDE Extension icon
2. Advanced > Start/Stop QEMU Server
3. Copy the output and insert `build/` for our `.bin` paths below
4. Execute it in terminal

Original:

```sh
/opt/esp/python_env/idf5.4_py3.12_env/bin/python /opt/esp/idf/components/esptool_py/esptool/esptool.py --chip esp32 merge_bin -o merged_qemu.bin --flash_mode dout --flash_size 4MB --fill-flash-size 4MB 0x1000 bootloader/bootloader.bin 0x10000 Learn-Esp-QEMU.bin 0x8000 partition_table/partition-table.bin
```

Update the command with `build/`:

```sh
/opt/esp/python_env/idf5.4_py3.12_env/bin/python /opt/esp/idf/components/esptool_py/esptool/esptool.py --chip esp32 merge_bin -o merged_qemu.bin --flash_mode dout --flash_size 4MB --fill-flash-size 4MB 0x1000 build/bootloader/bootloader.bin 0x10000 build/Learn-Esp-QEMU.bin 0x8000 build/partition_table/partition-table.bin
```

Outputs:
```sh
00 build/partition_table/partition-table.bin
esptool.py v4.8.1
Flash params set to 0x0320
SHA digest in image updated
Wrote 0x400000 bytes to file merged_qemu.bin, ready to flash to offset 0x0
```

## asdf

```sh
qemu-system-xtensa -s -S -nographic -machine esp32 -drive file=merged_qemu.bin,if=mtd,format=raw
```

Outputs:

```txt
Adding SPI flash device
```

## Hookup Debug partition_table

Video Timestamp: 11:50

1. Extensions: GDB - Native Debug
2. .vscode/launch.json
3. Update GDB path
4. ...