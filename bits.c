/*
 * CS:APP Data Lab
 *
 * Ezekiel Elin
 * eline
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

Replace the "return" statement in each function with one
or more lines of C code that implements the function. Your code
must conform to the following style:

int Funct(arg1, arg2, ...) {
    /* brief description of how your implementation works */
    int var1 = Expr1;
    ...
    int varM = ExprM;
    
    varJ = ExprJ;
    ...
    varN = ExprN;
    return ExprR;
}

Each "Expr" is an expression using ONLY the following:
1. Integer constants 0 through 255 (0xFF), inclusive. You are
not allowed to use big constants such as 0xffffffff.
2. Function arguments and local variables (no global variables).
3. Unary integer operations ! ~
4. Binary integer operations & ^ | + << >>

Some of the problems restrict the set of allowed operators even further.
Each "Expr" may consist of multiple operators. You are not restricted to
one operator per line.

You are expressly forbidden to:
1. Use any control constructs such as if, do, while, for, switch, etc.
2. Define or use any macros.
3. Define any additional functions in this file.
4. Call any functions.
5. Use any other operations, such as &&, ||, -, or ?:
6. Use any form of casting.
7. Use any data type other than int.  This implies that you
cannot use arrays, structs, or unions.


You may assume that your machine:
1. Uses 2s complement, 32-bit representations of integers.
2. Performs right shifts arithmetically.
3. Has unpredictable behavior when shifting an integer by more
than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
/*
 * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
 */
int pow2plus1(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    return (1 << x) + 1;
}

/*
 * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
 */
int pow2plus4(int x) {
    /* exploit ability of shifts to compute powers of 2 */
    int result = (1 << x);
    result += 4;
    return result;
}

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
1. Define or use any macros.
2. Define any additional functions in this file.
3. Call any functions.
4. Use any form of casting.
5. Use any data type other than int or unsigned.  This means that you
cannot use arrays, structs, or unions.
6. Use any floating point data types, operations, or constants.


NOTES:
1. Use the dlc (data lab checker) compiler (described in the handout) to
check the legality of your solutions.
2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
that you are allowed to use for your implementation of the function.
The max operator count is checked by dlc. Note that '=' is not
counted; you may use as many of these as you want without penalty.
3. Use the btest test harness to check your functions for correctness.
4. Use the BDD checker to formally verify your functions
5. The maximum number of ops for each function is given in the
header comment for each function. If there are any inconsistencies
between the maximum ops in the writeup and in this file, consider
this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2017 Free Software Foundation, Inc.
 This file is part of the GNU C Library.
 
 The GNU C Library is free software; you can redistribute it and/or
 modify it under the terms of the GNU Lesser General Public
 License as published by the Free Software Foundation; either
 version 2.1 of the License, or (at your option) any later version.
 
 The GNU C Library is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 Lesser General Public License for more details.
 
 You should have received a copy of the GNU Lesser General Public
 License along with the GNU C Library; if not, see
 <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
 include it implicitly at the start of every compilation.  It must
 not itself include <features.h> or any other header that includes
 <features.h> because the implicit include comes before any feature
 test macros that may be defined in a source file before it first
 explicitly includes a system header.  GCC knows the name of this
 header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
 and complex.  If the GCC (4.9 and later) predefined macros
 specifying compiler intent are available, use them to determine
 whether the overall intent is to support these features; otherwise,
 presume an older compiler has intent to support these features and
 define these macros by default.  */
/* wchar_t uses Unicode 9.0.0.  Version 9.0 of the Unicode Standard is
 synchronized with ISO/IEC 10646:2014, fourth edition, plus
 Amd. 1  and Amd. 2 and 273 characters from forthcoming  10646, fifth edition.
 (Amd. 2 was published 2016-05-01,
 see https://www.iso.org/obp/ui/#iso:std:iso-iec:10646:ed-4:v1:amd:2:v1:en) */
