# Compiler

## 語法

```
PROG = STMTS
BLOCK = { STMTS }
STMTS = STMT*
STMT = WHILE | BLOCK | ASSIGN
WHILE = while (E) STMT
ASSIGN = id '=' E;
E = F (op E)*
F = (E) | Number | Id
```
## 指令
make  
gcc -std=c99 -O0 lexer.c compiler.c main.c -o compiler  
./compiler test/if.c  

## 測試範例
a = 3;      
b = 5;       
if (a > b){  
    t = a;   
}  
else{       
   t = b;  
}  

## 執行結果
========== lex ==============  
token=a  
token==  
token=3  
token=;  
token=b  
token==  
token=5  
token=;  
token=if  
token=(  
token=a  
token=>  
token=b  
token=)  
token={  
token=t  
token==  
token=a  
token=;  
token=}  
token=else  
token={  
token=t  
token==  
token=b  
token=;  
token=}  
========== dump ==============
0:a  
1:=  
2:3  
3:;  
4:b  
5:=  
6:5  
7:;  
8:if  
9:(  
10:a  
11:>  
12:b  
13:)  
14:{  
15:t  
16:=  
17:a  
18:;  
19:}  
20:else  
21:{  
22:t  
23:=  
24:b  
25:;  
26:}  
============ parse =============
t0 = 3  
a = t0  
t1 = 5  
b = t1  
t2 = a  
t3 = b  
t4 = t2 > t3  
(if not t4 goto L0)  
t5 = a  
t = t5  
(if t4 is true goto L1)  
(L0)  
t6 = b  
t = t6  
(L1)  
