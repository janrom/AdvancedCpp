///////////////////////////////////////////////////////////////
/// Advanced C++
/// Adventure Game
/// Loads player's saved data from a file
/// 1101096 / LUDNS11 / janne.h.romppanen@edu.pkamk.fi
///////////////////////////////////////////////////////////////

#include "Command.h"
#include "Game.h" // for GetPlayer
#include <iostream>
#include <fstream>
#include <string>
#include <exception>

using namespace std;

class LoadCommand : public Command
{
public:
	LoadCommand( Game *pGame ) : Command(pGame) { }
	void Execute()
	{
		try
		{
			ifstream ifs;
			ifs.open("playerdata.txt");
			string strTmp;
			int iTmp = 0;
			int i = 0;
			string sArray[7];
			
			// while stream have stuff in it
			while( !ifs.eof() )
			{
				getline(ifs, strTmp);
				// starting mark for player statics
				if(strTmp == "#player")
					continue;
				// ending mark
				if(strTmp == "#")
					break;
				sArray[i] = strTmp;
				i++;				
			}
						
			GetGame()->GetPlayer().SetName(sArray[0]);
			GetGame()->GetPlayer().SetRace(sArray[1]);
			
			// convert string to integer via atoi-function. atoi is c-style function so string is needed to convert with c_str (c-style string)
			iTmp = atoi( sArray[2].c_str() ); 
			GetGame()->GetPlayer().SetClass( (Class)iTmp );
			
			iTmp = 0;
			iTmp = atoi( sArray[3].c_str() ); 
			GetGame()->GetPlayer().SetAge(iTmp);
			
			iTmp = 0;
			iTmp = atoi( sArray[4].c_str() ); 
			GetGame()->GetPlayer().SetGender( (Gender)iTmp );
			
			iTmp = 0;
			iTmp = atoi( sArray[5].c_str() ); 
			GetGame()->GetPlayer().SetExperience(iTmp);	
			
			iTmp = 0;
			iTmp = atoi( sArray[6].c_str() ); 
			GetGame()->GetPlayer().gold = iTmp;	
			
			ifs.close();
		}
		catch(exception & e)
		{
			cout << "File handling error with error:  " << e.what() << endl;
		}
	}
};
