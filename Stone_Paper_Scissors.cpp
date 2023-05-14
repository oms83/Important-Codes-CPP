#include<iostream>
#include<conio.h>
#include<ctime>
#include<string>
using namespace std;

enum enGameChocie {Stone=1, Paper=2, Scissors=3};
enum enWinner {Player1=1, Computer=2, Draw=3};
struct stRoundInfo
{
    short RoundNumber = 0;
    enGameChocie Player1Choice;
    enGameChocie ComputerChoice;
    enWinner Winner;
    string WinnerName;
};
struct stGameResults
{
    short GameRounds = 0;
    short Player1WinTimes=0;
    short Computer2WinTimes=0;
    short DrawTimes=0;
    enWinner GameWinner;
    string WinnerName;
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
enWinner WhoWonTheRound(stRoundInfo RoundInfo)
{
    if(RoundInfo.Player1Choice == RoundInfo.ComputerChoice)
        return enWinner::Draw;
    switch(RoundInfo.Player1Choice)
    {
        case enGameChocie::Stone:
            if(RoundInfo.ComputerChoice == enGameChocie::Paper)
                return enWinner::Computer;
            break;
        case enGameChocie::Paper:
            if(RoundInfo.ComputerChoice==enGameChocie::Scissors)
                return enWinner::Computer;
            break;
        case enGameChocie::Scissors:
            if(RoundInfo.ComputerChoice == enGameChocie::Stone)
                return enWinner::Computer;
            break;
    }
    return enWinner::Player1;
}
string ChoiceName(enGameChocie Choice)
{
    string arrGameChoices[3] = { "Stone", "Paper", "Scissors" };
    return arrGameChoices[Choice-1];
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
    cout << "Player1 Choice  : " << ChoiceName(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice : " << ChoiceName(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner    : [" << RoundInfo.WinnerName << "]\n";
    cout << "__________________________________\n";
    SetWinnerScreenColor(RoundInfo.Winner);
}
enWinner WhoWonTheGame(short PlayerWinTimes, short ComputerWinTimes)
{
    if(PlayerWinTimes>ComputerWinTimes)
        return enWinner::Player1;
    else if(ComputerWinTimes>PlayerWinTimes)
        return enWinner::Computer;
    else 
        return enWinner::Draw;
}
stGameResults FillGameResults(int GameRounds, short PlayerWinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.GameRounds = GameRounds;
    GameResults.Player1WinTimes = PlayerWinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.Computer2WinTimes = ComputerWinTimes;
    GameResults.GameWinner = WhoWonTheGame(PlayerWinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.GameWinner);
    return GameResults;
}
enGameChocie ReadPlayer1Choice()
{
    short Choice = 1;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Choice;
    } while(Choice<1 || Choice>3);
    return (enGameChocie)Choice;
}
enGameChocie GetComputerChoice()
{
    return (enGameChocie)RandomNumber(1, 3);
}
stGameResults PlayerGame(short HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes = 0, ComputerWinTimes = 0, DrawTimes = 0; 
    for (short GameRound = 1; GameRound <= HowManyRounds; GameRound++) 
    { 
        cout << "\nRound [" << GameRound << "] begins:\n"; 
        RoundInfo.RoundNumber = GameRound; 
        RoundInfo.Player1Choice = ReadPlayer1Choice(); 
        RoundInfo.ComputerChoice = GetComputerChoice(); 
        RoundInfo.Winner = WhoWonTheRound(RoundInfo); 
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner); 

        if (RoundInfo.Winner == enWinner::Player1) 
            Player1WinTimes++; 
        else if (RoundInfo.Winner == enWinner::Computer) 
            ComputerWinTimes++; 
        else
            DrawTimes++; 
        PrintRoundResults(RoundInfo); 
    } 
    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes); 
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
void ShowGameOverScreen() 
{ 
    cout << Tabs(2) << "__________________________________________________________\n\n"; 
    cout << Tabs(2) << "                 +++ G a m e O v e r +++\n"; 
    cout << Tabs(2) << "__________________________________________________________\n\n"; 
} 
void ShowFinalGameResults(stGameResults GameResults) 
{ 
    cout << Tabs(2) << "_____________________ [Game Results ]_____________________\n\n"; 
    cout << Tabs(2) << "Game Rounds : " << GameResults.GameRounds << endl; 
    cout << Tabs(2) << "Player1 won times : " << GameResults.Player1WinTimes << endl; 
    cout << Tabs(2) << "Computer won times : " << GameResults.Computer2WinTimes << endl; 
    cout << Tabs(2) << "Draw times : " << GameResults.DrawTimes << endl; 
    cout << Tabs(2) << "Final Winner : " << GameResults.WinnerName << endl; 
    cout << Tabs(2) << "___________________________________________________________\n"; 
    SetWinnerScreenColor(GameResults.GameWinner); 
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
void ResetScreen() 
{ 
 system("cls"); 
 system("color 0F"); 
} 
void StartGame() 
{ 
    char PlayAgain = 'Y'; 
    do
    { 
        ResetScreen(); 
        stGameResults GameResults = PlayerGame(ReadHowManyRounds()); 
        ShowGameOverScreen(); 
        ShowFinalGameResults(GameResults); 
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