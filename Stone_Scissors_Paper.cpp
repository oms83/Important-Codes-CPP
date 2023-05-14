// كم جولة بدك تلعب ورح تلعب مرة
// خيار اللاعب
// خيار الكمبيوتر (عشوائني)
// طباعة نتيجة الجولة
// تلوين الشاشة
// شو خيار اللاعب وشو خيار الكموبيوتر
// الفائز بالجولة 
// اسم الفائز بالجولة
// طباعة شكل نهاية اللعبة
// محصلة الجولات
// الفائز 
// عدد مرات فوز كل من اللاعب والكمبيوتر
// اسم الفائز
// هل تريد اللعب مرة ثانية؟
// إزالة خيارات اللعبة السابقة
#include<iostream>
#include<stdlib.h>
#include<string>
using namespace std;
enum enGameChoice { Stone=1, Paper=2, Scissors=3 };
enum enWinner { Player1=1, Computer=2, Draw=3 };
struct stRoundInfo
{
    int RoundNumber=0;
    enGameChoice Player1Choice;
    enGameChoice ComputerChoice;
    enWinner Winner;
    string WinnerName;
};
struct stGameResults
{
    short GameRounds=0;
    short Player1WinTimes=0;
    short ComputerWinTimes=0;
    short DrawTimes=0;
    enWinner Winner;
    string WinnerName="";
};
int RandomNumber(int From, int To)
{
    return rand()%(To-From+1)+From;
}
string WinnerName(enWinner Winner)
{
    string arrWinnerName[3]={"Player1", "Computer", "No Winner" };
    return arrWinnerName[Winner-1];
}
string RoundChoice(enGameChoice Choice)
{
    string arrRoundChoice[3] = {"Stone", "Paper", "Scissors"};
    return arrRoundChoice[Choice-1];
}
enWinner HowWonTheRound(stRoundInfo RoundInfo)
{
    if(RoundInfo.ComputerChoice == RoundInfo.Player1Choice)
        return enWinner::Draw;
    switch(RoundInfo.Player1Choice)
    {
        case enGameChoice::Stone:
            if(RoundInfo.ComputerChoice == enGameChoice::Paper)
                return enWinner::Computer;
        case enGameChoice::Paper:
            if(RoundInfo.ComputerChoice == enGameChoice::Scissors)
                return enWinner::Computer;
        case enGameChoice::Scissors:
            if(RoundInfo.ComputerChoice == enGameChoice::Stone)
                return enWinner::Computer;
    }
    return enWinner::Player1;
};
void SetScreenColor(enWinner Winner)
{
    switch(Winner)
    {
        case enWinner::Player1:
            system("color 2F");
            break;
        case enWinner::Computer:
            system("color 4F");
            cout << "\a";
            break;
        case enWinner::Draw:
            system("color 6F");
            break;
    }
}
int StrLength(string str)
{
    int Length=0;
    for(int i=0; str[i]!='\0'; Length++, i++);
    return Length;
}
void PrintHeader(string header, char CharType, short CharNumber)
{
    int Length = StrLength(header);
    for(int i=0; i<CharNumber; i++)
        cout << CharType;
    cout << endl;
    int M=(CharNumber-Length)/2;
    for(int i=0; i<M; i++)
        cout << " ";
    cout << header << endl;
    for(int i=0; i<CharNumber; i++)
        cout << CharType;
    cout << endl;
}
void PrintResultRound(stRoundInfo RoundInfo)
{
    cout << "\n____________Round [" << RoundInfo.RoundNumber << "]____________\n";
    cout << "Player1 Choice :: " << RoundChoice(RoundInfo.Player1Choice) << endl;
    cout << "Computer Choice:: " << RoundChoice(RoundInfo.ComputerChoice) << endl;
    cout << "Round Winner   :: [" << RoundInfo.WinnerName << "]"<< endl;
    cout << "_________________________________\n";
    SetScreenColor(RoundInfo.Winner);
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
stGameResults FillGameResults(int GameRounds, short Player1WinTimes, short ComputerWinTimes, short DrawTimes)
{
    stGameResults GameResults;
    GameResults.ComputerWinTimes = ComputerWinTimes;
    GameResults.Player1WinTimes = Player1WinTimes;
    GameResults.DrawTimes = DrawTimes;
    GameResults.GameRounds = GameRounds;
    GameResults.Winner = HowWonTheGame(Player1WinTimes, ComputerWinTimes);
    GameResults.WinnerName = WinnerName(GameResults.Winner);
    return GameResults;
}
enGameChoice ReadPlayer1Choice()
{
    short Number=1;
    do
    {
        cout << "\nYour Choice: [1]:Stone, [2]:Paper, [3]:Scissors ? ";
        cin >> Number;
    }
    while(Number>3 || Number<1);
    return (enGameChoice)Number;
}
enGameChoice GetComputerChoice()
{
    return (enGameChoice)RandomNumber(1,3);
}
stGameResults PlayGame(int HowManyRounds)
{
    stRoundInfo RoundInfo;
    short Player1WinTimes=0, ComputerWinTimes=0, DrawTimes=0;
    for(int Round=1; Round<=HowManyRounds; Round++)
    {
        cout << "\nRound [" << Round << "] begins:\n";
        RoundInfo.Player1Choice = ReadPlayer1Choice();
        RoundInfo.ComputerChoice = GetComputerChoice();
        RoundInfo.RoundNumber = Round;
        RoundInfo.Winner = HowWonTheRound(RoundInfo);
        RoundInfo.WinnerName = WinnerName(RoundInfo.Winner);
        if(RoundInfo.Winner == enWinner::Computer)
            ComputerWinTimes++;
        else if(RoundInfo.Winner == enWinner::Player1)
            Player1WinTimes++;
        else
            DrawTimes++;
        PrintResultRound(RoundInfo);
    }

    return FillGameResults(HowManyRounds, Player1WinTimes, ComputerWinTimes, DrawTimes);
}
int ReadHowManyRounds()
{
    int Number;
    do
    {
        cout << "How Many Rounds 1 to 10 ? "; 
        cin >> Number;
    }
    while(Number>10 || Number<1);
    return Number;
}
void ResetScreen()
{
    system("cls");
    system("color 0F");
}
void ShowFinalGameResults(stGameResults GameResult)
{
    cout << "Game Rounds        : " << GameResult.GameRounds << endl;
    cout << "Player1 Won Times  : " << GameResult.Player1WinTimes << endl;
    cout << "Computer Won Times : " << GameResult.ComputerWinTimes << endl;
    cout << "Draw Times         : " << GameResult.DrawTimes << endl;
    cout << "Final Winner       : [" << GameResult.WinnerName << "]" << endl; 
}
void StartGame()
{
    char PlayAgain = 'Y';
    do 
    {
        ResetScreen();
        stGameResults GameResults = PlayGame(ReadHowManyRounds());
        PrintHeader("Game Over", '_', 50);
        ShowFinalGameResults(GameResults);
        cout << "Do you want play again [Y/N]: ";
        cin >> PlayAgain; 
    }while(PlayAgain=='Y' || PlayAgain=='y');
}
int main()
{
    StartGame();
}