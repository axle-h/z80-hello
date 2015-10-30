;; Generic crt0.s for a Z80
;; From SDCC.
;; Modified to suit execution on Axh.Retro Z80 emulator

  .module crt0
  .globl  _main

  .area _HEADER (ABS)
;; Reset vector
  .org  0x0 ;; Start from address &0
init:
;; Stack at the top of memory.
  ld  sp,#0xffff

;; Initialise global variables
  call gsinit
  call _main
  jp   _exit

  ;; Ordering of segments for the linker.
  .area _HOME
  .area _CODE
  .area _GSINIT
  .area _GSFINAL
  .area _DATA
  .area _BSS
  .area _HEAP
  .area _CODE

__clock::
  ret

_exit::
  ret
  .area _GSINIT

gsinit::
  .area _GSFINAL
  ret
