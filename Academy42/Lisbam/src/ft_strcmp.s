section		.text
global		_ft_strcmp

_ft_strcmp:
		mov rax, 0
		mov rcx, 0


while:
		cmp BYTE[rdi], 0
		je case
		cmp BYTE[rdi + rcx], 0
		je equal
		mov dl, BYTE[rdi + rcx]
		mov al, BYTE[rsi + rcx]
		cmp dl, al
		jne calc
		inc rcx
		jmp while
calc:
		sub dl, al
return:
		movzx rax, dl
		ret
equal:
		mov dl, 0
		jmp return
case:
		mov dl, -1
		jmp return