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

	cout << "HP��ݒ肵�Ă������� > " << flush;
	cin >> hp;

	atk = 5;
	def = 2;
};

//�R�s�[�R���X�g���N�^
Hero::Hero(const Hero& other)
{
	name = new char[strlen(other.name) + 1];
	strcpy(name, other.name);

	hp = other.hp;
	atk = other.atk;
	def = other.def;

	//copy(other.name, other.name + def, name);

	//cout << "�R�s�[�R���X�g���N�^���Ă΂�܂����B" << endl;
}

//������Z�q�̃I�[�o�[���[�h
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

	cout << name << "�̍U��" << endl;
	enemy->ShowName();
	cout << "�� " << abs(damage) << " �̃_���[�W" << endl;

	enemy->SetHp(damage);
}

void Hero::Heal()
{
	int heal = 4;

	cout << "HP�� " << heal << " �񕜂���" << endl;
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

	cout << "���Ȃ��̖��O����͂��Ă������� > " << flush;
	cin >> inputName;

	int size = strlen(inputName);
	name = new char[size + 1];

	strcpy(name, inputName);

	cout << "���Ȃ��̖��O�� " << name << " �ł��B" << endl;
}

int Hero::InputKey()
{
	int inputKey;

	cout << "�ǂ�����H" << endl
		<< "�U�� > 1�̃L�[, �� > 3�̃L�[" << endl;
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

	//cout << "�f�X�g���N�^���Ă΂�܂����B" << endl;

};
