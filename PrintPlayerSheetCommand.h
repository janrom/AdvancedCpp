///////////////////////////////////////////////////////////////
/// Advanced C++
/// Adventure Game
/// Prints out playersheet
/// 1101096 / LUDNS11 / janne.h.romppanen@edu.pkamk.fi
///////////////////////////////////////////////////////////////

#include "Command.h"
#include "TextRenderer.h"
#include "Game.h"
#include <iostream>
#include <string>
#include <sstream> // for ostringstream

class PrintPlayerSheetCommand : public Command
{	
public:
	PrintPlayerSheetCommand( Game *pGame ) : Command(pGame) { }
	void Execute()
	{
		TextRenderer tr;
		int iTmp;
		// used for converting from integer to sring and as parameter for Render-function
		ostringstream os;
		tr.Render( "\nPlayersheet: \n\n" );
		tr.Render( "Name: " + GetGame()->GetPlayer().GetName() + "\n" );
		tr.Render( "Race: " + GetGame()->GetPlayer().GetRace() + "\n" );
				
		iTmp = 0;
		iTmp = GetGame()->GetPlayer().GetClass();
		switch ( iTmp )
		{
			case 0:
				tr.Render( "Class: Barbarian\n" );
				break;
			case 1:
				tr.Render( "Class: Wizard\n" );
				break;
			case 2:
				tr.Render( "Class: Palading\n" );
				break;
			case 3:
				tr.Render( "Class: Priest\n" );
				break;
			default:
				tr.Render( "Class: Peasant\n" );
		}
				
		iTmp = 0;
		iTmp = GetGame()->GetPlayer().GetAge();
		// remove all bits (flags). Otherwise old operations stays in stream
		os.clear();
		// C++ -style to put empty string to stream. C-style would be os.str(""). C++ -style could be more efficient
		os.str( string() );
		os << iTmp;
		tr.Render( "Age: " + os.str() + "\n" );
		
		iTmp = 0;
		iTmp = GetGame()->GetPlayer().GetGender();
		if(iTmp == 0)
		{
			tr.Render( "Gender: male\n" );
		}
		else
		{
			tr.Render( "Gender: female\n" );
		}
		
		iTmp = 0;
		iTmp = GetGame()->GetPlayer().GetExperience();
		os.clear();
		os.str( string() );
		os << iTmp;
		tr.Render( "Experience: " + os.str() + "\n\n" );		
	}
};