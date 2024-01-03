#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Student {

private:
    vector<int> marks;


public:

    // Метод для добавления отметки
    void addMark(int mark) {
        marks.push_back(mark);
    }

    void printMarks() {
        for (int i = 0; i < marks.size(); i++) {
            cout << marks[i] << ", ";
        }
        cout << endl;
    }


    // Метод для вычисления РАУ
    double calculateRAU() const {
        if (marks.empty()) {
            return 0.0;
        }

        double sum = 0.0;
        for (int mark : marks) {
            sum += mark;
        }

        return sum / marks.size();
    }


    // Метод для определения является ли студент отличником
    bool isExcellentStudent() const {

        if (calculateRAU() >= 4.8) {
            cout << "Студент отличник" << endl;
            return 1;
        }

        else {
            cout << "Студент не отличник" << endl;
            return 0;
        }
    }

};



class Teacher {
private:
    bool mood = rand() % 2;

public:

    void setMood(bool m) {
        mood = m;
        if (mood == 0) cout << "Плохое настроение" << endl;
        else cout << "Хорошее настроение" << endl;
    }


    void setMarkStudent(Student &student) {

        bool isExcellent = student.isExcellentStudent();

        if (mood == 1) {
            if (isExcellent) {
                student.addMark(5);
            }

            else {
                student.addMark(4);
            }
        }

        else {
            if (isExcellent) {
                student.addMark((rand() % 2 == 0) ? 4 : 5);
            }

            else {
                student.addMark((rand() % 2 == 0) ? 2 : 3);
            }
        }
    }


    void setMarkStudent(Student& student, int mark) {
        student.addMark(mark);
    }

};



int main() {

    srand(time(NULL));
    Student a;
    a.addMark(5);
    a.addMark(5);
    a.addMark(5);
    a.printMarks();
    a.isExcellentStudent();

    Teacher t;
    t.setMood(0);
    t.setMarkStudent(a);

    a.printMarks();
    a.isExcellentStudent();

    return 0;
}
