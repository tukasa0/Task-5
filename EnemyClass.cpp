#define _CRT_SECURE_NO_WARNINGS

#include "EnemyClass.h"
#include "HeroClass.h"
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <algorithm>

using namespace std;

enum Status
{
	Hp,
	Atk,
	Def,
	Heal,
};

Enemy::Enemy()
{
	InputName();

	cout << "HPを設定してください > " << flush;
	cin >> hp;

	atk = 5;
	def = 2;
}

//コピーコンストラクタ
Enemy::Enemy(const Enemy& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	hp = other.hp;
	atk = other.atk;
	def = other.def;

	//copy(other.name, other.name + def, name);

	//cout << "コピーコンストラクタが呼ばれました。" << endl;
}

//代入演算子のオーバーロード
void Enemy::operator=(const Enemy& other)
{
	char* opName = new char[strlen(other.name) + 1];
	strcpy(opName, other.name);
	delete[] name;
	name = opName;

	hp = other.hp;
	atk = other.atk;
	def = other.def;
}

void Enemy::Attack(Hero* hero)
{
	int damage = hero->GetStatus(Def) - atk;

	if (damage > 0)
	{
		damage = 0;
	}

	cout << name << "の攻撃" << endl;
	hero->ShowName();
	cout << "に " << abs(damage) << " のダメージ" << endl;

	hero->SetHp(damage);
}

int Enemy::GetStatus(const int status) const
{
	switch (status)
	{
	case Hp:
		return hp;
		break;

	case Atk:
		return atk;
		break;

	case Def:
		return def;
		break;

	default:
		break;
	}
}

void Enemy::SetHp(int changeInHp)
{
	hp += changeInHp;
}

void Enemy::InputName()
{
	if (name != NULL)
	{
		delete[] name;
		name = NULL;
	}

	const int MAX_NAME = 30;
	char inputName[MAX_NAME + 1];

	cout << "敵の名前を入力してください > " << flush;
	cin >> inputName;

	int size = strlen(inputName);
	name = new char[size + 1];

	strcpy(name, inputName);

	cout << "敵の名前は " << name << " です。" << endl;
}

void Enemy::ShowName() const
{
	cout << name;
}

Enemy::~Enemy()
{
	if (name != NULL)
	{
		delete[] name;
		name = NULL;
	}

	//cout << "デストラクタが呼ばれました。" << endl;
};