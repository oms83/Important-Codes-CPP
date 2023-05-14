#include<iostream>
#include<string>
#include<stdlib.h>
using namespace std;

enum enGameChoices { Stone=1, Paper=2, Scissors=3 };
enum enWinner { Player1=1, Computer=2, Draw=3 };
struct stRoundInfo
{
    short RoundNumber;
    enGameChoices Player1Choice;
    enGameChoices ComputerChoice;
    enWinner Winner;
    string WinnerName;
}; 
struct stGameResults
{
    short GameRound;
    short Player1WinTimes=0;
    short ComputerWinTimes=0;
    short DrawTimes=0;
    string WinnerName="";
    enWinner Winner;
};
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
string WinnerName(enWinner Winner)
{
    string arrWinnerName[3] = {"Player1", "Computer", "No Winner"};
    return arrWinnerName[Winner-1];
}
string RoundChoice(enGameChoices GameChoice)
{
    string arrGameChoice[3] = {"Stone", "Paper", "Scissors"};
    return arrGameChoice[GameChoice-1];
}
enWinner HowWonTheRound(stRoundInfo RoundInfo)
{
    if(RoundInfo.ComputerChoice == RoundInfo.Player1Choice)
        return enWinner::Draw;
    switch(RoundInfo.Player1Choice)
    {
        case enGameChoices::Stone:
            if(RoundInfo.ComputerChoice == enGameChoices::Paper)
                return enWinner::Computer;
        case enGameChoices::Paper:
            if(RoundInfo.ComputerChoice == enGameChoices::Scissors)
                return enWinner::Computer;
        case enGameChoices::Scissors:
            if(RoundInfo.ComputerChoice == enGameChoices::Stone)
                return enWinner::Computer;
    }
    return enWinner::Player1;
}
enGameChoices ReadPlayer1Choice()
{
    short Choice;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Choice;
    }while(Choice>3||Choice<1);
    return (enGameChoices)Choice;
}
enGameChoices GetComputerChoice()
{
    return (enGameChoices)RandomNumber(1, 3);
}
string Tabs(short NumberOfTabs) 
{ 
    string t = ""; 
    for (int i = 1; i < NumberOfTabs; i++) 
    { 
        t = t + "\t"; 
        cout << t; 
    } 
    return t; 
}
void ShowGameOver()
{
    cout << Tabs(2) << "----------------------------------------\n";
    cout << Tabs(2) << "        +++ G a m e  O v e r +++\n";
    cout << Tabs(2) << "----------------------------------------\n";
}
enWinner HowWonTheGame(short Player1WinTimes, short ComputerWinTimes)
{
    if(Player1WinTimes>ComputerWinTimes)
        return enWinner::Player1;
    else if(Player1WinTimes<ComputerWinTimes)
        return enWinner::Computer;
    else 
        return enWinner::Draw;
}
void SetWinnerScreenColor(enWinner Winner)
{
    switch(Winner)
    {
        case enWinner::Player1:
            system("color 2F");
            cout << "\a";
            break;
        case enWinner::Computer:
            system("color 4F");
            break;
        default:
            system("color 6F");
            break;
    }
}
void PrintRoundResults(stRoundInfo RoundInfo)
{
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "] ____________\n\n";
    cout << "Player1 Choice  : " << RoundChoice(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice : " << RoundChoice(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner    : [" << RoundInfo.WinnerName << "]\n";
    cout << "__________________________________\n";
    SetWinnerScreenColor(RoundInfo.Winner);
}
stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameRound = GameRounds;
    GameResults.Winner = HowWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.Winner);
    return GameResults;
}
void ResetScreen()
{
    system("color 0F");
    system("cls");
}
stGameResults PlayGame(int HowManyRound)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes=0, ComputerWinTimes=0, DrawTimes=0;
    for(int Round=1; Round<=HowManyRound; Round++)
    {
        cout << "Round [" << Round << "] begins: \n";
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.Winner = HowWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
        PrintRoundResults(RoundInfo);
        if(RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else if(RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else
            DrawTimes++;
    }
    return  FillGameResults(HowManyRound, Player1WinTimes, ComputerWinTimes, DrawTimes);
}
void PrintFinalGameResults(stGameResults GameResults)
{
    cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n"; 
    cout << Tabs(2) << "Game Rounds : " << GameResults.GameRound << endl; 
    cout << Tabs(2) << "Player1 won times : " << GameResults.Player1WinTimes << endl; 
    cout << Tabs(2) << "Computer won times : " << GameResults.ComputerWinTimes << endl; 
    cout << Tabs(2) << "Draw times : " << GameResults.DrawTimes << endl; 
    cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << endl; 
    cout << Tabs(2) << "___________________________________________________________\n"; 
    SetWinnerScreenColor(GameResults.Winner); 
}
short ReadHowManyRounds() 
{ 
    short GameRounds = 1; 
    do
    { 
        cout << "How Many Rounds 1 to 10 ? \n"; 
        cin >> GameRounds; 
    }while (GameRounds < 1 || GameRounds >10); 
    return GameRounds; 
} 
void StartGame() 
{ 
    char PlayAgain = 'Y'; 
    do
    { 
        ResetScreen(); 
        stGameResults GameResults = PlayGame(ReadHowManyRounds()); 
        ShowGameOver(); 
        PrintFinalGameResults(GameResults); 
        cout << endl << Tabs(3) << "Do you want to play again? Y/N? "; 
        cin >> PlayAgain; 

    } while (PlayAgain == 'Y' || PlayAgain == 'y'); 
}
int main() 
{ 
    srand((unsigned)time(NULL));  
    StartGame(); 
    return 0; 
}





