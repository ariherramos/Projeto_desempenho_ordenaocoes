	.file	"quick_sort.c"
	.text
	.p2align 2,,3
.globl _troca
	.def	_troca;	.scl	2;	.type	32;	.endef
_troca:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%ebx
	movl	8(%ebp), %edx
	movl	12(%ebp), %eax
	movl	(%edx), %ecx
	movl	(%eax), %ebx
	movl	%ebx, (%edx)
	movl	%ecx, (%eax)
	popl	%ebx
	leave
	ret
	.p2align 2,,3
.globl _mediana_de_tres
	.def	_mediana_de_tres;	.scl	2;	.type	32;	.endef
_mediana_de_tres:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	movl	8(%ebp), %edx
	movl	12(%ebp), %esi
	movl	16(%ebp), %ecx
	leal	(%ecx,%esi), %eax
	movl	%eax, %ebx
	shrl	$31, %ebx
	leal	(%ebx,%eax), %eax
	sarl	%eax
	leal	(%edx,%ecx,4), %ebx
	movl	(%ebx), %ecx
	leal	(%edx,%esi,4), %esi
	movl	(%esi), %edi
	cmpl	%edi, %ecx
	jl	L4
	movl	%edi, %ecx
L5:
	leal	(%edx,%eax,4), %edi
	movl	(%edi), %edx
	cmpl	%ecx, %edx
	jge	L6
	movl	%ecx, (%edi)
	movl	%edx, (%esi)
	movl	(%edi), %edx
L6:
	movl	(%ebx), %ecx
	cmpl	%edx, %ecx
	jge	L7
	movl	%edx, (%ebx)
	movl	%ecx, (%edi)
L7:
	popl	%ebx
	popl	%esi
	popl	%edi
	leave
	ret
	.p2align 2,,3
L4:
	movl	%edi, (%ebx)
	movl	%ecx, (%esi)
	jmp	L5
	.p2align 2,,3
.globl _particao
	.def	_particao;	.scl	2;	.type	32;	.endef
_particao:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$24, %esp
	movl	12(%ebp), %esi
	movl	16(%ebp), %ebx
	movl	%ebx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	8(%ebp), %eax
	movl	%eax, (%esp)
	call	_mediana_de_tres
	movl	8(%ebp), %edx
	movl	(%edx,%eax,4), %eax
	movl	%eax, -16(%ebp)
	leal	-1(%esi), %ecx
	movl	%ecx, -20(%ebp)
	incl	%ebx
	leal	(%edx,%esi,4), %edi
	.p2align 2,,3
L11:
	incl	-20(%ebp)
	movl	(%edi), %eax
	movl	%eax, -24(%ebp)
	cmpl	%eax, -16(%ebp)
	jg	L12
	leal	-1(%ebx), %eax
	movl	8(%ebp), %ecx
	leal	(%ecx,%eax,4), %edx
	jmp	L13
	.p2align 2,,3
L18:
	decl	%eax
L13:
	movl	%eax, %ebx
	movl	%edx, %esi
	movl	(%edx), %ecx
	subl	$4, %edx
	cmpl	%ecx, -16(%ebp)
	jl	L18
	cmpl	%eax, -20(%ebp)
	jge	L19
	movl	%ecx, (%edi)
	movl	-24(%ebp), %eax
	movl	%eax, (%esi)
L12:
	addl	$4, %edi
	jmp	L11
	.p2align 2,,3
L19:
	addl	$24, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	leave
	ret
	.p2align 2,,3
.globl _quick_sort
	.def	_quick_sort;	.scl	2;	.type	32;	.endef
_quick_sort:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$44, %esp
	movl	8(%ebp), %edi
	movl	12(%ebp), %ebx
	movl	16(%ebp), %esi
	cmpl	%esi, %ebx
	jge	L23
	.p2align 2,,3
L24:
	movl	%esi, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	call	_particao
	movl	%eax, 8(%esp)
	movl	%ebx, 4(%esp)
	movl	%edi, (%esp)
	movl	%eax, -28(%ebp)
	call	_quick_sort
	movl	-28(%ebp), %eax
	leal	1(%eax), %ebx
	cmpl	%esi, %ebx
	jl	L24
L23:
	addl	$44, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	leave
	ret
