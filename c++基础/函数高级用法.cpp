//函数重载: 函数名相同，参数列表不同
/*
    函数重载的规则:
    1. 函数名相同
    2. 参数列表不同
    3. 返回值类型不同
    4. 参数顺序不同
    5. 参数类型不同
    6. 参数个数不同
    7. 参数类型顺序不同
    8. 参数个数顺序不同
*/
// #include <iostream>
// using namespace std;
// int add(int a, int b){
//     return a + b;
// }
// int add(int a, int b, int c){
//     return a + b + c;
// }
// int main(){
//     cout << add(1, 2) << endl;
//     cout << add(1, 2, 3) << endl;
//     return 0;
// }

//函数默认参数: 函数参数有默认值
#include <iostream>
using namespace std;
int add(int a, int b = 10){
    return a + b;
}
int main(){
    cout << add(1) << endl;
    cout << add(1, 2) << endl;
    return 0;
}