// Student No.�GB10702057  Name�G�c�R�F 
// File Name�Gb10702057-hwk2-1.cpp
// Compiler�GDev C++
// Date�G2019/04/02
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
        poker[i].rank = a[i] % 13;  //�Ʀr
        poker[i].suit = a[i] % 4;  //���
        if ( b[i] == 0 && i < 36){ //�C�L���������P 
             printf("%c%c ", rank[poker[i].rank], suit[poker[i].suit]);
        }
        else if ( i < 36){         //�׶}�ιL���P 
            cout << "**";
        }
       if ( (i + 1) % 6 == 0 && i < 36) puts("");
    }
}

int number(int n){
    if ( n % 13 == 12 ){           //�p��x������ 
        return 20;
    }
    else {
        return n % 13 + 2;
    }
}

int main ( void ) {
    int a[SIZE], b[SIZE] = {0};     // a == �P, b == �O���ιL���P 
    char rank[] = "23456789tjqka", suit[] = "cdhs";
    PokerCard poker[SIZE];

    int player_number = 0, computer_number = 0;       // �C���U�۱o�� 
    int player_rand[3] = {0}, computer_rand[3] = {0}; // 0 == �Ĥ@�ӻ�l, 1 == �ĤG�ӻ�l, 2 == �P����l
    int player_total = 0, computer_total = 0;         // �U�۹C���`�� 
    char op = 'p';

    srand(time(0));
    random_array(a, SIZE);

    while ( op == 'p' || op == 'P'){                  //�P�O�C���}�l 
        cout << "Who plays first: Player (P) or Computer (C)?\n";
        cin >> op;                                    //�O�_�i��C�� 
        while ( op == 'p' || op == 'P'){              
        	
            print_array(poker, a, b, 52);             //�C�L 

            do{                                       //�üƪ��a��l 
                player_rand[0] = rand() % 6 + 1; 
                player_rand[1] = rand() % 6 + 1;
                player_rand[2] = (player_rand[0] - 1) * 6 + player_rand[1] - 1;
            }  while ( b[player_rand[2]] == 1 && b[player_rand[2]] != 0);   //���o�ϥιL 
            b[player_rand[2]] = 1;                    //�����w�ϥ� 

            do{                                       //�q���� 
                computer_rand[0] = rand() % 6 + 1;
                computer_rand[1] = rand() % 6 + 1;
                computer_rand[2] = (computer_rand[0] - 1) * 6 + computer_rand[1] - 1;
            } while ( b[computer_rand[2]] != 0 );
            b[computer_rand[2]] = 1;

            player_number = number(player_rand[2]);   //�p��U�۵P�o�� 
            computer_number = number(computer_rand[2]);
			
            if ( player_number > computer_number){    //�P�_�̲ױo���A�å[�` 
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
            //��X�U�۵��G 
            printf("Player:   %d %d    Card: %c%c       Points: %d\n", player_rand[0], player_rand[1], rank[poker[player_rand[2]].rank], suit[poker[player_rand[2]].suit], player_number);
			printf("Computer: %d %d    Card: %c%c       Points: %d\n", computer_rand[0], computer_rand[1], rank[poker[computer_rand[2]].rank], suit[poker[computer_rand[2]].suit], computer_number);
            cout << "Who plays first: Player (P) or Computer (C)?\n";
        	cin >> op;
        }
    }
    
    cout << "Player's total points: " << player_total << endl;
    cout << "Computer's total points: " << computer_total << endl;
    
    if ( player_total > computer_total ) {    //�C��������ܵ��G 
    	cout << "The winner is Player.\n";
	}
	else if ( player_total < computer_total ) {
		cout << "The winner is Computer.\n";
	}
	else{
		cout << "Draw the game\n";
	}
}
