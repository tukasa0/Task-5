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

void Battle(Hero* hero)
{
	Enemy enemy;

	int heroNowHp = hero->GetStatus(Hp);
	int enemyNowHp = enemy.GetStatus(Hp);

	while (true)
	{
		cout << endl;
		hero->ShowName();
		cout << " HP " << heroNowHp << endl;
		enemy.ShowName();
		cout << " HP " << enemyNowHp << endl;

		int action = hero->InputKey();

		if (action == Atk)
		{
			hero->Attack(&enemy);
			enemyNowHp = enemy.GetStatus(Hp);
		}
		else if (action == Heal)
		{
			hero->Heal();
		}

		if (enemyNowHp <= 0)
		{
			cout << "敵を倒した！" << endl;
			break;
		}

		enemy.Attack(hero);
		heroNowHp = hero->GetStatus(Hp);

		if (heroNowHp <= 0)
		{
			cout << "あなたは負けてしまった..." << endl;
			break;
		}
	}
}

void showStatus(Hero hero, Enemy enemy);

int main()
{
	Hero hero;
	Hero otherHero;
	Enemy enemy;
	Enemy otherEnemy;

	//Battle(&hero);


	showStatus(hero, enemy); // 代入前
	hero = otherHero;
	enemy = otherEnemy;
	showStatus(hero, enemy); // 代入後

}

void showStatus(const Hero const hero, const Enemy const enemy)
{
	cout << "あなたのパラメータ" << endl;
	hero.ShowName();
	printf(" HP:%d ATK:%d DEF:%d\n", hero.GetStatus(Hp), hero.GetStatus(Atk), hero.GetStatus(Def));

	cout << "敵のパラメータ" << endl;
	enemy.ShowName();
	printf(" HP:%d ATK:%d DEF:%d\n", enemy.GetStatus(Hp), enemy.GetStatus(Atk), enemy.GetStatus(Def));
}