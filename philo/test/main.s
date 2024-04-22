	.section	__TEXT,__text,regular,pure_instructions
	.build_version macos, 10, 15	sdk_version 10, 15
	.globl	_thread1_routine        ## -- Begin function thread1_routine
	.p2align	4, 0x90
_thread1_routine:                       ## @thread1_routine
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$0, -12(%rbp)
LBB0_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10000, -12(%rbp)       ## imm = 0x2710
	jge	LBB0_3
## %bb.2:                               ##   in Loop: Header=BB0_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	movl	_count(%rip), %eax
	addl	$1, %eax
	movl	%eax, _count(%rip)
	jmp	LBB0_1
LBB0_3:
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_thread2_routine        ## -- Begin function thread2_routine
	.p2align	4, 0x90
_thread2_routine:                       ## @thread2_routine
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	movq	%rdi, -8(%rbp)
	movl	$0, -12(%rbp)
LBB1_1:                                 ## =>This Inner Loop Header: Depth=1
	cmpl	$10000, -12(%rbp)       ## imm = 0x2710
	jge	LBB1_3
## %bb.2:                               ##   in Loop: Header=BB1_1 Depth=1
	movl	-12(%rbp), %eax
	addl	$1, %eax
	movl	%eax, -12(%rbp)
	movl	_count(%rip), %eax
	addl	$-1, %eax
	movl	%eax, _count(%rip)
	jmp	LBB1_1
LBB1_3:
	xorl	%eax, %eax
                                        ## kill: def $rax killed $eax
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.globl	_errorExit              ## -- Begin function errorExit
	.p2align	4, 0x90
_errorExit:                             ## @errorExit
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$16, %rsp
	movq	%rdi, -8(%rbp)
	movq	-8(%rbp), %rdi
	callq	_perror
	movq	-8(%rbp), %rsi
	leaq	L_.str(%rip), %rdi
	xorl	%eax, %eax
	movb	%al, %cl
	movb	%cl, %al
	callq	_printf
	movl	$1, %edi
	movl	%eax, -12(%rbp)         ## 4-byte Spill
	callq	_exit
	.cfi_endproc
                                        ## -- End function
	.globl	_main                   ## -- Begin function main
	.p2align	4, 0x90
_main:                                  ## @main
	.cfi_startproc
## %bb.0:
	pushq	%rbp
	.cfi_def_cfa_offset 16
	.cfi_offset %rbp, -16
	movq	%rsp, %rbp
	.cfi_def_cfa_register %rbp
	subq	$48, %rsp
	xorl	%eax, %eax
	movl	%eax, %ecx
	movl	$0, -4(%rbp)
	movl	%edi, -8(%rbp)
	movq	%rsi, -16(%rbp)
	leaq	-24(%rbp), %rdi
	movq	%rcx, %rsi
	leaq	_thread1_routine(%rip), %rdx
	callq	_pthread_create
	xorl	%r8d, %r8d
	cmpl	%eax, %r8d
	je	LBB3_2
## %bb.1:
	leaq	L_.str.1(%rip), %rdi
	callq	_errorExit
LBB3_2:
	xorl	%eax, %eax
	movl	%eax, %ecx
	leaq	-32(%rbp), %rdi
	movq	%rcx, %rsi
	leaq	_thread2_routine(%rip), %rdx
	callq	_pthread_create
	xorl	%r8d, %r8d
	cmpl	%eax, %r8d
	je	LBB3_4
## %bb.3:
	leaq	L_.str.2(%rip), %rdi
	callq	_errorExit
LBB3_4:
	xorl	%eax, %eax
	movl	%eax, %esi
	movq	-24(%rbp), %rdi
	callq	_pthread_join
	xorl	%ecx, %ecx
	movl	%ecx, %esi
	movq	-32(%rbp), %rdi
	movl	%eax, -36(%rbp)         ## 4-byte Spill
	callq	_pthread_join
	movl	_count(%rip), %esi
	leaq	L_.str.3(%rip), %rdi
	movl	%eax, -40(%rbp)         ## 4-byte Spill
	movb	$0, %al
	callq	_printf
	xorl	%ecx, %ecx
	movl	%eax, -44(%rbp)         ## 4-byte Spill
	movl	%ecx, %eax
	addq	$48, %rsp
	popq	%rbp
	retq
	.cfi_endproc
                                        ## -- End function
	.section	__DATA,__data
	.globl	_mutex                  ## @mutex
	.p2align	3
_mutex:
	.quad	850045863               ## 0x32aaaba7
	.space	56

	.p2align	2               ## @count
_count:
	.long	10                      ## 0xa

	.section	__TEXT,__cstring,cstring_literals
L_.str:                                 ## @.str
	.asciz	"%s"

L_.str.1:                               ## @.str.1
	.asciz	"thread1 no se ha podido crear"

L_.str.2:                               ## @.str.2
	.asciz	"thread2 no se ha podido crear"

L_.str.3:                               ## @.str.3
	.asciz	"Valor de count %d"


.subsections_via_symbols
