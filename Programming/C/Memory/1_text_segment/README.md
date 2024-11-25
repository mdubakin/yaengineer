# Компиляция

```sh
> gcc main.c
```

# Посмотреть размер статической схемы объектного файла

```sh
# Linux
> size ./a.out

text    data     bss     dec     hex filename
1673     616       8    2297     8f9 ./a.out
```

```sh
# MacOS
> size ./a.out

__TEXT  __DATA  __OBJC  others  dec     hex
16384   16384   0       4295000064      4295032832      100010000
```

# Посмотреть disassembly кода

```sh
# Linux
> objdump -d ./a.out

./a.out:     file format elf64-x86-64


Disassembly of section .init:

0000000000001000 <_init>:
...

Disassembly of section .plt:

0000000000001020 <.plt>:
...

Disassembly of section .plt.got:

0000000000001050 <__cxa_finalize@plt>:
...

Disassembly of section .plt.sec:

0000000000001060 <puts@plt>:
...

0000000000001070 <printf@plt>:
...

Disassembly of section .text:

0000000000001080 <_start>:
...

00000000000010b0 <deregister_tm_clones>:
...

00000000000010e0 <register_tm_clones>:
...

0000000000001120 <__do_global_dtors_aux>:
...

0000000000001160 <frame_dummy>:
...

0000000000001169 <greet>:
    1169:       f3 0f 1e fa             endbr64
    116d:       55                      push   %rbp
    116e:       48 89 e5                mov    %rsp,%rbp
    1171:       48 8b 05 98 2e 00 00    mov    0x2e98(%rip),%rax        # 4010 <hello>
    1178:       48 89 c7                mov    %rax,%rdi
    117b:       e8 e0 fe ff ff          call   1060 <puts@plt>
    1180:       90                      nop
    1181:       5d                      pop    %rbp
    1182:       c3                      ret

0000000000001183 <add>:
    1183:       f3 0f 1e fa             endbr64
    1187:       55                      push   %rbp
    1188:       48 89 e5                mov    %rsp,%rbp
    118b:       89 7d fc                mov    %edi,-0x4(%rbp)
    118e:       89 75 f8                mov    %esi,-0x8(%rbp)
    1191:       8b 55 fc                mov    -0x4(%rbp),%edx
    1194:       8b 45 f8                mov    -0x8(%rbp),%eax
    1197:       01 d0                   add    %edx,%eax
    1199:       5d                      pop    %rbp
    119a:       c3                      ret

000000000000119b <main>:
    119b:       f3 0f 1e fa             endbr64
    119f:       55                      push   %rbp
    11a0:       48 89 e5                mov    %rsp,%rbp
    11a3:       48 83 ec 10             sub    $0x10,%rsp
    11a7:       b8 00 00 00 00          mov    $0x0,%eax
    11ac:       e8 b8 ff ff ff          call   1169 <greet>
    11b1:       be 03 00 00 00          mov    $0x3,%esi
    11b6:       bf 05 00 00 00          mov    $0x5,%edi
    11bb:       e8 c3 ff ff ff          call   1183 <add>
    11c0:       89 45 fc                mov    %eax,-0x4(%rbp)
    11c3:       8b 45 fc                mov    -0x4(%rbp),%eax
    11c6:       89 c6                   mov    %eax,%esi
    11c8:       48 8d 05 43 0e 00 00    lea    0xe43(%rip),%rax        # 2012 <_IO_stdin_used+0x12>
    11cf:       48 89 c7                mov    %rax,%rdi
    11d2:       b8 00 00 00 00          mov    $0x0,%eax
    11d7:       e8 94 fe ff ff          call   1070 <printf@plt>
    11dc:       b8 00 00 00 00          mov    $0x0,%eax
    11e1:       c9                      leave
    11e2:       c3                      ret

Disassembly of section .fini:

00000000000011e4 <_fini>:
...
```

