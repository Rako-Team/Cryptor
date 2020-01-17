
ifdef X64

.code

	get_code_base proc
		call entry
entry:
		pop	rax
		sub rax, 1B45h

		ret
	get_code_base endp

	reset_callbacks proc
		mov rax, qword ptr gs:[60h]			; PEB
		mov qword ptr [rax + 350h], 0		; FlsHighIndex

		ret
	reset_callbacks endp

;	crt_memcpy proc dst:dword, src:dword, mem_size:dword
;		mov	edi, dst
;		mov	esi, src
;		mov	ecx, mem_size
;
;		rep movsb
;
;		ret
;	crt_memcpy endp
;
;	crt_memset proc pointer:dword, value:byte, mem_size:dword
;		mov edi, pointer
;		mov ecx, mem_size
;		mov al, value
;
;		rep stosb
;
;		ret
;	crt_memset endp

endif

end