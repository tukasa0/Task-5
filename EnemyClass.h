#ifndef ENEMYCLASS_H_
#define ENEMYCLASS_H_

class Hero;

class Enemy
{
public:
	Enemy();
	~Enemy();
	Enemy(const Enemy& other);      //コピーコンストラクタ
	void operator=(const Enemy& other);     //代入演算子のオーバーロード
	void Attack(Hero* hero);
	int GetStatus(const int status) const;
	void SetHp(const int changeInHp);
	void ShowName() const;

private:
	void InputName();

private:
	char* name;
	int hp;
	int atk;
	int def;
};

#endif // ENEMYCLASS_H_