```sh
# MacOS
> objdump -d ./a.out

./a.out: file format mach-o arm64

Disassembly of section __TEXT,__text:

0000000100003ed4 <_greet>:
100003ed4: ff 83 00 d1  sub sp, sp, #32
100003ed8: fd 7b 01 a9  stp x29, x30, [sp, #16]
100003edc: fd 43 00 91  add x29, sp, #16
100003ee0: 28 00 00 b0  adrp x8, 0x100008000 <_greet+0x20>
100003ee4: 08 01 40 f9  ldr x8, [x8]
100003ee8: e9 03 00 91  mov x9, sp
100003eec: 28 01 00 f9  str x8, [x9]
100003ef0: 00 00 00 90  adrp x0, 0x100003000 <_greet+0x1c>
100003ef4: 00 68 3e 91  add x0, x0, #3994
100003ef8: 22 00 00 94  bl 0x100003f80 <_printf+0x100003f80>
100003efc: fd 7b 41 a9  ldp x29, x30, [sp, #16]
100003f00: ff 83 00 91  add sp, sp, #32
100003f04: c0 03 5f d6  ret

0000000100003f08 <_add>:
100003f08: ff 43 00 d1  sub sp, sp, #16
100003f0c: e0 0f 00 b9  str w0, [sp, #12]
100003f10: e1 0b 00 b9  str w1, [sp, #8]
100003f14: e8 0f 40 b9  ldr w8, [sp, #12]
100003f18: e9 0b 40 b9  ldr w9, [sp, #8]
100003f1c: 00 01 09 0b  add w0, w8, w9
100003f20: ff 43 00 91  add sp, sp, #16
100003f24: c0 03 5f d6  ret

0000000100003f28 <_main>:
100003f28: ff c3 00 d1  sub sp, sp, #48
100003f2c: fd 7b 02 a9  stp x29, x30, [sp, #32]
100003f30: fd 83 00 91  add x29, sp, #32
100003f34: 08 00 80 52  mov w8, #0
100003f38: a8 43 1f b8  stur w8, [x29, #-12]
100003f3c: bf c3 1f b8  stur wzr, [x29, #-4]
100003f40: e5 ff ff 97  bl 0x100003ed4 <_greet>
100003f44: a0 00 80 52  mov w0, #5
100003f48: 61 00 80 52  mov w1, #3
100003f4c: ef ff ff 97  bl 0x100003f08 <_add>
100003f50: a0 83 1f b8  stur w0, [x29, #-8]
100003f54: a9 83 5f b8  ldur w9, [x29, #-8]
100003f58: e8 03 09 aa  mov x8, x9
100003f5c: e9 03 00 91  mov x9, sp
100003f60: 28 01 00 f9  str x8, [x9]
100003f64: 00 00 00 90  adrp x0, 0x100003000 <_main+0x3c>
100003f68: 00 78 3e 91  add x0, x0, #3998
100003f6c: 05 00 00 94  bl 0x100003f80 <_printf+0x100003f80>
100003f70: a0 43 5f b8  ldur w0, [x29, #-12]
100003f74: fd 7b 42 a9  ldp x29, x30, [sp, #32]
100003f78: ff c3 00 91  add sp, sp, #48
100003f7c: c0 03 5f d6  ret

Disassembly of section __TEXT,__stubs:

0000000100003f80 <__stubs>:
100003f80: 10 00 00 b0  adrp x16, 0x100004000 <__stubs+0x4>
100003f84: 10 02 40 f9  ldr x16, [x16]
100003f88: 00 02 1f d6  br x16
```

# Посмотреть содержимое строковых литералов

```sh
# Linux
> objdump -s -j .rodata  ./a.out

./a.out:     file format elf64-x86-64

Contents of section .rodata:
 2000 01000200 48656c6c 6f2c2057 6f726c64  ....Hello, World
 2010 21003520 2b203320 3d202564 0a00      !.5 + 3 = %d..
```

```sh
# MacOS
> objdump -s -j __cstring ./a.out

./a.out:        file format mach-o arm64
Contents of section __TEXT,__cstring:
 100003f8c 48656c6c 6f2c2057 6f726c64 21002573  Hello, World!.%s
 100003f9c 0a003520 2b203320 3d202564 0a00      ..5 + 3 = %d..
```