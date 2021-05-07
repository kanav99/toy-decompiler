   100003f2a:	48 89 7d f8          	mov    %rdi,-0x8(%rbp)
   100003f2e:	89 75 f4             	mov    %esi,-0xc(%rbp)
   100003f31:	89 55 f0             	mov    %edx,-0x10(%rbp)
   100003f34:	89 4d ec             	mov    %ecx,-0x14(%rbp)
   100003f37:	44 89 45 e8          	mov    %r8d,-0x18(%rbp)
   100003f3b:	44 89 4d e4          	mov    %r9d,-0x1c(%rbp)
   100003f3f:	48 8b 7d f8          	mov    -0x8(%rbp),%rdi
   100003f43:	89 7d e0             	mov    %edi,-0x20(%rbp)
   100003f46:	8b 4d 10             	mov    0x10(%rbp),%ecx
   100003f49:	89 4d dc             	mov    %ecx,-0x24(%rbp)
   100003f4c:	6b 4d e0 07          	imul   $0x7,-0x20(%rbp),%ecx
   100003f50:	83 c1 20             	add    $0x20,%ecx
   100003f53:	89 4d dc             	mov    %ecx,-0x24(%rbp)
   100003f56:	8b 4d dc             	mov    -0x24(%rbp),%ecx
   100003f59:	c1 e1 03             	shl    $0x3,%ecx
   100003f5c:	83 c1 02             	add    $0x2,%ecx
   100003f5f:	89 4d d8             	mov    %ecx,-0x28(%rbp)
   100003f62:	89 45 d4             	mov    %eax,-0x2c(%rbp)
   100003f65:	44 89 d0             	mov    %r10d,%eax