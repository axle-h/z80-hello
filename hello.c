#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>

void Fibonacci16(void);
void Fibonacci32(void);
void GCD(uint16_t num1, uint16_t num2);
bool addition_is_safe_uint16(uint16_t a, uint16_t b);
bool addition_is_safe_uint32(uint32_t a, uint32_t b);
size_t msb_uint16(uint16_t a);
size_t msb_uint32(uint32_t a);

void main(void)
{
  printf("***z80-hello***\n");
  Fibonacci16();
  Fibonacci32();
  GCD(54, 24); //6
  GCD(0xc637, 0x6c1e);
}

void Fibonacci16() {
  uint8_t count = 2;
  uint16_t fib1 = 0, fib2 = 1, fib3;

  printf("***16-Bit Fibonacci Series***\n");
  printf("1: %u\n", fib1);
  printf("2: %u\n", fib2);

  while (1)
  {
      if(!addition_is_safe_uint16(fib1, fib2)) {
        break;
      }

      fib3 = fib1 + fib2;
      count++;
      printf("%u: %u\n", count, fib3);
      fib1 = fib2;
      fib2 = fib3;
  }
}

void Fibonacci32() {
  uint8_t count = 2;
  uint32_t fib1 = 0, fib2 = 1, fib3;

  printf("***32-Bit Fibonacci Series***\n");
  printf("1: %lu\n", fib1);
  printf("2: %lu\n", fib2);

  while (1)
  {
      if(!addition_is_safe_uint32(fib1, fib2)) {
        break;
      }

      fib3 = fib1 + fib2;
      count++;
      printf("%u: %lu\n", count, fib3);
      fib1 = fib2;
      fib2 = fib3;
  }
}

void GCD(uint16_t num1, uint16_t num2) {
    uint16_t a = num1, b = num2, c;

    while ( a != 0 ) {
       c = a; a = b % a;  b = c;
    }

    printf("GCD of %u and %u = %u\n", num1, num2, b);
}

bool addition_is_safe_uint16(uint16_t a, uint16_t b) {
    size_t a_bits=msb_uint16(a), b_bits=msb_uint16(b);
    return (a_bits<16 && b_bits<16);
}

bool addition_is_safe_uint32(uint32_t a, uint32_t b) {
    size_t a_bits=msb_uint32(a), b_bits=msb_uint32(b);
    return (a_bits<32 && b_bits<32);
}

size_t msb_uint16(uint16_t a) {
    size_t bits=0;
    while (a!=0) {
        ++bits;
        a>>=1;
    };
    return bits;
}

size_t msb_uint32(uint32_t a) {
    size_t bits=0;
    while (a!=0) {
        ++bits;
        a>>=1;
    };
    return bits;
}
