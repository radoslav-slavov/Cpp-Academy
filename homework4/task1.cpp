#include <iostream>
#include <bitset>

void setAttendance(uint64_t &attendance, int studentNumber) {
    attendance |= (1ULL << (studentNumber - 1));
}

void clearAttendance(uint64_t &attendance, int studentNumber) {
    attendance &= ~(1ULL << (studentNumber - 1));
}

void printAttendanceInfo(const uint64_t &attendance, bool present) {
    std::cout << (present ? "Present" : "Absent") << " students: ";
    for (int i = 0; i < 64; ++i) {
        if (((attendance >> i) & 1) == present) {
            std::cout << (i + 1) << " ";
        }
    }
    std::cout << std::endl;
}

void toggleAttendance(uint64_t &attendance, int studentNumber) {
    attendance ^= (1ULL << (studentNumber - 1));
}

int main() {
    uint64_t attendance = 0;
    int option;

    while (true) {
        std::cout << "1. Set attendance" << std::endl;
        std::cout << "2. Clear attendance" << std::endl;
        std::cout << "3. Show absent students" << std::endl;
        std::cout << "4. Show present students" << std::endl;
        std::cout << "5. Change attendance" << std::endl;
        std::cout << "6. Exit" << std::endl;
        std::cin >> option;

        if (option == 6) {
            break;
        }

        int studentNumber;
        switch (option) {
            case 1:
                std::cout << "Enter student number (1-64): ";
                std::cin >> studentNumber;
                if (studentNumber >= 1 && studentNumber <= 64) {
                    setAttendance(attendance, studentNumber);
                } else {
                    std::cout << "Invalid student number!" << std::endl;
                }
                break;
            case 2:
                std::cout << "Enter student number (1-64): ";
                std::cin >> studentNumber;
                if (studentNumber >= 1 && studentNumber <= 64) {
                    clearAttendance(attendance, studentNumber);
                } else {
                    std::cout << "Invalid student number!" << std::endl;
                }
                break;
            case 3:
                printAttendanceInfo(attendance, false);
                break;
            case 4:
                printAttendanceInfo(attendance, true);
                break;
            case 5:
                std::cout << "Enter student number (1-64): ";
                std::cin >> studentNumber;
                if (studentNumber >= 1 && studentNumber <= 64) {
                    toggleAttendance(attendance, studentNumber);
                } else {
                    std::cout << "Invalid student number!" << std::endl;
                }
                break;
            default:
                std::cout << "Invalid option!" << std::endl;
                break;
        }
    }

    return 0;
}
