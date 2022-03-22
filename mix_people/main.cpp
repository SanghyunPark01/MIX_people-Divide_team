#include <iostream>
#include <cstring>
#include <random>
#include "Console.h"

using namespace std;

class person
{
private:
	string name;
	int team;
public:
	person() {};
	~person() {};
	void setname(string a) {
		name = a;
	}
	void setteam(int b) {
		team = b;
	}
	string outname(void) {
		return name;
	}
	int outteam(void) {
		return team;
	}
};
vector<person> P;
vector<int> tt;
int num_team;
int num_people;

void Getpeople(void);
void Getteamnum(void);
void SetTeam(void);
void Shuffle(void);
void PrintTeam(void);
int main(void)
{
	Getteamnum();
	Getpeople();
	num_people = P.size();

	Clear();
	SetTeam();
	PrintTeam();


	return 0;
}
void Getteamnum(void) {
	cout << "나눌 팀 수를 입력하세요" << endl;
	cin >> num_team;
	Clear();
}
void Getpeople(void)
{
	while (1) {
		string n;
		cout << "그만 추가하고싶으면 \"stop\"을 입력하세요"<<endl;
		cout << "현재 입력하신 사람의 수는 " << P.size() << " 입니다." << endl;

		cout << "이름을 입력하세요" << endl;
		cin >> n;
		if (n == "stop")break;
		person pe;
		pe.setname(n);
		P.push_back(pe);

		Clear();
	}


}
void Shuffle(void) {
	int temp;
	int rn;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dis(0,num_people-1);
	for (int i = 0; i < num_people-1 ; i++) {
		rn = dis(gen);
		temp = tt[i];
		tt[i] = tt[rn];
		tt[rn] = temp;
	}

	/*for (int i = 0; i < num_people; i++) {
		cout << tt[i] << endl;
	}*/
	

}
void SetTeam(void) {
	for (int i = 0; i < num_people; i++) { 
		tt.push_back(i+1); }
	Shuffle();
	for (int i = 0; i < num_people; i++) {
		P[i].setteam(tt[i]);
	}
}
void PrintTeam(void)
{
	int pt;

	vector<int> ppt;//people per team
	ppt.push_back(0);
	int k = num_people % num_team;
	pt = num_people / num_team;
	if (k == 0) {
		for (int i = 0; i < num_team;i++) {
			ppt.push_back(pt);
		}
	}
	else {
		pt = num_people / num_team;
		for (int i = 0; i < k; i++) {
			ppt.push_back(pt+1);
		}
		for (int i = k; i < num_team; i++) {
			ppt.push_back(pt);
		}
	}
	int sum = 0;
	for (int j = 1; j <= num_team; j++) {
		cout << "team " << j << endl;
		sum += ppt[j-1];
		for (int i = 0; i < num_people; i++) {
			if (P[i].outteam() <= ppt[j]+sum && P[i].outteam() > sum) {
				cout << P[i].outname() << endl;
			}
		}
		cout << endl;
	}

}