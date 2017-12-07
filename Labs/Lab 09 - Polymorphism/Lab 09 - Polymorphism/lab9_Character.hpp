#ifndef _CHARACTER
#define _CHARACTER

#include <string>
using namespace std;

enum TurnChoice { ATTACK = 0, HEAL = 1 };

class ICharacter
{
public:
	int GetAttack();
	int GetHealing();
	void Setup(const string& name, int atk, int mag);
	int GetHP();
	void SubtractDamage(int damage);
	string GetName();
	virtual TurnChoice GetChoice() = 0;
private:
	int m_hp, m_atk, m_mag;
	string m_name;
};

class NPC: public ICharacter
{
public:
	virtual TurnChoice GetChoice();

private:

};

class Player:public ICharacter
{
public:
	virtual TurnChoice GetChoice();

private:

};






#endif
