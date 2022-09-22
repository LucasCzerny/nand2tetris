// push constant 111
@111
D=A

A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 333
@333
D=A

A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// push constant 888
@888
D=A

A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// pop static 8
@8
D=A
A
A=D+A
D=M
@SP
M=M-1
A=M
D=M
A
A=D+A
A
M=D
// pop static 3
@3
D=A
o.
A=D+A
D=M
@SP
M=M-1
A=M
D=M
o.
A=D+A
o.
M=D
// pop static 1
@1
D=A
Foo.
A=D+A
D=M
@SP
M=M-1
A=M
D=M
Foo.
A=D+A
Foo.
M=D
// push static 3
@3
D=A
o.
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// push static 1
@1
D=A
Foo.
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// sub
@SP

// push static 8
@8
D=A
A
A=D+A
D=M
@SP
A=M
M=D
@SP
M=M+1
// add
@SP

