section		.text
global		_ft_strdup
extern		_malloc

_ft_strdup:
		mov rax, 0;
		mov rcx, 0

while:
		cmp BYTE[rdi + rcx], 0
		jne plus
		inc rcx
		push rdi
		mov  rax, rdi
		call _malloc
		cmp BYTE[rax], 0
		jne return
		pop rdi
		mov rax, rdi
		
return:
		ret 

plus: 
	inc rcx
	jmp while
