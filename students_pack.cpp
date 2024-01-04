#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;


class Student {

private:
    vector<int> marks;
    string name;

public:
    Student(string n): name(n) {};

    string getName() {
        return name;
    }

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
protected:
    bool mood = rand() % 2;
    int moodCounter = 0;

public:

    void setMood(bool m) {
        mood = m;
        if (mood == 0) cout << "Плохое настроение" << endl;
        else cout << "Хорошее настроение" << endl;
    }

    virtual void setMarkStudent(Student &student) {

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

        moodCounter++;
        if ((moodCounter % 5) == 0) {
            int moodChange = rand();
            setMood(moodChange % 2);
        }

    }

    void setMarkStudent(Student& student, int mark) {
        student.addMark(mark);
    }

};


class RandomMoodTeacher: public Teacher {

private:
    bool mood = rand() % 2;

public:

    void setMarkStudent(Student &student) override {

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

        moodCounter++;
        if ((moodCounter % 2) == 0) {
            int moodChange = rand();
            setMood(moodChange % 2);
        }

    }

};

class KindTeacher: public Teacher {

public:

    void setMarkStudent(Student &student) override {
        student.addMark(5);
    }

};

class EvilTeacher: public Teacher {

public:

    void setMarkStudent(Student &student) override {
        student.addMark(2);
    }

};


class Lesson {

public:

    void addStudent(Student &student) {
        groupList.push_back(student);
    }

    void setAllMarks(Teacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void setAllMarks(KindTeacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void setAllMarks(EvilTeacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void setAllMarks(RandomMoodTeacher &teacher) {
        for (int i = 0; i < groupList.size(); i++) {
            teacher.setMarkStudent(groupList[i]);
        }
    }

    void printNewMarks() {
        int n = 0;

        for (int i = 0; i < groupList.size(); i++) {
            n++;
            cout << n << " студент: ";
            groupList[i].printMarks();
        }
        cout << endl;
    }

private:
    vector<Student> groupList;

};


class Parent {

private:
    bool mood = rand() % 2;
    vector<Student> children;


public:

    void addChild(Student &child) {
        children.push_back(child);
    }

    void sayAboutAllChild() {
        if (children.size() == 0) return;

        for (int i = 0; i < children.size(); i++) {

            if (children[i].isExcellentStudent() && mood == 1) cout << children[i].getName() << " учится на отлично, он молодец. ";
            if (children[i].isExcellentStudent() && mood == 0) cout << children[i].getName() << " отличник, но не помогает мне по дому. ";
            if (!(children[i].isExcellentStudent()) && mood == 1) cout << children[i].getName() << " не отличник, но за то у него есть другие таланты, например хорошо рисует. ";
            if (!(children[i].isExcellentStudent()) && mood == 0) cout << children[i].getName() << " плохо учится и не помогает по дому, он бесполезен.";
        }

        cout << endl;
    }

    void sayAboutRandomChild() {

        int n = rand() % children.size();

        if (children[n].isExcellentStudent() && mood == 1) cout << children[n].getName() << " учится на отлично, он молодец. ";
        if (children[n].isExcellentStudent() && mood == 0) cout << children[n].getName() << " отличник, но не помогает мне по дому. ";
        if (!(children[n].isExcellentStudent()) && mood == 1) cout << children[n].getName() << " не отличник, но за то у него есть другие таланты, например хорошо рисует. ";
        if (!(children[n].isExcellentStudent()) && mood == 0) cout << children[n].getName() << " плохо учится и не помогает по дому, он бесполезен.";

        cout << endl;
    }

    void sayAboutGeneral () {

        bool token = 1;

        for (int i = 0; i < children.size(); i++) {
            if (children[i].isExcellentStudent()) continue;
            else token = 0;
        }

        if (token == 1 && mood == 1) cout << "Они самые лучшие дети" << endl;
        if (token == 1 && mood == 0) cout << "Они хорошие дети" << endl;
        if (token == 0 && mood == 1) cout << "Они хорошие дети, но не самые лучшие" << endl;
        if (token == 0 && mood == 0) cout << "Им стоит стараться лучше вести себя" << endl;
    }

    void sayAboutCertainChild(string name) {

        int counter = 10000;

        for (int i = 0; i < children.size(); i++) {
            if ((children[i].getName()) == name) counter = i;
            else continue;
        }

        if (counter != 10000) {
            bool token = 1;

            for (int i = 0; i < children.size(); i++) {
                if (!children[i].isExcellentStudent()) token = 0;
            }

            if (token == 1 && mood == 1) cout << children[counter].getName() << " учится на отлично, он молодец." << endl;
            if (token == 1 && mood == 0) cout << children[counter].getName() << " отличник, но не помогает мне по дому." << endl;
            if (token == 0 && mood == 1) cout << children[counter].getName() << " не отличник, но за то у него есть другие таланты, например хорошо рисует." << endl;
            if (token == 0 && mood == 0) cout << children[counter].getName() << " плохо учится и не помогает по дому, он бесполезен." << endl;

        }

        else cout << name << " - это не мой ребенок" << endl;
    }

};



int main() {

    srand(time(NULL));

    Student a("Аня");
    Student b("Миша");
    Student c("Гриша");
    Student d("Юля");

    a.addMark(5);
    b.addMark(3);
    c.addMark(4);
    d.addMark(5);

    Parent p;
    p.addChild(a);
    p.addChild(b);
    p.addChild(c);
    p.addChild(d);

    p.sayAboutAllChild();
    p.sayAboutRandomChild();
    p.sayAboutGeneral();
    p.sayAboutCertainChild("Аня");
    p.sayAboutCertainChild("Миша");
    p.sayAboutCertainChild("Гриша");

    return 0;
}
