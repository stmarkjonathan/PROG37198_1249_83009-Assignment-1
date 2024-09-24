#include "Level.h"
#include "CommandHandler.h"

int main()
{
    int indexCount = 0;
    int undoCount = 0;
    int redoCount = 0;

    ofstream writeStream("level.bin", ios::out | ios::binary);
    ifstream readStream("level.bin", ios::in | ios::binary);

    bool gameRunning = true;

    Level* level = new Level();
    level->AssignNonDefaultValues();
    CommandHandler* cmdHandler = new CommandHandler(level);

    do {
        cout << endl;
        cout << "[Q]uit [S]ave Level [L]oad Level [Z] Undo [Y] Redo" << endl;
        cout << "[C]reate image buffer [D]elete image buffer [A]dd chunk [R]emove chunk" << endl;
        cout << "Index " << indexCount << ", Undo count " << undoCount << ", Redo count " << redoCount << endl;
        cout << endl;
        cout << endl;

        char choice;
        cin >> choice;
        
        switch (choice)
        {
        case 'q':
        case 'Q':

            cout << "Quitting Game...";
            gameRunning = false;
            delete level;
            delete cmdHandler;
            break;

        case 's':
        case 'S':

            level->Serialize(writeStream);
            writeStream.close();
            break;

        case 'l':
        case 'L':

            level->Deserialize(readStream);
            readStream.close();
            break;

        case 'z':
        case 'Z':

            break;

        case 'y':
        case 'Y':

            break;

        case 'c':
        case 'C':

            cmdHandler->HandleInput("CREATE_BUFFER");

            break;

        case 'd':
        case 'D':

            cmdHandler->HandleInput("DELETE_BUFFER");

            break;

        case 'a':
        case 'A':

            cmdHandler->HandleInput("ADD_CHUNK");


            break;

        case 'r':
        case 'R':

            break;

        default:

            
            break;

        }

       

    } while (gameRunning);
    

}

