#include <stdio.h>
#include <string.h>
#include <conio.h>
#include <stdlib.h>

#define NUMPASSWORDS 3
#define NUMUSERS 3
#define LENGTH 8
#define PASSWWORD_FILE "passwords.txt"
#define PASSWWORD_FILE "users.txt"

typedef struct passenger {
	int passNum ;
	char fName[10];
	char sName[10] ;
	int yearBorn ;
	char email[15];
	int areaFrom ;
	int seating ;
	int trips;
	int duration;
} passengers_t;

 struct node {
	 int value;
	passengers_t passing;
	struct node* next;
};

 struct users {
	 char username[LENGTH];
	 char password[LENGTH];
};

void addPassenger(struct node** head);
//void displayPassenger(node* head);
int present(struct node* head, int passNum);
void listPassengers();
void statistics(int chosen, int demo);
//FILE *file = fopen("passenger.txt", "a+");
int searchBypassNumOrName(struct node* head);
int searchByPassNum(struct node* head, int passNum);
void sort(struct node* top);
void deletepassengers(struct node **head);
void report(struct node* head);

int main() {

	struct node* passengerList = NULL;
	//struct node* tail = NULL;

	int choice = 0;
	int correct = 0;


	printf("What would you like to do?\n");
	printf("1) Add passenger (Note: Passport Number must be unique).\n");
	printf("2) Display all passenger to screen\n");
	printf("3) Display passenger Details\n");
	printf("4) Update a passenger statistic\n");
	printf("5) Delete passenger\n");
	printf("6) Generate statistics\n");
	printf("7) Print all passenger details into a report file.\n");
	printf("8) List all the passenger of the following the UK in order of year born.\n");
	printf(" \n");
	printf("Enter 9 to Exit \n");
	printf(" \n");



	int passNum;
	while (choice != -1)
	{
		printf("Enter number: ");
		scanf("%d", &choice);


		if (choice == 1) {
			printf("1) Add passenger (Note: Passport Number must be unique).\n");

			addPassenger(&passengerList);
			
		}
		else if (choice == 2) {
			printf("2) Display all passenger details to screen\n");
			listPassengers();
			
			
		}
		else if (choice == 3) {
			printf("Please enter the passenger number\n");

			searchBypassNumOrName(&passengerList);
			break;
		}
		else if (choice == 4) {
			printf("4) Update a passenger statistic\n");
			
		}
		else if (choice == 5) {
			printf("5) Delete passenger\n");
			deletepassengers(&passengerList);
			
		}
		else if (choice == 6) {
			int chosen;
			int demo;
			printf("6) Generate statistics\n");

			printf("1. % of players who travel from the UK\n");
			printf("2. % of players who travel from the Rest of Europe\n");
			printf("3. % of players who travel from the Asia\n");
			printf("4. % of players who travel from the Americas\n");
			printf("5. % of players who travel from the Australasia\n");
			printf("6. % of players who spent on average one day in Ireland\n");
			printf("7. % of players who spent on average less than 3 days in Ireland\n");
			printf("8. % of players who spent on average less than 7 days in Ireland\n");
			printf("9. % of players who spent on average more than 7 days in Ireland\n");
			printf("choose stat \n");
			scanf("%d", &chosen);
			printf("1. Travel Class\n");
			printf("2. Born Before 1980\n");

			printf("choose stat \n");
			scanf("%d", &demo);

			printf("\n");
			statistics(chosen, demo);
		}
		else if (choice == 7) {
			printf("7) Print all passenger details into a report file.\n");
			report(passengerList);
			
		}
		else if (choice == 8) {
			printf("8) List all the passenger of the following the UK in order of year born.\n");
			break;
		}
		else if (choice == -1) {
			printf("Exiting\n");
			exit;
		}
	}
}
void loggedIn() {
	FILE* userFile = fopen("users.txt", "r");
	char uName[10];
	char password[10];
	printf("Enter username \n");
	scanf("%s", &uName);
	printf("Enter password \n");
	scanf("%s", &password);
}
void addPassenger(struct node** head)
{
	int tempPassNum;
	int email = 0;
	char tempEmail[20];
	struct node* temp;
	struct node* newnode;
	//struct passenger* newPass;

	newnode = (struct node*)malloc(sizeof(struct node));
	//newPass = (struct passenger*)malloc(sizeof(struct passenger));

	printf("Please enter the passenger number\n");
	scanf("%d", &newnode->passing.passNum);

	printf("Please enter the passenger first name\n");
	scanf("%s", &newnode->passing.fName);

	printf("Please enter the passenger second name\n");
	scanf("%s", &newnode->passing.sName);


	printf("Please enter the passenger year born\n");
	scanf("%d", &newnode->passing.yearBorn);

	printf("Please enter the passenger email \n");
	while (email == 0) {
		scanf("%s", &tempEmail);
		if (emailValid(tempEmail) == 1)
		{
			strcpy(newnode->passing.email, tempEmail);
			email++;
		}
		else {
			printf("Invalid email \n");
		}
	}


	printf("Which area did you travel from\n");
	printf(" 1 UK	\n2 Rest of Europe	\n3 Asia	\n4 Americas	\n5 Australasia \n");

	scanf("%d", &newnode->passing.areaFrom);


	printf("What was your travel class\n");
	printf("1 Economy	2 Premium Economy	3 Business Class	4 First Class\n");

	scanf("%d", &newnode->passing.seating);

	printf("How many trips to Ireland do you make per year?\n");
	printf("1 Less than three times per year \n 2 Less than five times per year \n 3 More than five times per year\n");

	scanf("%d", &newnode->passing.trips);


	printf("On average how long is your duration?\n");
	printf(" 1 One day \n 2 Less than 3 days\n 3 Less than 7 days \n 4 More than 7 days\n");
	scanf("%d", &newnode->passing.duration);


}


