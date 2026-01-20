/*
Smith有一台古老的计算机，这台计算机使用一套非常特殊的标记编程语言。现在我们仅考虑这一语言的一个小的子集，该子集可以实现一个简单计算器。

这台机器一共有 4 个无差别的寄存器，分别为 AX, BX, CX, DX，在指令中他们可以互相替代，下面的表格列出了所有支持的指令。
指令 	中文名 	格式 	解释
IN 	读操作指令 	IN AX,number 	读数据存储在AX中，AX=number
MOV 	传送指令 	MOV AX,BX 	AX=BX
ADD 	加法指令 	ADD AX,BX 	AX=AX+BX
SUB 	减法指令 	SUB AX,BX 	AX=AX-BX
MUL 	乘法指令 	MUL AX,BX 	AX=AX * BX
DIV 	除法指令 	DIV AX,BX 	AX=AX/BX（整除）
OUT 	写操作指令 	OUT AX 	输出AX的值

例如：以下代码实现表达式 (2+3*5)/6的计算并输出计算结果。

IN AX,3
IN BX,5
MUL AX,BX
IN CX,2
ADD CX,AX
IN BX,6
DIV CX,BX
OUT CX

输入用这种特殊标记编程语言编写的一段代码，请编写一个翻译器，对代码进行翻译，输出最后运行结果。
输入输出格式
输入描述:
输入代码片段。

注意：读的数据均为int型整数。所有被计算的数值（包括中间值）均保证在int范围内。

输入保证不包含任何多余的空白字符，在开始执行前，所有寄存器的值可以视为已经清零。
对于 30% 的数据指令数 <= 50；
对于 80% 的数据指令数 <= 100 000 ；
对于 100% 的数据指令数 <= 500 000 ；
输出描述:
对于每个 OUT 指令，输出一行表示结果。
输入输出样例
输入样例#:

IN AX,3
IN BX,5
MUL AX,BX
IN CX,2
ADD CX,AX
IN BX,6
DIV CX,BX
OUT CX

输出样例#:

2

*/
#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int getRegIndex(const string& s) {
    if (s[0] == 'A') return 0;
    if (s[0] == 'B') return 1;
    if (s[0] == 'C') return 2;
    return 3;
}

int main(){
    string line;
    vector<i64> Register(4, 0);
    while (getline(cin, line)) {
        if (line.empty()) continue;
        size_t sp = line.find(' ');
        string op = line.substr(0, sp);
        string rest = line.substr(sp + 1);
        if (op == "OUT") {
            int regIdx = getRegIndex(rest); 
            cout << Register[regIdx] << "\n";
        } else if (op == "IN") {
            size_t comma = rest.find(',');
            string regStr = rest.substr(0, comma);
            int val = stoi(rest.substr(comma + 1));
            Register[getRegIndex(regStr)] = val;
        } else {
            // 算术指令和MOV
            size_t comma = rest.find(',');
            string reg1 = rest.substr(0, comma);
            string reg2 = rest.substr(comma + 1);
            int idx1 = getRegIndex(reg1), idx2 = getRegIndex(reg2);
            // 根据op执行操作
            if (op == "MOV") {
                Register[idx1] = Register[idx2];
            } else if (op == "ADD") {
                Register[idx1] += Register[idx2];
            } else if (op == "SUB") {
                Register[idx1] -= Register[idx2];
            } else if (op == "MUL") {
                Register[idx1] *= Register[idx2];
            } else if (op == "DIV") {
                Register[idx1] /= Register[idx2];
            }
        }
    }
}



