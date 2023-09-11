#pragma once

#include "pch.h"

namespace Capture {
    static int DecodeBmp(
            std::vector<unsigned char> &image,
            unsigned &w,
            unsigned &h,
            const void *ptr
    ) {
        const auto header = static_cast<const BITMAPINFOHEADER *>(ptr);

        PrintDebug(L"biSize = {}", header->biSize);
        PrintDebug(L"biSizeImage = {}", header->biSizeImage);

        if (header->biSize < 40) return -1;
        // if (bmp[0] != 'B' || bmp[1] != 'M') return 1; //It's not a BMP file if it doesn't start with marker 'BM'
        const auto pixeloffset = header->biSize;
        //read width and height from BMP header
        w = header->biWidth;
        h = header->biHeight;
        //read number of channels from BMP header
        if (header->biBitCount != 24 && header->biBitCount != 32) return 2; //only 24-bit and 32-bit BMPs are supported.
        const auto numChannels = header->biBitCount / 8;

        //The amount of scanline bytes is width of image times channels, with extra bytes added if needed
        //to make it a multiple of 4 bytes.
        auto scanlineBytes = w * numChannels;
        if (scanlineBytes % 4 != 0) scanlineBytes = (scanlineBytes / 4) * 4 + 4;

        const auto dataSize = scanlineBytes * h;
        if (header->biSizeImage < dataSize) return 3; //BMP file too small to contain all pixels

        image.resize(w * h * 4);

        /*
        There are 3 differences between BMP and the raw image buffer for LodePNG:
        -it's upside down
        -it's in BGR instead of RGB format (or BRGA instead of RGBA)
        -each scanline has padding bytes to make it a multiple of 4 if needed
        The 2D for loop below does all these 3 conversions at once.
        */
        for (unsigned y = 0; y < h; y++) {
            for (unsigned x = 0; x < w; x++) {
                //pixel start byte position in the BMP
                const auto bmpos =
                        reinterpret_cast<uintptr_t>(ptr) + pixeloffset + (h - y - 1) * scanlineBytes + numChannels * x;
                //pixel start byte position in the new raw image
                const auto newpos = 4 * y * w + 4 * x;

                image[newpos + 0] = *reinterpret_cast<unsigned char *>(bmpos + 2); //R
                image[newpos + 1] = *reinterpret_cast<unsigned char *>(bmpos + 1); //G
                image[newpos + 2] = *reinterpret_cast<unsigned char *>(bmpos + 0); //B
                // 透明度情報が保持できないバグらしい
                // https://github.com/lvandeve/lodepng/issues/42
                image[newpos + 3] = 255; // numChannels == 3 ? 255 : *reinterpret_cast<unsigned char*>(bmpos + 3); //A
            }
        }

        return 0;
    }

    static std::optional <std::vector<unsigned char>> ConvertToPng(const void *ptr) {
        std::vector<unsigned char> bmp, png;
        unsigned w, h;

        if (const auto error = DecodeBmp(bmp, w, h, ptr)) {
            PrintDebug(L"BMP decoding error: {}", error);
            return std::nullopt;
        }

        if (const auto error = lodepng::encode(png, bmp, w, h)) {
            PrintDebug(L"PNG encoding error: {}", error);
            return std::nullopt;
        }

        PrintDebug(L"BMP -> PNG の変換に成功しました。");

#ifdef _DEBUG
        lodepng::save_file(png, "output.png");
#endif

        return png;
    }
}
