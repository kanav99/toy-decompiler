   100003f20:	55                   	push   %rbp
   100003f21:	48 89 e5             	mov    %rsp,%rbp
   100003f24:	8b 45 10             	mov    0x10(%rbp),%eax
   100003f27:	45 31 d2             	xor    %r10d,%r10d
   100003f2a:	89 7d fc             	mov    %edi,-0x4(%rbp)
   100003f2d:	89 75 f8             	mov    %esi,-0x8(%rbp)
   100003f30:	89 55 f4             	mov    %edx,-0xc(%rbp)
   100003f33:	89 4d f0             	mov    %ecx,-0x10(%rbp)
   100003f36:	44 89 45 ec          	mov    %r8d,-0x14(%rbp)
   100003f3a:	44 89 4d e8          	mov    %r9d,-0x18(%rbp)
   100003f3e:	8b 4d fc             	mov    -0x4(%rbp),%ecx
   100003f41:	89 4d e4             	mov    %ecx,-0x1c(%rbp)
   100003f44:	8b 4d 10             	mov    0x10(%rbp),%ecx
   100003f47:	89 4d e0             	mov    %ecx,-0x20(%rbp)
   100003f4a:	6b 4d e4 07          	imul   $0x7,-0x1c(%rbp),%ecx
   100003f4e:	83 c1 20             	add    $0x20,%ecx
   100003f51:	89 4d e0             	mov    %ecx,-0x20(%rbp)
   100003f54:	8b 4d e0             	mov    -0x20(%rbp),%ecx
   100003f57:	c1 e1 03             	shl    $0x3,%ecx
   100003f5a:	83 c1 02             	add    $0x2,%ecx
   100003f5d:	89 4d dc             	mov    %ecx,-0x24(%rbp)
   100003f60:	89 45 d8             	mov    %eax,-0x28(%rbp)
   100003f63:	44 89 d0             	mov    %r10d,%eax
   100003f66:	5d                   	pop    %rbp
   100003f67:	c3                   	retq   
