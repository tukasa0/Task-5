#ifndef HEROCLASS_H_
#define HEROCLASS_H_

class Enemy;

class Hero
{
public:
	Hero();
	~Hero();
	Hero(const Hero& other);            // コピーコンストラクタ
	void operator=(const Hero& other);  // 代入演算子のオーバーロード
	void Attack(Enemy* enemy);
	void Heal();
	int GetStatus(const int status) const;
	void SetHp(const int changeInHp);
	int InputKey();
	void ShowName() const;


private:
	void InputName();



private:
	char* name;
	int hp;
	int atk;
	int def;


};

#endif // HEROCLASS_H_
