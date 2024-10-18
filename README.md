# IMGtoASCII
A simple C code that transforms Images to ASCII Art.

This project is a simple C-based Image to ASCII Converter that uses the [stb_image.h](https://github.com/nothings/stb)  library to load and decode image files. The program converts the pixels of an image into ASCII characters based on their brightness, creating a text-based representation of the image.

## Features
- Supports common image formats such as JPEG, PNG, TGA, BMP, PSD, GIF, HDR, PIC.
- Converts pixel brightness into a character representation.
- Lightweight and fast implementation using stb_image.h.
## Requirements
- C Compiler (e.g., gcc)
- stb_image.h library (already included in this project).

## How it works
The program reads the image file provided by the user, calculates the brightness of each pixel, and maps the brightness to a corresponding character in a predefined set of ASCII characters. The brighter the pixel, the more "solid" the character that represents it.

The program uses the following character set to represent pixel brightness:

`^\",:;Il!i~+_-?][}(1)(|\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao#MW&8%B@S`

This set ranges from light (backticks, commas) to dark/solid (#, %, @, S).

## Installation 

1. Clone the repo:

```sh
git clone https://github.com/yourusername/image-to-ascii.git
cd image-to-ascii
```

2. Make sure you have *gcc* or any compatible C compiler installed.
3. Build the program:

```sh
gcc image_to_ascii.c -o imgtoascii
```

## Usage
Run the program from the terminal, passing the path to an image file as an argument. The output will be displayed in the terminal as ASCII art.

```sh
./imgtoascii <image_file>
```

## Reference

This project uses the [stb_image.h](https://github.com/nothings/stb)  library for loading and decoding image files. stb_image.h is a popular, single-file header library designed for easy image loading from files or memory, supporting various image formats such as JPG, PNG, BMP, GIF, and more.

For more information about stb_image.h, please refer to the official [stb GitHub repository](https://github.com/nothings/stb).

## Contributing

Contributions are welcome! If you'd like to improve the project, please feel free to fork the repository, make changes, and submit a pull request.