int searchBypassNumOrName(struct node* head) {
	struct node* newnode = head;
	char searchName[30];
	char passingName[30];
	int choice;
	int passNum;
	int count = 0;
	int location = -1;

	printf("Search by\n 1) Passport Num\n 2) Full name\n");



	scanf("%d", &choice);
	if (choice == 1) {
		scanf("Enter passNum : %d", &passNum);
		location = searchByPassNum(head, passNum);
	}
	return location;
}
int searchByPassNum(struct node* head, int passNum) {
	struct node* newnode = head;
	int count = 0;
	int location = -1;

	while (newnode != NULL) {
		if (newnode->passing.passNum == passNum) {
			location = count;
			break;
		}

		count++;
		newnode = newnode->next;
	}

	return location;
}
int present(struct node* head, int passNum) {
	int isPresent = 0;
	int count = 0;
	struct node *temp = head;
	return count;

}
void listPassengers() {
	FILE* read = fopen("Passenger.txt", "r");
	if (read != NULL)
	{
		int c;

		while ((c = fgetc(read)) != EOF)
		{
			putchar(c);
		}
		printf("\n");
		fclose(read);
	}

}
int emailValid(char emailaddress[]) {
	int valid = 0;
	int j = 0;

	char atSym = '@';
	char com[] = ".com";

	char *end;
	end = &emailaddress[strlen(emailaddress) - 4];
	int length = strlen(emailaddress);

	for (int i = 0; i <length; i++) {
		if (atSym == emailaddress[i]) {
			j++;
		}
	}
	if (j >= 1) {
		if (strcmp(end, com) == 0) {
			valid = 1;
		}
	}
	return valid;
}

void statistics(int choice, int demo) {
	
	
}


void sort(struct node* top)
{
	struct node* new1;
	struct node* count;

	new1 = top;

	for (; new1->next != NULL; new1 = new1->next)
	{
		for (count = new1->next; count != NULL; count = count->next)
		{
			if (new1->value > count->value)
			{
				int temp = new1->value;
				new1->value = count->value;
				count->value = temp;
			}
		}
	}
}

void deletepassengers(struct node** head) {
	int present = 0;
	int tempNum;
	struct node *temp;
	struct node *prev;
	int status;
	temp = (struct node*)malloc(sizeof(struct node));
	temp = *head;
	prev = NULL; 

	printf("\nPlease enter the passenger number of the passengers you want to delete: ");
	scanf("%d", &tempNum);

	while (temp != NULL) {
		if (temp->passing.passNum == tempNum) {//if passNum and tempNum are equal 
			printf("\nDeleting the passengers with passenger Number: %d\n", temp->passing.passNum);

			present = 1;

			if (prev != NULL) {
				prev->next = temp->next;
			}
			else {
				*head = temp->next;
			}
			free(temp);

			break;
		}

		prev = temp;
		temp = temp->next;
	}
		if (present == 0) {
		printf("\nSorry, no passengers with passNum Number: %d in the database!\n", tempNum);//can't find the passengers
	}
}
void report(struct node* head) {

	FILE *file = fopen("passenger.txt", "w+");
	struct node* newnode;
	struct node* temp;

	newnode = (struct node*)malloc(sizeof(struct node));
	while (newnode != NULL) {

		fprintf(file, "\nPass num:%d ", newnode->passing.passNum);
		fprintf(file, " First name:%s ", newnode->passing.fName);
		fprintf(file, " Second name:%s ", newnode->passing.sName);
		fprintf(file, " Year:%d ", newnode->passing.yearBorn);
		fprintf(file, " Email:%s ", newnode->passing.email);
		fprintf(file, " From:%d ", newnode->passing.areaFrom);
		fprintf(file, " Class:%d ", newnode->passing.seating);
		fprintf(file, " Trips:%d ", newnode->passing.trips);
		fprintf(file, " Duration:%d ", newnode->passing.duration);

		newnode = newnode->next;
	}
	

}