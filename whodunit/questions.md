# Questions

## What's `stdint.h`?

Declares integer types having specified widths, and shall define corresponding sets of macros

## What's the point of using `uint8_t`, `uint32_t`, `int32_t`, and `uint16_t` in a program?

To simplify syntax of complex data structures. They're just aliases to pre-existing data types.

## How many bytes is a `BYTE`, a `DWORD`, a `LONG`, and a `WORD`, respectively?

Byte - 1
DWORD - 4
LONG - 8
WORD - 2

## What (in ASCII, decimal, or hexadecimal) must the first two bytes of any BMP file be? Leading bytes used to identify file formats (with high probability) are generally called "magic numbers."

42 4D (BM)

## What's the difference between `bfSize` and `biSize`?

bfSize - size of file
biSize - size of image

## What does it mean if `biHeight` is negative?

the bitmap is a top-down DIB and its origin is the upper-left corner.

## What field in `BITMAPINFOHEADER` specifies the BMP's color depth (i.e., bits per pixel)?
The biBitCount specifies the number of bits per pixel. It defines the max number of colors in the bitmap

## Why might `fopen` return `NULL` in `copy.c`?

if it failed to open file

## Why is the third argument to `fread` always `1` in our code?

we read 1 byte at a time

## What value does `copy.c` assign to `padding` if `bi.biWidth` is `3`?

3

## What does `fseek` do?
moves a file pointer to specified location. In copy.c's case, it skips over the padding int and
    looks for next RGBTRIPLE to read

## What is `SEEK_CUR`?
-Constant that specifies the current pos of the pointer
