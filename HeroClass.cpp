#define _CRT_SECURE_NO_WARNINGS

#include "HeroClass.h"
#include "EnemyClass.h"
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

Hero::Hero()
{
	InputName();

	cout << "HPを設定してください > " << flush;
	cin >> hp;

	atk = 5;
	def = 2;
};

//コピーコンストラクタ
Hero::Hero(const Hero& other)
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
void Hero::operator=(const Hero& other)
{
	char* opName = new char[strlen(other.name) + 1];
	strcpy(opName, other.name);
	delete[] name;
	name = opName;

	hp = other.hp;
	atk = other.atk;
	def = other.def;
}

void Hero::Attack(Enemy* enemy)
{
	int damage = enemy->GetStatus(Def) - atk;

	if (damage > 0)
	{
		damage = 0;
	}

	cout << name << "の攻撃" << endl;
	enemy->ShowName();
	cout << "に " << abs(damage) << " のダメージ" << endl;

	enemy->SetHp(damage);
}

void Hero::Heal()
{
	int heal = 4;

	cout << "HPが " << heal << " 回復した" << endl;
	hp += heal;
}

int Hero::GetStatus(const int status) const
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

void Hero::SetHp(const int changeInHp)
{
	hp += changeInHp;
}

void Hero::ShowName() const
{
	cout << name;
}

void Hero::InputName()
{
	if (name != NULL)
	{
		delete[] name;
		name = NULL;
	}

	const int MAX_NAME = 30;
	char inputName[MAX_NAME + 1];

	cout << "あなたの名前を入力してください > " << flush;
	cin >> inputName;

	int size = strlen(inputName);
	name = new char[size + 1];

	strcpy(name, inputName);

	cout << "あなたの名前は " << name << " です。" << endl;
}

int Hero::InputKey()
{
	int inputKey;

	cout << "どうする？" << endl
		<< "攻撃 > 1のキー, 回復 > 3のキー" << endl;
	cin >> inputKey;

	return inputKey;
}

Hero::~Hero()
{
	if (name != NULL)
	{
		delete[] name;
		name = NULL;
	}

	//cout << "デストラクタが呼ばれました。" << endl;

};
