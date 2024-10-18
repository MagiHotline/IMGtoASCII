#include <stdio.h>
#include <string.h>
/*
Library used for image loading/decoding from file/memory: JPG, PNG, TGA, BMP, PSD, GIF, HDR, PIC
Please go check documentation in https://github.com/nothings/stb/blob/master/stb_image.h
*/
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

int main(int argc, char *argv[]) {

    if (argc < 2) {
        // Check if an image file was provided as an argument
        printf("Usage: ./imgtoascii.exe <image_file>\n");
        return 1; // Exit with an error code
    }

    // Characters that represent pixel brightness
    char chars[] = "`^\",:;Il!i~+_-?][}(1)(|\\/tfjrxnuvczXYUJCLQ0OZmwqpdbkhao#MW&8%B@S";
    // Length
    int charsLen = strlen(chars);
    // Image Properties
    int width, height, pixelSize;

    // The return value from an image loader is an 'unsigned char *' which points
    // to the pixel data, or NULL on an allocation failure or if the image is
    // corrupt or invalid. The pixel data consists of *y scanlines of *x pixels,
    // with each pixel consisting of N interleaved 8-bit components; the first
    // pixel pointed to is top-left-most in the image. There is no padding between
    // image scanlines or between pixels, regardless of format. The number of
    // components N is 'desired_channels' if desired_channels is non-zero, or
    // *channels_in_file otherwise. If desired_channels is non-zero,
    // *channels_in_file has the number of components that _would_ have been
    // output otherwise. E.g. if you set desired_channels to 4, you will always
    // get RGBA output, but you can check *channels_in_file to see if it's trivially
    // opaque because e.g. there were only 3 channels in the source image.
    unsigned char *ImageData = stbi_load(argv[1], &width, &height, &pixelSize, 0);

    if(ImageData) {

        //printf("Width: %d\nHeight: %d\nPixelSize: %d\n", width, height, pixelSize);

        unsigned char *pixels = ImageData;
        for(int rowIndex = 0; rowIndex < height; rowIndex++)
        {
            for(int columIndex = 0; columIndex < width; columIndex++)
            {
                // Take out the RGBA data
                unsigned char R = *pixels++;
                unsigned char G = *pixels++;
                unsigned char B = *pixels++;
                if(pixelSize >= 4) {unsigned char A = *pixels++;}

                // Calculate the average of RGB values
                float Avg = (R+G+B) / 3.0f;
                // Calculate the value to index the character array
                int charIndex = (int)(charsLen * (Avg / 255.0f));
                //Print out the indexed char
                putchar(chars[charIndex]);
            }
            putchar('\n');
        }

    } else {
        printf("Failed to load image %s\n", argv[1]);
    }

    return 0;
}
