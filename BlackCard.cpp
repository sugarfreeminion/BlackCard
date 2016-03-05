/*******************************************************
 * Program Name:    BlackCard
 * Date:            29 FEB 2016
 * Description:     The first argument is a path to a 
 *                  file. Each line includes a test
 *                  case with names of players and a 
 *                  number for a "black spot". Players
 *                  and a number are separated by a '|'
 ******************************************************/

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

using namespace std;

int StringToInt(string val);

int main(int argc, char *argv[])
{
    ifstream inputFile;

    string line;

    char delimiter = '|';

    inputFile.open(argv[1]);

    if(inputFile.is_open())
    {
        stringstream lineStream;

        while(getline(inputFile,line))
        {
            string players;
            string tempPlayer;
            string tempBlackSpot;

            vector<string> player;
            size_t delimiterLocation = line.find(delimiter);

            unsigned int blackSpot = 0;

            //cout << line << endl;

            players = line.substr(0,delimiterLocation-1);
            tempBlackSpot = line.substr(delimiterLocation+2, line.size()-delimiterLocation+1);

            lineStream << players;

            while(getline(lineStream,tempPlayer,' '))
            {
                player.push_back(tempPlayer);
            }

            blackSpot = StringToInt(tempBlackSpot);

            while(player.size() > 1)
            {
                int removeIndex = blackSpot % player.size();

                if( removeIndex == 0 )
                {
                    removeIndex = player.size();
                }

                removeIndex = removeIndex - 1;

                player.erase(player.begin() + removeIndex);
            }

            cout << player[0] << endl;

            lineStream.str("");
            lineStream.clear();
        }

        inputFile.close();
    }
    else
    {
        cout << "Error opening input file" << endl;
    }

    return 0;
}

int StringToInt(string val)
{
    stringstream valStream;

    int result;

    valStream << val;

    valStream >> result;

    return result;
}
