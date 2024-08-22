# Alarm-simple-
A simple alarm app in C

# Alarm Management System

## Overview
This C program is an alarm management system that allows users to create, edit, and manage multiple alarms. It provides a simple menu-driven interface to perform various operations, such as creating a new alarm list, adding alarms, editing or canceling alarms, and displaying all scheduled alarms. The program stores alarms in a linked list, making it easy to manage and update the alarms dynamically.

## Features
- **Create a New Alarm List**: Initialize an empty list to store alarms.
- **Add a New Alarm**: Schedule a new alarm with a specific time (in military format) and select the days of the week for which the alarm should be active.
- **Edit an Alarm**: Modify an existing alarm's time or the days it is set to go off.
- **Cancel an Alarm**: Remove a specific alarm from the list.
- **Delete All Alarms**: Clear the entire list of alarms.
- **Display Alarms**: View all scheduled alarms with their respective times and active days.

## Usage
1. **Initialize a New Alarm List**: Start by initializing a new list to store alarms.
2. **Add Alarms**: Add new alarms by entering the alarm time and selecting the days of the week for which the alarm should be active.
3. **Edit or Cancel Alarms**: Modify or remove existing alarms as needed.
4. **View Scheduled Alarms**: Display the list of all alarms, showing the time and the days they are set to go off.
5. **Exit**: Safely exit the program, deleting the alarm list to prevent memory leaks.

## Menu Options
- `1. Initialize a new list`
- `2. Schedule a new alarm`
- `3. Edit an existing alarm`
- `4. Cancel an existing alarm`
- `5. Delete all alarms`
- `6. Display all alarms`
- `7. Exit`

## Example
Upon running the program, the user is presented with a menu to choose from the above options. The user can input the desired option number to perform an action. For example, selecting option `2` allows the user to schedule a new alarm by entering the time in military format (e.g., `0700` for 7:00 AM) and specifying the days of the week.

## Code Structure
- **main.c**: Contains the main logic for the alarm management system, including functions to create and manipulate the alarm list, and handle user inputs from the menu.

## How to Compile and Run
1. **Compile the Program**:
   ```bash
   gcc main.c -o alarm_manager
