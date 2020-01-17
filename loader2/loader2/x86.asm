
ifndef X64

.model flat, stdcall

.code

	get_code_base proc
		call entry
entry:
		pop	eax
		sub eax, 1425h

		ret
	get_code_base endp

	reset_callbacks proc
		ASSUME FS:NOTHING
		mov eax, fs:[30h]					; PEB
		ASSUME FS:ERROR
		mov dword ptr [eax + 22Ch], 0		; FlsHighIndex

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