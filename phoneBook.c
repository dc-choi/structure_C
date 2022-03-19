#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define CAPACITY 100
#define BUFFER_SIZE 20

char *names[CAPACITY];
char *numbers[CAPACITY];
int personCount = 0;

void add()
{
	char name_buffer[BUFFER_SIZE];
	char number_buffer[BUFFER_SIZE];

	printf("이름을 추가하세요 : ");
	scanf("%s", name_buffer);

	printf("전화번호를 추가하세요 : ");
	scanf("%s", number_buffer);

	names[personCount] = strdup(name_buffer);
	numbers[personCount] = strdup(number_buffer);
	personCount++;

	printf("%s was add!\n", name_buffer);
}

void find()
{
	char buf[BUFFER_SIZE];
	int index = 0;

	printf("이름을 입력하세요 : ");
	scanf("%s", buf);

	while (names[index])
	{
		if (strcmp(buf, names[index]) == 0)
		{
			printf("%s의 전화번호는 %s입니다.\n", names[index], numbers[index]);
			return;
		}
		index++;
	}
	printf("%s는 등록되어있지않습니다.\n", buf);
}

void status()
{
	for (int index = 0; index < personCount; index++)
		printf("%s %s\n", names[index], numbers[index]);
	printf("등록된 총 인원수는 %d명 입니다.\n", personCount);
}

void delete()
{
	char buf[BUFFER_SIZE];
	int index = 0;

	printf("이름을 입력하세요 : ");
	scanf("%s", buf);

	while (names[index])
	{
		if (strcmp(buf, names[index]) == 0)
		{
			names[index] = names[personCount - 1];
			numbers[index] = numbers[personCount - 1];
			personCount--;
			printf("%s 삭제 완료.\n", buf);
			return;
		}
		index++;
	}
	printf("%s는 등록되어있지않습니다.\n", buf);
}

int main(void)
{
	char command[BUFFER_SIZE];

	while (1)
	{
		printf("$ ");
		scanf("%s", command);

		if (strcmp(command, "add") == 0)
			add();
		else if (strcmp(command, "find") == 0)
			find();
		else if (strcmp(command, "status") == 0)
			status();
		else if (strcmp(command, "delete") == 0)
			delete();
		else if (strcmp(command, "exit") == 0)
			break;
		else
			printf("명령어 형식이 올바르지 않습니다.\n");	
	}

	return 0;
}