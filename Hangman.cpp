#include<string>
#include<iostream>

class _programVariables
{
private:
    short const _MAXTRIES = 12;
    short _amountGuessed = 0;
    short _mainMenu;

    std::string _guess;
    std::string _word[3] = { "abstract" , "incoherence" , "biochemistry" };

public: 
    char _restart;
    char& _ref_restart = _restart;

    void welcome_page(void);
    void game_easy(short index, char& _ref_restart);
};



int main()
{
    _programVariables _programVarObj;

    do
    {
        system("CLS");
        _programVarObj.welcome_page();

    } while (_programVarObj._restart == 'y');
    
    return 0;
}



void _programVariables::welcome_page(void)
{
    do
    {
        std::cout << "Welcome to Hangman. Choose a difficulty:\n" << std::endl;
        std::cout << "1.) Easy" << std::endl;
        std::cout << "2.) Normal" << std::endl;
        std::cout << "3.) Hard\n" << std::endl;
        std::cin >> _mainMenu;
        system("CLS");

        while (!std::cin || _mainMenu < 1 || _mainMenu > 3)
        {
            system("CLS");
            std::cin.clear();
            std::cin.ignore(100, '\n');

            std::cout << "Invalid input\n\n";

            std::cout << "Welcome to Hangman. Choose a difficulty:\n" << std::endl;
            std::cout << "1.) Easy" << std::endl;
            std::cout << "2.) Normal" << std::endl;
            std::cout << "3.) Hard\n" << std::endl;
            std::cin >> _mainMenu;
        }


        switch (_mainMenu)
        {
        case 1:
            game_easy(0, _ref_restart);
            break;
        case 2:
            game_easy(1, _ref_restart);
            break;
        case 3:
            game_easy(2, _ref_restart);
            break;
        default:
            std::cout << "Unknown error. Exiting application...";
            exit(0);
        }

    } while (_restart == 'y');
}

void _programVariables::game_easy(short index, char& _ref_restart)
{ 
    std::string _empty(_word[index].length(), '-');

    do
    {
        system("CLS");

        std::cout << "Guess #" << _amountGuessed + 1 << std::endl;
        std::cout << "Word: " << _empty << std::endl;
        std::cout << "\nYour guess: ";
        std::cin >> _guess;
        ++_amountGuessed;

        for(unsigned int x = 0; x <= _word[index].size(); x++)
        {
            int _charFind = _word[index].find(_guess, x);

            if (_charFind != std::string::npos)
            {
                _empty.replace(_charFind, 1, _guess);
            }
            
        }

        if (_empty == _word[index])
        {
            system("CLS");
            std::cout << "You won! You guessed \"" << _word[index] << "\" in only " << _amountGuessed << " guesses!\n\n";
            std::cout << "Would you like to go to the main menu? (y/n): ";
            std::cin >> _ref_restart;

            break;
        }
        
        if(_amountGuessed == 12)
        {
            system("CLS");
            
            std::cout << "Better luck next time. The word was \"" << _word[index] << "\"\n\n";
            std::cout << "Would you like to go to the main menu? (y/n): ";
            std::cin >> _ref_restart;

            break;
        }

    } while (_amountGuessed < _MAXTRIES);
    
}
