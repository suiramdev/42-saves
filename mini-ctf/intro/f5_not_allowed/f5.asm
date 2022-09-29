; 0x18 	var1
; 0x8	var2
; 0x10	var3

0000000000001139 <check_secret>:
    1139:       55                      push   rbp
    113a:       48 89 e5                mov    rbp,rsp
    113d:       48 89 7d e8             mov    QWORD PTR [rbp-0x18],rdi			; Argument of type long int
    1141:       48 8b 45 e8             mov    rax,QWORD PTR [rbp-0x18]			; We save temp our argument
    1145:       48 89 45 f8             mov    QWORD PTR [rbp-0x8],rax			; Set it to one of our function's variables
    1149:       48 8b 45 f8             mov    rax,QWORD PTR [rbp-0x8]			; We save temp our setted variable value
    114d:       8b 00                   mov    eax,DWORD PTR [rax]				;
    114f:       35 40 20 5b 7f          xor    eax,0x7f5b2040					; Condition xor between value of 0x8 and 0x7f...
; 0x7f5b2040 == 2136678464
    1154:       89 45 f0                mov    DWORD PTR [rbp-0x10],eax			; Cast to int, and save our value on a another var
; 0x7f5b2040 == 2136678464
    1157:       48 8b 45 f8             mov    rax,QWORD PTR [rbp-0x8]
    115b:       48 83 c0 04             add    rax,0x4							;
    115f:       8b 00                   mov    eax,DWORD PTR [rax]
    1161:       35 53 23 59 76          xor    eax,0x76592353
    1166:       89 45 f4                mov    DWORD PTR [rbp-0xc],eax

    1169:       81 7d f0 37 13 37 13    cmp    DWORD PTR [rbp-0x10],0x13371337
    1170:       75 10                   jne    1182 <check_secret+0x49>			; goto 1182 if not equal

    1172:       81 7d f4 37 13 37 13    cmp    DWORD PTR [rbp-0xc],0x13371337
    1179:       75 07                   jne    1182 <check_secret+0x49>			; goto 1182 if not equal

    117b:       b8 01 00 00 00          mov    eax,0x1							; write 1 for return
    1180:       eb 05                   jmp    1187 <check_secret+0x4e> 		; goto 1187

    1182:       b8 00 00 00 00          mov    eax,0x0							; write 0 for return
    1187:       5d                      pop    rbp		
    1188:       c3                      ret										; end procedure, return value
