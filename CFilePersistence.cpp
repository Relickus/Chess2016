#include "CFilePersistence.h"
#include <iostream>
#include <fstream>

using namespace std;

bool CFilePersistence::loadGame(const char * file) const {
    
     
        ifstream ifs( file );

        if( ! ifs.is_open() ){
            
            cout << "Nepodarilo se nacist soubor \""<< file <<"\" "<<endl;
            return false;
        }

}

bool CFilePersistence::saveGame() const {
    
    time_t timestamp;    
    time(&timestamp);
    
    string s( ctime(&timestamp) );
    
    ofstream ofs( s.c_str() );

        if( ! ofs.is_open() ){
        
            cout << "Nepodarilo se vytvorit soubor \""<< s <<"\" "<<endl;
            return false;
        }
    

}
