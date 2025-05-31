# HOSTEL-MANEGMENT-SYSTEM
A C-based Mess Management System for managing daily menus and collecting student feedback.


🔧 Developed by: [janhvi khawale]


📌 Project Description

The Mess Management System is a simple C-based console application that simulates basic functionalities of a college mess (cafeteria) system. It enables two types of users: Mess Providers and Students to interact with the system.

This project is designed for learning purposes, particularly to demonstrate file handling, user login simulation, and menu-driven interfaces in C programming.

------------------------------------------
🎯 Features


✅ Mess Provider:

Login with username and password

Add today’s menu (breakfast, lunch, dinner)

View feedback from students

View a weekly report based on student ratings



✅ Student:

Login with name

View today’s menu

Submit feedback (rating + complaint)



🗂 Files Used

menu.txt – Stores the current day's menu

feedback.txt – Stores student feedback in the format: rating,complaint


> ⚠ Both files are created/accessed automatically when you run the program.


---------------------------------------------

📁 Code Structure

main()

Displays the main menu

Directs user to either mess provider or student interface



messproviderlogin()

Simulates login using hardcoded credentials

Access to menu addition, feedback viewing, and report



addmenu()

Mess provider inputs meals

Saves data to menu.txt



studentlogin()

Student enters their name

Can view menu or submit feedback



viewmenu()

Displays today’s menu by reading from menu.txt



submitfeedback()

Takes rating and optional complaint

Saves to feedback.txt



viewfeedback()

Displays all feedback lines from feedback.txt



weeklyreport()

Reads all feedback

Counts and displays rating distribution



🔒 Mess Provider Credentials

Username: gcoey

Password: pass123


-----------------------------------------------------------
⚙ How to Run

1. Open any C compiler (Code::Blocks, Turbo C, GCC, etc.)


2. Copy the entire code into a .c file (e.g., mess_system.c)


3. Compile and run the program


4. Interact via command-line inputs

---------------------------------------------------

🚀 Future Improvements (Ideas)

Use dynamic memory for scalability

Add date-based menu/feedback system

Encrypt password storage

GUI interface using C/C++ graphics libraries or external tools

Separate admin and student data files

Store student name along with feedback

-----------------------------------------------------------

### Watch the Demo Video

You can see a demonstration of this project in action here:

[*Watch the Demo Video on Google Drive*](https://drive.google.com/file/d/1YLfENOXzDAM_zxVAhxmtYIYBilNDyNpo/view?usp=sharing)

   
