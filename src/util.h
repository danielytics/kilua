#pragma once

#include <iostream>


/**
 * A utility class for converting strings and characters.
 *
 * We assume that a single ASCII character can become a wide
 * character of no more than 6 bytes.
 */
class Util
{
public:

    /**
     * Convert the single wide-character specified to
     * an ASCII string.
     *
     * NOTE: The caller must `delete[]` the result.
     */
    static char * wchar2ascii(wchar_t ch)
    {
        std::wstring tmp;
        tmp += ch;

        char *str = new char[7];
        sprintf(str, "%ls", tmp.c_str());

        return (str);
    }


    /**
     * Convert a normal string to a wide string.
     *
     * NOTE: The caller must `delete[]` the result.
     */
    static wchar_t * ascii2wide(const char *in)
    {
        size_t in_size  = strlen(in) + 1;
        size_t out_size = in_size * 5;

        wchar_t* result = new wchar_t[out_size];

        mbstowcs(result, in, out_size);
        return (result);
    };


    /**
     * Convert the wide-character string specified to
     * an ASCII string.
     *
     * NOTE: The caller must `delete[]` the result.
     */
    static char * wide2ascii(wchar_t *in)
    {
        std::wstring tmp;
        tmp += in;

        char *str = new char[tmp.size() + 1];
        sprintf(str, "%ls", tmp.c_str());

        return (str);
    };

    static char * widestr2ascii(std::wstring in)
    {
        size_t len = in.size() * 5 + 1;
        char *str = new char[len + 1];
        sprintf(str, "%ls", in.c_str());
        return (str);
    };

};