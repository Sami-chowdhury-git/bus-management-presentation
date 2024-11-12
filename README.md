Bus Management System

Introduction

The Bus Management System is a C-based command-line application designed to manage bus ticket reservations between two primary routes: Sylhet to Dhaka and Sylhet to Chittagong. This program allows users to view available buses, book specific seats, check bus statuses, and cancel bookings in a simple, streamlined interface. With customizable fare rates and user authentication, this system provides a foundation for managing basic bus reservations and simulates core functionalities often found in real-world reservation software.

Background:

I was looking for interesting projects to work on when I came across the idea of creating a bus management system. Since I frequently travel by bus to visit relatives and explore new places, the idea immediately appealed to me. During my search, I found a basic source code on GitHub, but it had several bugs and limited features. I took on the challenge of fixing those issues and added new functionalities to make the program more practical and visually appealing.

Features:

The Bus Management System includes several essential features for bus reservation management:

Login System: Simple authentication ensures only authorized users can access the system.

Route Selection: Users can choose from two main routes (Sylhet to Dhaka and Sylhet to Chittagong).

Bus Listing: Displays available buses per route for easy selection.

Ticket Booking: Allows users to book a specific number of seats by selecting seat numbers. Tickets are priced by destination.

Seat Status View: Users can check bus seat statuses, seeing which are booked and which remain available.

Booking Cancellation: Users can cancel specific seat reservations by seat number, updating availability and managing fare adjustments.

Limitations:

Some limitations of the current version include:

Limited Routes: Only supports two fixed routes, with a set number of buses for each route.

Static Bus Names: Bus names are hardcoded, requiring code updates to add or modify buses.

Offline-Only: Lacks real-time data integration, suitable mainly for offline use.

Basic Command-Line Interface: The text-based interface may be less user-friendly for those unfamiliar with command-line environments.

No Data Persistence: Booking data resets on program restart, as there’s no file or database integration.

Future Scope:

Several enhancements could be made to improve this system’s usability and functionality:

Database Integration: Persistent data storage would allow for saving booking information across sessions.

Expanded Routes and Bus Options: More routes and dynamically updatable bus options would increase the system’s utility.

Graphical Interface: Transitioning to a graphical or web-based UI would enhance accessibility and improve user experience.

Automated Seat Assignment: The system could suggest available seats to users to streamline the booking process.

Advanced Fare Management: Expanding fare options, such as discounts or classes, would add flexibility.

Mobile and Web Support: Developing a mobile or web-based version would enable remote access, enhancing convenience.

main manu:

![Screenshot 2024-11-12 215103](https://github.com/user-attachments/assets/56465a5f-27b8-4a42-8390-2912e7567255)

view bus list:

![Screenshot 2024-11-12 220420](https://github.com/user-attachments/assets/70748483-da64-4114-a4a8-eb983dde8a8d)

ticket booking feature:

![ticket book 2](https://github.com/user-attachments/assets/d82204b7-90b3-4a64-932d-bc4dd22fcd49)

view bus status:

![bus status](https://github.com/user-attachments/assets/09922151-150d-4254-b590-154a0404c242)

cancel booking feature:

![cancel booking 2](https://github.com/user-attachments/assets/5c8e753a-4650-4698-b8f6-b0afe923ce2e)

exit manu:


![exit](https://github.com/user-attachments/assets/83911fda-0d05-449a-a5bb-d266aba441aa)







