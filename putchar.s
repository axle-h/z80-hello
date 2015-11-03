;; Modified to suit execution on Axh.Retro Z80 emulator

  .area _CODE

; Pull a character off the top of the stack and send it to io port 0
_putchar::
_putchar_rr_s::
          ld      hl,#2
          add     hl,sp
          ld      a,(hl)
          out     (0),a
          ret

; Pull a character from register E and send it to io port 0
_putchar_rr_dbs::
          ld      a,e
          out     (0),a
          ret
