# libasm
### The goal of this project is to redo some functions of the libc but entirely in assembly.

```c
size_t ft_strlen(const char *);
char *ft_strcpy(char *, const char *);
int ft_strcmp(const char *, const char *);
ssize_t ft_write(int fd, const void *buf, size_t count);
ssize_t ft_read(int fd, void *buf, size_t count);
char *ft_strdup(const char *s);
```
And for the bonus part do some function for a linked list
```c
typedef struct s_list
{
	char *data;
	struct s_list *next;
} t_list;

void ft_list_push_front(t_list **, void *);
int ft_list_size(t_list *begin_list);
```

## Some Docs

Guide to x86<br/>
https://www.cs.virginia.edu/~evans/cs216/guides/x86.html

Wiki x86 asm<br/>
https://en.wikibooks.org/wiki/X86_Assembly/X86_Architecture

### Registers
![Many register in asm](https://camo.githubusercontent.com/7554f94d634c05b559a04a0904950ff63a4074d7754a3500673cf55ce7b3470f/68747470733a2f2f692e737461636b2e696d6775722e636f6d2f4e304b6e472e706e67)


## System Call

List of Linux system call: https://blog.rchapman.org/posts/Linux_System_Call_Table_for_x86_64/

| %rax | System call | %rdi            | %rsi            | %rdx         |
| ---- | ----------- | --------------  | --------------- | ------------ |
| 0    | sys_read    | unsigned int fd | char *buf       | size_t count |
| 1    | sys_write   | unsigned int fd | const char *buf | size_t count |
| ... | ... | ... | ... | ... | ... |

## Jump table

| Instruction | Description | Condition Code | C Equivalent |
| - | - | - | - |
| jmp			| Jump to label						| -			| - |
| je / jz		| Jump if equal/zero 				| ZF		| a = b |
| jne / jnz		| Jump if not equal/nonzero 		| ~ZF		| a ≠ b |
| js			| Jump if negative					| SF		| - |
| jns			| Jump if nonnegative				| ~SF		| - |
| jg / jnle		| Jump if greater (signed)			| ~(SF^0F)&~ZF | a > b |
| jge / jnl		| Jump if greater or equal (signed) | ~(SF^0F) 	| a ≥ b |
| jl / jnge		| Jump if less (signed)				| SF^0F		| a < b |
| jle / jng 	| Jump if less or equal				| (SF^OF)\|ZF | a ≤ b |
| ja / jnbe 	| Jump if above (unsigned)			| ~CF&~ZF	| a > b |
| jae / jnb 	| Jump if above or equal (unsigned) |~CF		| a ≥ b |
| jb / jnae 	| Jump if below (unsigned)			| CF		| a < b |
| jbe / jna 	| Jump if below or equal (unsigned) | CF\|ZF	| a ≤ b |
