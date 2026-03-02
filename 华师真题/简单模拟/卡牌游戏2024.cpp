/*

判定卡牌个数 N <= 9
卡牌号、匹配色、分数

盒子个数 M <= 384
得分卡牌的个数 T < 8
卡牌号，匹配色的个数S,S个匹配数 系数P

输入：  
4
1 1 10
3 2 10
3 2 20
7 4 20
2
3
1 2 1 2 2
3 2 1 2 2
7 2 1 4 4
3
1 2 1 2 2
3 2 1 2 2
3 2 3 4 4

输出：
第一行输出得分最多盒子的下标(从1开始计算)。
第二行输出盒子得分。

1
140

耗时： 88min
关键：注意卡牌排序 line 102-108
*/

#include <bits/stdc++.h>
using namespace std;
typedef struct JudgeCards
{
    int number;     // 卡牌号
    int color;      // 颜色
    int score;      // 分数
};

typedef struct ScoreCards
{
    int number;     // 卡牌号
    int S;          // 颜色个数
    int colors[6] = {0};    // 颜色
    int score;      // 分数
};

typedef struct Boxs
{
    int T;          // 盒子内卡牌个数
    int maxScore;       // 该盒子的最高得分
    vector<ScoreCards> cards;   // 得分卡牌
};


int main(){

    int N;          // 判定卡牌个数
    cin >> N;
    vector<JudgeCards> cards(N);    // 判定卡牌
    for(int i = 0; i < N; i++){
        cin >> cards[i].number;
        cin >> cards[i].color;
        cin >> cards[i].score;
    }

    int M;          // 盒子个数
    cin >> M;
    vector<Boxs> boxs(M);       // 盒子
    for(int i = 0; i < M; i++){ // 单个盒子
        cin >> boxs[i].T;
        for(int j = 0; j < boxs[i].T; j++){ // 单个卡牌
            ScoreCards card;
            cin >> card.number;
            cin >> card.S;
            for(int k = 0; k < card.S; k++){
                int x;
                cin >> x;
                card.colors[x] = 1;
            }
            cin >> card.score;
            boxs[i].cards.push_back(card);
        }
    }

    /*
        1.先将判定卡牌 按照卡牌号升序排序，其次按照卡牌分数降序排序
        2.将得分卡牌 按照卡牌号升序排序 其次按照卡牌颜色数量降序排序,最后按照 卡牌得分降序排序
        3.用双指针控制 判定卡牌 和 得分卡牌的匹配关系
    */
    sort(cards.begin(), cards.end(), [](JudgeCards& a, JudgeCards& b){
        // 降序大于，升序小于
        if(a.number == b.number) return a.score > b.score;
        return a.number < b.number;
    });
    for(auto &box : boxs){
        sort(box.cards.begin(), box.cards.end(), [](ScoreCards& a, ScoreCards& b){
            if(a.number == b.number && a.S == b.S) return a.score > b.score;
            if(a.number == b.number) return a.S > b.S;
            return a.number < b.number;
        });
    }

    // 计算每个盒子可能的最大值
    for(auto &box : boxs){
        int i = 0;  // 判定卡牌指针
        int j = 0;  // 得分卡牌指针
        while(i < N && j < box.T){
            if(cards[i].number == box.cards[j].number &&
                cards[i].color <= 6 && box.cards[j].colors[cards[i].color]){
                    int score = cards[i].score * box.cards[j].score;
                    box.maxScore += score;
                    // cout << "success: " << cards[i].score << " * " << box.cards[j].score << endl;
                    i++;
                    j++;
            }
            else if(cards[i].number < box.cards[j].number){
                i++;
            }
            else{
                j++;
            }
        }
    }

    int maxRes = 0;
    int maxIdx = 0;
    for(int i = 0; i < M; i++){
        if(boxs[i].maxScore > maxRes){
            maxRes = boxs[i].maxScore;
            maxIdx = i;
        }
    }

    cout << maxIdx + 1 << endl;
    cout << maxRes << endl;
    
    return 0;
}