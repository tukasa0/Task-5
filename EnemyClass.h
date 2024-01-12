#ifndef ENEMYCLASS_H_
#define ENEMYCLASS_H_

class Hero;

class Enemy
{
public:
	Enemy();
	~Enemy();
	Enemy(const Enemy& other);      //�R�s�[�R���X�g���N�^
	void operator=(const Enemy& other);     //������Z�q�̃I�[�o�[���[�h
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