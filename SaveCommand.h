///////////////////////////////////////////////////////////////
/// Advanced C++
/// Adventure Game
/// Saves player's data to file
/// 1101096 / LUDNS11 / janne.h.romppanen@edu.pkamk.fi
///////////////////////////////////////////////////////////////

#include "Command.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <fstream>
#include <exception>

using namespace std;

class SaveCommand : public Command
{
public:
	SaveCommand( Game *pGame ) : Command(pGame) { }
	void Execute()
	{
		try
		{
			ofstream ofs( "playerdata.txt" );
			ostringstream os;
			int iTmp;
			ofs << GetGame()->GetPlayer().GetName() + "\n";
			ofs << GetGame()->GetPlayer().GetRace() + "\n";
			
			iTmp = GetGame()->GetPlayer().GetClass();
			os << iTmp;
			ofs << os.str() + "\n";
			// remove all bits (flags). Otherwise old operations stays in stream
			os.clear();
			// C++ -style to put empty string to stream. C-style would be os.str(""). C++ -style could be more efficient
			os.str( string() );
			
			iTmp = GetGame()->GetPlayer().GetAge();
			os << iTmp;
			ofs << os.str() + "\n";
			os.clear();
			os.str( string() );
				
			iTmp = GetGame()->GetPlayer().GetGender();
			os << iTmp;
			ofs << os.str() + "\n";
			os.clear();
			os.str( string() );
			
			iTmp = GetGame()->GetPlayer().GetExperience();
			os << iTmp;
			ofs << os.str() + "\n";
			os.clear();
			os.str( string() );
			
			iTmp = GetGame()->GetPlayer().gold;
			os << iTmp;
			ofs << os.str() + "\n";
			os.clear();
			os.str( string() );
			
			ofs.close();
		}
		catch(exception & e)
		{
			cout << "File handling error with error code: " << e.what() << endl;
		}
	}
};