#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdarg.h>
#include <stdio.h>

typedef struct format {
    int plus;
    int hash;
    int width;
    int precision;
    int minus;
    int space;
    int zero;
    int sp_padding;
    int zero_padding;
    char F;
} s_form;


int ft_parse_char(s_form *form, int c);
//none 0
// #define G_NONE   ""


// ///SINGLE FLAGS
// #define G_H      "#"
// #define G_M      "-"
// #define G_P      "+"
// #define G_S      " "
// #define G_Z      "0"

// //2 comb
// #define G_HM     "#-"
// #define G_HP     "#+"
// #define G_HS     "# "
// #define G_HZ     "#0"
// #define G_MP     "-+"
// #define G_MS     "- "
// #define G_MZ     "-0"
// #define G_PS     "+ "
// #define G_PZ     "+0"
// #define G_SZ     " 0"

// //3 comb
// #define G_HMP    "#-+"
// #define G_HMS    "#- "
// #define G_HMZ    "#-0"
// #define G_HPS    "#+ "
// #define G_HPZ    "#+0"
// #define G_HSZ    "# 0"
// #define G_MPS    "-+ "
// #define G_MPZ    "-+0"
// #define G_MSZ    "- 0"
// #define G_PSZ    "+ 0"

// // 4 comb
// #define G_HMPS   "#-+ "
// #define G_HMPZ   "#-+0"
// #define G_HMSZ   "#- 0"
// #define G_HPSZ   "#+ 0"
// #define G_MPSZ   "-+ 0"

// //flags
// #define G_ALL    "#-+ 0"

// char *flags_combination[] = {
//     G_H, G_M, G_P, G_S, G_Z, G_HM, G_HP,
//     G_HS, G_HZ, G_MP, G_PS, G_PZ, G_SZ,
//     G_HMP, G_HMS, G_HMZ, G_HPS, G_HPZ, G_HSZ, G_MPS,
//     G_MPZ, G_MSZ, G_PSZ
// }


#endif