import calendar

def display_calendar():
    # Get user input for the year and month
    year = int(input("Enter the year (e.g., 2024): "))
    month = int(input("Enter the month (1-12): "))

    # Display the calendar for the input month and year
    print("\n" + calendar.month(year, month))

def main():
    while True:
        display_calendar()
        # Option to view another month/year or exit
        cont = input("Do you want to view another month? (yes/no): ").lower()
        if cont != 'yes':
            print("Exiting the calendar viewer.")
            break

if __name__ == "__main__":
    main()
