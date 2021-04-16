// Student No.：B10702057  Name：盧昱達 
// File Name：b10702057-hwk2-1.cpp
// Compiler：Dev C++
// Date：2019/04/02
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 52

using namespace std;

typedef struct {
    int rank, suit;
} PokerCard;

void random_array(int a[], int n){
	srand(time(0));
    for ( int i = 0; i < n; i++){
        a[i] = rand() % n;
        for ( int j = 0; j < i; j++){
            if (a[i] == a[j]){
                --i;
                break;
            }
        }
    }
}

void print_array(PokerCard poker[], int a[], int b[], int n){
    char rank[] = "23456789tjqka", suit[] = "cdhs";
    for ( int i = 0; i < n; i++){
        poker[i].rank = a[i] % 13;  //數字
        poker[i].suit = a[i] % 4;  //花色
        if ( b[i] == 0 && i < 36){ //列印六成六的牌 
             printf("%c%c ", rank[poker[i].rank], suit[poker[i].suit]);
        }
        else if ( i < 36){         //避開用過的牌 
            cout << "**";
        }
       if ( (i + 1) % 6 == 0 && i < 36) puts("");
    }
}

int number(int n){
    if ( n % 13 == 12 ){           //計算台的分數 
        return 20;
    }
    else {
        return n % 13 + 2;
    }
}

int main ( void ) {
    int a[SIZE], b[SIZE] = {0};     // a == 牌, b == 記錄用過的牌 
    char rank[] = "23456789tjqka", suit[] = "cdhs";
    PokerCard poker[SIZE];

    int player_number = 0, computer_number = 0;       // 每輪各自得分 
    int player_rand[3] = {0}, computer_rand[3] = {0}; // 0 == 第一個骰子, 1 == 第二個骰子, 2 == 牌的位子
    int player_total = 0, computer_total = 0;         // 各自遊戲總分 
    char op = 'p';

    srand(time(0));
    random_array(a, SIZE);

    while ( op == 'p' || op == 'P'){                  //判別遊戲開始 
        cout << "Who plays first: Player (P) or Computer (C)?\n";
        cin >> op;                                    //是否進行遊戲 
        while ( op == 'p' || op == 'P'){              
        	
            print_array(poker, a, b, 52);             //列印 

            do{                                       //亂數玩家骰子 
                player_rand[0] = rand() % 6 + 1; 
                player_rand[1] = rand() % 6 + 1;
                player_rand[2] = (player_rand[0] - 1) * 6 + player_rand[1] - 1;
            }  while ( b[player_rand[2]] == 1 && b[player_rand[2]] != 0);   //不得使用過 
            b[player_rand[2]] = 1;                    //紀錄已使用 

            do{                                       //電腦骰 
                computer_rand[0] = rand() % 6 + 1;
                computer_rand[1] = rand() % 6 + 1;
                computer_rand[2] = (computer_rand[0] - 1) * 6 + computer_rand[1] - 1;
            } while ( b[computer_rand[2]] != 0 );
            b[computer_rand[2]] = 1;

            player_number = number(player_rand[2]);   //計算各自牌得分 
            computer_number = number(computer_rand[2]);
			
            if ( player_number > computer_number){    //判斷最終得分，並加總 
                player_total += player_number + computer_number;
                player_number = player_number + computer_number;
                computer_number = 0;
            }
            else if ( player_number < computer_number){
                computer_total += player_number + computer_number;
                computer_number = player_number + computer_number;
                player_number = 0;
            }
            else{
                player_total += player_number;
                computer_total += computer_number;
            }
            //輸出各自結果 
            printf("Player:   %d %d    Card: %c%c       Points: %d\n", player_rand[0], player_rand[1], rank[poker[player_rand[2]].rank], suit[poker[player_rand[2]].suit], player_number);
			printf("Computer: %d %d    Card: %c%c       Points: %d\n", computer_rand[0], computer_rand[1], rank[poker[computer_rand[2]].rank], suit[poker[computer_rand[2]].suit], computer_number);
            cout << "Who plays first: Player (P) or Computer (C)?\n";
        	cin >> op;
        }
    }
    
    cout << "Player's total points: " << player_total << endl;
    cout << "Computer's total points: " << computer_total << endl;
    
    if ( player_total > computer_total ) {    //遊戲結束顯示結果 
    	cout << "The winner is Player.\n";
	}
	else if ( player_total < computer_total ) {
		cout << "The winner is Computer.\n";
	}
	else{
		cout << "Draw the game\n";
	}
}
