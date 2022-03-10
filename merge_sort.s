	.file	"merge_sort.c"
	.section .rdata,"dr"
	.align 4
LC0:
	.ascii "merge_sort->funde_sort: ponteiro inavalido\0"
LC1:
	.ascii "Malloc funde_sort: \0"
	.text
	.p2align 2,,3
.globl _funde_sort
	.def	_funde_sort;	.scl	2;	.type	32;	.endef
_funde_sort:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	8(%ebp), %edi
	movl	12(%ebp), %eax
	movl	%eax, -44(%ebp)
	movl	16(%ebp), %ebx
	movl	%ebx, -40(%ebp)
	movl	20(%ebp), %eax
	movl	%eax, -32(%ebp)
	movl	24(%ebp), %ebx
	movl	%ebx, -36(%ebp)
	testl	%edi, %edi
	je	L21
	movl	-44(%ebp), %eax
	testl	%eax, %eax
	je	L3
	movl	-32(%ebp), %edx
	incl	%edx
	movl	-32(%ebp), %eax
	cmpl	%eax, -40(%ebp)
	jg	L4
	cmpl	-36(%ebp), %edx
	jg	L22
	movl	-40(%ebp), %ebx
	incl	%ebx
	movl	%ebx, -28(%ebp)
	movl	-40(%ebp), %eax
	movl	-44(%ebp), %ebx
	leal	(%ebx,%eax,4), %ecx
	jmp	L9
	.p2align 2,,3
L24:
	movl	%esi, (%ecx)
	movl	-28(%ebp), %ebx
	incl	%eax
	cmpl	%eax, -32(%ebp)
	jl	L4
L25:
	incl	-28(%ebp)
	addl	$4, %ecx
	cmpl	%edx, -36(%ebp)
	jl	L23
L9:
	movl	(%edi,%eax,4), %esi
	movl	(%edi,%edx,4), %ebx
	cmpl	%ebx, %esi
	jl	L24
	movl	%ebx, (%ecx)
	movl	-28(%ebp), %ebx
	incl	%edx
	cmpl	%eax, -32(%ebp)
	jge	L25
	.p2align 2,,3
L4:
	cmpl	%edx, -40(%ebp)
	jge	L12
	movl	-40(%ebp), %eax
	sall	$2, %eax
	movl	-44(%ebp), %ecx
	addl	%eax, %ecx
	addl	%eax, %edi
	movl	-40(%ebp), %eax
	.p2align 2,,3
L13:
	movl	(%ecx), %ebx
	movl	%ebx, (%edi)
	incl	%eax
	addl	$4, %ecx
	addl	$4, %edi
	cmpl	%eax, %edx
	jg	L13
L12:
	movl	-44(%ebp), %eax
	movl	%eax, 8(%ebp)
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	leave
	jmp	_free
	.p2align 2,,3
L23:
	movl	%ebx, %ecx
L10:
	leal	(%edi,%eax,4), %esi
	movl	-44(%ebp), %ebx
	leal	(%ebx,%ecx,4), %ecx
	movl	%edx, -28(%ebp)
	movl	-32(%ebp), %ebx
	.p2align 2,,3
L11:
	movl	(%esi), %edx
	movl	%edx, (%ecx)
	incl	%eax
	addl	$4, %esi
	addl	$4, %ecx
	cmpl	%eax, %ebx
	jge	L11
	movl	-28(%ebp), %edx
	jmp	L4
L22:
	movl	-40(%ebp), %eax
	movl	%eax, %ecx
	jmp	L10
L3:
	movl	$LC1, (%esp)
	call	_perror
	movl	$1, (%esp)
	call	_exit
L21:
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$42, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC0, (%esp)
	call	_fwrite
	movl	$1, (%esp)
	call	_exit
	.section .rdata,"dr"
	.align 4
LC2:
	.ascii "merge_sort: ponteiro inavalido\0"
	.text
	.p2align 2,,3
.globl _merge_sort
	.def	_merge_sort;	.scl	2;	.type	32;	.endef
_merge_sort:
	pushl	%ebp
	movl	%esp, %ebp
	pushl	%edi
	pushl	%esi
	pushl	%ebx
	subl	$60, %esp
	movl	8(%ebp), %ebx
	movl	12(%ebp), %esi
	movl	16(%ebp), %edi
	testl	%ebx, %ebx
	je	L30
	cmpl	%edi, %esi
	jge	L29
	leal	(%edi,%esi), %eax
	movl	%eax, %edx
	shrl	$31, %edx
	addl	%eax, %edx
	sarl	%edx
	movl	20(%ebp), %eax
	movl	%eax, 12(%esp)
	movl	%edx, 8(%esp)
	movl	%esi, 4(%esp)
	movl	%ebx, (%esp)
	movl	%edx, -28(%ebp)
	call	_merge_sort
	movl	20(%ebp), %ecx
	movl	%ecx, 12(%esp)
	movl	%edi, 8(%esp)
	movl	-28(%ebp), %edx
	leal	1(%edx), %eax
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_merge_sort
	movl	20(%ebp), %eax
	sall	$2, %eax
	movl	%eax, (%esp)
	call	_malloc
	movl	20(%ebp), %ecx
	movl	%ecx, 20(%esp)
	movl	%edi, 16(%esp)
	movl	-28(%ebp), %edx
	movl	%edx, 12(%esp)
	movl	%esi, 8(%esp)
	movl	%eax, 4(%esp)
	movl	%ebx, (%esp)
	call	_funde_sort
L29:
	addl	$60, %esp
	popl	%ebx
	popl	%esi
	popl	%edi
	leave
	ret
L30:
	movl	__imp___iob, %eax
	addl	$64, %eax
	movl	%eax, 12(%esp)
	movl	$30, 8(%esp)
	movl	$1, 4(%esp)
	movl	$LC2, (%esp)
	call	_fwrite
	movl	$1, (%esp)
	call	_exit
	.def	_free;	.scl	2;	.type	32;	.endef
	.def	_perror;	.scl	2;	.type	32;	.endef
	.def	_malloc;	.scl	2;	.type	32;	.endef
	.def	_fwrite;	.scl	2;	.type	32;	.endef
	.def	_exit;	.scl	2;	.type	32;	.endef
