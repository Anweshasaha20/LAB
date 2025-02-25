import java.util.Scanner;

class Date {
    private int day;
    private int month;
    private int year;

    public Date() {
        this.day = 1;
        this.month = 1;
        this.year = 1970;
    }

    public Date(int day) {
        this.day = day;
        this.month = 1;
        this.year = 1970;
    }

    public Date(int day, int month) {
        this.day = day;
        this.month = month;
        this.year = 1970;
    }

    public Date(int day, int month, int year) {
        this.day = day;
        this.month = month;
        this.year = year;
    }

    public Date getPreviousDay() {
        Date previousDay = new Date(this.day, this.month, this.year);

        if (previousDay.day > 1) {
            previousDay.day--;
        } else {
            if (previousDay.month > 1) {
                previousDay.month--;
                previousDay.day = getDaysInMonth(previousDay.month, previousDay.year);
            } else {
                previousDay.year--;
                previousDay.month = 12;
                previousDay.day = 31;
            }
        }

        return previousDay;
    }

    public Date getNextDay() {
        Date nextDay = new Date(this.day, this.month, this.year);

        if (nextDay.day < getDaysInMonth(nextDay.month, nextDay.year)) {
            nextDay.day++;
        } else {
            if (nextDay.month < 12) {
                nextDay.month++;
                nextDay.day = 1;
            } else {
                nextDay.year++;
                nextDay.month = 1;
                nextDay.day = 1;
            }
        }

        return nextDay;
    }

    public void printDate() {
        System.out.printf("%02d-%02d-%04d\n", day, month, year);
    }

    private int getDaysInMonth(int month, int year) {
        switch (month) {
            case 4:
            case 6:
            case 9:
            case 11:
                return 30;
            case 2:
                return isLeapYear(year) ? 29 : 28;
            default:
                return 31;
        }
    }

    private boolean isLeapYear(int year) {
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }
}

 class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter day: ");
        int day = scanner.nextInt();
        System.out.print("Enter month: ");
        int month = scanner.nextInt();
        System.out.print("Enter year: ");
        int year = scanner.nextInt();

        Date date = new Date(day, month, year);

        System.out.print("Current Date: ");
        date.printDate();

        Date previousDay = date.getPreviousDay();
        System.out.print("Previous Day: ");
        previousDay.printDate();

        Date nextDay = date.getNextDay();
        System.out.print("Next Day: ");
        nextDay.printDate();

        scanner.close();
    }
}