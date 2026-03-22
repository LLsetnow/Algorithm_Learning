#include<bits/stdc++.h>
using namespace std;

struct Person{
	string name;
	int type;//1-散牌，2-对子，3-豹子
	int score;
};

bool cmp(const Person &per1,const Person &per2){ // 优先级比较
	if(per1.type!=per2.type){
		return per1.type>per2.type;
	}else if(per1.score!=per2.score){
		return per1.score>per2.score;
	}else{
		return per1.name<per2.name;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	map<string,int> card={
		{"3",1},{"4",2},{"5",3},{"6",4},{"7",5},{"8",6},{"9",7},
		{"10",8},{"J",9},{"Q",10},{"K",11},{"A",12},{"2",13}
	};
	
	int n;cin>>n;
	vector<Person> person(n);
	string name,a,b,c;
	for(int i=0;i<n;i++){
		cin>>name>>a>>b>>c;
		int p1=card[a];
		int p2=card[b];
		int p3=card[c];
		
		vector<int> pai = {p1,p2,p3};
		sort(pai.begin(),pai.end());//从小到大排序
		
		Person p;
		p.name=name;
		if(pai[0]==pai[1]&&pai[1]==pai[2]){
			p.type = 3;
			p.score = pai[0]*100;//豹子只存一张
		}else if(pai[0]==pai[1]){//小的两张是对子
			p.type=2;
			p.score=pai[0]*100+pai[2];
		}else if(pai[1]==pai[2]){//大的两张是对子
			p.type=2;
			p.score=pai[1]*100+pai[0];
		}else{
			p.type=1;
			p.score=pai[2]*10000+pai[1]*100+pai[0];//从大到小
		}
		person[i]=p;
	}
	sort(person.begin(),person.end(),cmp);
	for(int i=0;i<n;i++){
		cout<<person[i].name<<'\n';//!用\n换行，不然频繁刷新缓冲区会超时
	}
	return 0;
}