/* We do not support C11 <threads.h>.  */
/*
 * bitCount - returns count of number of 1's in word
 *   Examples: bitCount(5) = 2, bitCount(7) = 3
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 40
 *   Rating: 4
 */
int bitCount(int x) {
    /* This solution works in all cases, however it has
     * the side effect of requiring a large number of
     * operations, and is not the most efficient way
     * of achieving the count */
    
    /* We shift every bit to the rightmost space (making
     * the value of the bit 1) and add them all up */
    int x0 = (x >> 0) & 1;
    int x1 = (x >> 1) & 1;
    int x2 = (x >> 2) & 1;
    int x3 = (x >> 3) & 1;
    int x4 = (x >> 4) & 1;
    int x5 = (x >> 5) & 1;
    int x6 = (x >> 6) & 1;
    int x7 = (x >> 7) & 1;
    int x8 = (x >> 8) & 1;
    int x9 = (x >> 9) & 1;
    int x10 = (x >> 10) & 1;
    int x11 = (x >> 11) & 1;
    int x12 = (x >> 12) & 1;
    int x13 = (x >> 13) & 1;
    int x14 = (x >> 14) & 1;
    int x15 = (x >> 15) & 1;
    int x16 = (x >> 16) & 1;
    int x17 = (x >> 17) & 1;
    int x18 = (x >> 18) & 1;
    int x19 = (x >> 19) & 1;
    int x20 = (x >> 20) & 1;
    int x21 = (x >> 21) & 1;
    int x22 = (x >> 22) & 1;
    int x23 = (x >> 23) & 1;
    int x24 = (x >> 24) & 1;
    int x25 = (x >> 25) & 1;
    int x26 = (x >> 26) & 1;
    int x27 = (x >> 27) & 1;
    int x28 = (x >> 28) & 1;
    int x29 = (x >> 29) & 1;
    int x30 = (x >> 30) & 1;
    int x31 = (x >> 31) & 1;
    
    return x0 + x1 + x2 + x3 + x4 + x5 + x6 + x7 + x8 + x9 + x10 + x11 + x12 + x13 + x14 + x15 + x16 + x17 + x18 + x19 + x20 + x21 + x22 + x23 + x24 + x25 + x26 + x27 + x28 + x29 + x30 + x31;
}
/*
 * bitXor - x^y using only ~ and &
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    /* This works because we can show the truth tables
     x: 1010
     y: 1100
     
     The left side:
     x & y: 1000
     ~(x & y): 0111
     
     The right side:
     ~x: 0101
     ~y: 0011
     ~x & ~y: 0001
     ~(~x & ~y): 1110
     
     Combining the two
     sides with &:
     
     0111 & 1110: 0110
     
     Which is the same as the result of x ^ y
     */
    return (~(x & y)) & ~(~x & ~y);
}
/*
 * byteSwap - swaps the nth byte and the mth byte
 *  Examples: byteSwap(0x12345678, 1, 3) = 0x56341278
 *            byteSwap(0xDEADBEEF, 0, 2) = 0xDEEFBEAD
 *  You may assume that 0 <= n <= 3, 0 <= m <= 3
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 25
 *  Rating: 2
 */
