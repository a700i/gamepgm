#include <stdio.h>
#include <conio.h>
#include <windows.h>
void gotoxy(int x, int y);
void display_text(int count);
void display_question(void);
void display_result(void);
void intro_game(void);
int restart_game(void);
void play_beep(void);  // 소리 재생 함수
char sol[10][11];  //사용자의 입력 값을 저장할 배열
int main(void)
{
    int restart = 1;  // 처음 실행 시는 항상 시작

    while (restart) {
        intro_game();
        display_question();
        printf("\n문제풀이가 모두 끝났습니다.\n");
        printf("\n\n풀이를 보려면 아무키나 누르시오.");
        getch();
        display_result();

        restart = restart_game();  // 재시작 여부 확인
    }
    
    printf("\n게임이 종료되었습니다.\n");
    return 0;
}

void gotoxy(int x, int y)
{
   COORD Pos = {x - 1, y - 1};
   SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}
void display_text(int count)
{
	gotoxy(1,2);
	printf("다음 문제를 읽고 답을 입력하시오.\n\n");
	printf("(%d번 문제) \n\n", count+1);

}
void display_question(void)
{
	FILE *fp1;
	char chr1[82];
	int line=5, count=0;
	char *file1="심리테스트질문.txt";
	fp1=fopen(file1, "r");
	system("cls");
	while(!feof(fp1))
	{
		fgets(chr1, 80, fp1);
		if (chr1[0]==10)
		{
			display_text(count);
			gotoxy(1, line);
			scanf("%s", sol[count]);
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	display_text(count);
	gotoxy(1, line);
	scanf("%s", sol[count]);
	fclose(fp1);

}
void display_result(void)
{
	FILE *fp2;
	char chr1[82];
	int line=5, count=0;
	char *file2="심리테스트해설.txt";
	fp2=fopen(file2, "r");
	system("cls");
	while(!feof(fp2))
	{
		fgets(chr1, 80, fp2);
		if (chr1[0]==10)
		{
			gotoxy(1, line+1);
			printf("당신의 답은 : %s\n", sol[count]);
			printf("다음문제의 해설은 아무키나 누르시오.");
			getch();
			system("cls");
			line=5;
			count++;
		}
		else
		{
			gotoxy(1, line++);
			printf("%s", chr1);
		}
	}
	gotoxy(1, line+1);
	printf("당신의 답은 : %s\n", sol[count]);
	fclose(fp2);

}
void intro_game(void)
{
    system("cls");
    printf("\n\n");
    printf("***********************************\n");
    printf("*                                 *\n");
    printf("*        심리 테스트 게임         *\n");
    printf("*                                 *\n");
    printf("***********************************\n\n");
    printf("제시되는 문제에 모두 답을 하고나면\n");
	printf("해설이 출력됩니다.\n\n");
    printf("시작하려면 아무 키나 누르세요...");
    getch();
    play_beep();  // 소리 재생
}

int restart_game(void)
{
    char choice;
    printf("\n게임을 다시 시작하려면 'y'를 누르시오. 종료하려면 다른 키를 누르시오: ");
    choice = getch();
    play_beep();  // 소리 재생

    if (choice == 'y' || choice == 'Y') {
        return 1;  // 재시작
    } else {
        return 0;  // 종료
    }
}
// 소리 재생 함수
void play_beep(void)
{
    Beep(1000, 100);  // 1000Hz의 소리를 100ms 동안 재생
}
