# morse

A program to flash morse code!

## building

This is a simple no-deps c program so it should be trivial.

Compiling with gcc can be done with:

```gcc morse.c -o morse```

## Usage

The text to be flashed is read from stdin, produced brightness values are on stdout.

Example invocation to flash power button (on thinkpad w/ acpi): 

``` yes 'morse code  ' | ./a.out | sudo tee /sys/class/leds/tpacpi\:\:power/brightness```

