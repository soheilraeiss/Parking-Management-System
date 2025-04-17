Parking Management System
Overview
The Parking Management System is a cross-platform application developed using C++ and QML within the Qt framework. It is designed to streamline the management of parking facilities by tracking vehicle entries and exits, supporting multiple user types (VIP, Normal, Daily) with distinct pricing models, and providing real-time capacity and fee calculations. The system is ideal for commercial parking lots, shopping centers, office buildings, or any facility requiring organized parking management.
Main Aims

Manage and track vehicles entering and exiting a parking facility.
Accommodate different user types with varying privileges and pricing:
VIP Users: 20% discount on parking fees, multiple vehicle registration.
Normal Users: Standard parking rates, basic registration.
Daily Users: Special rates for long-term or temporary parking.


Calculate parking fees based on duration of stay.
Maintain a database of parked vehicles and their owners.

Key Features

User Classification System: Differentiates between VIP, Normal, and Daily users.
Real-time Tracking: Monitors vehicle entry and exit.
Automated Cost Calculation: Computes fees based on user type and parking duration.
Multiple Pricing Models: Supports varied pricing structures for different users.
Capacity Management: Default limit of 100 parking spaces, with real-time availability updates.
Detailed Session Information: Displays comprehensive details for each parking session.
Graphical Interface: Built with QML for an enhanced user experience.
Data Storage: Temporarily stores user and parking data in Excel (.xls/.xlsx) files.
Reporting System: Generates reports on occupancy, user listings, and income.

Project Structure
The system is organized into the following main components:

User Class Hierarchy:
Base User: Stores basic user information.
VIPUser: Manages premium users with discounts and privileges.
NormalUser: Handles regular registered users.
DailyUser: Supports temporary parking users.


Parking Management Classes:
ParkingManagement: Main controller for system operations.
ParkingVIP: Manages VIP parking spaces.
ParkingNormal: Handles regular parking spaces.
ParkingDaily: Manages daily/temporary parking.


Key Functionalities:
User registration and management.
Space allocation and entry/exit tracking.
Duration-based fee calculation.
Reporting and transaction logging.


File Operations:
Reads/writes user and parking data.
Maintains transaction logs in Excel files.



Usage Flow

Initialize the system with floor and space configurations.
Select user type (VIP, Normal, or Daily).
Process vehicle entry or exit.
Handle payments based on calculated fees.
Generate reports for occupancy, income, or user details.

Special Features

VIP Users: Register multiple vehicles, receive discounted rates, and access special privileges.
Normal Users: Pay standard rates with basic registration.
Daily Users: Pay hourly rates without registration for temporary access.
Excel Integration: Stores user and parking data in Excel files for easy access and updates.
Real-time Notifications: Informs drivers of available parking spaces upon arrival.

Technical Details

Language: C++ (modern features, including multithreading).
Framework: Qt with QML for the graphical user interface.
Data Storage: Temporary storage in Excel (.xls/.xlsx) files.
Platform: Cross-platform compatibility.

Installation

Clone the repository:
git clone https://github.com/<your-username>/parking-management-system.git


Install the Qt framework and required dependencies.

Build the project using Qt Creator or the command line:
qmake
make


Run the application:
./parking_management_system



Future Enhancements

Implement socket-based communication to enable data exchange between multiple computers.
Add support for cloud-based data storage for scalability.
Enhance the UI with additional customization options for users.
Integrate real-time notifications for parking availability via mobile apps.

Contributing
Contributions are welcome! Please submit a pull request or open an issue to discuss improvements or bug fixes.
License
This project is licensed under the MIT License. See the LICENSE file for details.
Contact
For questions or feedback, please contact the project maintainer at soheilraeiss@gmail.com
