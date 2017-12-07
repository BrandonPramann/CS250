//#include "Character.hpp"

#include <cstdlib>
#include <iostream>
#include "lab9_Character.hpp"
using namespace std;

int ICharacter::GetAttack()
{
	return rand() % m_atk;
}

int ICharacter::GetHealing()
{
	int healing = rand() % m_mag;
	m_hp += healing;

		if (m_hp > 100)
		 {
		m_hp = 100;
		 }
	
		return healing;
}

void ICharacter::Setup(const string & name, int atk, int mag)
{
	m_name = name;
	m_atk = atk;
	m_mag = mag;
	m_hp = 100;
}

int ICharacter::GetHP()
{
	return m_hp;
}

void ICharacter::SubtractDamage(int damage)
{
	m_hp -= damage;
}

string ICharacter::GetName()
{
	return m_name;
}

TurnChoice NPC::GetChoice()
{
	return TurnChoice(rand()%2);
}

TurnChoice Player::GetChoice()
{
	int choice;
	cout << "Select your choice: ";
	cin >> choice;
	cout << endl;
	return TurnChoice(choice);
}
