#include <iostream>
#include <fstream>
#include <string>
#include <string.h>
#include <windows.h>
using namespace std;

/*int brute_force(string src,string dst)
{
  int i=0,j,k;
  while(i<src.length()){
 	for(j=i,k=0;j<src.length()&&k<dst.length()&&src[j]==dst[k];j++,k++);
	if(k==dst.length()){
	  return i;
	}
      i++;
   }
  return -1;
}*/

void gotoxy(int xpos, int ypos)
{
	COORD scrn;
	HANDLE hOuput = GetStdHandle(STD_OUTPUT_HANDLE);
	scrn.X = xpos; scrn.Y = ypos;
	SetConsoleCursorPosition(hOuput,scrn);
}

int InputText(char input[]){
	fstream InF;
	int n = 0;                                                                            
	char FName[20], ch;  //FName = 檔名
	cout << "輸入方程式檔名:\n";
	cin >> FName;
	InF.open(FName, ios::in);
	if(!InF){
		cout << "檔案無法開啟\n";
	}else{
		while(InF.get(ch)){
			cout << ch;
			input[n] = ch;
		}
		InF.close();
	}
	return n;
}

void printchar(char input[], int n){
	cout << input;
	for ( int i = 0; i < n; i++){
		cout << input[i];
	}
}
int main(void){
	int n; // n = 紀錄文章總長度
	char input[2000];
	n = InputText(input);
	//cout << n << endl;
	//cout << input << endl;
	//printchar(input, n);
}
