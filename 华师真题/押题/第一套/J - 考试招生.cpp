/*

小诺所在的灵幻学院举办成仙考试，有 n 名考生（编号 1 到 n）参加，需提交 4 门灵幻科目的成绩 s1, s2, s3, s4（0≤si≤100，i = 1,2,3,4） ，学院有 m 个灵幻系（编号 1 到 m）进行招生 。
录取规则
各灵幻系按编号从小到大依次招生，每个系计划招生 k 人（1≤k≤n）。
从尚未被录取的考生中，先按四门成绩总分∑(i = 1 到 4) si 从高到低排序录取 。若总分相同：
    当 c∈{1,2,3,4} 时，按第 c 门科目的成绩 sc 从高到低排序录取。
    当 c = 0 时，不考虑单科成绩，只按总分 。
若经过上述排序后成绩仍相同，则按考生编号从小到大全部录取，此时录取人数可超过计划的 k 人。
输入输出格式
输入描述:
第一行：两个正整数 n 和 m（1≤n≤1000，1≤m≤100）。
接下来 n 行：每行 4 个整数，表示每个考生的四门科目成绩。
再接下来 m 行：每行 2 个整数 k 和 c（1≤k≤n，0≤c≤4） ，分别是每个系的计划招生人数和成绩排序规则参数。
输出描述:
共 m 行，每行第一个数为该灵幻系实际录取人数 p，后面 p 个数为按录取规则被录取考生的编号。

输入输出样例
输入样例#:
3 3
90 100 100 100
100 100 90 100
100 100 100 100
1 0
1 2
1 0

输出样例#:
1 3
2 1 2
0


n 个考生 m 个系 4门课[0-100]

招生优先级：
    1.从 编号小的系 开始招生
    2.剩余考生中 按照总分降序
    3.总分相同 根据 系的成绩排序规则参数 c 而论
        3.1 按照 第c门成绩降序
        3.2 c = 0 则跳过
    4. 按照 编号升序

*/

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

struct Student
{
    int socre[5];   // 单科成绩 score[0]为空
    int sum;        // 成绩总分
    int number;     // 编号
};

struct Xi
{
    int c;      // 排序规则参数
    int k;      // 计划招生人数
    int real;   // 实际招生人数
    vector<int> record; // 录取学生编号
};

void printStudents(vector<Student> students, int n){
    for(int i = 1; i <= n; i++){
        int A = students[i].socre[1];
        int B = students[i].socre[2];
        int C = students[i].socre[3];
        int D = students[i].socre[4];
        int sum = students[i].sum;
        cout << "Number = " << i << endl;
        cout << "   Score : " << A << " " << B << " " << C << " " << D << " " << sum << endl;
    }
    
}
int main(){

    int n, m;
    cin >> n >> m;
    Student stuInit = {{-1, -1, -1, -1, -1}, -1, -1};
    vector<Student> students(n + 2, stuInit);    // [1-based]
    vector<Xi> xis(m + 2);              // [1-based]
    for(int i = 1; i <= n; i++){
        cin >> students[i].socre[1] >> students[i].socre[2] >> students[i].socre[3] >> students[i].socre[4];
        students[i].number = i;
        students[i].sum = students[i].socre[1] + students[i].socre[2] + students[i].socre[3] + students[i].socre[4];
    }
    for(int i = 1; i <= m; i++){
        cin >> xis[i].k >> xis[i].c;
        xis[i].real = 0;
    }

    // 学生按照总分降序排序 students[0] 为空
    sort(students.begin() + 1, students.end(), [](Student &a, Student &b){
        if(a.sum == b.sum)
            return a.number < b.number;
        // 大降小升
        return a.sum > b.sum;
    });

    // 打印排序后的学生
    // printStudents(students, n);

    // 学生索引双指针
    int l = 1, r = 1;
    // 开始招生
    for(int i = 1; i<= m; i++){
        Xi xi = xis[i];
        // 还有名额 与 学生
        while(xi.k > 0 && l <= n){
            
            // [l ~ r - 1]的学生总分相同
            while(students[r].sum == students[l].sum) r++;
            int legth = r - l;  // 同分学生个数
            // cout << "tong fen :[" << l << "-" << r-1 << "]" << endl; 
            if(xi.k >= legth || xi.c == 0){
                // 全招
                xi.k -= legth;
                xi.real += legth;
                // 同分且够招的情况下，也要根据 c 排序决定招生顺序
                if(xi.c != 0){
                    // 优先按照 单课降序 其次按照 编号升序
                    sort(students.begin() + l, students.begin() + r, [xi](Student &a, Student &b){
                        // 大降小升
                        if(a.socre[xi.c] == b.socre[xi.c])
                            return a.number < b.number;
                        return a.socre[xi.c] > b.socre[xi.c];
                    });
                }
                for(int i = l; i < r; i++) xi.record.push_back(students[i].number);
                l = r;
            }
            else{
                // 不够招生要开始排名 且 c != 0 的系
                // 优先按照 单课降序 其次按照 编号升序
                sort(students.begin() + l, students.begin() + r, [xi](Student &a, Student &b){
                    // 大降小升
                    if(a.socre[xi.c] == b.socre[xi.c])
                        return a.number < b.number;
                    return a.socre[xi.c] > b.socre[xi.c];
                });
                // 查找单科分数相同的学生个数
                int r = l;
                // [l ~ r - 1]的学生总分相同
                while(students[r].socre[xi.c] == students[l].socre[xi.c]) r++;
                legth = r - l;
                // 无论招生人数够不够 都全招
                xi.k -= legth;
                xi.real += legth;
                for(int i = l; i < r; i++) xi.record.push_back(students[i].number);
                l = r;
            }
        }

        // 该系招生完毕
        cout << xi.real << " ";
        if(xi.real != 0){
            for(auto x : xi.record) cout << x << " ";
        }
        cout << endl;
    }
}