int byteSwap(int x, int n, int m) {
    /*
     * identify the shift amounts for n and m, in bit-space
     * this is done by multiplying them by 8 (the size of a byte)
     */
    int nshift = n << 3;
    int mshift = m << 3;
    
    /* Create a mask for the value of the two bytes we want to move around */
    int nMask = 0xFF << (nshift);
    int mMask = 0xFF << (mshift);
    
    /*
     * Get the value of those bytes, shifted back to the rightmost position
     * For example,
     * 0xA48C9F3C gets masked and becomes
     * 0x008C0000, which then gets shifted to 0x8C
     */
    
    int nValue = ((x & nMask) >> (nshift)) & 0xFF;
    int mValue = ((x & mMask) >> (mshift)) & 0xFF;
    
    /* Easiest way to "set" a bit is if it starts as 0 */
    int x2 = x & ~nMask;
    int x3 = x2 & ~mMask;
    
    /*
     * Shift the values we got before to the byte that we want them to
     * end up in.
     */
    int nTarget = mValue << (nshift);
    int mTarget = nValue << (mshift);
    
    /* OR them into the x variable */
    int x4 = x3 | nTarget;
    int x5 = x4 | mTarget;
    
    return x5;
}
/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) {
    /* This filters out negative numbers from returning 1 */
    return ((x >> 31) & 1) ^ 1;
}
/*
 * logicalNeg - implement the ! operator, using all of
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int logicalNeg(int x) {
    /* Using or, move all the bits to space 1 */
    int x1 = x | (x >> 16);
    int x2 = x1 | (x1 >> 8);
    int x3 = x2 | (x2 >> 4);
    int x4 = x3 | (x3 >> 2);
    int x5 = x4 | (x4 >> 1);
    /* Flip the rightmost bit (negation part)*/
    int x_1 = (x5 & 1) ^ 1;
    /* Flip it again if the number is negative */
    return x_1 & ~(x >> 31);
}
/*
 * upperBits - pads n upper bits with 1's
 *  You may assume 0 <= n <= 32
 *  Example: upperBits(4) = 0xF0000000
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 10
 *  Rating: 1
 */
int upperBits(int n) {
    /*
     * First, we put either a 1 or a 0 in the most significant bit space
     * a 0 if n is 0, a 1 otherwise
     */
    int x = (!!n) << 31;
    /*
     * Then, we shift right n - 1 times
     * If x was set to 0, then we have 0 0s (which is what we want)
     * If x was set to 1, then we have 1 + (n - 1) 1s (also good)
     */
    return x >> (n + ~0);
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
    /* use logical NOT on 0x00000000 to get 0xFFFFFFFF */
    return ~0;
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    /*
     * Disregarding the challenge of overflows, the straightforward
     * way to compare x and y is using subtraction and checking
     * the sign on the bit
     */
    
    /*
     * One issue encountered is that y == x should return 0, so I
     * counter that by adding 1 to y, shifting everything over, causing
     * the results to come back correct.
     */
    int yp1 = y + 1;
    
    /*
     * calculate x + (2s complement of y) in place of subtraction
     */
    int diff = x + (~yp1 + 1);
    
    /*
     * Get the sign of the leftmost bit. Flip it,
     * because negative result should return 0, and
     * positive should return 1, etc.
     */
    int flippedSign = ((diff >> 31) & 1) ^ 1;
    
    /*
     * The flipped sign bit can be returned in normal
     * circumstances, however overflows etc. can cause
     * odd behavior, so some other checks are needed
     */
    
    /*
     * Get the sign bit for x and y
     */
    int xSign = ((x >> 31) & 1);
    int ySign = ((y >> 31) & 1);
    
    /*
     * Generate bits for whether x is positive and y is negative
     * or y is positive and x is negative. These two cases cover
     * some edge cases and overflow problems
     */
    int xPosYneg = (xSign ^1) & ySign;
    int yPosXneg = xSign & (ySign ^1);
    
    /*
     * Set the desired return bit on the condition that
     * one of them is in fact 1
     */
    int desiredClearcaseRes = xPosYneg;
    
    /*
     * Decide whether to use the bit we just made
     */
    int clearcase = xPosYneg | yPosXneg;// | yZerXneg;
    
    /*
     * This statement returns the flippedSign bit, or, if clearcase is 1, the desiredClearcaseRes bit
     *
     * This is achieved by zero-ing out the flippedSign bit IF clearcase is 1, then
     * ORing in the desiredCLearcaseRes if clearcase is 1.
     */
    return (flippedSign & (~clearcase)) | (desiredClearcaseRes & clearcase) /* zero out if clear */;
}
/*
 * bitParity - returns 1 if x contains an odd number of 0's
 *   Examples: bitParity(5) = 0, bitParity(7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int bitParity(int x) {
    return 2;
}
