////////////////////
/// C++ Object-oriented Programming
/// Adventure Game 6
/// Reference answer 
/// anssi.grohn@pkamk.fi
////////////////////
#ifndef __Gold_h__
#define __Gold_h__
////////////////////////////////////////////////////////////////////////////////
class GoldFactory;
////////////////////////////////////////////////////////////////////////////////
class Gold 
{
 
private:
  unsigned int m_nAmount;
  
public:
	Gold(unsigned int value);
  virtual ~Gold();
  unsigned int GetAmount() const;
  void SetAmount( unsigned int value );
	Gold &operator+=(Gold *p_gold)
	{
		Gold *gold = new Gold(0);
		gold->m_nAmount = p_gold->GetAmount();
		
		return *gold;
	}
};
////////////////////////////////////////////////////////////////////////////////
#endif
