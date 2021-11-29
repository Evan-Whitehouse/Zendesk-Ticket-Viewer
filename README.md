# Zendesk Ticket Viewer

This project interacts with the Zendesk API to retrieve all tickets associated with an account and then displays them for the user.

## Installation
1. Make sure gcc is installed on your computer. (https://www.youtube.com/watch?v=wY24ehH6mC0)
2. Edit the shell script in Zendesk-Ticket-Viewer/controller, get-tickets.sh. Enter the username, password and domain name for your account in the appropriately named places.
3. Type make in the terminal while in the home directory.
4. Unit Tests can be compiled by running make in their directories.

## Design

The project was completed in C because I believe that it demonstrates skills that align with the team I am most interested in interning with at Zendesk, core services. I implemented the Model-View-Controller design pattern in order to promote clear, maintainable and testable code. All tickets were loaded into a list at the launch of the application, which I believe is more efficient with smaller numbers of tickets as we don't need to make multiple API calls, but may be less efficient as the number of tickets increases, where we could save resources by only getting tickets that we were interested in displaying.

### Model

Contains all methods for creating and handling an array of pointers to tickets and allocating that to memory. parseTickets is a JSON parsing function I wrote that is specific to Zendesk tickets, and I chose to write it over using an exisiting C json parsing library as it would allow me to create a ticket structure exactly suited to the fields I wanted to display, and would cut out unnecessary complexity. I broke up the logic in filling in the fields of the ticket appropriately into a seperate function mostly for readability reasons. ticketCount is a helper function in parseTickets that is also used for some of the logic in the controller. freeAll is a necessary function due to the fact that the array of ticket pointers is allocated to the heap by parseTickets and the program will need a portable way to deallocate that data structure and avoid memory leaks.  

### View

The view is rather straightforward and consists of functions the controller will call when prompted by user interaction. The fields "ID", "Subject", "Created At", "Updated At", "Priority", and "Status" were chosen to display by default imagining the client as a human surveying the list looking to quickly see actionable information to respond to. When a ticket is searched individually I decided to also print the description in order to give them more information and take advantage of the additional screen space available.

### Controller

The controller is the means of interaction between the program and the user, and uses the model to interact with the underlying data and the view to display the correct output according to the situation. For this program I decided to use a finite state machine for the menu, which I think promotes easy transitions between the various screens a user may need to see. A variable called page was created to help regulate which set of tickets would be displayed, as well as regulate state transitions. The main function of controller uses a while loop and conditional logic to handle state transitions, a decision that was made due to time constraints and would be very hard to implement for an FSM with more states. If I had more time to work on the project I would implement seperate functions for the state transitions which would make the main function a lot cleaner.

## Usage

Enter ./ztv in your terminal to launch the executable. Follow onscreen directions to navigate the UI. Enter q to quit while in the list view.

## Testing

Unit tests are present for the model and view, although view tests are fairly limited as several of the functions just call a printf statement. 
The controller does not have unit tests written, and I did black box testing to ensure state transitions were working as expected. If the state transitions were separate functions unit testing would be a lot more effective, and I would implement it by redirecting a text file containing a series of entries into the standard input during the test, and then redirect stdout to another textfile, comparing that file to one with my expected output. Time constraints over the holidays didn't allow me to complete that to my full satisfaction, but I'm definitely aware that it can be improved. I used https://jera.com/techinfo/jtns/jtn002 as my unit testing framework.

I also ran tbe program in valgrind to check for memory, leaks and none were found as seen below.
![image](https://user-images.githubusercontent.com/94804089/143813631-41c07e00-ebfc-41a4-9ff3-a4e7e65d0ca0.png)
