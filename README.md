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

### View

### Controller

## Usage

## Testing

