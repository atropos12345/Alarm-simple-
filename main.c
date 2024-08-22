/******************************************************************************

RUBEN RAMIREZ
0432694
                    HOMEWORK 4

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define LENGTH 7

enum Weekday {
	MONDAY,
	TUESDAY,
	WEDNESDAY,
	THURSDAY,
	FRIDAY,
	SATURDAY,
	SUNDAY
};

enum options {
	NEW_ALARM_LIST = 1,
	NEW_ALARM_TIME = 2,
	EDIT_ALARM = 3,
	CANCEL_ALARM = 4,
	DELETE_LIST = 5,
	DISPLAY = 6,
	EXIT = 7
};

typedef struct node {
	struct node *next;
	int alarm_time;
	int day[LENGTH];

} node;

void menu();
bool createList(node **Headptr);
bool insert(node **Headptr, int alarm, int *day);
void day_string(int day);
void Display(node **Headptr);
void delete_list(node **Headptr);
void delete_alarm(node **head, int key);
void alarm();

int main()
{
	alarm();
	return 0;
}

// prints the menu options
void menu()
{
	printf("Please type the number of the menu option you would like.\n");
	printf("1. Initialize a new a list\n");
	printf("2. Schedule a new alarm.\n");
	printf("3. Edit an alarm\n");
	printf("4. Cancel an existing alarm\n");
	printf("5. Cancel all alarms\n");
	printf("6. Display the list of all scheduled alarms\n");
	printf("7. exit\n");
}

// initialize a pointer to the head of a new list
bool createList(node **Headptr)
{
	*Headptr = NULL;
	return true;
}

// creates a new node and places it in chronological order in the list
// updates node with the alarm time and day of the week
bool insert(node **Headptr, int alarm, int *day)
{
	node *new_node = malloc(sizeof(node));
	if (new_node == NULL) return false;
	new_node->alarm_time = alarm;
	new_node->next = NULL;
	for(int i = 0; i < (LENGTH); i++)
	{
		new_node->day[i] = day[i];
	}

	if(*Headptr == NULL || alarm < (*Headptr)->alarm_time)
	{
		new_node->next = *Headptr;
		*Headptr = new_node;
		return true;
	}
	node *curr = *Headptr;

	while (curr->next != NULL && curr->next->alarm_time < alarm)
	{
		curr = curr->next;
	}

	new_node->next = curr->next;
	curr->next = new_node;
	return true;
}

void day_string(int day)
{
	enum Weekday today;
	today = day;
	switch (today)
	{
	case MONDAY:
		printf("Monday");
		break;
	case TUESDAY:
		printf("Tuesday");
		break;
	case WEDNESDAY:
		printf("Wednesday");
		break;
	case THURSDAY:
		printf("Thursday");
		break;
	case FRIDAY:
		printf("Friday");
		break;
	case SATURDAY:
		printf("Saturday");
		break;
	case SUNDAY:
		printf("Sunday");
		break;
	default:
		printf("an unknown day");
		break;
	}
}

// print the alarm list
void Display(node **Headptr)
{
	if(*Headptr == NULL)
	{
		printf("List is empty\n");
		return;
	}
	node *curr = *Headptr;
	int alarm_num = 1;

	while(curr != NULL)
	{
		printf("alarm %d is set to %d hours on ", alarm_num, curr->alarm_time);
		for(int j = 0; j < LENGTH; j++)
		{
			if(curr->day[j] == 1)
			{
				day_string(j);
				printf(" ");
			}
		}
		printf("\n");
		alarm_num ++;
		curr = curr->next;
	}
}

// delete entire list
void delete_list(node **Headptr)
{
	node *curr = *Headptr;

	while(curr != NULL)
	{
		*Headptr = curr->next;
		free(curr);
		curr = *Headptr;
	}
}

// delete one instance of an alarm
void delete_alarm(node **head, int key) {
	node *temp = *head, *prev;

	// If the head node itself holds the key to be deleted
	if (temp != NULL && temp->alarm_time == key) {
		*head = temp->next; // Changed head
		free(temp); // free old head
		return;
	}

	// Search for the key to be deleted, keep track of the
	// previous node as we need to change 'prev->next'
	while (temp != NULL && temp->alarm_time != key) {
		prev = temp;
		temp = temp->next;
	}

	// If the key was not present in the linked list
	if (temp == NULL) {
		printf("Element not found\n");
		return;
	}

	// Unlink the node from linked list
	prev->next = temp->next;
	free(temp); // Free memory
}

void alarm()
{
	enum options option;
	node *newlist = NULL;
	bool created = false;
	int alarm, day[LENGTH];
	bool running = true;
	int temp = 0;
	while(running)
	{
		menu();
		scanf("%d", &temp);
		option = temp;
		switch(option)
		{
		case NEW_ALARM_LIST:
			created = createList(&newlist);
			if(created)
			{
				printf("List created successfully.\n");
			}
			else
			{
				printf("Failed to create list.\n");
			}
			break;

		case EDIT_ALARM:
			printf("Enter alarm time to edit: ");
			scanf("%d", &alarm);
			delete_alarm(&newlist, alarm);

		case NEW_ALARM_TIME:
			while(true)
			{
				printf("Enter alarm time (in military time): ");
				scanf("%d", &alarm);
				if(alarm < 0 || alarm > 2359)
				{
					printf("Invalid time format: HHMM\n");
				}
				else
				{
					break;
				}

			}

			printf("Enter day/s of the week:\n");
			for(int i = 0; i < LENGTH; i++)
			{
				int day_num = -1;
				while(true)
				{
					printf("Is the alarm set for ");
					day_string(i);
					printf("? (0 = No, 1 = Yes): ");
					scanf("%d", &day_num);
					if(day_num == 0 || day_num == 1)
					{
						break;
					}
					printf("invalid input\n");
				}
				day[i] = day_num;
			}
			created = insert(&newlist, alarm, day);
			if(created)
			{
				printf("Alarm created successfully.\n");
			}
			else
			{
				printf("Failed to create alarm.\n");
			}
			break;

		case CANCEL_ALARM:
			while(true)
			{
				printf("Enter alarm time (in military time): ");
				scanf("%d", &alarm);
				if(alarm < 0 || alarm > 2359)
				{
					printf("Invalid time format: HHMM\n");
				}
				else
				{
					break;
				}

			}
			delete_alarm(&newlist, alarm);

			break;
		case DELETE_LIST:
			delete_list(&newlist);
			printf("List deleted successfully.\n");
			break;
		case DISPLAY:
			Display(&newlist);
			break;
		case EXIT:
			// will delete list for now to prevent memory leak;
			printf("Now exiting alarm\n");
			delete_list(&newlist);
			running = false;
			break;
		default:
			printf("Invalid option.\n");
		}
	}
}






